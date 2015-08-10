#include <QtWidgets/QApplication>
#include<QLabel>
#include<QComboBox>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
	QApplication::setStyle("WindowsVista");
	QApplication app(argc, argv);

	QComboBox *styleComboBox = new QComboBox;
	styleComboBox->addItems(QStyleFactory::keys());
	styleComboBox->show();

	QLabel label("<h2><i>Hello</i>" "<font color=red> Qt!</font></h2>");
	label.show();
	return app.exec();
}