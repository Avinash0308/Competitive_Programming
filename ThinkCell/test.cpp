#include <map>
template <typename K, typename V>
class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;

public:
	// constructor associates whole range of K with val
	interval_map(V const &val)
		: m_valBegin(val)
	{
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const &keyBegin, K const &keyEnd, V const &val)
	{
		// INSERT YOUR SOLUTION HERE
		if (!(keyBegin < keyEnd))
			return;
		auto it = m_map.lower_bound(keyEnd);
		auto it2 = m_map.lower_bound(keyBegin);
		auto it3 = m_map.upper_bound(keyBegin);
		auto it4 = m_map.upper_bound((keyEnd));
		if (it == m_map.begin())
		{
			if (val == m_valBegin)
			{
				return;
			}
			else
			{
				if (it4 == m_map.begin())
				{
					m_map[keyBegin] = val;
					m_map[keyEnd] = m_valBegin;
				}
				else
				{
					m_map[keyBegin] = val;
				}
			}
		}
		else if (it3 == m_map.end())
		{
			if (it2 == m_map.end())
			{
				if (!(m_valBegin == val))
				{
					auto ite = m_map.end();
					ite--;
					(*ite).second = m_valBegin;
					m_map[keyBegin] = val;
					m_map[keyEnd] = m_valBegin;
				}
			}
			else
			{
				if (!(m_valBegin == val))
				{
					m_map[keyBegin] = val;
					m_map[keyEnd] = m_valBegin;
				}
			}
		}
		else if (it3 == it4)
		{
			V value = m_map[keyBegin];
			if (!(val == value))
			{
				m_map[keyBegin] = val;
				m_map[keyEnd] = value;
			}
		}	
		else if (it2 == m_map.begin())
		{
			V value = m_map[keyEnd];
			while (!(m_map.begin() == it4))
			{
				m_map.erase(m_map.begin());
			}
			if (value == val)
			{
				m_map[keyBegin] = val;
			}
			else
			{
				m_map[keyBegin] = val;
				m_map[keyEnd] = value;
			}
		}
		else if (it == m_map.end())
		{
			auto ite = m_map.end();
			ite--;
			while (!(ite == it2))
			{
				m_map.erase(ite);
				ite = m_map.end();
				ite--;
			}
			if (m_map[keyBegin] == val)
			{
				if (!(val == m_valBegin))
				{
					m_map[keyEnd] = m_valBegin;
				}
			}
			else
			{
				m_map[keyBegin] = val;
				m_map[keyEnd] = m_valBegin;
			}
		}
		else
		{
			V end = m_map[keyEnd];
			V beg = m_map[keyBegin];
			while(!(it2 == it)){
				m_map.erase(it2);
				it2 = m_map.lower_bound(keyBegin);
			}
			if((!(val == beg)) && (!(end == val)) ){
				m_map[keyBegin] = val;
				m_map[keyEnd] = end;
			}
			else if((val == beg) && (end == val)){}
			else if(end == val){
				m_map[keyBegin] = val;
			}
			else{
				m_map[keyEnd] = val;
			}
		}
	}

	// look-up of the value associated with key
	V const &operator[](K const &key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
int main(){
	return 0;
}