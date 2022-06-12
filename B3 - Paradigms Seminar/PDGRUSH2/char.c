/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGRUSH2-theau.grasseau
** File description:
** char
*/

#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char value;
    char *_str_;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->value = va_arg(*args, int);
    this->_str_ = NULL;
}

static void Char_dtor(CharClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    if (this->_str_)
        free(this->_str_);
}

static const char *Char_str(CharClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    if (this->_str_)
        free(this->_str_);
    if ((this->_str_ = malloc(50)) == NULL)
        raise("Error Malloc");
    sprintf(this->_str_, "<Char (%c)>", this->value);
    return this->_str_;
}

static CharClass *Char_add(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Char, first->value + second->value);
}

static CharClass *Char_sub(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Char, first->value - second->value);
}

static CharClass *Char_mul(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Char, first->value * second->value);
}

static CharClass *Char_div(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Char, first->value / second->value);
}

static bool Char_eq(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return first->value == second->value;
}

static bool Char_gt(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return first->value > second->value;
}

static bool Char_lt(CharClass *first, CharClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return first->value < second->value;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,  
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .value = 0,
    ._str_ = NULL
};

const Class *Char = (const Class *)&_description;
