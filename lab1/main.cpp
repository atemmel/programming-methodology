#include "int_sorted.h"

#include <iostream>
#include <random>
#include <chrono>

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

int_sorted sort(const int* begin, const int* end)
{
	if(begin == end) return int_sorted(nullptr, 0);	
	if(begin == end - 1) return int_sorted(begin, 1);

	ptrdiff_t half = (end - begin) / 2;

	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(mid, end));
}

void selectionSort(int* begin, int* end)
{

	for(int* it = begin; it != end; it++)
	{
		int* lowest = it;

		for(int* jt = it; jt != end; jt++)
		{
			if(*jt < *lowest) lowest = jt;
		}

		std::swap(*it, *lowest);
	}
}

void compareSorts()
{
	int_buffer bigBuffer(400000);

	for(int* it = bigBuffer.begin(); it != bigBuffer.end(); it++)
	{
		*it = rand();
	}
	auto stdBuffer = bigBuffer;

	auto beginMerge = std::chrono::high_resolution_clock::now();
	int_sorted merge = sort(bigBuffer.begin(), bigBuffer.end());
	auto endMerge = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffMerge = endMerge - beginMerge;

	std::cout << "Merge took: " << diffMerge.count() << " s\n";

	auto beginSelect = std::chrono::high_resolution_clock::now();
	selectionSort(bigBuffer.begin(), bigBuffer.end());
	auto endSelect = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffSelect = endSelect - beginSelect;

	std::cout << "Selection took: " << diffSelect.count() << " s\n";


	auto beginStd = std::chrono::high_resolution_clock::now();
	std::sort(stdBuffer.begin(), stdBuffer.end());
	auto endStd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffStd = endStd - beginStd;

	std::cout << "Standard took: " << diffStd.count() << " s\n";
}

void printSorted(const int_sorted & srt)
{
	for(const int* it = srt.begin(); it != srt.end(); it++)
	{
		std::cout << *it << ", ";
	}

	std::cout << '\n';
}

void printBuff(const int_buffer & buff)
{
	for(const int* it = buff.begin(); it != buff.end(); it++)
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

	//int_sorted
	puts("int_sorted:" );

	int_sorted sorted(buff.begin(), buff.size());

	int_sorted secondSorted = sorted;

	printSorted(sorted);

	for(int i = 0; i < 10; i++)
	{

		sorted.insert(dist(mt));
	}

	printSorted(sorted);

	printSorted(sorted.merge(secondSorted));

	//merge
	puts("Merge sorted:");

	auto mergeSortedBuff = sort(buff.begin(), buff.begin());

	mergeSortedBuff.insert(5);

	printSorted(mergeSortedBuff);

	//selection
	puts("Selection sort:");
	printBuff(buff);
	selectionSort(buff.begin(), buff.end());
	printBuff(buff);

	//chrono test

	srand(time(0));


	compareSorts();
}
