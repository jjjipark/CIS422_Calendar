/********************************************************************************
** Form generated from reading UI file 'Add_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_WINDOW_H
#define UI_ADD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_Window
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QDateTimeEdit *dateTimeEnd;
    QLineEdit *categoryEdit;
    QDateTimeEdit *dateTimeStart;
    QLabel *label;
    QPlainTextEdit *text_Description;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *delete_button;
    QCheckBox *priority_box;
    QPushButton *save_button;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Add_Window)
    {
        if (Add_Window->objectName().isEmpty())
            Add_Window->setObjectName(QStringLiteral("Add_Window"));
        Add_Window->resize(585, 474);
        centralWidget = new QWidget(Add_Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout_2->addWidget(nameEdit, 0, 2, 1, 1);

        dateTimeEnd = new QDateTimeEdit(centralWidget);
        dateTimeEnd->setObjectName(QStringLiteral("dateTimeEnd"));

        gridLayout_2->addWidget(dateTimeEnd, 3, 2, 1, 1);

        categoryEdit = new QLineEdit(centralWidget);
        categoryEdit->setObjectName(QStringLiteral("categoryEdit"));

        gridLayout_2->addWidget(categoryEdit, 1, 2, 1, 1);

        dateTimeStart = new QDateTimeEdit(centralWidget);
        dateTimeStart->setObjectName(QStringLiteral("dateTimeStart"));

        gridLayout_2->addWidget(dateTimeStart, 2, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        text_Description = new QPlainTextEdit(centralWidget);
        text_Description->setObjectName(QStringLiteral("text_Description"));

        gridLayout_2->addWidget(text_Description, 4, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        delete_button = new QPushButton(centralWidget);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        delete_button->setStyleSheet(QStringLiteral("QPushButton {  background-color: rgb(216,108, 112)}"));

        horizontalLayout->addWidget(delete_button);

        priority_box = new QCheckBox(centralWidget);
        priority_box->setObjectName(QStringLiteral("priority_box"));
        priority_box->setEnabled(true);
        priority_box->setStyleSheet(QStringLiteral("QCheckBox{margin-left:50%; margin-right:50%;}"));
        priority_box->setChecked(false);

        horizontalLayout->addWidget(priority_box);

        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QStringLiteral("save_button"));

        horizontalLayout->addWidget(save_button);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        Add_Window->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Add_Window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Add_Window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Add_Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Add_Window->setStatusBar(statusBar);
        QWidget::setTabOrder(nameEdit, categoryEdit);
        QWidget::setTabOrder(categoryEdit, dateTimeStart);
        QWidget::setTabOrder(dateTimeStart, dateTimeEnd);
        QWidget::setTabOrder(dateTimeEnd, text_Description);
        QWidget::setTabOrder(text_Description, delete_button);
        QWidget::setTabOrder(delete_button, priority_box);
        QWidget::setTabOrder(priority_box, save_button);

        retranslateUi(Add_Window);

        QMetaObject::connectSlotsByName(Add_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Add_Window)
    {
        Add_Window->setWindowTitle(QApplication::translate("Add_Window", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("Add_Window", "Category", nullptr));
        label_4->setText(QApplication::translate("Add_Window", "End Time", nullptr));
        label_3->setText(QApplication::translate("Add_Window", "Start Time", nullptr));
        nameEdit->setText(QString());
        dateTimeEnd->setDisplayFormat(QApplication::translate("Add_Window", "dd/MM/yyyy hh:mm AP", nullptr));
        categoryEdit->setText(QString());
        dateTimeStart->setDisplayFormat(QApplication::translate("Add_Window", "dd/MM/yyyy h:mm AP", nullptr));
        label->setText(QApplication::translate("Add_Window", "Name", nullptr));
        text_Description->setPlainText(QString());
        label_5->setText(QApplication::translate("Add_Window", "Description", nullptr));
        delete_button->setText(QApplication::translate("Add_Window", "Delete", nullptr));
        priority_box->setText(QApplication::translate("Add_Window", "High Priority", nullptr));
        save_button->setText(QApplication::translate("Add_Window", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Window: public Ui_Add_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_WINDOW_H
