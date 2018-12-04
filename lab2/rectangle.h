#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(float _width = 0.f, float _height = 0.f);

	float getArea() const;

	float width, height;
};

#endif
