#ifndef CAR_H
#define CAR_H

#include <string>

struct Car
{
	bool operator==(const Car & lhs);

	std::string name;
	double velocity = 0;
};

#endif
