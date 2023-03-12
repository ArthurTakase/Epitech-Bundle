def getCommands(commands, fileContent, toFind):
    keys = list(fileContent.keys())

    for i in range(len(keys)):
        if fileContent[keys[i]] in commands:
            continue
        rule, currentTarget = keys[i].split(':')
        if toFind in currentTarget.split():
            commands.append(fileContent[keys[i]])
            getCommands(commands, fileContent, rule)

def searchCommands(fileContent, elements, toFind):
    commands = []
    
    getCommands(commands, fileContent, toFind)
    
    if toFind not in elements:
        return 84
    if len(commands) > 0:
        commands.sort()
        [print(command) for command in commands]
    else:
        print()
    return 0