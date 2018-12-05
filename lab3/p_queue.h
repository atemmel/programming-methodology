#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <functional>
#include <algorithm>
#include <vector>

template<typename T, typename UnaryPredicate = std::less<> >
class p_queue
{
public:
	T pop()
	{
		T value = m_elements.front();
		m_elements.erase(m_elements.begin());
		return value;
	}

	void push(const T & value)
	{
		UnaryPredicate predicate;

		auto it = std::find_if(m_elements.begin(), m_elements.end(), [&](const T & input)
		{
			return predicate(input, value);
		});

		m_elements.insert(it, value);
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
	std::vector<T> m_elements;
};

#endif
