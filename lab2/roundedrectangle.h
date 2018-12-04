#ifndef ROUNDEDRECTANLGE_H
#define ROUNDEDRECTANGLE_H

#include "rectangle.h"
#include "circle.h"

class RoundedRectangle : public Rectangle
{
public:
	RoundedRectangle(float _width = 0.f, float _height = 0.f, float _radius = 0.f);

	float getArea() const override;

	Circle corner;
};

#endif
