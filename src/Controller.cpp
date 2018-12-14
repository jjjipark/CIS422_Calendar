//
//  Controller.cpp
//  Controller
//
//  Created by Rebeccalynn Araya on 4/13/18.
//  Copyright © 2018 Rebeccalynn Araya. All rights reserved.
//

#include <Controller.hpp>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

//Errors
enum EXIT_CODES {
	STREAM_ERROR = -1
};

//Constructor
Controller::Controller()
{

}

//Destructor
Controller::~Controller()
{
	 
}


int Controller::edit_event(struct view_event event)
{
	/*
	 Adds an event to the view_event structure. If the event's database ID matches any controller ID already in memory, 
	 then the event already exists and is edited accordingly. If the event does not have a database ID then this is a new
	 event and a view_event struct gets created an added to memory. The database ID will be initialzied to -1.
	 @param - view_event structure
	 @returns the controller ID
	 */
    if (event.controller_id >= 0){
		for (view_with_id_list::iterator it = events.begin(); it != events.end(); it++){
			if (it->first.controller_id == event.controller_id){
				it->first = event;
                return it->second;
			}
		}

	}
	event.controller_id = (int32_t)events.size();
	events.push_back(view_event_with_db_id(event, -1));
    return event.controller_id;
}

int64_t local_to_unix(struct tm *time)
{
	/*
	 Switches from local time to unix time
	 @param - a struct tm local time stamp
	 @returns the UNIX epoch time
	 */
	return (int64_t)mktime(time);
}

struct tm *unix_to_local(int64_t unix_time)
{
	/*
	 Switches from unix time to local time
	 @param - inclusive time in UNIX epoch time
	 @returns time structure for local time
	 */
	struct tm *timeinfo;
	timeinfo = localtime((time_t *) &unix_time);
	return timeinfo;
}

struct view_event db_to_view(struct db_event const& event){
	struct view_event new_event;
	new_event.name =        event.name;
	new_event.description = event.description;
	new_event.category =    event.category;
	new_event.start =      *unix_to_local(event.start);
	new_event.end =        *unix_to_local(event.end);
	new_event.priority =    event.priority;
	new_event.deletion =    event.deletion;
	return new_event;
}

view_list Controller::get_events(struct tm *start, struct tm *end)
{
	/*
	 Given the parameters specified by the request from the view, the function calls the model to request the 
	 data from the database. The local time must be switched to UNIX epoch time. Also, the vector of db_events
	 gets transformed to a vector of view_events. Then, this structure is saved to local memory. Lastly, the 
	 vector of structs is filtered for the specified priority and returned.
	 @param- Start time in local time, End time in local time, specified cateogry, priority number
	 @returns a vector of view_event structs
	 */
	int64_t start_unix = local_to_unix(start);
	int64_t end_unix   = local_to_unix(end);

    Interval requested_events_interval(interval_pair(start_unix, end_unix));
	requested_events_interval.Difference(this->stored_events_interval); // Get the interval of events needed from the database
	this->stored_events_interval.Union(requested_events_interval);
	

	db_list db_events;
	interval_list intervals = requested_events_interval.get_intervals();
	for (interval_list::iterator it = intervals.begin(); it != intervals.end(); it++){
		db_list returned_events = model.get_events(it->first, it->second);
		db_events.insert(db_events.end(), returned_events.begin(), returned_events.end());
	}

	view_list view_events;

	//Get all events saved in controller from within requested time range.
	for (view_with_id_list::iterator it = this->events.begin(); it!= this->events.end(); it++){
		int64_t event_start = local_to_unix(&(it->first.start));
		int64_t event_end = local_to_unix(&(it->first.end));
		if (start_unix < event_end && end_unix > event_start){
            if (it->first.deletion == false)
                view_events.push_back(it->first);
		}
	}

	//Get all events from Model from within requested time range.
	for (db_list::iterator it = db_events.begin(); it != db_events.end(); it++){
		struct view_event new_event = db_to_view(*it);
        new_event.controller_id = events.size();
        bool exists_in_controller = false;
        for (view_with_id_list::iterator it2 = this->events.begin(); it2 != this->events.end(); it2++){
            if (it2->second == it->db_id){
                exists_in_controller = true;
                break;
            }
        }
        if (!exists_in_controller){
            events.push_back(view_event_with_db_id(new_event, it->db_id));
            view_events.push_back(new_event);
        }
	}

	std::sort(view_events.begin(), view_events.end(), [](view_event &a, view_event &b) {return local_to_unix(&(a.start)) < local_to_unix(&(b.start));});
	return view_events;
}

void Controller::save()
{
    //Prompts user to see if the events should be saved
	db_list db_events;
	for (view_with_id_list::iterator it = this->events.begin(); it != this->events.end(); it++){
        if (it->first.controller_id >= 0){
			struct db_event new_event;
			new_event.name =        it->first.name;
			new_event.description = it->first.description;
			new_event.category =    it->first.category;
			new_event.start =       local_to_unix(&(it->first.start));
			new_event.end =         local_to_unix(&(it->first.end));
			new_event.priority =    it->first.priority;
			new_event.deletion =    it->first.deletion;
			new_event.db_id =       it->second;
			db_events.push_back(new_event);
		}
	}
	events.clear();
	stored_events_interval.clear();
	model.save_changes(db_events);
}

void Controller::export_to_csv() {
	/*
	Saves all current modifications in the controller to the database.  Requests all events from the database
	in the form of db_events.  A backup file is created or overwritten named "backup-YYYY-MM-DD.csv".  The 
	db_events' information for each event is written to the file. No input, no return.
	*/
    this->save();
	std::vector<db_event> events = this->model.get_all_events();
	FILE *f_out;
    unsigned int i;
	char filename[100];
	char dateA[11];
	char dateB[11];
	char start_time[6];
	char end_time[6];
	time_t raw_time = time(NULL);
	struct tm *tm_time;

	tm_time = localtime(&raw_time);
	sprintf(filename, "backup-%.4d-%.2d-%.2d.csv", tm_time->tm_year + 1900
												 , tm_time->tm_mon + 1
												 , tm_time->tm_mday);
	
	f_out = std::fopen(filename,"wb");
	//If there is an error with creating stream for writing to the file, write error to stderr and exit.
	if (f_out == NULL) {
		fprintf(stderr, "File I/O Error: No memory for stream");
		exit(STREAM_ERROR);
	}
	
	//For each event, create a string of all event details and write that string to the backup file.  
	for (i = 0; i < events.size(); i++) {
		
		tm_time = localtime((time_t *) &events[i].start);
		sprintf(dateA, "%.2d/%.2d/%.4d", tm_time->tm_mday
									   , tm_time->tm_mon + 1
									   , tm_time->tm_year + 1900);
		sprintf(start_time, "%.2d:%.2d", tm_time->tm_hour
									   , tm_time->tm_min);

		tm_time = localtime((time_t *) &events[i].end);	
		sprintf(dateB, "%.2d/%.2d/%.4d", tm_time->tm_mday
									   , tm_time->tm_mon + 1
									   , tm_time->tm_year + 1900);
		sprintf(end_time, "%.2d:%.2d", tm_time->tm_hour
									   , tm_time->tm_min);
		
		fprintf(f_out, "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n", dateA
													   , start_time
													   , end_time
													   , events[i].name.c_str()
													   , events[i].description.c_str()
													   , events[i].category.c_str()
													   , events[i].priority
													   , dateB);
	}
	fclose(f_out);
}
