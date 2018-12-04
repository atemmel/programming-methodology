#ifndef SHAPE3D
#define SHAPE3D

#include "shape.h"

class Shape3d : public Shape
{
public:
	virtual float getVolume() const = 0;

};

#endif
