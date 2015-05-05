/********************************************************************************
** Form generated from reading UI file 'learning2.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNING2_H
#define UI_LEARNING2_H

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

class Ui_learning2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *learning2Class)
    {
        if (learning2Class->objectName().isEmpty())
            learning2Class->setObjectName(QStringLiteral("learning2Class"));
        learning2Class->resize(600, 400);
        menuBar = new QMenuBar(learning2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        learning2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(learning2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        learning2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(learning2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        learning2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(learning2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        learning2Class->setStatusBar(statusBar);

        retranslateUi(learning2Class);

        QMetaObject::connectSlotsByName(learning2Class);
    } // setupUi

    void retranslateUi(QMainWindow *learning2Class)
    {
        learning2Class->setWindowTitle(QApplication::translate("learning2Class", "learning2", 0));
    } // retranslateUi

};

namespace Ui {
    class learning2Class: public Ui_learning2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNING2_H
