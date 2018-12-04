#include "roundedrectangle.h"
#include "parallelepiped.h"
#include "cylinder.h"

#include <iostream>
#include <vector>
#include <memory>

using ShapeVector = std::vector<std::shared_ptr<Shape> >;

float getData(const ShapeVector & shapes)
{
	float sum = 0.f;

	for(auto & shape : shapes) sum += shape->getArea();

	return sum;
}

int main()
{
	ShapeVector shapes;

	shapes.push_back(std::make_shared<Circle>(5.f));
	shapes.push_back(std::make_shared<Cylinder>(5.f, 2.f));
	shapes.push_back(std::make_shared<Parallelepiped>(3.f, 3.f, 3.f));
	shapes.push_back(std::make_shared<Rectangle>(4.f, 4.f));
	shapes.push_back(std::make_shared<RoundedRectangle>(4.f, 3.f, 1.f));

	std::cout << "Sum: " << getData(shapes) << '\n';

	return 0;
}
