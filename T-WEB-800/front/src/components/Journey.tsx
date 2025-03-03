import { useCallback, useEffect, useState } from "react"
import { FaEye } from "react-icons/fa"
import { FaTrashAlt } from "react-icons/fa"
import "../scss/journey.scss"
import { FaCopy } from "react-icons/fa"
import { toast } from "react-toastify"
import { journeyActions } from "./CurrentJourney"
import { myJourneysActions } from "./MyJourneys"

export interface SaveData {
    code: string,
    data: string,
    id: number,
    last_update: string,
    user: number,
}

interface SaveElement {
    id: number,
    name: string,
}

export default function Journey({ save }: { save: SaveData }) {
    const [nbSteps, setNbSteps] = useState<number>(0)
    const [data, setData] = useState<SaveElement[]>([])

    const OpenJourney = useCallback(() => {
        journeyActions.importJourney(save.code)
    }, [])

    const RemoveJourney = useCallback(() => {
        myJourneysActions.removeJourney(save.id)
    }, [])

    const CopyJourney = useCallback(() => {
        navigator.clipboard.writeText(save.code)
        toast.success("Code copié dans le presse-papier")
    }, [])

    const ConvertDate = (date: string) => {
        const dateObj = new Date(date);
        const day = dateObj.getDate().toString().padStart(2, '0');
        const month = (dateObj.getMonth() + 1).toString().padStart(2, '0');
        const year = dateObj.getFullYear();

        const hours = dateObj.getHours().toString().padStart(2, '0');
        const minutes = dateObj.getMinutes().toString().padStart(2, '0');
        const seconds = dateObj.getSeconds().toString().padStart(2, '0');

        return `${day}/${month}/${year} à ${hours}:${minutes}:${seconds}`
    }

    useEffect(() => {
        const data = atob(save.data)
        const datajson = JSON.parse(data)
        setData(datajson)
        setNbSteps(datajson.length)
    }, [save])

    return (
        <div className="journey" id={`save_${save.id}`}>
            <div className="title">
                <span>{save.code}</span>
                <button className="smallAction" onClick={CopyJourney}><FaCopy /></button>
            </div>
            <div className="categories">
                <div className="category">{ConvertDate(save.last_update)}</div>
                <div className="category">{nbSteps} étapes</div>
            </div>
            {
                nbSteps > 0
                ?   <div className="description">
                    { data.map((element: SaveElement, index: number) => {
                        return (
                            <div key={index} className="descriptionElement">
                                <span>{decodeURIComponent(element.name)}</span>
                            </div>
                        )
                    }) }
                    </div>
                : null
            }
            <div className="actions">
                <button className="action" onClick={OpenJourney}><FaEye /> Charger</button>
                <button className="action" onClick={RemoveJourney}><FaTrashAlt /> Supprimer</button>
            </div>
        </div>
    )
}