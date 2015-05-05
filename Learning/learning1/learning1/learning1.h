#ifndef LEARNING1_H
#define LEARNING1_H

#include <QtWidgets/QMainWindow>
#include "ui_learning1.h"

class learning1 : public QMainWindow
{
	Q_OBJECT

public:
	learning1(QWidget *parent = 0);
	~learning1();

private:
	Ui::learning1Class ui;
};

#endif // LEARNING1_H
