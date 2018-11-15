#include "int_buffer.h"

//#define TEST_ALL

int_buffer::int_buffer(size_t size)
	: m_beg(new int[size]), m_end(m_beg + size)
{
#ifdef TEST_ALL
	puts("constructor 1");
#endif
}

int_buffer::int_buffer(const int* source, size_t size)
	: m_beg(new int[size]), m_end(m_beg + size)
{
#ifdef TEST_ALL
	puts("constructor 2");
#endif

	for(size_t i = 0; i < size; i++)
	{
		m_beg[i] = source[i];
	}
}

int_buffer::int_buffer(const int_buffer & rhs)
	: m_beg(new int[rhs.size()]), m_end(m_beg + rhs.size())
{
#ifdef TEST_ALL
	puts("copy constructor");
#endif
	size_t size = rhs.size();

	for(size_t i = 0; i < size; i++)
	{
		m_beg[i] = rhs.m_beg[i];
	}
}

int_buffer::int_buffer(int_buffer && rhs)
{
#ifdef TEST_ALL
	puts("move constructor");
#endif
	std::swap(m_beg, rhs.m_beg);
	std::swap(m_end, rhs.m_end);
}

int_buffer::~int_buffer()
{
#ifdef TEST_ALL
	puts("destructor");
#endif
	if(m_beg) delete[] m_beg;
}

int_buffer & int_buffer::operator=(const int_buffer & rhs)
{
#ifdef TEST_ALL
	puts("assignment");
#endif

	if(this == &rhs) return *this;

	delete[] m_beg;
	size_t size = rhs.size();
	m_beg = new int[size];

	for(size_t i = 0; i < size; i++)
	{
		m_beg[i] = rhs.m_beg[i];
	}

	return *this;
}

int_buffer & int_buffer::operator=(int_buffer &&rhs)
{
	if(this == &rhs) return *this;

	delete[] m_beg;
	m_beg = rhs.m_beg;
	m_end = rhs.m_end;
	rhs.m_beg = rhs.m_end = nullptr;

	return *this;
}

size_t int_buffer::size() const
{
	return m_end - m_beg;
}

int* int_buffer::begin()
{
#ifdef TEST_ALL
	puts("beg");
#endif
	return m_beg;
}

int* int_buffer::end()
{
#ifdef TEST_ALL
	puts("end");
#endif
	return m_end;
}

const int* int_buffer::begin() const
{
#ifdef TEST_ALL
	puts("const begin");
#endif
	return m_beg;
}

const int* int_buffer::end() const
{
#ifdef TEST_ALL
	puts("const end");
#endif
	return m_end;
}

void int_buffer::swap(int_buffer & rhs)
{
	std::swap(m_beg, rhs.m_beg);
	std::swap(m_end, rhs.m_end);
}
