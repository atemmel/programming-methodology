#ifndef MYPRINT_H
#define MYPRINT_H

#include "car.h"

#include <iostream>

struct MyPrint
{
	void operator()(const Car & car) const;
};

#endif
