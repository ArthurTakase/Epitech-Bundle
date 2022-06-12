/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *buff;

    if (this == NULL)
        raise("Null Ptr");
    if ((buff = malloc(50)) == NULL)
        raise("Error Malloc");
    sprintf(buff, "<Point (%d, %d)>", this->x, this->y);
    return buff;
}

static PointClass *Point_add(PointClass *first, PointClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Point, first->x + second->x,  first->y + second->y);
}

static PointClass *Point_sub(PointClass *first, PointClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Point, first->x - second->x,  first->y - second->y);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
