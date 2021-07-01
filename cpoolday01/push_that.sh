#!/bin/bash

# Cette partie sert uniquement si vous voulez mettre un message de commit
# ------
if expr $# = 0; then
    varmsg="update"
else
    varmsg="$1"
fi
# ------

./mr_clean

echo "CLEAN !"

git add .
git commit -m "$varmsg" 
git push -u origin master
