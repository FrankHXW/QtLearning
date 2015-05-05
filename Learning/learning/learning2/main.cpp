#include <QtWidgets/QApplication>
#include "2.1_finddialog.h"
#include "2.3_gotocelldialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	FindDialog *dialog1 = new FindDialog;
	dialog1->show();

	GoToCellDialog *dialog2 = new GoToCellDialog;
	dialog2->show();
	return app.exec();
} 