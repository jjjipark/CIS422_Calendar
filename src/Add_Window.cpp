#include "Add_Window.h"
#include "ui_Add_Window.h"
#include <QPushButton>
#include <QCoreApplication>
#include <string>
#include <iostream>
#include <Weekly.h>
#include <QCloseEvent>

Add_Window::Add_Window(struct view_event event, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_Window)

{
    ui->setupUi(this);

    ui->priority_box->setStyleSheet("QCheckBox { color: red }");

    //Set text_Name to event.name
	ui->nameEdit->setText(QString::fromStdString(event.name));
    //Set dateTimeStart to start time of event structure
    ui->categoryEdit->setText(QString::fromStdString(event.category));
    //Set text_Description to event.desc
    ui->text_Description->document()->setPlainText(QString::fromStdString(event.description));
    //Set dateTimeStart text box to start time of event structure
    ui->dateTimeStart->setDateTime(tm_to_QDate(event.start));
    //Set dateTimeEnd text box to end time of event structure
    ui->dateTimeEnd->setDateTime(tm_to_QDate(event.end));
    //Set priority_box to priority
    ui->priority_box->setChecked(event.priority);
	//Store a copy of the view_event locally as 'view'
    view = event;

    //Call save_button_clicked(), when save_button is released
    connect(ui->save_button, SIGNAL(released()), this, SLOT(save_button_clicked()));
    //Call delete_button_clicked(), when delete_button is released
    connect(ui->delete_button, SIGNAL(released()), this, SLOT(delete_button_clicked()));
}

QDateTime tm_to_QDate(struct tm t){
    /*convert struct tm to QDate
     * @param - tm structure
     * returns DateTime as a type of QDateTime
     */
    QDate new_date;
    new_date.setDate(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
    QTime new_time;
    new_time.setHMS(t.tm_hour, t.tm_min, t.tm_sec);
    return QDateTime(new_date, new_time);
}

Add_Window::~Add_Window()
{
    delete ui;
}

void Add_Window::closeEvent(QCloseEvent * e)
{
    emit closed();
}

void Add_Window::on_dateTimeStart_dateTimeChanged(const QDateTime &dateTime) {
    /* Let a user choose only 15 minute blocks of time [00,15,30,45].
     * When the minute user choose is not a multiple of 15,
     * it will be automatically adjusted.
     * @param - selected start_DateTime
     */

    QTime time_increment = dateTime.time();
    int minute = time_increment.minute();
    if (minute == 14 || minute == 46){
        minute = 0;
    }else if (minute == 1 || minute == 29){
        minute = 15;
    }else if (minute == 16 || minute == 44){
        minute = 30;
    }else if (minute == 31){
        minute = 45;
    }else if (minute <= 7 || minute >= 53){
        minute = 0;
    }else if (minute >= 8 && minute <= 22){
        minute = 15;
    }else if (minute >= 23 && minute <= 37){
        minute = 30;
    }else if (minute >= 38 && minute <= 52){
        minute = 45;
    }
    time_increment.setHMS(time_increment.hour(), minute, 0);
    //Set time value to dateTime box
    ui->dateTimeStart->setTime(time_increment);
    ui->dateTimeEnd->setMinimumDateTime(ui->dateTimeStart->dateTime().addSecs(15*60));
}

void Add_Window::on_dateTimeEnd_dateTimeChanged(const QDateTime &dateTime) {

    /* Let a user choose only 15 minute blocks of time[00,15,30,45].
     * When the minute user choose is not a multiple of 15,
     * it will be automatically adjusted.
     * @param - selected end_DateTime
     */

    QTime time_increment = dateTime.time();
    int minute = time_increment.minute();
    if (minute == 14 || minute == 46){
        minute = 0;
    }else if (minute == 1 || minute == 29){
        minute = 15;
    }else if (minute == 16 || minute == 44){
        minute = 30;
    }else if (minute == 31){
        minute = 45;
    }else if (minute <= 7 || minute >= 53){
        minute = 0;
    }else if (minute >= 8 && minute <= 22){
        minute = 15;
    }else if (minute >= 23 && minute <= 37){
        minute = 30;
    }else if (minute >= 38 && minute <= 52){
        minute = 45;
    }
    time_increment.setHMS(time_increment.hour(), minute, 0);
    ui->dateTimeEnd->setTime(time_increment);
    //ui->dateTimeStart->setMaximumDateTime(ui->dateTimeEnd->dateTime().addSecs(-15*60));
}

struct tm Add_Window::QDate_to_tm(QDateTime Ddate){
    /* Convert QDateTime to struct_tm
     * @param - QDateTime
     * returns dateTime as a type of struct_tm
     */
    struct tm new_date;
    QDate d = Ddate.date();
    new_date.tm_year = d.year() - 1900;
    new_date.tm_mon = d.month() -1;
    new_date.tm_mday = d.day();
    new_date.tm_wday = d.dayOfWeek();
    QTime t = Ddate.time();
    new_date.tm_hour = t.hour();
    new_date.tm_min = t.minute();
    new_date.tm_sec = t.second();

    return new_date;
}

void Add_Window::save_button_clicked()
{
    /* Recieves signal from save_button.
     */

    //Update event information to view_event structure
    this->view.start = QDate_to_tm(this->ui->dateTimeStart->dateTime());
    this->view.end = QDate_to_tm(this->ui->dateTimeEnd->dateTime());
    this->view.priority = this->ui->priority_box->checkState();
    //Get name, category, and description of the event from ui
    QString name = this->ui->nameEdit->text();
    QString category = this->ui->categoryEdit->text();
    QString description = this->ui->text_Description->toPlainText();

    //Reformat name, category, and description
    name.replace(QString("\t"), QString("    "));
    name.replace(QString("\n"), QString("\\n"));
    category.replace(QString("\t"), QString("    "));
    category.replace(QString("\n"), QString("\\n"));
    description.replace(QString("\t"), QString("    "));
    description.replace(QString("\n"), QString("\\n"));

    QString regex = "[^a-zA-Z0-9\\\\ ]";

    name.remove(QRegExp(regex));
    category.remove(QRegExp(regex));
    description.remove(QRegExp(regex));


    //Update event information to view_event structure
    this->view.name = name.toStdString();
    this->view.category = category.toStdString();
    this->view.description = description.toStdString();

    //send signal saved() when save_button is clicked
	emit saved();
    //close current add_window when save_button is clicked
    this->close();
}

void Add_Window::delete_button_clicked()
{
    /*Close add_window when a user clicks delete button
     */

    //Update deletion status to view
    view.deletion = true;
    //Send signal deleted() when delete_button is clicked
	emit deleted();
    //Close current add_window when delete_button is clicked
    this->close();
}
