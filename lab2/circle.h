#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
	Circle(float _radius = 0.f);

	constexpr static float Pi = 3.14159;

	float getArea() const;

	float radius;
};

#endif
