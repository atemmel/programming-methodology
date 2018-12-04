#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
	virtual ~Shape() = default;

	std::string getColour() const;

	void setColour(const std::string & colour);

	virtual float getArea() const = 0;

private:
	std::string m_colour;
};

#endif
