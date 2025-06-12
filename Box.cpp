#include "Box.hpp"
Box::Box(float l, float w, float h)
{
    length = l;
    width = w;
    height = h;
}

float Box::Size()
{
    return length * width * height;
}