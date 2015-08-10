#include <QtWidgets/QApplication>
#include "2.1_finddialog.h"
#include "2.3_gotocelldialog.h"
#include "2.4_sortdialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	FindDialog *dialog1 = new FindDialog;
	dialog1->show();

	GoToCellDialog *dialog2 = new GoToCellDialog;
	dialog2->show();

	SortDialog *dialog3 = new SortDialog;
	dialog3->setColumnRange('A', 'Z');
	dialog3->show();

	return app.exec();
} 