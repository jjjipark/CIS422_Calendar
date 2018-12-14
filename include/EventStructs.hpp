#ifndef EVENT_STRUCTS_HPP
#define EVENT_STRUCTS_HPP
#include <string>
#include <cstdint>
#include <ctime>

struct db_event {
	int32_t     db_id = -1;
	std::string name;
	std::string description;
	std::string category;
	int64_t     start;
	int64_t     end;
	int64_t     creation_time;
	uint32_t    priority = 0;
	bool        deletion = false;
};

struct view_event {
	int32_t     controller_id = -1;
	std::string name;
	std::string description;
	std::string category;
	struct tm   start;
	struct tm   end;
	uint32_t    priority = 0;
	bool        deletion = false;
};

#endif /* EVENT_STRUCTS_HPP */