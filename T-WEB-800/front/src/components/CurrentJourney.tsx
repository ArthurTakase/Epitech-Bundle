import { useCallback, useEffect, useRef, useState } from "react"
import { ActivityData } from "./Activity"
import { actions } from "./Map"
import L from "leaflet"
import { MarkerData } from "./Map"
import JourneyActivity from "./JourneyActivity"
import "../scss/currentJourney.scss"
import "leaflet-routing-machine";
import Pin from "../pictures/Pin.png"
import { FiDownloadCloud } from "react-icons/fi"
import { FaSave } from "react-icons/fa"
import { MdErrorOutline } from "react-icons/md"
import axios from "axios"
import { toast } from "react-toastify"
import { FaCopy } from "react-icons/fa"
import { myJourneysActions } from "./MyJourneys"

interface JourneyActions {
    addActivity: (activity: ActivityData) => void,
    removeActivity: (activity: ActivityData) => void,
    moveActivity: (activity: ActivityData, up: number) => void,
    setActionBar: (actionBar: boolean) => void,
    activityExist: (activity: ActivityData) => boolean,
    importJourney: (code: string) => void,
}

export const journeyActions: JourneyActions = {
    addActivity: (_: ActivityData) => {},
    removeActivity: (_: ActivityData) => {},
    moveActivity: (_: ActivityData, __: number) => {},
    setActionBar: (_: boolean) => {},
    activityExist: (_: ActivityData) => false,
    importJourney: (_: string) => {},
}

