#include <Weekly.h>
#include <ui_Weekly.h>
#include <iostream>
#include <QtAlgorithms>
#include <ctime>
#include <QtWidgets>

Weekly::Weekly(QWidget *parent) : QDialog(parent), ui(new Ui::Weekly)
{
    ui->setupUi(this);
    //Call get_date() every time the date at the top of the window is changed.
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &Weekly::get_date);
    //Call open_add_window() when the Add button is clicked.
    connect(ui->Add_Button, &QPushButton::clicked, this, &Weekly::open_add_window);
    //Call backupToCSV() when the Backup button is clicked.
    connect(ui->Export_Button, &QPushButton::clicked, this, &Weekly::backupToCSV);
    //Call setToday() when the Today button is clicked.
    connect(ui->Today_Button, &QPushButton::released, this, &Weekly::setToday);
    //Set the date input to today's date.
    ui->dateEdit->setDate(QDate::currentDate());
}

Weekly::~Weekly()
{
    delete ui;
}

QDateTime Weekly::get_prev_Sunday(QDateTime date){
    /*Get previous Sunday date
     * @param - a date chosen by user
     * returns previous sunday date
     */
    QDate Ddate = date.date();
    return date.addDays(-(Ddate.dayOfWeek() % 7));
}

struct tm Weekly::QDate_to_tm(QDateTime Ddate){
    /*convert type of date from QDate to struct tm
     * @param - QDateTime
     * returns struct_tm
     */

    struct tm new_date;
    QDate d = Ddate.date();
    new_date.tm_year = d.year() - 1900;
    new_date.tm_mon = d.month() -1;
    new_date.tm_mday = d.day();
    QTime t = Ddate.time();
    new_date.tm_hour = t.hour();
    new_date.tm_min = t.minute();
    new_date.tm_sec = t.second();

    return new_date;
}

void Weekly::get_date(){
    /*Get current week dates and get events of the week from controller that are in database.
     */

    //get time from dateEdit box
    QDateTime Ddate = QDateTime(ui->dateEdit->date());

    //get previous sunday date of Ddate
    prev_sun = get_prev_Sunday(Ddate);
    //delete events that are not in current week
    qDeleteAll(events.begin(), events.end());
    events.clear();
    //display date/day to header of the calendar
    set_month_days(prev_sun.date());

    //Get next sunday date
    QDateTime next_sun = prev_sun.addDays(7);

    //Convert Ddate to struct tm
    struct tm start = QDate_to_tm(prev_sun);
    struct tm end = QDate_to_tm(next_sun);

    //From Controller, get events from prev_Sunday to Saturday and create buttons of the events
    std::vector<struct view_event> new_events = controller.get_events(&start, &end);
    for (std::vector<struct view_event>::iterator it = new_events.begin(); it != new_events.end(); it++){
        struct view_event e = *it;
        createButton(e);
    }
}

