#ifndef EVENTS_H
#define EVENTS_H
#include <QString>
#include <QObject>
#include <EventStructs.hpp>
#include <Weekly.h>
#include <Add_Window.h>

/*Event_Button class stores buttons of events
 */

class Event_Button: public QObject
{
    Q_OBJECT

public:
    explicit Event_Button(struct view_event event, class Weekly* weekly);
    void SetList(QList<QPushButton *> buttons);
    ~Event_Button();

public slots:
    void button_pressed();

signals:
    void removed();

private:
    QList<QPushButton *> buttons;
    struct view_event event;
    Weekly *weekly;
};

#endif // EVENTS_H
