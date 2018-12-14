# CIS 422 Calendar Project (Group 3)
By Alonzo Altamirano, Becca Araya, Jieun Park, and Taylor Santos

# Revisions
Date|Author|Notes
---|---|---
04/08/2018|Alonzo|Intial creation of document. Add project background, team roles, management plan, build plan, schedule and milestones, SRS
04/09/2018|Alonzo|Convert Project Plan to Markdown
04/10/2018|Taylor|Add Software Design Specification
04/10/2018|Jieun|Expand Software Design Specification
04/10/2018|Alonzo|Expand SRS, Modify Build Plan
04/10/2018|Taylor|Cement Team Roles
04/10/2018|Alonzo|Risks and Mitigation, Typo Fixes
04/11/2018|Alonzo|Expand SRS, Add Use Cases, Expand Mangement Plan, Expand Project Background, Revise Schedule and Milestones
04/11/2018|Jieun|Expand Software Design Specification
04/11/2018|Becca|Reviewed and Cleaned Up Errors
04/23/18|Becca|Small changes to Controller Functionality

Note: Author solely indicates the name of the typist.  All project plan details were discussed by the entire group at in-person group meetings.

# 1. Project Background
Our project is to produce a desktop application that assists end users in creating, viewing, and storing events in a calendar format.  The purpose of this system is to provide the end user with an organizational tool for their personal event planning. Prospective users are expected to be familiar with calendars, the usage of personal computers, and the usage of interfacing devices such as mouse, keyboard, and display.  End users are able to add events which possess information for an event’s name, date(s), start/end times, description, priority, category, recurrence, and time-zone.  End users are able to graphically view events for any given week and also view each event’s attributes.  End users are able to edit event attributes after creation and delete entire events.  All event data is stored in a database such that the end user may close and open the application as they wish and all modifications to information by the end user will be retained.  Precise details can be viewed at **Software Requirements Specification**. 

# 2. Team Roles
Role | Team Member | Responsibilities
---|---|---
System Architect|Taylor, Becca, Jieun| Specify designs that maintain accordance with system requirements with which modules will be implemented. Communicate with implementers in order to exact and refine designs.
Requirements Analyst| Everyone | Explore and specify objectively verifiable requirements of system and software. Communicate with system architects in order to exact and refine requirements.
Quality Control| Alonzo | Develop testing plans(procedures) and perform integration tests.
Developer(Back End)| Taylor, Becca | Realize(implement) designs of logical modules in accordance with specified requirements. Produce documentation for assisting developers and maintainers to utilize and modify the code.
Developer(Front End)| Jieun | Realize(implement) designs of user interface modules in accordance with specified requirements. Produce documentation for assisting developers and maintainers to utilize and modify the code. 
Technical Writer| Alonzo | Produce user documentation. Produce user manual. Maintain logs of group events.
Configuration Control| Taylor | Manage builds and modifications to the system. Facilitate usage of version control for all group members.
Project Management| Alonzo | Develop a Project Plan. Maintain progress of system development within project schedule. Facilitate communication within group.
Tester| Becca, Jieun, Taylor | Develop and perform unit tests on modules of the system.

# 3. Management Plan
To maintain communication, our group will use the application Slack for internal discussion throughout the development process.  Two in person meetings will be held each week at Knight Library to discuss current milestone progression and also team sentiment.  Version control will be managed using a private GitHub repository.  Task management for implementation stages will be performed using the application Trello.  Milestones should be completed prior to their due date.  Group work on subsequent milestones begins at the end of the completion of the previous milestone.  Major decisions for the project such as SRS, SDS, and build plans will be made by stakeholders at in person meetings.  Precise details regarding major project decisions will be explored and cemented at in person meetings as well as by using the Slack general thread.  Small, specific decisions about implementation will be made by the team member responsible for that portion of the project and will be communicated to relevant members using code documentation and Slack personal threads as well as in person meetings.

