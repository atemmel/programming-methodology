#include "rectangle.h"

Rectangle::Rectangle(float _width, float _height)
: width(_width), height(_height)
{
}

float Rectangle::getArea() const
{
	return width * height;
}
