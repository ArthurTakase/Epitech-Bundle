/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGRUSH2-theau.grasseau
** File description:
** new
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    va_list list;

    va_start(list, class);
    return va_new(class, &list);
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *object;

    if (class == NULL || ap == NULL)
        raise("Null Ptr");
    if ((object = malloc(class->__size__)) == NULL)
        raise("Malloc failed.");
    memcpy(object, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(object, ap);
    va_end(*ap);
    if (object == NULL)
        raise("Malloc failed.");
    return object;
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Null Ptr");
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}
