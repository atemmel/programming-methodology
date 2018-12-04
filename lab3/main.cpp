#include "p_queue.h"

#include <iostream>
#include <string>
#include <random>


int main()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> dist(15, 30);

	p_queue<std::string, std::greater<>> queue;

	/*
	queue.push("Albin", 5);
	queue.push("James", 2);
	queue.push("Jens", 3);
	*/

	std::cout << queue.pop() << '\n' << dist(generator) << '\n';

	return 0;
}
