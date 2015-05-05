#include "learning1.h"
#include <QtWidgets/QApplication>
#include<QLabel>
#include<QPushButton>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton *button = new QPushButton("Quit");
	QLabel *label = new QLabel("label");
	QObject::connect(button, SIGNAL(clicked()), label, SLOT(show()));
	button->show();
	return app.exec();
}
