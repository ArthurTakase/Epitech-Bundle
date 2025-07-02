import os
import random
import re
from pathlib import Path

BASE_DIR = Path(__file__).parent
VARIANT_COUNT = 5

def read_map(filepath):
    with open(filepath, "r") as f:
        return [list(line.rstrip('\n')) for line in f]

def write_map(map_data, filepath):
    with open(filepath, "w") as f:
        for line in map_data:
            f.write("".join(line) + "\n")

def is_cell(char):
    return char in (" ", ":", "|", "R", "G", "Y", "B")

def generate_variant(original_map):
    variant = [row.copy() for row in original_map]
    rows = len(variant)
    cols = len(variant[0])

    # Zones internes modifiables (pas les bords)
    inner_cells = [
        (r, c)
        for r in range(1, rows - 1)
        for c in range(1, cols - 1)
    ]

    # On choisit un nombre de changements aléatoire
    num_changes = random.randint(5, 20)
    selected_cells = random.sample(inner_cells, k=min(num_changes, len(inner_cells)))

    for r, c in selected_cells:
        current = variant[r][c]
        if current in [":", "|"]:
            # 50% de chance de supprimer un mur
            variant[r][c] = " " if random.random() < 0.5 else current
        elif current == " ":
            # 30% de chance de créer un nouveau mur
            if random.random() < 0.3:
                variant[r][c] = random.choice([":", "|"])

    # Déplacement des points R, G, Y, B
    locs = ["R", "G", "Y", "B"]
    empty = [
        (r, c)
        for r in range(1, rows - 1)
        for c in range(1, cols - 1)
        if variant[r][c] == " "
    ]
    random.shuffle(empty)

    for loc in locs:
        # Supprime ancien
        for r in range(rows):
            for c in range(cols):
                if variant[r][c] == loc:
                    variant[r][c] = " "

        # Place nouveau
        if empty:
            r, c = empty.pop()
            variant[r][c] = loc

    return variant


def main():
    # Supprimer tous les fichiers *_v*.map
    for variant_file in BASE_DIR.glob("*_v*.map"):
        variant_file.unlink()
        print(f"🗑️ Supprimé : {variant_file.name}")

    map_files = sorted(BASE_DIR.glob("*x*.map"))

    for map_file in map_files:
        if "_v" in map_file.stem:
            continue  # Ignore les variantes déjà supprimées

        original_map = read_map(map_file)
        basename = map_file.stem

        for i in range(1, VARIANT_COUNT + 1):
            variant = generate_variant(original_map)
            new_name = BASE_DIR / f"{basename}_v{i}.map"
            write_map(variant, new_name)
            print(f"✅ {new_name.name} généré.")

if __name__ == "__main__":
    main()
