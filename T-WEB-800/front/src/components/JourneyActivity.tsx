import Activity, { ActivityData } from "./Activity"
import { journeyActions } from "./CurrentJourney"
import { FaTrashAlt } from "react-icons/fa";
import { FaArrowUp } from "react-icons/fa";
import { FaArrowDown } from "react-icons/fa";

export default function JourneyActivity({activity_data, index}: {activity_data: ActivityData, index: number}) {
    return (
        <div className="journeyActivity" data-id={activity_data.id} data-name={activity_data.title}>
            <div className="journeyActivityInfos">
                <p className="journeyActivityID">{index + 1}</p>
                <div className="journetActivityBtns">
                    <button className="journeyActivityUp" onClick={() => journeyActions.moveActivity(activity_data, -1)}><FaArrowUp /></button>
                    <button className="journeyActivityDown" onClick={() => journeyActions.moveActivity(activity_data, 1)}><FaArrowDown /></button>
                    <button className="journeyActivityRemove" onClick={() => journeyActions.removeActivity(activity_data)}><FaTrashAlt /></button>
                </div>
            </div>
            <div className="journeyActivityActivity">
                <Activity activity_data={activity_data} showAddJourney={false} createPoint={false} />
            </div>
        </div>
    )
}