/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGRUSH2-theau.grasseau
** File description:
** char
*/

#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int value;
    char *_str_;
}   IntClass;


static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->value = va_arg(*args, int);
    this->_str_ = NULL;
}

static void Int_dtor(IntClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    if (this->_str_)
        free(this->_str_);
}

static const char *Int_str(IntClass *this)
{
    if (this->_str_)
        free(this->_str_);
    if ((this->_str_ = malloc(50)) == NULL)
        raise("Error Malloc");
    sprintf(this->_str_, "<Int (%d)>", this->value);
    return this->_str_;
}

static Object *Int_add(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return new(Int, this->value + other->value);
}

static Object *Int_sub(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return new(Int, this->value - other->value);
}

static Object *Int_mul(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return new(Int, this->value * other->value);
}

static Object *Int_div(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    if (other->value == 0)
        raise("Floating Point.");
    return new(Int, this->value / other->value);
}

static bool Int_eq(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return this->value == other->value ? true : false;
}

static bool Int_gt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return this->value > other->value ? true : false;
}

static bool Int_lt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null Ptr");
    return this->value < other->value ? true : false;
}


static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .value = 0,
    ._str_ = NULL
};

const Class *Int = (const Class *)&_description;
