#!/bin/bash

#cut -d: -f 5 | grep " $1" | wc -l
grep -i -o " $1" | wc -l
