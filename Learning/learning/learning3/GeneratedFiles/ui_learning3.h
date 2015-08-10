/********************************************************************************
** Form generated from reading UI file 'learning3.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNING3_H
#define UI_LEARNING3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_learning3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *learning3Class)
    {
        if (learning3Class->objectName().isEmpty())
            learning3Class->setObjectName(QStringLiteral("learning3Class"));
        learning3Class->resize(600, 400);
        menuBar = new QMenuBar(learning3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        learning3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(learning3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        learning3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(learning3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        learning3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(learning3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        learning3Class->setStatusBar(statusBar);

        retranslateUi(learning3Class);

        QMetaObject::connectSlotsByName(learning3Class);
    } // setupUi

    void retranslateUi(QMainWindow *learning3Class)
    {
        learning3Class->setWindowTitle(QApplication::translate("learning3Class", "learning3", 0));
    } // retranslateUi

};

namespace Ui {
    class learning3Class: public Ui_learning3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNING3_H
