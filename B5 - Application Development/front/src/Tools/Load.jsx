import '../css/colors.css'
import '../css/style.css'

import { AiOutlineLoading3Quarters } from 'react-icons/ai'

function Load() {
    return (
        <div className="loadZone">
            <AiOutlineLoading3Quarters className="load"/>
        </div>
    )
}

export default Load