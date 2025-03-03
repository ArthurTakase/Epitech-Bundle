import "../scss/activity.scss"
import { FaLink } from "react-icons/fa"
import { FaMapMarkerAlt } from "react-icons/fa"
import { FaBookmark } from "react-icons/fa6"
import L from "leaflet"
import { actions } from "./Map"
import { useEffect, useState } from "react"
import MarkerPink from "../pictures/Pink.png"
import MarkerYellow from "../pictures/Yellow.png"
import MarkerGreen from "../pictures/Green.png"
import MarkerBlue from "../pictures/Blue.png"
import MarkerPurple from "../pictures/Purple.png"
import PinkYellow from "../pictures/PinkYellow.png"
import { journeyActions } from "./CurrentJourney"

interface Location {
    lat: number
    lng: number
}

interface Address {
    city: string
    countryCode: string
    countryName: string
    county: string
    houseNumber: string
    label: string
    postalCode: string
    state: string
    stateCode: string
    street: string
}

interface Category {
    id: string
    name: string
    primary?: boolean
}

interface Contact {
    phone?: { value: string }[]
    www?: { value: string }[]
}

export interface ActivityData {
    access: Location[]
    address: Address
    categories: Category[]
    contacts: Contact[]
    distance: number
    id: string
    language: string
    position: Location
    resultType: string
    title: string
}

interface IconURL {
    enjoy: string
    drink: string
    eat: string
    sleep: string
    travel: string
    search: string
}

export default function Activity({activity_data, showAddJourney = true, createPoint = true}: {activity_data: ActivityData, showAddJourney?: boolean, createPoint?: boolean}) {
    const [showAddJourneyUseState, setShowAddJourney] = useState<boolean>(showAddJourney)
    const iconURL: IconURL = {
        enjoy: MarkerYellow,
        drink: MarkerPink,
        eat: MarkerGreen,
        sleep: MarkerBlue,
        travel: MarkerPurple,
        search: PinkYellow
    }

    const setView = () => {
        actions.useMap?.setView([activity_data.position.lat, activity_data.position.lng], 20)
    }

    const AddMarker = () => {
        if (AlreadyAdded()) { return }

        const marker = L.marker([activity_data.position.lat, activity_data.position.lng])
        marker.bindPopup(activity_data.title)
        marker.setIcon(L.icon({
            iconUrl: iconURL[actions.lastActivity as keyof IconURL],
            iconSize: [25, 41],
            iconAnchor: [12, 41],
            popupAnchor: [1, -34],
        }))
        marker.on('click', () => {
            actions.useMap?.setView([activity_data.position.lat, activity_data.position.lng], 20)
            
            // close the previous active activity
            const previous = document.querySelector('.activity.active') as HTMLElement
            if (previous) previous.classList.remove('active')

            // set the current activity as active
            const current = document.getElementById(activity_data.id)
            if (current) current.classList.add('active')
            
            const parent = document.querySelector('.explorerList') as HTMLElement
            if (parent && current) parent.scrollTo({top: current.offsetTop - parent.offsetTop, behavior: 'smooth'})
        })
        marker.on('mouseover', () => { marker.openPopup() })
        marker.on('mouseout', () => { marker.closePopup() })
        marker.options.title = "activity"
        marker.addTo(actions.useMap!)

        actions.markers.push({
            marker: marker,
            id: activity_data.id
        })
    }

    const AlreadyAdded = (): boolean => {
        return !!actions.markers.find(marker => marker.id === activity_data.id)
    }

    const FormatLink = (link: string): string => {
        if (link.startsWith("http://") || link.startsWith("https://")) return link
        return `http://${link}`
    }

    const AddToJourney = () => {
        journeyActions.addActivity(activity_data)
        
        const button = document.getElementById(`addToJourney_${activity_data.id}`) as HTMLButtonElement
        if (button) button.style.display = "none"
    }

    useEffect(() => {
        if (createPoint) AddMarker()
        if (showAddJourney && journeyActions.activityExist(activity_data)) setShowAddJourney(false)
    }, [])

    return (
        <div className="activity" id={activity_data.id}>
            {/* Ajouter image de l'event */}
            <div className="title">{activity_data.title}</div>
            <div className="categories">
                {
                    activity_data.categories?.map((category: Category, index: number) => {
                        return <div key={index} className="category">{category.name}</div>
                    })
                }
            </div>
            <div className="address">{activity_data.address.label}</div>
            <div className="links">
                {
                    activity_data?.contacts?.length > 0 && activity_data.contacts[0]["www"] ?
                        <span className="linksTitle"><u>Plus d'infos:</u></span>
                        : null
                }
                {
                    activity_data?.contacts?.length > 0 ?
                        activity_data.contacts[0]["www"]
                            ? activity_data.contacts[0]["www"].map((link: any, index: number) => {
                                return <a key={index} href={FormatLink(link.value)} target="_blank" rel="noreferrer"><FaLink /></a>
                            })
                            : null
                        : null
                }
            </div>
            <div className="actions">
                <button className="action" onClick={setView}><FaMapMarkerAlt /> Voir</button>
                <button className="action" id={`addToJourney_${activity_data.id}`}  style={{display: `${showAddJourneyUseState ? 'block' : 'none'}`}} onClick={AddToJourney}><FaBookmark /> Ajouter</button>
            </div>
        </div>
    )
}