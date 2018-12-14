#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
//
//  BinaryTree.hpp
//  BinaryTree
//
//  Created by Rebeccalynn Araya on 4/13/18.
//  Copyright © 2018 Rebeccalynn Araya. All rights reserved.
//

//Between controller and database
#include <sstream>
#include <cstdint>
#include <ctime>
#include <vector>
#include <list>
#include <utility>
#include <Model.hpp>
#include <EventStructs.hpp>
#include <Interval.hpp>

typedef std::pair<struct view_event, int32_t> view_event_with_db_id;
typedef std::vector<view_event_with_db_id> view_with_id_list;
typedef std::vector<struct db_event> db_list;
typedef std::vector<struct view_event> view_list;

class Controller
{
public:
	Controller();
	~Controller();
	int edit_event(struct view_event event);
	void export_to_csv();
    std::vector<struct view_event> get_events(struct tm *start, struct tm *end);
	void save();
private:
	Model model;
	view_with_id_list events;
	Interval stored_events_interval;
	
};

int64_t local_to_unix(struct tm *time);
struct tm *unix_to_local(int64_t time);
struct view_event db_to_view(struct db_event const& event);
#include <stdio.h>

#endif /* Controller_hpp */
