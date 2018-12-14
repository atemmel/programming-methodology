#include "myprint.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <array>

struct GreaterThanOpel
{
	bool operator()(const Car & car) const
	{
		return car.name > "Opel";
	}
};

struct MyBinOp
{
	double operator()(double lhs, const Car & rhs) const
	{
		return lhs + rhs.velocity;
	}
};

struct MyUnOp
{
	double operator()(const Car & car) const
	{
		return car.velocity;
	}
};

struct MyFunc
{
	MyFunc(double _m) 
		: m(_m)
	{}

	double operator()(double in) const
	{
		return in - m;
	}

private:
	double m = 0;
};

int main()
{
	
	std::array<Car, 3> array;

	array[0] = {"BMW", 15.0};
	array[1] = {"Audi", 5.0};
	array[2] = {"Volkswagen", 10.0};

	std::vector<Car> cars(array.begin(), array.end());

	//1---------
	MyPrint myPrint;
	std::for_each(cars.begin(), cars.end(), myPrint);

	//2---------
	auto it = std::find_if(cars.begin(), cars.end(), GreaterThanOpel());
	
	if(it != cars.end()) myPrint(*it);

	//3---------
	it = std::adjacent_find(cars.begin(), cars.end());

	if(it != cars.end()) myPrint(*it);
	else std::cout << "No adjacent elements.\n";

	//4---------
	std::equal(array.begin(), array.end(), cars.begin()) ? 
		std::cout << "The ranges are equal.\n" :
		std::cout << "The ranges are not equal.\n";

	//5---------
	it = std::search(cars.begin(), cars.end(), array.begin() + 1, array.end());

	std::for_each(it, cars.end(), myPrint);

	//6---------
	auto mean = std::accumulate(cars.begin(), cars.end(), 0., [](double lhs, const Car & car)
	{
		MyBinOp myBinOp;
		return myBinOp(lhs, car);
	}) / cars.size();

	std::cout << "Mean velocity is: " << mean << " units.\n";

	//7---------
	std::vector<double> v2;

	std::transform(cars.begin(), cars.end(), std::back_inserter(v2), MyUnOp());

	//8---------
	
	MyFunc myFunc(mean);
	std::transform(v2.begin(), v2.end(), v2.begin(), myFunc);

	//9---------
	std::sort(v2.begin(), v2.end());
	for(auto d : v2)
	{
		std::cout << d << ' ';
	}

	std::cout << '\n';
}
