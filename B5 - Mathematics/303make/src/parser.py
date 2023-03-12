from typing import Dict, List
from src.args import ParserReturn
from typing import List


def parser(makefile) -> ParserReturn:
    contents = []
    values = {}
    with open(makefile) as file:
        lines = file.readlines()
        if (len(lines) <= 1):
            exit(84)
        for line in lines:
            line = line.rstrip("\n")
            if (line == ""):
                continue
            contents.append(line)
            if line.find(":") == -1:
                continue
            title, content = line.split(":")
            dependencies = [dependencie for dependencie in content[1:].split(" ")]
            values[title] = dependencies
    values = add_missing_file(values)
    deep = format_matrix(values)
    return ParserReturn(values, deep, formatContent(contents))


def formatContent(content: List[str]) -> Dict:
    newContent = {}
    count_line = 0
    count_cc = 0

    for line in content:
        if ':' in line:
            count_line += 1
        else:
            count_cc += 1
    
    if count_line != count_cc:
        exit(84)

    try:
        for i in range(len(content)):
            if ':' in content[i]:
                newContent[content[i]] = content[i + 1]
    except:
        exit(84)

    return newContent

def add_missing_file(values: Dict) -> Dict:
    new_values = values.copy()
    for dependencies in values.values():
        for dependencie in dependencies:
            if not dependencie in values.keys():
                new_values[dependencie] = []
    return new_values


def format_matrix(values: Dict) -> Dict:
    memo = {}
    rec_tree(values, list(values.keys())[0], memo=memo)
    return memo


def rec_tree(values: Dict, current_key: str, memo: Dict = {}, queu: List[str] = []):
    if current_key not in memo.keys():
        memo[current_key] = []
    if queu:
        memo[current_key].append(queu[-1])

    dependencies = values[current_key]
    if not dependencies:
        return

    queu.append(current_key)
    for dependencie in dependencies:
        rec_tree(values, dependencie, memo, queu.copy())


def get_links(values: Dict) -> List[List[str]]:
    ordered_values = sorted(values.keys())
    links = []
    for value in ordered_values:
        get_dependencies(values, value, links, [])
    return links


def get_dependencies(
    values: Dict, value: str, links: List[List[str]], dependencies: List[str] = []
) -> None:
    dependencies.append(value)
    if not values[value]:
        links.append(dependencies)

    for dependencie in values[value]:
        get_dependencies(values, dependencie, links, dependencies.copy())
