#include "parallelepiped.h"

Parallelepiped::Parallelepiped(float _width, float _height, float _depth)
: side(_width, _height), depth(_depth)
{
}

float Parallelepiped::getArea() const
{
	return 2 * (side.width * side.height + side.width * depth + side.height * depth);
}

float Parallelepiped::getVolume() const
{
	return side.getArea() * depth;
}
