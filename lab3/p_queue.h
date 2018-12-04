#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <functional>
#include <vector>

template<typename T, typename comparison = std::less<>>
class p_queue
{
public:
	T pop()
	{
		T value = m_elements.front().value;
		m_elements.erase(m_elements.begin());
		return value;
	}

	void push(const T & value, int priority = 0)
	{
		auto it = m_elements.begin();
		comparison comp;

		while(it != m_elements.end())
		{
			if(comp(it->priority, priority)) break;
			++it;
		}

		m_elements.insert(it, {value, priority} );
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
		queue_element(T value = T(), int priority = 0)
			: value(value), priority(priority) {}
		
		T value;
		int priority;
	};

	std::vector<queue_element> m_elements;
};

#endif
