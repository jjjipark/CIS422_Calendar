#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <utility>
#include <cstdint>
#include <list>

typedef std::pair<int64_t, int64_t> interval_pair;
typedef std::list<interval_pair> interval_list;

class Interval{
public:
	Interval();
	Interval(interval_pair interval);
	void Union(Interval const& other);
	void Union(interval_pair interval);
	void Difference(Interval const& other);
	void Difference(interval_pair interval);  
	void print();
	void clear();
	interval_list get_intervals();
private:
	interval_list intervals;
};

#endif /* INTERVAL_HPP */
