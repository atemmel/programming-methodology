#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <vector>


struct compare_less
{
	bool operator()(int lhs, int rhs) const
	{
		return lhs < rhs;
	}
};

template<typename T, comparison = compare_less>
class p_queue
{
public:
	T pop()
	{

	}

	void push(const T & value, int priority = 0)
	{
		auto it = m_elements.begin();

		while(it != m_elements.end())
		{
			if(
			++it;
		}
	}

	size_t size() const
	{
		return m_elements.size();
	}

	bool empty() const
	{
		return m_elements.empty();
	}

private:
	struct queue_element
	{
		T value;
		int priority = 0;
	};

	std::vector<queue_element> m_elements;
};

#endif
