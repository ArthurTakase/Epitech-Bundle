function GenerateKey() {
    return (`${new Date().getTime() * Math.random()}`)
}

export default GenerateKey