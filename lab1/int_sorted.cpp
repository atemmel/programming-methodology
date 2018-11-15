#include "int_sorted.h"

int_sorted::int_sorted(const int* source, size_t size)
	: m_buffer(nullptr, 0)
{	
	if(size == 0)
	{
		return;
	}
	else if(size == 1)
	{
		int_buffer tmpBuff(source, 1);
		m_buffer = std::move(tmpBuff);
		return;
	}

	int_sorted tmp = sort(source, source + size);

	m_buffer = std::move(tmp.m_buffer);
}

size_t int_sorted::size() const
{
	return m_buffer.size();
}

int* int_sorted::insert(int value)
{
	//Skapa ett större buffer
	int_buffer nextBuffer(m_buffer.size() + 1);
	
	int* index = nextBuffer.begin();

	//Hitta insertionspunkten
	for(const int* it = m_buffer.begin(); it != m_buffer.end(); it++)
	{
		if(*it > value)
		{
			break;
		}
		else
		{
			++index;
		}
	}

	*index = value;

	int* oldIter = m_buffer.begin();
	int* newIter = nextBuffer.begin();

	while(oldIter != m_buffer.end())
	{
		if(index == newIter)
		{
			++newIter;
		}

		*newIter = *oldIter;

		++oldIter;
		++newIter;
	}

	m_buffer = std::move(nextBuffer);

	return index;
}

const int* int_sorted::begin() const
{
	return m_buffer.begin();
}

const int* int_sorted::end() const
{
	return m_buffer.end();
}

int_sorted int_sorted::merge(const int_sorted & merge_with) const
{	
	int_buffer mergedBuffer(m_buffer.size() + merge_with.size());
	const int* aIter = m_buffer.begin();
	const int* bIter = merge_with.begin();
	const int* aEnd = m_buffer.end();
	const int* bEnd = merge_with.end();
	int* mergedIter = mergedBuffer.begin();

	while(aIter != aEnd && bIter != bEnd)
	{
		if(*aIter < *bIter)
		{
			*mergedIter = *aIter;
			++mergedIter, ++aIter;
		}
		else
		{
			*mergedIter = *bIter;
			++mergedIter, ++bIter;
		}
	}

	while(aIter != aEnd)
	{
		*mergedIter = *aIter;
		++mergedIter, ++aIter;
	}

	while(bIter != bEnd)
	{
		*mergedIter = *bIter;
		++mergedIter, ++bIter;
	}

	return int_sorted(mergedBuffer.begin(), mergedBuffer.size());
}


int_sorted int_sorted::sort(const int* begin, const int* end)
{
	if(begin == end) return int_sorted(nullptr, 0);	
	if(begin == end - 1) return int_sorted(begin, 1);

	ptrdiff_t half = (end - begin) / 2;

	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(mid, end));
}
