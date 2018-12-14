#ifndef ADD_WINDOW_H
#define ADD_WINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDebug>
#include <QPushButton>
#include <EventStructs.hpp>
#include <QObject>

/* Add_Window class shows new add_window window to add, delete or edit an event.
 * User can define name, category, description priority, start and end time of the event.
 * Save Button saves the event and the event will be displayed on weekly calendar in matching time bock.
*/

namespace Ui {
class Add_Window;
}

class Add_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_Window(struct view_event event, QWidget *parent = 0);
    ~Add_Window();
    QPushButton *save_button;

    std::vector<struct view_event> events;
    struct view_event view;

signals:
    void deleted();
	void closed();
    void clicked();
	void saved();

private slots:
	void save_button_clicked();
	void delete_button_clicked();
	void on_dateTimeStart_dateTimeChanged (const QDateTime &dateTime);
	void on_dateTimeEnd_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::Add_Window *ui;
    struct tm QDate_to_tm(QDateTime Ddate);
	void closeEvent(QCloseEvent * e);
};

QDateTime tm_to_QDate(struct tm t);

#endif // ADD_WINDOW_H
