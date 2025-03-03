import React, { useCallback } from 'react'
import '../scss/explorer.scss'
import { RefObject, useState } from 'react'
import axios from 'axios'
import Activity from './Activity'
import { toast } from 'react-toastify'
import { actions } from "./Map"
import { FaLocationCrosshairs } from "react-icons/fa6";
import { IoMdMore } from "react-icons/io";
import { ActivityData } from './Activity'
import CreatableSelect from 'react-select/creatable';
import Categories from '../json/categories.json'

type CityData = {
    lat: number
    lon: number
}

type CategoriesData = {
    value: string
    label: string
}

export default function Explorer() {
    const inputRef: RefObject<HTMLInputElement> = React.createRef()
    const activitiesRef: RefObject<HTMLDivElement> = React.createRef()
    const [activities, setActivities] = useState<ActivityData[]>([])
    const [advancedSearch, setAdvancedSearch] = useState<boolean>(false)
    const [selectedCategories, setSelectedCategories] = useState<CategoriesData>({ value: "", label: "" })

    const categories: CategoriesData[] = Categories.categories;

    async function getCityCoordinates(city: string): Promise<CityData> {
        const url = `http://localhost:4000/api/location?city=${encodeURIComponent(city)}`
        const response = await axios.get(url)

        if (response.data.data.length === 0) {
            throw new Error(`Aucune ville trouvée pour ${city}`)
        }

        const data = response.data.data[0]
        return {
            lat: parseFloat(data.lat),
            lon: parseFloat(data.lon),
        }
    }

    const creatableSelectChange = (newValue: any, _: any) => {
        setSelectedCategories(newValue)
        getActivities("search", null, newValue)
    }

    const getActivities = useCallback(async (type: string, coord: string | null = null, cat: CategoriesData = { value: "", label: "" }) => {
        let search = ""
        if (!inputRef.current?.value) {
            const input = document.getElementById('explorerInput') as HTMLInputElement
            search = input.value
            if (!search) return
        } else search = inputRef.current?.value

        let tempActivities = activities

        const pattern: RegExp = /^(-?\d+(\.\d+)?),\s*(-?\d+(\.\d+)?)$/
        const input: string = coord ?? (search || '')
        const match: RegExpMatchArray | null = input.match(pattern)
        let data: CityData = {
            lat: match ? parseFloat(match[1]) : 0,
            lon: match ? parseFloat(match[3]) : 0,
        }

        try { if (!match) data = await getCityCoordinates(input) }
        catch (error) {
            toast.error(`Aucune ville trouvée pour ${input}`)
            return
        }

        if (coord === null && (actions.lastActivity != type || cat.value !== actions.lastCat)) {
            actions.markers.forEach(marker => {
                marker.marker.remove()
            })
            actions.setMarkers([])
            tempActivities = []
        }

        let url = ""
        if ((advancedSearch || type === "search") && (cat.value !== "" || selectedCategories.value !== "")) {
            const realCat = cat.value !== "" ? cat : selectedCategories
            url = `http://localhost:4000/api/here/browse?lat=${data.lat}&lon=${data.lon}&cat=${realCat.value}`
        } else if (type !== "search") url = `http://localhost:4000/api/${type}?lat=${data.lat}&lon=${data.lon}`

        if (url === "") {
            setActivities([])
            toast.error(`${advancedSearch}, ${type}, ${cat.value}, ${selectedCategories.value}`)
            return
        }

        actions.useMap?.setView([data.lat, data.lon], 16)
        actions.lastActivity = type
        actions.lastCat = cat.value

        try {
            const response = await axios.post(url)
            const newActivities = response.data.data.items.filter((activity: ActivityData) => {
                return !tempActivities.find((act: ActivityData) => act.id === activity.id)
            })
    
            setActivities([...tempActivities, ...newActivities])
        } catch (error) { toast.error(`Aucune activité trouvée pour ${input}`) }
    }, [activities, setActivities])

    return (
    <>
        <div className='explorerInput'>
            <input ref={inputRef} placeholder='Où voulez-vous voyager ?' id="explorerInput"></input>
            <button className='advancedSearch' onClick={() => setAdvancedSearch(!advancedSearch)}><IoMdMore /></button>
            {
                !advancedSearch
                ?
                    <div className='explorerTypes'>
                        <button onClick={() => getActivities("enjoy")}>🥳 Enjoy</button>
                        <button onClick={() => getActivities("drink")}>🍹 Drink</button>
                        <button onClick={() => getActivities("eat")}>🍽️ Eat</button>
                        <button onClick={() => getActivities("sleep")}>💤 Sleep</button>
                        <button onClick={() => getActivities("travel")}>🚌 Travel</button>
                    </div>
                :
                    <div className='explorerSearch'>
                        <CreatableSelect
                        closeMenuOnSelect={true}
                        options={categories}
                        placeholder="Catégories"
                        onChange={creatableSelectChange}
                        />
                    </div>
            }
        </div>
        <div className='explorerList' ref={activitiesRef}>
            {activities.length == 0
                ? <>~ Choisissez une destination et une catégorie ~</>
                : activities.map((activity: ActivityData) => <Activity key={activity.id} activity_data={activity}/>)}
        </div>
        {
            actions.lastActivity
            ?   <div className='reloadExplorer'>
                    <button onClick={() => {
                        if (!actions.useMap || !actions.lastActivity) return
                        const center = actions.useMap.getCenter()
                        getActivities(actions.lastActivity, `${center.lat}, ${center.lng}`)
                    }}><FaLocationCrosshairs /></button>
                </div>
            : null
        }
    </>
    )
}