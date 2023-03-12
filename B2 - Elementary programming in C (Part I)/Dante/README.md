# Dante

## Note

| MyEpitech | Norme |
|--|--|
| 60% | 1 minor | 11.1

## DESCRIPTION

This program can generate and solve mazes.

You can generate a perfect maze or not. A perfect maze has 1 and only one solution.

And you can solve mazes, you will always have the shortest solution.

## HOW TO USE

To generate a maze type `./generator/generator [WIDTH] [HEIGHT] (perfect)`

- WIDTH -> choose the width of your maze (at least 1)
- HEIGHT -> choose the height of your maze (at least 1)
- perfect -> It is an optional argument, if you want one and only one solution

And to solve your maze type `./solver/solver [MAZE]`

- MAZE -> the maze you want to solve

## EXAMPLE

```txt
./generator/generator 20 10 perfect

*X***X*************X
*X*X*X*XXXXXXX*XXXXX
*X*X*X*X*****X*****X
*X*XXX*X*XXXXX*XXX*X
*X*******X*****X***X
*XXXXXXX*X*XXXXX*XXX
*X*****X*X*X*****X*X
*X*X*X*XXX*X*XXXXX*X
***X*X*****X********
XXXXXXXXXXXXXXXXXXX*

./solver/solver 20x10_maze

oX***X*************X
oX*X*X*XXXXXXX*XXXXX
oX*X*X*X*****XoooooX
oX*XXX*X*XXXXXoXXXoX
oX*******XoooooXoooX
oXXXXXXX*XoXXXXXoXXX
oXoooooX*XoXoooooX*X
oXoX*XoXXXoXoXXXXX*X
oooX*XoooooXoooooooo
XXXXXXXXXXXXXXXXXXXo
```
