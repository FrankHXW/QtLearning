/********************************************************************************
** Form generated from reading UI file 'learning1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNING1_H
#define UI_LEARNING1_H

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

class Ui_learning1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *learning1Class)
    {
        if (learning1Class->objectName().isEmpty())
            learning1Class->setObjectName(QStringLiteral("learning1Class"));
        learning1Class->resize(600, 400);
        menuBar = new QMenuBar(learning1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        learning1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(learning1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        learning1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(learning1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        learning1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(learning1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        learning1Class->setStatusBar(statusBar);

        retranslateUi(learning1Class);

        QMetaObject::connectSlotsByName(learning1Class);
    } // setupUi

    void retranslateUi(QMainWindow *learning1Class)
    {
        learning1Class->setWindowTitle(QApplication::translate("learning1Class", "learning1", 0));
    } // retranslateUi

};

namespace Ui {
    class learning1Class: public Ui_learning1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNING1_H
