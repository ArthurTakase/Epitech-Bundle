import '../scss/leftPanel.scss'
import Explorer from './Explorer'
import MyJourneys from './MyJourneys'
import CurrentJourney from './CurrentJourney'
import React, { useCallback } from 'react'

interface LeftPanelActions {
    ToggleMyJourneys: (state: boolean) => void;
}

export const leftPanelActions: LeftPanelActions = {
    ToggleMyJourneys: (_: boolean) => {},
}

export default function LeftPanel() {
    const [myJourneys, setMyJourneys] = React.useState<boolean>(false)
    const [tab, setTab] = React.useState<string>('explorer')

    const ToggleMyJourneys = useCallback((show: boolean) => {
        setMyJourneys(show)
        setTab('explorer')
    }, [tab])

    React.useEffect(() => {
        if (localStorage.getItem('token')) ToggleMyJourneys(true)
        leftPanelActions.ToggleMyJourneys = ToggleMyJourneys
    }, [])

    return (
        <div id="leftPanel">
            <div className="LeftZoneHeader">
                <button onClick={() => setTab("explorer")} className={tab === 'explorer' ? 'active' : ''}>Explorer</button>
                <button onClick={() => setTab("currentJourney")} className={tab === 'currentJourney' ? 'active' : ''}>Voyage actuel</button>
                {myJourneys
                    ? <button onClick={() => setTab("myJourneys")} className={tab === 'myJourneys' ? 'active' : ''}>Mes Voyages</button>
                    : null
                }
            </div>
            <div className='tab'>
                <div className={`tabElement ${tab === 'explorer' ? 'active' : ''}`}><Explorer /></div>
                <div className={`tabElement ${tab === 'currentJourney' ? 'active' : ''}`}><CurrentJourney /></div>
                {myJourneys
                    ? <div className={`tabElement ${tab === 'myJourneys' ? 'active' : ''}`}><MyJourneys /></div>
                    : null
                }
            </div>
        </div>
    )
}