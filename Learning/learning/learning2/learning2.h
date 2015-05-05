#ifndef LEARNING2_H
#define LEARNING2_H

#include <QtWidgets/QMainWindow>
#include "ui_learning2.h"

class learning2 : public QMainWindow
{
	Q_OBJECT

public:
	learning2(QWidget *parent = 0);
	~learning2();

private:
	Ui::learning2Class ui;
};

#endif // LEARNING2_H
