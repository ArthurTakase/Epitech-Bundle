import random
import os
from copy import deepcopy
import argparse
from pathlib import Path

parser = argparse.ArgumentParser(description="Génère des variantes de carte Taxi")
parser.add_argument("map_file", nargs="?", default="5x5_empty.map", help="Carte de base")
parser.add_argument("-n", "--num", type=int, default=10, help="Nombre de variantes")
parser.add_argument("--wall-prob", type=float, default=0.25, help="Probabilité de placer un mur vertical")
args = parser.parse_args()

N_VARIANTS = args.num
WALL_PROB = args.wall_prob
MAP_FILE = args.map_file
OUTPUT_DIR = Path(MAP_FILE).parent
OUTPUT_PREFIX = f"{Path(MAP_FILE).stem}_var"

# Positions des lettres à placer
LETTERS = ["R", "G", "B", "Y"]

def read_map(filepath):
    with open(filepath, "r") as f:
        return [list(line.rstrip("\n")) for line in f]

def write_map(map_data, filepath):
    with open(filepath, "w") as f:
        for line in map_data:
            f.write("".join(line) + "\n")

def is_case(row, col, map_data):
    return map_data[row][col] == " "

def get_case_coords(map_data):
    coords = []
    for row in range(1, len(map_data)-1):
        for col in range(1, len(map_data[0])-1, 2):
            if is_case(row, col, map_data):
                coords.append((row, col))
    return coords

def letter_positions(map_data):
    positions = {}
    for row in range(1, len(map_data) - 1):
        for col in range(1, len(map_data[0]) - 1):
            char = map_data[row][col]
            if char in LETTERS:
                positions[char] = (row - 1, col // 2)
    return positions

def neighbors(pos, map_data):
    r, c = pos
    rows = len(map_data) - 2
    cols = (len(map_data[0]) - 1) // 2
    neigh = []
    if r > 0:
        neigh.append((r - 1, c))
    if r < rows - 1:
        neigh.append((r + 1, c))
    if c < cols - 1 and map_data[1 + r][2 * c + 2] == ":":
        neigh.append((r, c + 1))
    if c > 0 and map_data[1 + r][2 * c] == ":":
        neigh.append((r, c - 1))
    return neigh

def is_solvable(map_data):
    letters = letter_positions(map_data)
    if len(letters) < len(LETTERS):
        return False
    start = next(iter(letters.values()))
    visited = {start}
    queue = [start]
    while queue:
        pos = queue.pop(0)
        for nb in neighbors(pos, map_data):
            if nb not in visited:
                visited.add(nb)
                queue.append(nb)
    return all(pos in visited for pos in letters.values())

def has_all_letters_once(map_data):
    counts = {letter: 0 for letter in LETTERS}
    for row in map_data:
        for char in row:
            if char in counts:
                counts[char] += 1
    return all(counts[l] == 1 for l in LETTERS)

def generate_variant(base_map):
    map_data = deepcopy(base_map)

    # Nettoie les anciennes lettres
    for r in range(1, len(map_data) - 1):
        for c in range(1, len(map_data[0]) - 1):
            if map_data[r][c] in LETTERS:
                map_data[r][c] = " "

    # Ajout de murs aléatoires (uniquement "|" entre deux cases)
    for row in range(1, len(map_data)-1):
        for col in range(2, len(map_data[0])-2, 2):  # uniquement les colonnes qui peuvent avoir un "|"
            if map_data[row][col] == ":" and random.random() < WALL_PROB:
                map_data[row][col] = "|"

    # Placement des lettres RGBY dans des cases libres
    available_coords = get_case_coords(map_data)
    random.shuffle(available_coords)
    for letter in LETTERS:
        if not available_coords:
            break
        r, c = available_coords.pop()
        map_data[r][c] = letter

    return map_data

def main():
    base_map = read_map(MAP_FILE)
    i = 0
    attempts = 0
    while i < N_VARIANTS:
        variant = generate_variant(base_map)
        attempts += 1
        if not is_solvable(variant) or not has_all_letters_once(variant):
            continue
        output_path = OUTPUT_DIR / f"{OUTPUT_PREFIX}{i}.map"
        write_map(variant, output_path)
        print(f"✅ Variante sauvegardée : {output_path} ✔️")
        i += 1

if __name__ == "__main__":
    main()