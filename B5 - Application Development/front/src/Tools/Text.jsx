import Container from './Container'

function Text({ text }) {
    
    if (text === undefined || text === null) { return <></> }
    
    return ( <Container  key="front_background" type={`biggerContainer fact`}>{text}</Container> )
}

export default Text