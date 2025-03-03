import '../scss/map.scss'
import 'leaflet/dist/leaflet.css'
import { MapContainer, TileLayer, useMap } from 'react-leaflet'
import { Map } from 'leaflet'
import { useState } from 'react'

export interface MarkerData {
    marker: L.Marker
    id: string
}

interface Actions {
    useMap: Map | null
    lastActivity: string
    lastCat: string
    markers: MarkerData[]
    setMarkers: (markers: MarkerData[]) => void
}

export const actions: Actions = {
    useMap: null,
    lastActivity: "",
    lastCat: "",
    markers: [],
    setMarkers: () => {}
}

function SetActions() {
    actions.useMap = useMap()
    return null
}

export default function MyMap() {
    const [markers, setMarkers] = useState<MarkerData[]>([])
    actions.setMarkers = setMarkers
    actions.markers = markers

    return (
        <div id="map">
            <div className='default-leaflet-infos'>
                <h3>Plus d'informations</h3>
                <span><i>(English only)</i> Ajoutez des événements à votre voyage pour obtenir les détails du trajet.</span>
            </div>
            <MapContainer center={[51.505, -0.09]} zoom={13} scrollWheelZoom={true} className="mapContainer">
                <TileLayer
                    attribution='&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
                    url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
                />
                <SetActions />
            </MapContainer>
        </div>
    )
}