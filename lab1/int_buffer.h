#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <algorithm>
#include <cstddef>

class int_buffer 
{
public:
	//ctor
	explicit int_buffer(size_t size);
	int_buffer(const int* source, size_t size);
	int_buffer(const int_buffer & rhs);
	int_buffer(int_buffer && rhs);

	//dtor
	~int_buffer();

	//assignment
	int_buffer & operator=(const int_buffer & rhs);
	int_buffer & operator=(int_buffer && rhs);

	size_t size() const;
	int* begin();
	int* end();

	const int* begin() const;
	const int* end() const;

private:
	void swap(int_buffer & rhs);

	int* m_beg = nullptr;
	int* m_end = nullptr;
};

#endif
