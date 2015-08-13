#include <QtWidgets/QApplication>
#include<QLabel>
#include<QComboBox>
#include<QStyleFactory>
#include<QSplashScreen>


#include"mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication::setStyle("Fusion");
	QApplication app(argc, argv);

	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap("./images/splash.jpg"));
	splash->show();

	Qt::Alignment bottomLeft = Qt::AlignBottom | Qt::AlignLeft;
	splash->showMessage(QObject::tr("Setting up the main window...."), bottomLeft, Qt::white);

	MainWindow *mainWin=new MainWindow;
	mainWin->show();

	splash->finish(mainWin);
	delete splash;
	return app.exec();
}