# 4. Build Plan
Our team will be utilizing an iterative process to increase the modularity of the system and to ensure that core functionality is met prior to advanced functionality.  Iterative development also mitigates risks associated with major design/implementation flaws by allowing these issues to be discovered and corrected as early as possible.  Finally, the iterative process allows for time to learn about developing a GUI.
1. Requirements analysis generates a software requirements specification(SRS) for the overall system and for its major components.  The SRS is recorded.
2. System architects review the SRS.  If requirements are ambiguous or otherwise necessitate revision, system architects consult with requirements analysis to rectify those requirements before proceeding.  In order to achieve a system consistent with the SRS, System arcitects consider design patterns to use in a high level Software Design Specification that encapsulates the entire system and its major components as well as their interactions.  The SDS is recorded.  The order in which these components are built and modified are divided into their own milestones that are fit within the schedule.
3. During the scheduled time allotted for each system milestone’s development, the following iterative process is performed:
   * System architects design a specific solution for achieving that milestone’s requirements.  This solution describes an intermediate level model detailing which exact components are to be built as well as the precise manner in which components will be interfaced with each other and with the current system.  System architects define platform/system specific implementation details for each component and for each of their interfaces.  System architects write a document detailing what specifications were decided upon for this(these) model(s), why these decisions were made, and what issues could arise from these decisions.
    * Implementers (Developers) acquire the design specification.  If design is ambiguous or otherwise necessitates revision, implementers consult with system architects to rectify design specifications before proceeding.
    * Implementers define coding tasks to perform in order to realize(implement) the design specification.  Implementers communicate amongst themselves as to how tasks are divided into discrete actions to be completed and how these actions are distributed between their group members.  As tasks are executed, a log of who executed each task and when is produced.  All code is documented with standard docstrings and includes comments where applicable.  Configuration control ensures proper configuration of the program and also version control.
    * Testers produce, store, and execute unit tests for newly built components and previously built components to ensure that each component is robust.  If unit tests fail, testers communicate with implementers to provide feedback and to rectify the errors that are discovered.
    * Quality controllers produce, store, and execute integration test for newly built components and previously built components to ensure that all interfaces and the system as a whole are robust.  If integration tests fail, quality controllers communicate with implementers to provide feedback and to rectify the errors that are discovered.
    * When this step is reached, working code consistent with the current milestone should be achieved.  This step is reached prior to the scheduled due date of the milestone.
4. At this stage, the entire system is developed.  A means of acquiring the application is produced, documentation for acquiring the application is produced, and the user manual is written.  This stage is reached prior to the due date of the system.  

# 5. Detailed Schedule and Milestones
Milestone|Description|Due Date
---|---|---
1 | Explore Technologies/Libraries | Tuesday 04/10/2018
2 | Project Plan, SRS, SDS Complete | Wednesday 04/11/2018
3 | Database Operational | Friday 04/13/2018
4 | Header Files Written for MVC Components | Saturday 04/14/2018
5 | GUI Prototype| Monday 04/16/2018
6 | Calendar and Event Representations and Processing| Tuesday 04/17/2018
7 | Database Integration | Thursday 04/19/2018
8 | GUI Integration| Friday 04/20/2018
9 | All System Requirements are met | Sunday 0/22/2018
10 | User documentation and User manual Written| Tuesday 04/24/2018
11 | Application Easily Accessible | Thursday 04/26/2018

