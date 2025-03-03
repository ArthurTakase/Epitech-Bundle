import axios from 'axios';
import { useCallback, useEffect, useState } from 'react';
import Journey, { SaveData } from './Journey';
import '../scss/journey.scss'
import { toast } from 'react-toastify';

interface MyJourneysActions {
    GetSaves: () => void,
    removeJourney: (id: number) => void,
}

export const myJourneysActions: MyJourneysActions = {
    GetSaves: () => {},
    removeJourney: (_: number) => {},
}

export default function MyJourneys()
{
    const [saves, setSaves] = useState<SaveData[]>([])

    const GetSaves = useCallback(() => {
        const header = { "Authorization": `Bearer ${localStorage.getItem('token')}` }
        axios.get(`http://localhost:4000/api/saves/user/${localStorage.getItem('id')}`, { headers: header })
        .then(res => {
            setSaves(res.data.data)
        })
        .catch(err => {
            console.error(err)
            toast.error("Erreur lors de la récupération des voyages")
        })
    }, [])

    const RemoveJourney = useCallback((id: number) => {
        const header = { "Authorization": `Bearer ${localStorage.getItem('token')}` }
        axios.delete(`http://localhost:4000/api/saves/${id}`, { headers: header })
        .then(() => {
            toast.success("Voyage supprimé")
            GetSaves()
        })
        .catch(() => {
            toast.error("Erreur lors de la suppression du voyage")
        })
    }, [saves])

    useEffect(() => {
        GetSaves()
        myJourneysActions.GetSaves = GetSaves
        myJourneysActions.removeJourney = RemoveJourney
    }, [])

    return (
        <>
            <div className="journeysList">
            { saves.length === 0
                ? <>~ N'hésitez pas à sauvegarder vos voyages pour les retrouver ici ~</>
                : saves.map((save) => ( <Journey key={save.id} save={save} /> ))
            }
        </div>
        </>
    )
}