#include "roundedrectangle.h"

RoundedRectangle::RoundedRectangle(float _width, float _height, float _radius)
: Rectangle(_width , _height), corner(_radius)
{
}

float RoundedRectangle::getArea() const
{
	return Rectangle::getArea()  - corner.radius * corner.radius * (4 - Circle::Pi);
}
