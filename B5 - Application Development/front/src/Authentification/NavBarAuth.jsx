import React, { Component } from "react"
import { Link } from "react-router-dom"

import "../css/navbarAuth.css"

class ButtonNavBar extends Component {

    constructor(props) {
        super(props)
        this.state = {
            classPicked: this.props.classPicked,
            types: ["Login", "Register"],
            links: ["/login", "/register"],
            active: this.props.active,
        }
        this.switchClass = this.switchClass.bind(this);
    }

    switchClass(type) {
        this.setState({ active: type, classPicked: "activeButton" });
    }

    render() {
        return (
            <div className="navbarAuth">
                {
                    this.state.types.map((type, i) => (
                        <Link to={this.state.links[this.state.types.indexOf(type)]} key={i}>
                            <button
                                type="button"
                                className={`button ${this.state.active === type ? "active" : ""}`}
                                key={type}
                                onClick={() => this.switchClass(type)}
                            >
                                {type}
                            </button>
                        </Link>
                    ))
                }
            </div >
        )
    }
}

export default ButtonNavBar;