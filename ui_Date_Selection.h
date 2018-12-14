/********************************************************************************
** Form generated from reading UI file 'Date_Selection.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_SELECTION_H
#define UI_DATE_SELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Date_Selection
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *Date_Selection)
    {
        if (Date_Selection->objectName().isEmpty())
            Date_Selection->setObjectName(QStringLiteral("Date_Selection"));
        Date_Selection->resize(460, 333);
        gridLayoutWidget = new QWidget(Date_Selection);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 441, 312));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 2);


        retranslateUi(Date_Selection);

        QMetaObject::connectSlotsByName(Date_Selection);
    } // setupUi

    void retranslateUi(QDialog *Date_Selection)
    {
        Date_Selection->setWindowTitle(QApplication::translate("Date_Selection", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Date_Selection", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Date_Selection: public Ui_Date_Selection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_SELECTION_H
