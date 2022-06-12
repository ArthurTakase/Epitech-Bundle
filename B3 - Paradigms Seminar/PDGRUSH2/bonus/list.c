/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "../raise.h"
#include "list.h"
#include "../new.h"
#include "../container.h"

typedef struct node_s
{
    Container base;
    Class *_type;
    size_t _index;
    struct node_s *_next;
    Class *_value;
}   ListClass;

struct node_s *new_node(Class *elem)
{
    struct node_s *node = malloc(sizeof(struct node_s));

    if (!node)
        raise("Malloc failed.");
    node->_value = elem;
    node->_index = 0;
    node->_next = NULL;
    return (node);
}

static void List_additem(ListClass **this, size_t position, Class *value)
{
    struct node_s *node = new_node(value);
    ListClass *tmp = *this;
    unsigned int i = 0;

    if (!node)
        return;
    while (i != position) {
        tmp = tmp->_next;
        if (tmp == NULL)
            raise("Position out of bounds.");
        i++;
    }
    tmp->_next = node;
    node->_index = i;
    return;
}

static void List_ctor(ListClass *this, va_list *args)
{
    this->_type = va_arg(*args, Class *);
    int nb_elem = va_arg(*args, int);
    printf("type = %s\n", str(this->_type));
    while (nb_elem >= 0) {
        nb_elem--;
        List_additem(&this, 0, va_arg(*args, Class *));
        printf("List = %s\n", (char *)this->_value);
    }
}

static void List_dtor(ListClass **this)
{
    ListClass *tmp = *this;

    while ((*this) != NULL) {
        tmp = (*this)->_next;
        free((*this));
        *this = tmp;
    }
}

static size_t List_len(ListClass *this)
{
    size_t inc = 0;
    ListClass *tmp = this;
    
    while (tmp->_next) {
        if (!tmp)
            raise("Position out of bounds.");
        tmp = tmp->_next;
        inc++;
    }
    return (inc);
}

static Object *List_begin(ListClass *this)
{
    return this;
}

static Object *List_end(ListClass **this)
{
    ListClass *tmp = *this;
    
    while (tmp->_next) {
        tmp = tmp->_next;
    }
    return tmp;
}

static Object *List_getitem(ListClass **this, size_t pos)
{
    unsigned int inc = 0;
    ListClass *tmp = *this;
    
    while (inc !=  pos) {
        if (!tmp)
            raise("Position out of bounds.");
        tmp = tmp->_next;
        inc++;
    }
    return (tmp->_value);
}

static char *List_str(ListClass *this)
{
    char *buff = malloc(sizeof(char) * 100);

    if (!this)
        return "";
    sprintf(buff, "%s ->", str(this->_value));
    strcat(buff, List_str(this->_next));
    return (buff);
}

static const ListClass _descr = {
    {
        {
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = (to_string_t)&List_str,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        // .__setitem__ = (setitem_t)&List_setitem,
        .__additem__ = (additem_t)&List_additem,
    },
    ._type = NULL,
    ._index = 0,
    ._next = NULL
};

const Class *List = (const Class *)&_descr;
