#include "circle.h"

Circle::Circle(float _radius) 
: radius(_radius)
{

}

float Circle::getArea() const
{
	return Pi * radius * radius;
}
