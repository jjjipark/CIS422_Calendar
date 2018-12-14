#ifndef MODEL_HPP
#define EVENT_HPP
#include <sqlite3.h>
#include <ctime>
#include <vector>
#include <cstdint>

class Model {
public:
	std::vector<struct db_event> get_all_events();
    std::vector<struct db_event> get_events(int64_t start, int64_t end);
	void save_changes(std::vector<struct db_event> events);
	Model();
	~Model();
private:
	sqlite3 *db;
	void open_database(const char* db_name);
	void close_database();
	void create_table();
};

int select_callback(void *data, int argc, char **argv, char **name);

#endif /* MODEL_HPP */