export default function CurrentJourney() {
    const [journey, setJourney] = useState<ActivityData[]>([])
    const [markers, setMarkers] = useState<MarkerData[]>([])
    const [actionBar, setActionBar] = useState<boolean>(false)
    const [code, setCode] = useState<string>("")
    const codeInputRef = useRef<HTMLInputElement>(null)

    const removeMarker = useCallback((activity: ActivityData) => {
        const marker = markers.find((m) => m.id === activity.id)
        if (marker) {
            marker.marker.remove()
            const newMarkers = markers.filter((m) => m.id !== activity.id)
            setMarkers(newMarkers)
        }
    }, [markers])

    const addActivity = useCallback((activity: ActivityData) => {
        if (journey.find((a) => a.id === activity.id)) return
        
        const newJourney = [...journey, activity]
        setJourney(newJourney)
        createRoute(newJourney)
    }, [journey])

    const removeActivity = useCallback((activity: ActivityData) => {
        const isConfirmed = window.confirm("Êtes-vous sûr de vouloir supprimer cette activité ?");
    
        if (!isConfirmed) {
            return; 
        }

        removeMarker(activity);
        const newJourney = journey.filter((a) => a.id !== activity.id);
        setJourney(newJourney);
        createRoute(newJourney);
    
        const button = document.getElementById(`addToJourney_${activity.id}`) as HTMLButtonElement;
        if (button) button.style.display = "block";
    }, [journey, removeMarker]);
    

    const moveActivity = useCallback((activity: ActivityData, up: number) => {
        const index = journey.findIndex((a) => a.id === activity.id)
        if (index === -1) return

        const newIndex = index + up
        if (newIndex < 0 || newIndex >= journey.length) return

        const newJourney = journey.slice()
        newJourney[index] = journey[newIndex]
        newJourney[newIndex] = journey[index]

        createRoute(newJourney)
        setJourney(newJourney)
    }, [journey])

    const createMarker = (i: any, wp: any): L.Marker => {
        const marker = L.marker(wp.latLng, {
            icon: L.divIcon({
                html: `<div>
                    <img src=${Pin} alt="Pin" />
                    <span>${i + 1}</span>
                    </div>`,
                iconSize: [25, 41],
                iconAnchor: [12, 41],
                popupAnchor: [1, -34],
                className: 'waypointActivity'
            }),
        })
        marker.on('click', () => {
            actions.useMap?.setView(wp.latLng, 20)
        })
        return marker
    }

    const createRoute = useCallback((newJourney: ActivityData[]) => {
        const routeInfos = document.querySelectorAll(".leaflet-routing-container.leaflet-bar.leaflet-control")
        routeInfos.forEach((info) => info.remove())

        actions.useMap?.eachLayer((layer) => {
            if (layer instanceof L.Polyline)
                layer.remove()
            if (layer instanceof L.Marker && layer.options.title !== "activity")
                layer.remove()
        })

        const waypoints: L.Routing.Waypoint[] = newJourney.map((activity) => {
            return {
                latLng: L.latLng(activity.position.lat, activity.position.lng),
            }
        })

        const route = L.Routing.control({
            waypoints: waypoints,
            routeWhileDragging: false,
            addWaypoints: false,
            show: false,
            plan: L.Routing.plan(waypoints, {
                draggableWaypoints: false,
                createMarker
            }),
            formatter: new L.Routing.Formatter({
                language: "fr",
                units: 'metric',
                roundingSensitivity: 10,
                distanceTemplate: '{value} {unit}',
            })
        })

        route.addTo(actions.useMap!)
    }, [])

    const SaveJourney = useCallback(() => {
        if (!localStorage.getItem('token')) {
            toast.error("Connectez-vous pour sauvegarder un voyage")
            return
        }

        const journeyElements = document.getElementsByClassName("journeyActivity")
        const journeyDatas = Array.from(journeyElements).map((element) => {
            return {
                id: element.getAttribute("data-id"),
                name: encodeURIComponent(element.getAttribute("data-name") || "")
            }
        })

        if (journeyDatas.length === 0) {
            toast.error("Ajoutez des activités pour sauvegarder un voyage")
            return
        }

        const header = { "Authorization": `Bearer ${localStorage.getItem('token')}` }
        const journeySave = JSON.stringify(journeyDatas)
        const journeySaveBase64 = btoa(journeySave)
        const body = { 'save': { 'data': journeySaveBase64 } }

        axios.post("http://localhost:4000/api/saves", body, { headers: header })
        .then(res => {
            const code = res.data.data.code
            toast.success("Voyage sauvegardé (code: " + code + ")")
            setCode(code)
            myJourneysActions.GetSaves()
        })
        .catch(err => {
            console.error(err)
            toast.error("Erreur lors de la sauvegarde")
        })
    }, [])

    const ExportJourney = useCallback(() => {
        if (!localStorage.getItem('token')) return
        if (code === "") return

        navigator.clipboard.writeText(code)
        toast.success("Code copié dans le presse-papier")
    }, [code])

    const ImportJourney = useCallback((code: string | undefined) => {
        if (code === undefined) return
        
        axios.get(`http://localhost:4000/api/saves/code/${code}`)
        .then(res => {
            setJourney(res.data.data)
            createRoute(res.data.data)
            for (const activity of res.data.data) {
                const button = document.getElementById(`addToJourney_${activity.id}`) as HTMLButtonElement
                if (button) button.style.display = "none"
            }
            toast.success("Voyage importé avec succès")
        })
        .catch(err => {
            console.error(err)
            toast.error(`Erreur lors de l'importation. ${err}`)
        })
    }, [])

    const ActivityExist = useCallback((activity: ActivityData): boolean => {
        return journey.find((a) => a.id === activity.id) !== undefined
    }, [journey])

    useEffect(() => {
        journeyActions.addActivity = addActivity
        journeyActions.removeActivity = removeActivity
        journeyActions.moveActivity = moveActivity
        journeyActions.setActionBar = setActionBar
        journeyActions.activityExist = ActivityExist
        journeyActions.importJourney = ImportJourney

        if (localStorage.getItem('token')) setActionBar(true)
    }, [addActivity, removeActivity, moveActivity, setActionBar])

    return (
    <>
        <div className="journeyTitle">
            <div className="journeySaveExport">
                {actionBar && journey.length > 0
                    ?   <button onClick={SaveJourney}>
                            <FaSave />
                            <span>Sauvegarder</span>
                        </button>
                    : null
                }
                {actionBar && code !== "" && journey.length > 0
                    ?   <button onClick={ExportJourney}>
                            <FaCopy />
                            <span>Copier</span>
                        </button>
                    : null
                }
                {!actionBar
                    ? <button disabled={true} className="disabled"><MdErrorOutline /> Connectez-vous</button>
                    : null
                }
            </div>
            <div className="journeyCode">
                <input type="text" placeholder="Entrez un code" ref={codeInputRef} />
                <button onClick={() => ImportJourney(codeInputRef.current?.value)}><FiDownloadCloud /></button>
            </div>
        </div>
        <div className="journeyList">
            { journey.length === 0
                ? <>~ Importez une sauvegarde ou ajoutez des destinations à votre trajet ~</>
                : journey.map((activity, index) => <JourneyActivity key={index} activity_data={activity} index={index} /> )}
        </div>
    </>
    )
}