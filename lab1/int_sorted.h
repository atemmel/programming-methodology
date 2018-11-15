#ifndef INT_SORTED_H
#define INT_SORTED_H

#include "int_buffer.h"

#include <utility>

class int_sorted
{
public:
	int_sorted(const int* source, size_t size);

	size_t size() const;

	int* insert(int value);

	const int* begin() const;
	const int* end() const;

	int_sorted merge(const int_sorted & merge_with) const;
private:
	int_buffer m_buffer;
};

#endif
