#!/bin/bash

grep "theo1\|steven1\|arnaud1\|pierre-jean" | sed 's/theo1/Wile E. Coyote/g; s/steven1/Daffy Duck/g; s/arnaud1/Porky Pig/g; s/pierre-jean/Marvin the Martian/g'
