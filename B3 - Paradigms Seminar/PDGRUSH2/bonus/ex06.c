/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGRUSH2-theau.grasseau
** File description:
** ex06
*/

#include "../new.h"
#include "list.h"
#include "../int.h"
#include "../container.h"

int main()
{
  Object* l = new(List, Int, 5, new(Int, 1), new(Int, 1), new(Int, 1), new(Int, 1), new(Int, 1));

  // additem(l, new(Int, 1));
  // additem(&l, new(Int, 2));
  // additem(&l, new(Int, 3));
  // additem(&l, new(Int, 4));
  // additem(&l, new(Int, 5));
  // additem(&l, new(Int, 6));

  printf("%s\n", str(l));
  // delete(l);
  return 0;
}