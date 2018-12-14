#include <Event_Button.h>
#include <QTextStream>
#include <stdlib.h>
#include <Add_Window.h>
#include <QPushButton>
#include <iostream>
#include <QtAlgorithms>
#include <QMainWindow>


//Constructor
Event_Button::Event_Button(struct view_event event, class Weekly* weekly)
{
    /*@param - structure of view_event, title of event, description of event, class Weekly
     */
    this->event = event;
    this->weekly=weekly;

}

//Destructor
Event_Button::~Event_Button()
{
    //Delete list of buttons
    qDeleteAll(buttons.begin(), buttons.end());
    buttons.clear();
}

void Event_Button::SetList(QList<QPushButton *> buttons){
    /*Set list of buttons
     * @param - list of QPushButtons
     */
    this->buttons = buttons;
}

void Event_Button::button_pressed()
{
    /* When event Button is clicked, open add_window containing information of the event that has been clicked
     */
    Add_Window *add_window = new Add_Window(event, weekly);

    //When a user edits and saves an event, call NewButton() from Weekly create new event button
    connect(add_window, &Add_Window::saved, weekly, &Weekly::NewButton);

    //When a user deletes an event, call deleteButton() from Weekly to delete event button
    connect(add_window, &Add_Window::deleted, weekly, &Weekly::deleteButton);
    //When a user close add_window, call get_date() from Weekly to refresh weekly calendar
	connect(add_window, &Add_Window::closed, weekly, &Weekly::get_date);
    //Show add_window
    add_window->show();

    //emits removed()
    emit removed();
}
