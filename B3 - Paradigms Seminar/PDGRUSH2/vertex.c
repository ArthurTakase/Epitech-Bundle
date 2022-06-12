/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGRUSH2-theau.grasseau
** File description:
** vertex
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;


static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    (void)this;
}

static const char *Vertex_str(VertexClass *this)
{
    char *buff;

    if (this == NULL)
        raise("Null Ptr");
    if ((buff = malloc(50)) == NULL)
        raise("Error Malloc");
    sprintf(buff, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return buff;
}

static const Object *Vertex_add(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return new(Vertex, this->x + other->x, this->y + other->y,
                this->z + other->z);
}

static const Object *Vertex_sub(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return new(Vertex, this->x - other->x, this->y - other->y,
                this->z - other->z);
}


static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