# 6. Software Requirements Specification
Core Functionality:
* Logic/Processing: We will be producing a simple calendar application.  All requests(i.e. any act of input) run(i.e. stores, manipulates, and/or outputs) in half a second(500ms) or less.  All transactions are high fidelity, in other words there are no errors when entering and retrieving or exchanging calendar data.  All events will be editable in their entirety, though with the same constraints as with their creation.  Constraints with creation are invalid dates(nonexistent or unspecified) and invalid times(nonexistent or unspecified).  All functionality will be component based to facilitate extensibility.  All events will be capable of overlapping.  User will have the option to specify event name, event description, event category, event priority, event start and end time or event all day, event recurrence, and event time zone.  A user will be able to Add, Edit, and Delete events.  
* Database: Database file is capable of being accessed by User.  Database is capable of storing at least one thousand events.  All changes will only be cemented in the database at closure of the program.
* GUI: All times displayed will be consistent with HH:MM format, use 15 minute blocks of time (e.g. 1:15PM, 1:30PM), and DD/MM/YYYY date format.  With one click, a user can see the next or previous week. With four clicks maximum, a user can see any week.  From the display window, the user will have all 24 hours of the day available to view for a week. The system will generate no more than three additional windows for completing any one task.  Events will not be allowed to be created if constraints for creation are not met as specified in the above section Logic/Processing as well as if the name is not provided.  User is prompted as to what errors their event form contains relative to these constraints.  User can additionally display by priority and/or by category of event.  User may view the attributes of an event after creation.

Advanced Functionality:
* Events are color coded.
* An undo button will be an option.  

# 7. Use Cases

1. Case: A user wishes to add an event to their calendar.
  * User opens application.
  * User clicks button to add event.
  * User fills out form with valid data to specify event attributes.
  * User clicks button to add event.  Prompted until input form is valid.
  
  Outcome: Event is added to calendar.
  
2. Case: A user wishes to edit an event.
  * User opens application.
  * User navigates to week of event.
  * User clicks on event block to display attributes form.
  * User edits event block.
  * User clicks button to edit event.  Prompted until input form is valid.
  
  Outcome: Event is edited in calendar.

3. Case: A user wishes to delete an event.
  * User opens application.
  * User navigates to week of event.
  * User clicks on event block to display attributes form.
  * User clicks button to delete event.
  
  Outcome: Event is deleted from calendar.

# 8. Software Design Specification
We will be developing our application in C++, using SQLite to handle database management and Qt to handle the graphical user interface. SQLite emerged as a natural choice for the database management for our application. It requires no configuration or installation on the user's machine, does not require a separate server or process, uses a stable cross-platform database format, and is very fast and compact<sup id="a1">[1](#f1)</sup>. Because its database is stored as a single file on the user's machine, it will be easier to give the user the ability to merge multiple calendars together, provided they have access to both database files. Qt creator is a cross-platform integrated development environment (IDE) for developing and debugging C++ applications using the Qt GUI Application Development Framework SDK, and is included with the SDK. The software has a free LGPL license and runs on Windows, OS X, Linux. Qt has complete and readable documentation, example code, and a large library and set of extentions which will boost our development speed. Our system will take a **Model-View-Controller** approach. 

![SDS Diagram](images/SDS_Diagram.png)

Note: Arrows indicate function calls. The arrow head indicates the module containing the function, the arrow tail indicates the module calling the function.

The **Model** encapsulates any functionality that interacts directly with our database. Storing and retrieving events from the database will be handled solely by the Model. The model will expose 2 functions: one for requesting data and one for passing in new changes to the data. The first function will allow the Controller to request a list of all events that occur within a specified time range. This includes any events that may start before or end after the time range, as long as they overlap it in some way. These events will be returned as a list of structs containing all their saved data, including name, description, start and end time, category, priority, a unique ID, and information about recurrence. The second function provided by the model takes one argument, a list of event structs representing a series of events to be added or updated in the database. The model will check for any preexisting events using their unique IDs, so that their entries in the database may be updated with the edited information. Otherwise, the events will be added as new entries  We will be using Shantanu Kher's method<sup id="a2">[2](#f2)</sup> for representing recurring events in a database. When the Controller makes a request for events within a time range, the Model will determine which, if any, of the recurring events fall within that range. Modifications made to a recurring event will affect all instances of that event.

