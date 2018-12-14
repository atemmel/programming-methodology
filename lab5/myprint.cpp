#include "myprint.h"

void MyPrint::operator()(const Car & car) const
{
	std::cout << car.name << ", " << car.velocity << '\n';
}
