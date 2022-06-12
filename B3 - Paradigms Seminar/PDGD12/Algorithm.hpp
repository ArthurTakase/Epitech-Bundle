/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-arthur.decaen
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b)
{
    return (a < b) ? b : a;
}

template <typename T>
T clamp(T value, T min, T max)
{
    if (max < value)
        return max;
    if (value < min)
        return min;
    return value;
}

#endif /* !ALGORITHM_HPP_ */
