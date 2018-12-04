#include "cylinder.h"

Cylinder::Cylinder(float _radius, float _height)
: base(_radius), height(_height)
{
}

float Cylinder::getArea() const
{
	return 2 * Circle::Pi * base.radius * height;
}

float Cylinder::getVolume() const
{
	return base.getArea() * height;
}
