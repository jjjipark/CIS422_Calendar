#include <Model.hpp>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <EventStructs.hpp>
#include <list>
#include <cstring>
#include <time.h>
#include <iostream>

std::vector<struct db_event> Model::get_all_events() {
    /*
    Uses SQLite to retrieve each and every event from the database.
    @returns a vector of events in the form of db_event structs
    */
    char *err = 0;
    const std::string str("SELECT * FROM EVENTS");
    std::vector<db_event> events;
    if (sqlite3_exec(this->db, str.c_str(), select_callback, (void*)(&events), &err)) {
        fprintf(stderr, "SQL error: %s\n", err);
    }
    return events;

}

std::vector<struct db_event> Model::get_events(int64_t start, int64_t end) {
	/*
	Uses SQLite to retrieve all events from the database which overlap with the time interval [start, end]
	@param start - Inclusive start time in UNIX epoch time
	@param end -   Inclusive end time in UNIX epoch time
	@returns a vector of events in the form of db_event structs
	*/
	std::ostringstream ss;
	ss << "SELECT * FROM EVENTS WHERE "\
		"START < " << end << " AND END > " << start
		<< std::ends;
	char *err = 0;
	const std::string &str = ss.str();
	std::vector<db_event> events;
	if (sqlite3_exec(this->db, str.c_str(), select_callback, (void*)(&events), &err)) {
		fprintf(stderr, "SQL error: %s\n", err);
	}
	//Clear the stringstream
	ss.str("");
	ss.clear();
	return events;
}

void Model::save_changes(std::vector<struct db_event> events) {
	/*
	Given a vector of events, adds new events to the database and updates events that already exist.
	@param events - A vector of events. New events must have db_id set to <= 0. Existing events must have
	                db_id set to the value they were assigned when first added to the database.
	*/
    for (unsigned int i = 0; i < events.size(); i++) {
		std::ostringstream ss;
        if (events[i].db_id <= 0) {
            if (events[i].deletion == false){
                //New event: add it to the database.
                ss << "INSERT INTO EVENTS ( NAME, DESCRIPTION, CATEGORY, START, END, CREATION_TIME, PRIORITY) VALUES ('"
                    << events[i].name << "', '"
                    << events[i].description << "', '"
                    << events[i].category << "', "
                    << events[i].start << ", "
                    << events[i].end << ", "
                    << events[i].creation_time << ", "
                    << events[i].priority << ");"
                    << std::ends;
            }
		} else {
			if (events[i].deletion) {
				//Event is marked for deletion.
				ss << "DELETE FROM EVENTS WHERE ID = " << events[i].db_id << std::ends;
			} else {
				//Event is an edit of an existing entry in the database.
				ss << "UPDATE EVENTS SET "\
					"NAME = '" << events[i].name << "', "\
					"DESCRIPTION = '" << events[i].description << "', "\
					"CATEGORY = '" << events[i].category << "', "\
					"START = '" << events[i].start << "', "\
					"END = '" << events[i].end << "', "\
					"CREATION_TIME = '" << events[i].creation_time << "', "\
					"PRIORITY = '" << events[i].priority << "' "\
					"WHERE ID = " << events[i].db_id << ";"
					<< std::ends;
			}
		}
		char *err = 0;
		const std::string &str = ss.str();
		if (sqlite3_exec(db, str.c_str(), NULL, 0, &err)) {
			fprintf(stderr, "SQL error: %s\n", err);
		}
		//Clear the stringstream
		ss.str("");
		ss.clear();
	}
}

Model::Model() {
	/*
	Model constructor. Creates or opens the database, then ensures the table is set correctly.
	A pointer to the database is stored in the Model's db member.
    */
	this->open_database("Events.db");
	this->create_table();
}

Model::~Model() {
	/*
	Model destructor. Closes the database.
	*/
	this->close_database();
}

void Model::open_database(const char* db_name) {
	/*
	Opens an SQLite database given a filename. Stores a pointer to the database in the Model object's db member.
	@param db_name - A filename for the database. If a databse already exists, it is opened. Otherwise, it is created.
    */
	if (sqlite3_open(db_name, &this->db)) {
		fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(this->db));
		exit(EXIT_FAILURE);
    }
}

void Model::close_database() {
	/*
	Closes the database pointed to by the Model object's db member.
	*/
	sqlite3_close(this->db);
}

void Model::create_table() {
	/*
	Creates a table in the database containing the necessary columns:
	ID: A unique id assigned to each event when added to the database. Used to update existing events when needed.
	NAME:          A name given to an event by the user.
	DESCRIPTION:   A description given to the event by the user.
	CATEGORY:      A category given to the event by the user.
	START:         The event's start time in UNIX epoch time.
	END:           The event's end time in UNIX epoch time.
	CREATION_TIME: The UNIX epoch time when the user first created the event.
	PRIORITY:      The priority given to the event by the user.
	*/
	const char *create_table_command = "CREATE TABLE IF NOT EXISTS EVENTS("\
	                                   "ID            INTEGER PRIMARY KEY AUTOINCREMENT,"\
	                                   "NAME          TEXT,"\
	                                   "DESCRIPTION   TEXT,"\
	                                   "CATEGORY      TEXT,"\
	                                   "START         INT,"\
	                                   "END           INT,"\
	                                   "CREATION_TIME INT,"
	                                   "PRIORITY      INT);";
	char *err = 0;
	if (sqlite3_exec(db, create_table_command, NULL, 0, &err)) {
		fprintf(stderr, "SQL error: %s\n", err);
		exit(EXIT_FAILURE);
	}
}

int select_callback(void *vector_ptr, int argc, char **argv, char **name) {
	/*
	This function is called by sqlite3_exec() for every entry in the database matched by a SELECT call.
	This function is passed as an argument to sqlite3_exec(), so it cannot be a method belonging to Model.
	@param vector_ptr - A pointer to a vector of db_events to be filled with each matched entry in the database.
	@param argc -       The number of columns of data associated with the database entry.
	@param argv -       An array of cstrings for the value stored in each column of this entry.
	@param name -       An array of cstrings for the names of each column of this entry.
	@returns 0 if the callback ran correctly, otherwise non-zero which causes sqlite3_exec() to return SQLITE_ABORT.
	*/
	db_event event;
	for (int i = 0; i<argc; i++) {
		try {
			if (strcmp(name[i], "ID") == 0)                 event.db_id = std::stol(argv[i]);
			else if (strcmp(name[i], "NAME") == 0)          event.name = std::string(argv[i]);
			else if (strcmp(name[i], "DESCRIPTION") == 0)   event.description = std::string(argv[i]);
			else if (strcmp(name[i], "CATEGORY") == 0)      event.category = std::string(argv[i]);
			else if (strcmp(name[i], "START") == 0)         event.start = std::stoll(argv[i]);
			else if (strcmp(name[i], "END") == 0)           event.end = std::stoll(argv[i]);
			else if (strcmp(name[i], "CREATION_TIME") == 0) event.creation_time = std::stoll(argv[i]);
			else if (strcmp(name[i], "PRIORITY") == 0)      event.priority = std::stoul(argv[i]);
			else {
				fprintf(stderr, "Error. The database contains invalid data: \"%s =\n%s\".", name[i], argv[i] ? argv[i] : "NULL");
				return 1;
			}
		} catch (const std::exception &e) {
			fprintf(stderr, "%s", e.what());
			return 1;
		}
	}
	//The vector_ptr must be passed as a void*, so cast it back to a vector pointer before calling push_back().
	((std::vector<db_event>*)vector_ptr)->push_back(event);
	return 0;
}
