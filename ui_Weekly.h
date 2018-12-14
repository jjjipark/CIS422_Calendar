/********************************************************************************
** Form generated from reading UI file 'Weekly.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKLY_H
#define UI_WEEKLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Weekly
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *Prev_Button;
    QPushButton *Next_Button;
    QGridLayout *EventsLayout;
    QLabel *label_2;
    QLabel *label_0;
    QLabel *Sunday;
    QLabel *Saturday;
    QLabel *label_3;
    QLabel *label_62;
    QLabel *label_82;
    QLabel *label_86;
    QLabel *label_74;
    QLabel *label_78;
    QLabel *label_58;
    QLabel *label_70;
    QLabel *label_66;
    QLabel *label_7;
    QLabel *label_19;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_30;
    QLabel *Monday;
    QLabel *Wednesday;
    QLabel *Friday;
    QLabel *Tuedsay;
    QLabel *Thursday;
    QLabel *label_24;
    QLabel *label_50;
    QLabel *label_54;
    QLabel *label_31;
    QLabel *label_46;
    QLabel *label_4;
    QLabel *label_42;
    QLabel *label_38;
    QDateEdit *dateEdit;
    QPushButton *Export_Button;
    QPushButton *Save_Button;
    QPushButton *Today_Button;
    QPushButton *Add_Button;

    void setupUi(QDialog *Weekly)
    {
        if (Weekly->objectName().isEmpty())
            Weekly->setObjectName(QStringLiteral("Weekly"));
        Weekly->resize(984, 555);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Weekly->sizePolicy().hasHeightForWidth());
        Weekly->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(Weekly);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        Prev_Button = new QPushButton(Weekly);
        Prev_Button->setObjectName(QStringLiteral("Prev_Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Prev_Button->sizePolicy().hasHeightForWidth());
        Prev_Button->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Prev_Button, 6, 1, 1, 1);

        Next_Button = new QPushButton(Weekly);
        Next_Button->setObjectName(QStringLiteral("Next_Button"));
        sizePolicy1.setHeightForWidth(Next_Button->sizePolicy().hasHeightForWidth());
        Next_Button->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Next_Button, 6, 5, 1, 1);

        EventsLayout = new QGridLayout();
        EventsLayout->setSpacing(0);
        EventsLayout->setObjectName(QStringLiteral("EventsLayout"));
        EventsLayout->setSizeConstraint(QLayout::SetMaximumSize);
        EventsLayout->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(Weekly);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(31, 0));
        label_2->setBaseSize(QSize(31, 0));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_2, 9, 1, 4, 1);

        label_0 = new QLabel(Weekly);
        label_0->setObjectName(QStringLiteral("label_0"));
        sizePolicy2.setHeightForWidth(label_0->sizePolicy().hasHeightForWidth());
        label_0->setSizePolicy(sizePolicy2);
        label_0->setMinimumSize(QSize(31, 0));
        label_0->setBaseSize(QSize(31, 0));
        label_0->setScaledContents(false);
        label_0->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_0, 1, 1, 4, 1);

        Sunday = new QLabel(Weekly);
        Sunday->setObjectName(QStringLiteral("Sunday"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Sunday->sizePolicy().hasHeightForWidth());
        Sunday->setSizePolicy(sizePolicy3);
        Sunday->setMinimumSize(QSize(50, 0));

        EventsLayout->addWidget(Sunday, 0, 2, 1, 1);

        Saturday = new QLabel(Weekly);
        Saturday->setObjectName(QStringLiteral("Saturday"));
        sizePolicy3.setHeightForWidth(Saturday->sizePolicy().hasHeightForWidth());
        Saturday->setSizePolicy(sizePolicy3);

        EventsLayout->addWidget(Saturday, 0, 8, 1, 1);

        label_3 = new QLabel(Weekly);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(31, 0));
        label_3->setBaseSize(QSize(31, 0));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_3, 13, 1, 4, 1);

        label_62 = new QLabel(Weekly);
        label_62->setObjectName(QStringLiteral("label_62"));
        sizePolicy2.setHeightForWidth(label_62->sizePolicy().hasHeightForWidth());
        label_62->setSizePolicy(sizePolicy2);
        label_62->setMinimumSize(QSize(31, 0));
        label_62->setBaseSize(QSize(31, 0));
        label_62->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_62, 69, 1, 4, 1);

        label_82 = new QLabel(Weekly);
        label_82->setObjectName(QStringLiteral("label_82"));
        sizePolicy2.setHeightForWidth(label_82->sizePolicy().hasHeightForWidth());
        label_82->setSizePolicy(sizePolicy2);
        label_82->setMinimumSize(QSize(31, 0));
        label_82->setBaseSize(QSize(31, 0));
        label_82->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_82, 89, 1, 4, 1);

        label_86 = new QLabel(Weekly);
        label_86->setObjectName(QStringLiteral("label_86"));
        sizePolicy2.setHeightForWidth(label_86->sizePolicy().hasHeightForWidth());
        label_86->setSizePolicy(sizePolicy2);
        label_86->setMinimumSize(QSize(31, 0));
        label_86->setBaseSize(QSize(31, 0));
        label_86->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_86, 93, 1, 4, 1);

        label_74 = new QLabel(Weekly);
        label_74->setObjectName(QStringLiteral("label_74"));
        sizePolicy2.setHeightForWidth(label_74->sizePolicy().hasHeightForWidth());
        label_74->setSizePolicy(sizePolicy2);
        label_74->setMinimumSize(QSize(31, 0));
        label_74->setBaseSize(QSize(31, 0));
        label_74->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_74, 81, 1, 4, 1);

        label_78 = new QLabel(Weekly);
        label_78->setObjectName(QStringLiteral("label_78"));
        sizePolicy2.setHeightForWidth(label_78->sizePolicy().hasHeightForWidth());
        label_78->setSizePolicy(sizePolicy2);
        label_78->setMinimumSize(QSize(31, 0));
        label_78->setBaseSize(QSize(31, 0));
        label_78->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_78, 85, 1, 4, 1);

        label_58 = new QLabel(Weekly);
        label_58->setObjectName(QStringLiteral("label_58"));
        sizePolicy2.setHeightForWidth(label_58->sizePolicy().hasHeightForWidth());
        label_58->setSizePolicy(sizePolicy2);
        label_58->setMinimumSize(QSize(31, 0));
        label_58->setBaseSize(QSize(31, 0));
        label_58->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_58, 65, 1, 4, 1);

        label_70 = new QLabel(Weekly);
        label_70->setObjectName(QStringLiteral("label_70"));
        sizePolicy2.setHeightForWidth(label_70->sizePolicy().hasHeightForWidth());
        label_70->setSizePolicy(sizePolicy2);
        label_70->setMinimumSize(QSize(31, 0));
        label_70->setBaseSize(QSize(31, 0));
        label_70->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_70, 77, 1, 4, 1);

        label_66 = new QLabel(Weekly);
        label_66->setObjectName(QStringLiteral("label_66"));
        sizePolicy2.setHeightForWidth(label_66->sizePolicy().hasHeightForWidth());
        label_66->setSizePolicy(sizePolicy2);
        label_66->setMinimumSize(QSize(31, 0));
        label_66->setBaseSize(QSize(31, 0));
        label_66->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_66, 73, 1, 4, 1);

        label_7 = new QLabel(Weekly);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(31, 0));
        label_7->setBaseSize(QSize(31, 0));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_7, 21, 1, 4, 1);

        label_19 = new QLabel(Weekly);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);
        label_19->setMinimumSize(QSize(31, 0));
        label_19->setBaseSize(QSize(31, 0));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_19, 33, 1, 4, 1);

        label_11 = new QLabel(Weekly);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setMinimumSize(QSize(31, 0));
        label_11->setBaseSize(QSize(31, 0));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_11, 25, 1, 4, 1);

        label_15 = new QLabel(Weekly);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setMinimumSize(QSize(31, 0));
        label_15->setBaseSize(QSize(31, 0));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_15, 29, 1, 4, 1);

        label_30 = new QLabel(Weekly);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy2.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy2);
        label_30->setMinimumSize(QSize(31, 0));
        label_30->setBaseSize(QSize(31, 0));
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_30, 37, 1, 4, 1);

        Monday = new QLabel(Weekly);
        Monday->setObjectName(QStringLiteral("Monday"));
        sizePolicy3.setHeightForWidth(Monday->sizePolicy().hasHeightForWidth());
        Monday->setSizePolicy(sizePolicy3);

        EventsLayout->addWidget(Monday, 0, 3, 1, 1);

        Wednesday = new QLabel(Weekly);
        Wednesday->setObjectName(QStringLiteral("Wednesday"));
        sizePolicy3.setHeightForWidth(Wednesday->sizePolicy().hasHeightForWidth());
        Wednesday->setSizePolicy(sizePolicy3);

        EventsLayout->addWidget(Wednesday, 0, 5, 1, 1);

        Friday = new QLabel(Weekly);
        Friday->setObjectName(QStringLiteral("Friday"));
        sizePolicy3.setHeightForWidth(Friday->sizePolicy().hasHeightForWidth());
        Friday->setSizePolicy(sizePolicy3);

        EventsLayout->addWidget(Friday, 0, 7, 1, 1);

        Tuedsay = new QLabel(Weekly);
        Tuedsay->setObjectName(QStringLiteral("Tuedsay"));
        sizePolicy3.setHeightForWidth(Tuedsay->sizePolicy().hasHeightForWidth());
        Tuedsay->setSizePolicy(sizePolicy3);

        EventsLayout->addWidget(Tuedsay, 0, 4, 1, 1);

        Thursday = new QLabel(Weekly);
        Thursday->setObjectName(QStringLiteral("Thursday"));
        sizePolicy3.setHeightForWidth(Thursday->sizePolicy().hasHeightForWidth());
        Thursday->setSizePolicy(sizePolicy3);

        EventsLayout->addWidget(Thursday, 0, 6, 1, 1);

        label_24 = new QLabel(Weekly);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy2.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy2);
        label_24->setMinimumSize(QSize(31, 0));
        label_24->setBaseSize(QSize(31, 0));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_24, 5, 1, 4, 1);

        label_50 = new QLabel(Weekly);
        label_50->setObjectName(QStringLiteral("label_50"));
        sizePolicy2.setHeightForWidth(label_50->sizePolicy().hasHeightForWidth());
        label_50->setSizePolicy(sizePolicy2);
        label_50->setMinimumSize(QSize(31, 0));
        label_50->setBaseSize(QSize(31, 0));
        label_50->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_50, 57, 1, 4, 1);

        label_54 = new QLabel(Weekly);
        label_54->setObjectName(QStringLiteral("label_54"));
        sizePolicy2.setHeightForWidth(label_54->sizePolicy().hasHeightForWidth());
        label_54->setSizePolicy(sizePolicy2);
        label_54->setMinimumSize(QSize(31, 0));
        label_54->setBaseSize(QSize(31, 0));
        label_54->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_54, 61, 1, 4, 1);

        label_31 = new QLabel(Weekly);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy2.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy2);
        label_31->setMinimumSize(QSize(31, 0));
        label_31->setBaseSize(QSize(31, 0));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_31, 41, 1, 4, 1);

        label_46 = new QLabel(Weekly);
        label_46->setObjectName(QStringLiteral("label_46"));
        sizePolicy2.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy2);
        label_46->setMinimumSize(QSize(31, 0));
        label_46->setBaseSize(QSize(31, 0));
        label_46->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_46, 53, 1, 4, 1);

        label_4 = new QLabel(Weekly);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(31, 0));
        label_4->setBaseSize(QSize(31, 0));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_4, 17, 1, 4, 1);

        label_42 = new QLabel(Weekly);
        label_42->setObjectName(QStringLiteral("label_42"));
        sizePolicy2.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy2);
        label_42->setMinimumSize(QSize(31, 0));
        label_42->setBaseSize(QSize(31, 0));
        label_42->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_42, 49, 1, 4, 1);

        label_38 = new QLabel(Weekly);
        label_38->setObjectName(QStringLiteral("label_38"));
        sizePolicy2.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy2);
        label_38->setMinimumSize(QSize(31, 0));
        label_38->setBaseSize(QSize(31, 0));
        label_38->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        EventsLayout->addWidget(label_38, 45, 1, 4, 1);

        EventsLayout->setRowStretch(0, 1);
        EventsLayout->setRowStretch(1, 1);
        EventsLayout->setRowStretch(2, 1);
        EventsLayout->setRowStretch(3, 1);
        EventsLayout->setRowStretch(4, 1);
        EventsLayout->setRowStretch(5, 1);
        EventsLayout->setRowStretch(6, 1);
        EventsLayout->setRowStretch(7, 1);
        EventsLayout->setRowStretch(8, 1);
        EventsLayout->setRowStretch(9, 1);
        EventsLayout->setRowStretch(10, 1);
        EventsLayout->setRowStretch(11, 1);
        EventsLayout->setRowStretch(12, 1);
        EventsLayout->setRowStretch(13, 1);
        EventsLayout->setRowStretch(14, 1);
        EventsLayout->setRowStretch(15, 1);
        EventsLayout->setRowStretch(16, 1);
        EventsLayout->setRowStretch(17, 1);
        EventsLayout->setRowStretch(18, 1);
        EventsLayout->setRowStretch(19, 1);
        EventsLayout->setRowStretch(20, 1);
        EventsLayout->setRowStretch(21, 1);
        EventsLayout->setRowStretch(22, 1);
        EventsLayout->setRowStretch(23, 1);
        EventsLayout->setRowStretch(24, 1);
        EventsLayout->setRowStretch(25, 1);
        EventsLayout->setRowStretch(26, 1);
        EventsLayout->setRowStretch(27, 1);
        EventsLayout->setRowStretch(28, 1);
        EventsLayout->setRowStretch(29, 1);
        EventsLayout->setRowStretch(30, 1);
        EventsLayout->setRowStretch(31, 1);
        EventsLayout->setRowStretch(32, 1);
        EventsLayout->setRowStretch(33, 1);
        EventsLayout->setRowStretch(34, 1);
        EventsLayout->setRowStretch(35, 1);
        EventsLayout->setRowStretch(36, 1);
        EventsLayout->setRowStretch(37, 1);
        EventsLayout->setRowStretch(38, 1);
        EventsLayout->setRowStretch(39, 1);
        EventsLayout->setRowStretch(40, 1);
        EventsLayout->setRowStretch(41, 1);
        EventsLayout->setRowStretch(42, 1);
        EventsLayout->setRowStretch(43, 1);
        EventsLayout->setRowStretch(44, 1);
        EventsLayout->setRowStretch(45, 1);
        EventsLayout->setRowStretch(46, 1);
        EventsLayout->setRowStretch(47, 1);
        EventsLayout->setRowStretch(48, 1);
        EventsLayout->setRowStretch(49, 1);
        EventsLayout->setRowStretch(50, 1);
        EventsLayout->setRowStretch(51, 1);
        EventsLayout->setRowStretch(52, 1);
        EventsLayout->setRowStretch(53, 1);
        EventsLayout->setRowStretch(54, 1);
        EventsLayout->setRowStretch(55, 1);
        EventsLayout->setRowStretch(56, 1);
        EventsLayout->setRowStretch(57, 1);
        EventsLayout->setRowStretch(58, 1);
        EventsLayout->setRowStretch(59, 1);
        EventsLayout->setRowStretch(60, 1);
        EventsLayout->setRowStretch(61, 1);
        EventsLayout->setRowStretch(62, 1);
        EventsLayout->setRowStretch(63, 1);
        EventsLayout->setRowStretch(64, 1);
        EventsLayout->setRowStretch(65, 1);
        EventsLayout->setRowStretch(66, 1);
        EventsLayout->setRowStretch(67, 1);
        EventsLayout->setRowStretch(68, 1);
        EventsLayout->setRowStretch(69, 1);
        EventsLayout->setRowStretch(70, 1);
        EventsLayout->setRowStretch(71, 1);
        EventsLayout->setRowStretch(72, 1);
        EventsLayout->setRowStretch(73, 1);
        EventsLayout->setRowStretch(74, 1);
        EventsLayout->setRowStretch(75, 1);
        EventsLayout->setRowStretch(76, 1);
        EventsLayout->setRowStretch(77, 1);
        EventsLayout->setRowStretch(78, 1);
        EventsLayout->setRowStretch(79, 1);
        EventsLayout->setRowStretch(80, 1);
        EventsLayout->setRowStretch(81, 1);
        EventsLayout->setRowStretch(82, 1);
        EventsLayout->setRowStretch(83, 1);
        EventsLayout->setRowStretch(84, 1);
        EventsLayout->setRowStretch(85, 1);
        EventsLayout->setRowStretch(86, 1);
        EventsLayout->setRowStretch(87, 1);
        EventsLayout->setRowStretch(88, 1);
        EventsLayout->setRowStretch(89, 1);
        EventsLayout->setRowStretch(90, 1);
        EventsLayout->setRowStretch(91, 1);
        EventsLayout->setRowStretch(92, 1);
        EventsLayout->setRowStretch(93, 1);
        EventsLayout->setRowStretch(94, 1);
        EventsLayout->setRowStretch(95, 1);
        EventsLayout->setRowStretch(96, 1);

        gridLayout->addLayout(EventsLayout, 7, 1, 1, 5);

        dateEdit = new QDateEdit(Weekly);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        dateEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dateEdit, 4, 3, 3, 1);

        Export_Button = new QPushButton(Weekly);
        Export_Button->setObjectName(QStringLiteral("Export_Button"));

        gridLayout->addWidget(Export_Button, 5, 5, 1, 1);

        Save_Button = new QPushButton(Weekly);
        Save_Button->setObjectName(QStringLiteral("Save_Button"));
        sizePolicy1.setHeightForWidth(Save_Button->sizePolicy().hasHeightForWidth());
        Save_Button->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Save_Button, 4, 5, 1, 1);

        Today_Button = new QPushButton(Weekly);
        Today_Button->setObjectName(QStringLiteral("Today_Button"));

        gridLayout->addWidget(Today_Button, 5, 1, 1, 1);

        Add_Button = new QPushButton(Weekly);
        Add_Button->setObjectName(QStringLiteral("Add_Button"));
        sizePolicy1.setHeightForWidth(Add_Button->sizePolicy().hasHeightForWidth());
        Add_Button->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Add_Button, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Weekly);

        QMetaObject::connectSlotsByName(Weekly);
    } // setupUi

    void retranslateUi(QDialog *Weekly)
    {
        Weekly->setWindowTitle(QApplication::translate("Weekly", "Dialog", nullptr));
        Prev_Button->setText(QApplication::translate("Weekly", "Prev", nullptr));
        Next_Button->setText(QApplication::translate("Weekly", "Next", nullptr));
        label_2->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">2 AM</p></body></html>", nullptr));
        label_0->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">12 AM</p></body></html>", nullptr));
        Sunday->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        Saturday->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">3 AM</p></body></html>", nullptr));
        label_62->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">5 PM</p></body></html>", nullptr));
        label_82->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">10 PM</p></body></html>", nullptr));
        label_86->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">11 PM</p></body></html>", nullptr));
        label_74->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">8 PM</p></body></html>", nullptr));
        label_78->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">9 PM</p></body></html>", nullptr));
        label_58->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">4 PM</p></body></html>", nullptr));
        label_70->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">7 PM</p></body></html>", nullptr));
        label_66->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">6 PM</p></body></html>", nullptr));
        label_7->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">5 AM</p></body></html>", nullptr));
        label_19->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">8 AM</p></body></html>", nullptr));
        label_11->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">6 AM</p></body></html>", nullptr));
        label_15->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">7 AM</p></body></html>", nullptr));
        label_30->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">9 AM</p></body></html>", nullptr));
        Monday->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        Wednesday->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        Friday->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        Tuedsay->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        Thursday->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label_24->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">1 AM</p></body></html>", nullptr));
        label_50->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">2 PM</p></body></html>", nullptr));
        label_54->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">3 PM</p></body></html>", nullptr));
        label_31->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">10 AM</p></body></html>", nullptr));
        label_46->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">1 PM</p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">4 AM</p></body></html>", nullptr));
        label_42->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">12 PM</p></body></html>", nullptr));
        label_38->setText(QApplication::translate("Weekly", "<html><head/><body><p align=\"right\">11 AM</p></body></html>", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("Weekly", "dd/MM/yyyy", nullptr));
        Export_Button->setText(QApplication::translate("Weekly", "Export", nullptr));
        Save_Button->setText(QApplication::translate("Weekly", "Save", nullptr));
        Today_Button->setText(QApplication::translate("Weekly", "Today", nullptr));
        Add_Button->setText(QApplication::translate("Weekly", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Weekly: public Ui_Weekly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKLY_H
