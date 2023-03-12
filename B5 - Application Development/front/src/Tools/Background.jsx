import Container from './Container'

function Background({ childrens, url }) {
    
    if (url === null) { return <></> }
    
    return (
        <Container  key="front_background"
                    type={`biggerContainer ${url.includes("youtube") ? "video" : ""}`}>
            {
                url.includes("youtube") ||
                url.includes("vimeo") ||
                url.includes("dailymotion") ?
                <iframe width="100%"
                        height="100%"
                        src={url}
                        title="Video player"
                        frameBorder="0"
                        allowFullScreen>
                </iframe>
                : <img alt="Background from the user" src={url} />
            }
            {childrens}
        </Container>
    )
}

export default Background