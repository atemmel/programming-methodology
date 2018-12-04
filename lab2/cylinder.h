#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"
#include "shape3d.h"

class Cylinder : public Shape3d
{
public:
	Cylinder(float _radius = 0.f, float _height = 0.f);

	float getArea() const;
	float getVolume() const;
	
	Circle base;
	float height;
};

#endif
