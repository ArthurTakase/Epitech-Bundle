import { AiOutlineCheck } from 'react-icons/ai'
import { useState, useEffect } from 'react'

import AXIOS from "../Tools/Client.jsx"
import Load from '../Tools/Load'
import { Error, SetNotif } from '../Tools/Notif'

function EditContainer({ widget, json }) {
    const [actionsMore, setActionsMore] = useState(<div className="row-2 border"><div>Action Option</div></div>)
    const [reactionsMore, setReactionsMore] = useState(<div className="row-2 border"><div>Reaction Option</div></div>)
    const [location, setLocation] = useState(<></>)

    function submit() {
        const token = "Bearer " + localStorage.getItem("token")
        const url = localStorage.getItem("url") + "/widgets/" + widget.id

        widget.name = document.getElementById("name").value
        widget.action.name = document.getElementById("actionsList").value
        widget.reaction.name = document.getElementById("reactionsList").value
        var tempActionID = widget.action.options.action_id
        var tempReactionID = widget.reaction.options.reaction_id
        widget.action.options = { "action_id": tempActionID }
        widget.reaction.options = { "reaction_id": tempReactionID }

        try {
            var actionOptions = document.getElementById("inputAction")
            for (var i = 1; i < actionOptions.children.length; i++) {
                if (actionOptions.children[i].value !== "")
                    widget.action.options[actionOptions.children[i].placeholder] = actionOptions.children[i].value
            }
        } catch (err) {}

        try {
            var reactionOptions = document.getElementById("inputReaction")
            for (var j = 1; j < reactionOptions.children.length; j++) {
                if (reactionOptions.children[j].value !== "")
                    widget.reaction.options[reactionOptions.children[j].placeholder] = reactionOptions.children[j].value
            }
        } catch (err) {}

        AXIOS.patch(url, {"widget" : widget}, { headers: { Authorization: token,} })
            .then(res => { window.location.reload() })
            .catch(res => { Error({"res": res}) })
    }

    /* A function that is called when the user selects an action. It will then display the options for
    the action. */
    function moreInputAction() {
        setLocation(<></>)
        var data = document.getElementById("actionsList").value;

        json.server.services.forEach(element => {
            element.actions.forEach(elem => {
                if (elem.name === data) {
                    if (Object.keys(elem.options).length === 0) { setActionsMore(<div></div>) }
                    else {
                        setActionsMore(<div id="inputAction" className="row-2 border"><div>Action Option</div>{
                            Object.keys(elem.options).map((e) => {
                                if (elem.options[e] === "location") { Location() }
                                return <input type={elem.options[e]} placeholder={e} key={e} defaultValue={
                                widget.action.options[e] ? widget.action.options[e] : ""
                            }></input> })
                        }</div>)
                    }
                    return
                }
            })
        })
    }

    /* A function that is called when the user selects an action. It will then display the options for
    the action. */
    function moreInputReaction() {
        var data = document.getElementById("reactionsList").value;
        json.server.services.forEach(element => {
            element.reactions.forEach(elem => {
                if (elem.name === data) {
                    if (Object.keys(elem.options).length === 0) { setReactionsMore(<div></div>) }
                    else {
                        setReactionsMore(<div id="inputReaction" className="row-2 border"><div>Reaction Option</div>{
                            Object.keys(elem.options).map((e) => {
                                return <input type={elem.options[e]} placeholder={e} key={e} defaultValue={
                                    widget.reaction.name === elem.name ? widget.reaction.options[e] : ""
                                }></input>
                            })
                        }</div>)
                    }
                    return
                }
            })
        })
    }

    function Location() {
        if (navigator.geolocation) {
            navigator.geolocation.getCurrentPosition((position) => {
                setLocation(
                    <div className="row-2 border red">
                        <div>📍 (click to copy)</div>
                        <div className="row-2-text" onClick={() => {
                            navigator.clipboard.writeText(position.coords.latitude)
                            SetNotif({ "title": "Infos", "body": "Latitude copied to clipboard" })
                        }}>{position.coords.latitude} </div>
                        <div className="row-2-text" onClick={() => {
                            navigator.clipboard.writeText(position.coords.longitude)
                            SetNotif({ "title": "Infos", "body": "Longitude copied to clipboard" })
                        }}>{position.coords.longitude}</div>
                    </div>
                )
            });
        } else { 
            setLocation(
                <div className="row-2 border">
                    <div>📍</div>
                    <div>Geolocation is not supported by this browser.</div>
                </div>
            )
        }
    }

    useEffect(() => {
        moreInputAction()
        moreInputReaction()
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [])

    return (
        <>
            <div className="row-2 border">
                <div>Edit Widget n°{widget.id}</div>
                <input type="text" id="name" className="requiered" placeholder="Widget Name" defaultValue={widget.name}/>
            </div>
            <div className="row-2 border">
                <div>Actions/Reactions</div>
                <select name="reactionsList" id="actionsList" className="requiered" onChange={moreInputAction} defaultValue={widget.action.name}>{
                    json.server.services.map((elem) => {
                        var act = elem.actions.map((i) => { return (<option value={i.name} key={i.name}>{i.description}</option>) })
                        return (act)
                    })
                }</select>
                <select name="actionsList" id="reactionsList" className="requiered" onChange={moreInputReaction} defaultValue={widget.reaction.name}>{
                    json.server.services.map((elem) => {
                        var reac = elem.reactions.map((i) => { return (<option value={i.name} key={i.name}>{i.description}</option>) })
                        return (reac)
                    })
                }</select>
            </div>
            {location}
            {actionsMore}
            {reactionsMore}
            <button onClick={submit} className="btnBig cornerBtn"><AiOutlineCheck /></button>
        </>
    );
}

export default function Edit({ widget }) {
    const [elementE, setElementE] = useState(<Load/>)

    useEffect(() => {
        AXIOS.get(localStorage.getItem('url') + '/about.json')
            .then(function (res) { setElementE(<EditContainer json={res.data} widget={widget}/>) })
            .catch(function (err) { Error({"res": err}) });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    return ( <>{elementE}</> )
}