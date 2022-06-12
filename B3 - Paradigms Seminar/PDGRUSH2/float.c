/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGRUSH2-theau.grasseau
** File description:
** float
*/

#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float value;
    char *_str_;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->value = va_arg(*args, double);
    this->_str_ = NULL;
}

static void Float_dtor(FloatClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    if (this->_str_)
        free(this->_str_);
    (void)this;
}

static const char *Float_str(FloatClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    if (this->_str_)
        free(this->_str_);
    if ((this->_str_ = malloc(50)) == NULL)
        raise("Error Malloc");
    sprintf(this->_str_, "<Float (%f)>", this->value);
    return this->_str_;
}

static FloatClass *Float_add(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Float, first->value + second->value);
}

static FloatClass *Float_sub(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Float, first->value - second->value);
}

static FloatClass *Float_mul(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return new(Float, first->value * second->value);
}

static FloatClass *Float_div(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    if (first->value == 0)
        raise("Floating Point.");
    return new(Float, first->value / second->value);
}

static bool Float_eq(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return first->value == second->value;
}

static bool Float_gt(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return first->value > second->value;
}

static bool Float_lt(FloatClass *first, FloatClass *second)
{
    if (first == NULL || second == NULL)
        raise("Null Ptr");
    return first->value < second->value;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .value = 0.0,
    ._str_ = NULL
};

const Class *Float = (const Class *)&_description;