The **Controller** will keep a local representation of requested data in memory. This data will be stored in a binary tree structure, sorted by start time. This will allow the Controller to quickly search through the events, iterate through the events, and add new events. Each event will be given a new unique ID independent of its database ID through which it can be later identified. This in-memory representation of the events allows events to be modified quickly without needing to interact with the database every time a change is made. When new data is requested by the View, the Controller will first verify if it already has the data in-memory, otherwise it will make a request to the Model to retrieve the necessary data from the database to be stored in-memory. The controller will expose 3 functions: one to request data, one for passing changes to a single event, and one for initiating a save action. The first function allows the View to request all events within a specified timeframe, and provides arguments for filtering by category or priority. The controller will return an ordered list of events that match the given filters, sorted by start time. The second function provides the View with the ability to send one event's information back to the Controller. This represents either a new event created by the user or an existing event that has been edited. If it is a new event, the Controller will add it to its event tree. Otherwise, the controller will use the event's unique ID to identify it in the tree to be updated. In either case, the unique ID is returned to the View. Finally, the View may intitiate a save action through the Controller's third function. The Controller will then select any new or updated events to be passed to the Model's second function, where they will be added to the database.

The **View** will handle displaying the locally stored data to the user through the GUI and also requesting any new data from the Controller should it need to be displayed. The initial window shows current week view and it comes with PREV and NEXT buttons to move the calendar backward and forward. For each click on either button, it will change a week at a time. A specific week selection functionality is to be incorporated by the GUI prototype milestone.

![screen shot 2018-04-11 at 3 10 33 pm](https://user-images.githubusercontent.com/29620049/38645881-8e16ad64-3d9a-11e8-8ab2-6e0c0206fb66.png)

A user can enter events to be scheduled in the calendar by the ADD button. To create an event, the user clicks the ADD button and a new window pops up containing a subject input box, time selection, and date input box with an arrow button. This will display a month view through which the user can select the appropiate date. 

![screen shot 2018-04-11 at 3 03 43 pm](https://user-images.githubusercontent.com/29620049/38645668-c368f676-3d99-11e8-97c1-c2c5b17f1e77.png)

![screen shot 2018-04-11 at 3 06 09 pm](https://user-images.githubusercontent.com/29620049/38645717-ed597262-3d99-11e8-8731-d3289bbf6cb8.png)

After the user saves the event, it should be presented on the calendar in the matching time block. All events on the calendar are clickable. When the user clicks on an event, it displays a message box to allow the user to EDIT or DELETE the event. 

# 9. Risks and Mitigation
Risk|Solution
---|---
SQLite becomes unusable for our project(a critical bug is discovered, SQLite library copies are deleted and support is discontinued, etc).|We will pursue usage of another database software to rely on from the pool of comparable technologies available(PostgreSQL, MySQL, etc).
QT becomes unusable for our project(a critical bug is discovered, QT is deleted and support is discontinued, etc).|We will pursue usage of another GUI library to rely on from the pool of comparable technologies available(GTK+, FLTK, etc).
We get behind schedule and the project is due soon.|We will cut out accounting for advanced functionality and focus on only the core function.  We will increase the hours that each of us devote to the project and if need be meet on additional occasions.
Someone gets sick or dies.| We will document our work and decisions not only to assist in future maintenance but also to account for this possibility.  By having multiple system architects and developers with knowledge of the same topics we will develop redundancy for this proposed eventuality.
Database file is corrupted or tampered with.| We will provide the user with information in the user manual for making a copy of the database file.
# 10. Resources and References  
<b id="f1">1</b>: https://sqlite.org/different.html [↩](#a1)  
<b id="f2">2</b>: http://www.vertabelo.com/blog/technical-articles/again-and-again-managing-recurring-events-in-a-data-model [↩](#a2)   
<b id="f3">3</b>: https://www.sqlite.org/cintro.html [↩](#a3) 
<b id="f4">4</b>: http://doc.qt.io/qt-5/reference-overview.html [↩](#4) 