void Weekly::NewButton()
{
    /*When add_window emits signal named released() from save_button, NewButton() is executed.
     * Add an event to the view structure by calling edit_event() from controller.
     * It will check whether the event conflicts with other events before creating.
     */
    Add_Window *w = (Add_Window*)sender();
	struct view_event edited_event = w->view;
    QString error_message;
    bool error = false;
    //Limit name, category, description length
    if (edited_event.name.size() >= 1 && edited_event.name.size() <= 30 && edited_event.category.size() <= 50 && edited_event.description.size() <= 300){
        view_list overlapping_events = controller.get_events(&(edited_event.start), &(edited_event.end));
        //Check if an event already exists.
        //If not, add an event and update to controller
        if (overlapping_events.size() == 0 || (overlapping_events.size() == 1 && overlapping_events[0].controller_id == edited_event.controller_id)) {
            controller.edit_event(edited_event);
            QDateTime event_start = tm_to_QDate(edited_event.start);
            QDateTime event_end = tm_to_QDate(edited_event.end);
            QDateTime week_start = this->prev_sun;
            QDateTime week_end = week_start.addDays(7);
            get_date();
        //If there exists, error message pops up
        } else {
            error = true;
            error_message = "You have a previous event during this time interval.";
        }
    //If a user types in name, category, description more than their limit
    } else {
        error = true;
        error_message = "Names must have between 1 and 30 characters, categories must have 50 characters or fewer, and descriptions must have 300 characters or fewer.";
    }
    //If error is true, message box pops up and add_window will reopen
    if (error){
        QMessageBox messageBox;
        messageBox.critical(0, "Invalid Event", error_message);
        messageBox.setFixedSize(500, 200);
        //reopen add_widnow
        Add_Window *new_window = new Add_Window(edited_event, this);
        new_window->show();
        //Call NewButton() when add_window emits saved() signal
        connect(new_window, &Add_Window::saved, this, &Weekly::NewButton);
        //Call deleteButton() when add_window emits deleted() signal
        connect(new_window, &Add_Window::deleted, this, &Weekly::deleteButton);
        //Call date_date() when add_window emits closed() signal
        connect(new_window, &Add_Window::closed, this, &Weekly::get_date);
    }
}

void Weekly::setToday()
{
    /*Get current date and display to dateEdit box.
     */
    ui->dateEdit->setDate(QDate::currentDate());
    //display events of current week
    get_date();
}

void Weekly::backupToCSV()
{
    /*Call export_to_csv() to save all modifications from view to controller to database
     */
    controller.export_to_csv();
    get_date();
}

void Weekly::closeEvent(QCloseEvent * e)
{
    /*Check for user to save all changes or not
     */
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Changes", "Would you like to save your changes?", QMessageBox::Yes|QMessageBox::No);
    //If user selects 'Yes', save all changes to controller
    if (reply == QMessageBox::Yes) {
        this->controller.save();
    }
}

void Weekly::deleteButton()
{
    /* Deletes events and updates to controller
     */
    Add_Window *w = (Add_Window*)sender();
    //Update deleted events to controller
    controller.edit_event(w->view);
}

void Weekly::removeEventButton()
{
    /*Remove Event_button that has been clicked
     */
    Event_Button *e = (Event_Button*)sender();
    this->events.removeOne(e);
    delete e;
}

void Weekly::createButton(struct view_event event)
{
    /*Create Button as requested from add_window class
     *@param - structure of view_event, name of event, description of event
     */
    QDateTime curr_start = tm_to_QDate(event.start);
    if (curr_start < this->prev_sun)
        curr_start = this->prev_sun;
    QDateTime curr_end = tm_to_QDate(event.end);
    if (curr_end > this->prev_sun.addDays(7))
        curr_end = this->prev_sun.addDays(7);

    //Create list of buttons
    QList<QPushButton *> buttons;
    //Create Event_Button object
    Event_Button *event_button = new Event_Button(event, this);
    //If start and end time of the event is not equal
    while(curr_start < curr_end){
        QDateTime next_end = curr_end;
        if (next_end.date() != curr_start.date()){
            //Increments next_end by 1
            next_end = curr_start.addDays(1);
            //Set time to midnight to display event from 12AM to end of event
            next_end.setTime(QTime(0,0)); //Midnight
        }
        //Button size and position
        int start = curr_start.time().hour() * 4 + curr_start.time().minute()/15;
        int end = next_end.time().hour() * 4 + next_end.time().minute()/15;
        if (end == 0){
            end = 24*4;
        }
        int wday = curr_start.date().dayOfWeek() % 7;

        curr_start = next_end;

        QHBoxLayout *L = new QHBoxLayout();
        //add Button to EventsLayout
        ui->EventsLayout->addLayout(L,1+start,/*x*/2+wday,/*height*/end-start,/*width*/1);
        //Create event button
        QPushButton *button = new QPushButton(this);
        //Set button text
        button->setText(QString::fromStdString(event.name));
        //m_button->setGeometry(QRect(ui->SunGrid->pos(),QSize(ui->SunGrid->size().width(), 100)));

        //If the evnet is not priority, set color to rgb(216,108,112)
        if(event.priority != 0){
            button->setStyleSheet("background-color: rgb(216,108,112)");
        //If it is priority, set color to rgb(190,223,228)
        }else{
            button->setStyleSheet("background-color: rgb(190,223,228)");
        }
        button->setMinimumHeight(1);
        L->addWidget(button);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button->show();

        //When created button clicked, call button_pressed() from Event_Button class
        //to open add_window with the event information
        connect(button, &QPushButton::clicked, event_button, &Event_Button::button_pressed);

        //When it gets signal named removed() from Event_Button class, call removeEventButton() to remove event button
        connect(event_button, &Event_Button::removed, this, &Weekly::removeEventButton);

        //Store button to list of buttons
        buttons.append(button);
    }
    event_button->SetList(buttons);
    events.append(event_button);
}

