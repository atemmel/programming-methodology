#include "p_queue.h"

#include <iostream>
#include <string>
#include <random>

struct Broker 
{
	std::string name;
	int price;
};

int main()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> dist(15, 30);

	struct CompBroker
	{
		bool operator()(const Broker & lhs, const Broker & rhs) const
		{
			return lhs.price > rhs.price;
		}
	};

	p_queue<Broker, CompBroker> buyers, sellers;

	constexpr int n = 7;

	for(int i = 0; i < n; i++)
	{
		buyers.push({"Erik Pendel", dist(generator)});
		buyers.push({"Jarl Wallenburg", dist(generator)});
		buyers.push({"Joakim von Anka", dist(generator)});
		sellers.push({"Erik Pendel", dist(generator)});
		sellers.push({"Jarl Wallenburg", dist(generator)});
		sellers.push({"Joakim von Anka", dist(generator)});
	}

	while(!buyers.empty() && !sellers.empty())
	{
		auto buyer = buyers.pop();
		auto seller = sellers.pop();

		if(buyer.price >= seller.price)
		{
			std::cout << buyer.name << " bought shares worth " << seller.price << " for the price of "
				<< buyer.price << " from " << seller.name << '\n';
		}
	}

	return 0;
}
