#include <Tools/Curve.hpp>
#include <cmath>

/**
 * It returns the y-coordinate of a sine wave with a given amplitude and period at
 * a given x-coordinate
 *
 * @param amplitude The maximum height of the curve.
 * @param period The period of the curve.
 * @param x The x-coordinate of the point to be calculated.
 *
 * @return The amplitude of the sine wave multiplied by the period of the sine wave
 * multiplied by the x value.
 */
int Tools::curve(float amplitude, float period, int x) noexcept
{
    return amplitude * sin(period * x);
}