void Weekly::set_month_days(QDate monday){
    /*Display current week date
     * @param - previous Sunday
     */

    QDate curr = monday;
    //Add ui labels into list
    QLabel *labels[7] = {ui->Sunday, ui->Monday, ui->Tuedsay, ui->Wednesday, ui->Thursday, ui->Friday, ui->Saturday};
    //Set text format
    labels[0]->setText(curr.toString("MMM d\nddd"));
    labels[0]->setAlignment(Qt::AlignCenter);
    int start_month = curr.month();
    int start_year = curr.year();
    curr = curr.addDays(1);
    for(int i=1; i<7; i++){
        //If the year of curr is not same as start_year, display yyy/MMM/d/ddd
        if (curr.year() != start_year){
            labels[i]->setText(curr.toString("yyyy\nMMM d\nddd"));
            start_year = curr.year();
            start_month = curr.month();
        }
        //If the month of curr is not same as start_month, display MMM/d/ddd
        else if (curr.month() != start_month){
            labels[i]->setText(curr.toString("MMM d\nddd"));
            start_month = curr.month();
        //Otherwise, display d/ddd
        }else{
            labels[i]->setText(curr.toString("d\nddd"));
        }
        labels[i]->setAlignment(Qt::AlignCenter);
        curr = curr.addDays(1);
    }
}

void Weekly::on_Next_Button_clicked()
{
    /*As Next_Button is clicked, the dates in calendar header shows next week of current week
     */
    ui->dateEdit->setDate(ui->dateEdit->date().addDays(7));
}

void Weekly::on_Prev_Button_clicked()
{
    /*As Prev_Button is clicked, the dates in calendar header shows last week of current week
     */
    ui->dateEdit->setDate(ui->dateEdit->date().addDays(-7));
}

void Weekly::open_add_window()
{
    /*When add_button is clicked, open new add_window
     */
	struct view_event new_event;
	QDateTime start_date;
	QDateTime end_date;
	start_date.setDate(QDate::currentDate());

	end_date = start_date;
	end_date.setTime(QTime(0, 15, 0));
    //convert start_date from QDate to struct_tm
	struct tm start_tm = QDate_to_tm(start_date);
	struct tm end_tm = QDate_to_tm(end_date);
	new_event.start = start_tm;

    //show new add_window
	new_event.end = end_tm;
    add_window = new Add_Window(new_event, this);
    add_window->show();

    //Call NewButton() when add_window emits saved() signal
    connect(add_window, &Add_Window::saved, this, &Weekly::NewButton);
    //Call deleteButton when add_window emits deleted() signal
    connect(add_window, &Add_Window::deleted, this, &Weekly::deleteButton);
    //Call get_date() when add_window emits closed() signal
	connect(add_window, &Add_Window::closed, this, &Weekly::get_date);
}

void Weekly::on_Save_Button_released()
{
    /*Request to save all changed events to controller before quit the application
     */
    this->controller.save();
    this->get_date();
}
