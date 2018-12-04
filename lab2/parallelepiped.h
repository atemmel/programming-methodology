#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "rectangle.h"
#include "shape3d.h"

class Parallelepiped : public Shape3d
{
public:
	Parallelepiped(float _width = 0.f, 
			float _height = 0.f, float _depth = 0.f);

	float getArea() const;
	float getVolume() const;

	Rectangle side;
	float depth;
};

#endif
