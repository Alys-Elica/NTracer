#include "ntcolor.h"

NTColor::NTColor(double r, double g, double b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

NTColor::NTColor() {
    NTColor(0.0, 0.0, 0.0);
}

NTColor operator*(const NTColor &col1, const NTColor &col2)
{
    return NTColor(col1.r * col2.r,
                   col1.g * col2.g,
                   col1.b * col2.b);
}

NTColor operator*(const NTColor &col, const double multiple)
{
    return NTColor(col.r * multiple,
                   col.g * multiple,
                   col.b * multiple);
}

void operator*=(NTColor &col, const NTColor &col2)
{
    col = col * col2;
}

void operator*=(NTColor &col, const double multiple)
{
    col = col * multiple;
}

NTColor operator+(const NTColor &col1, const NTColor &col2)
{
    return NTColor(col1.r + col2.r,
                   col1.g + col2.g,
                   col1.b + col2.b);
}

void operator+=(NTColor &col1, const NTColor &col2)
{
    col1.r += col2.r;
    col1.g += col2.g;
    col1.b += col2.b;
}

NTColor operator/(const NTColor &c1, double multiple)
{
    return NTColor(c1.r / multiple, c1.g / multiple, c1.b / multiple);
}

void operator/=(NTColor &c1, double multiple)
{
    c1.r /= multiple;
    c1.g /= multiple;
    c1.b /= multiple;
}
