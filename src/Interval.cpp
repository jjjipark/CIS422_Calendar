#include <Interval.hpp>
#include <iostream>
#include <algorithm>

Interval::Interval(){
}

Interval::Interval(interval_pair interval){
	this->Union(interval);
}

void Interval::Union(Interval const& other){
	interval_list::const_iterator it;
	for (it=other.intervals.begin(); it != other.intervals.end(); it++){
		this->Union(*it);
	}
}

void Interval::Difference(Interval const& other){
	interval_list::const_iterator it;
	for (it=other.intervals.begin(); it != other.intervals.end(); it++){
		this->Difference(*it);
	}
}

void Interval::Union(interval_pair interval){
	int64_t first = interval.first < interval.second ? interval.first : interval.second;
	int64_t second = interval.first < interval.second ? interval.second : interval.first;
	bool found_first = false;
	interval_list::iterator it;
	if (this->intervals.size() == 0){
		this->intervals.push_back(interval_pair(first,second));
		return;
	}
	for (it=this->intervals.begin(); it != this->intervals.end(); it++){
		//The interval belonging to first has been found...
		if (found_first){
			//The current interval lies completely within first's interval
			if (it->second < second){
				it = this->intervals.erase(it);
				it--;
			//The current interval overlaps with second
			}else if (it->first <= second){
				std::prev(it)->second = it->second; //Set first's end point to the current end point
				this->intervals.erase(it); //Delete the current interval
				return;
			//Second lies between first's interval and the current interval
			}else{
				return;
			}
		}else{
			//First occurs before the current interval
			if (it->first > first){
				//First and second do not overlap with any intervals
				if (it->first > second){
					this->intervals.insert(it, interval_pair(first, second));
					return;
				//First is outside the current interval but (first, second) overlaps with it
				}else{
					it->first = first;
					//Second lies within the current interval
					if(it->second >= second){
						return;
					//Current interval lies completely within (first, second)
					}else{
						it->second = second;
						found_first = true;
					}
				}
			//The current interval overlaps with first
			}else if (it->second >= first){
				//The current interval completely contains (first, second)
				if (it->second >= second){
					return;
				//Second lies somewhere outside first's interval
				}else{
					it->second = second;
					found_first = true;
				}
			}			
		}
	}
	if (!found_first)
		this->intervals.insert(this->intervals.end(), interval_pair(first, second));
}

void Interval::Difference(interval_pair interval){
	int64_t first = interval.first < interval.second ? interval.first : interval.second;
	int64_t second = interval.first < interval.second ? interval.second : interval.first;
	bool found_first = false;
	interval_list::iterator it;
	for (it=this->intervals.begin(); it != this->intervals.end(); ){
		//The interval belonging to first has been found...
		if (found_first){
			//The current interval lies completely within first's interval
			if (it->second <= second){
				it = this->intervals.erase(it);
				continue;
			//The current interval overlaps with second
			}else if (it->first <= second){
				it->first = second; //Set the current interval's start to second
				return;
			//Second lies between first's interval and the current interval
			}else{
				return;
			}
		}else{
			//First occurs before the current interval
			if (it->first >= first){
				//First and second do not overlap with any intervals
				if (it->first >= second){
					return;
				//Second lies within the current interval
				}else if (it->second > second){
					it->first = second;
					return;
				//The current interval is contained within (first, second)
				}else{
					it = this->intervals.erase(it);
					found_first = true;
					continue;
				}
			//The current interval overlaps with first
			}else if (it->second >= first){
				//The current interval completely contains (first, second)
				if (it->second > second){
					int64_t new_second = it->second;
					it->second = first;
					it++;
					this->intervals.insert(it, interval_pair(second, new_second));
					return;
				//Second lies somewhere outside first's interval
				}else{
					it->second = first;
					found_first = true;
				}
			}			
		}
		if (it != this->intervals.end())
			it++;
	}
}

void Interval::clear(){
	intervals.clear();
}

void Interval::print(){
	interval_list::iterator it;
	for (it=this->intervals.begin(); it != this->intervals.end(); ++it){
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}

interval_list Interval::get_intervals(){
	return intervals;
}