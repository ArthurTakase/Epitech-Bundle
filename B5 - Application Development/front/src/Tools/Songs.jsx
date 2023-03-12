import Container from "./Container"
import GenerateKey from '../Tools/Key'

import "../css/shelf.css"

function ShelfItem({ redirect, img, title, artist }) {
    return (
        <a className="shelfItem" href={redirect} target="_blank" rel="noreferrer">
            <img src={img} alt="Album cover" />
            <div className="shelfItemOverlay">{title}<br/>{artist}</div>
        </a>
    )
}

export function AlbumsShelf( {albums} ) {
    if (albums === null || albums["albums"] === undefined) { return <></> }

    return (
        <Container type="shelf">
            <div className="shelfTitle"> (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ 🎶 🎹 🎶</div>
            <div className="shelfContent">
            {
                albums["albums"].map((album) => {
                    return ( <ShelfItem key={GenerateKey()} redirect={album["url"]} img={album["image"]} title={album["title"]} artist={album["artist"]} /> )
                })
            }
            </div>
        </Container>
    )
}