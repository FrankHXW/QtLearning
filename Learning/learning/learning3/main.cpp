#include <QtWidgets/QApplication>
#include<QLabel>
#include<QComboBox>
#include <QStyleFactory>

#include"mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication::setStyle("Fusion");
	QApplication app(argc, argv);

	MainWindow *mainWin=new MainWindow;
	mainWin->show();
	return app.exec();
}