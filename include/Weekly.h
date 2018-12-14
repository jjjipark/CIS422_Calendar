#ifndef WEEKLY_H
#define WEEKLY_H

#include <QDialog>
#include <QDateTime>
#include <Add_Window.h>
#include <time.h>
#include <QPushButton>
#include <QSignalMapper>
#include <QList>
#include <Controller.hpp>
#include <QDateTime>
#include <Event_Button.h>
#include <QHBoxLayout>


namespace Ui {
class Weekly;
}

class Weekly : public QDialog
{
    Q_OBJECT

public:
    explicit Weekly(QWidget *parent = 0);
    ~Weekly();

    QDateTime get_prev_Sunday(QDateTime date);
    //QPushButton *m_button;
    Add_Window *add_window;
    QSignalMapper *signalMapper;
    QList<class Event_Button*> events;
    Controller controller;


    QDateTime prev_sun;

    struct tm QDate_to_tm(QDateTime Ddate);

signals:
    void released();
    void textChanged();

public slots:
    void open_add_window();
    void NewButton();
    void get_date();
    void deleteButton();
    void removeEventButton();
    void backupToCSV();
    void setToday();

private slots:
    void on_Next_Button_clicked();
    void on_Prev_Button_clicked();

    void set_month_days(QDate monday);

    void on_Save_Button_released();

private:
    void createButton(struct view_event event);
    void closeEvent(QCloseEvent * e);
    Ui::Weekly *ui;
};

#endif // WEEKLY_H
