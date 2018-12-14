#include "car.h"

bool Car::operator==(const Car & lhs)
{
	return name == lhs.name;
}
