#include "int_sorted.h"

#include <iostream>
#include <random>

void f(int_buffer buf)
{
	int val = 1;

	
	for(int* i = buf.begin(); i != buf.end(); i++)
	{
		*i = val++;
	}

	for(const int* i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << *i << '\n';
	}
}

void printSorted(const int_sorted & srt)
{
	for(const int* it = srt.begin(); it != srt.end(); it++)
	{
		std::cout << *it << ", ";
	}

	std::cout << '\n';
}

int main()
{
	//f(int_buffer(10));
	

	int_buffer buff(10);

	std::mt19937 mt((std::random_device()()));
	std::uniform_int_distribution<int> dist(1, 100);

	for(int* it = buff.begin(); it != buff.end(); it++)
	{
		*it = dist(mt);
	}


	int_sorted sorted(buff.begin(), buff.size());

	int_sorted secondSorted = sorted;

	printSorted(sorted);


	for(int i = 0; i < 10; i++)
	{

		sorted.insert(dist(mt));
	}

	printSorted(sorted);

	printSorted(sorted.merge(secondSorted));
}
