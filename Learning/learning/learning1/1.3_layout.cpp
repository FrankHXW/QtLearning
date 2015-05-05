#include "learning1.h"
#include <QtWidgets/QApplication>
#include <QHBoxlayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	window->setWindowTitle("Enter your age");

	QSpinBox *spinBox = new QSpinBox;
	QSlider *slider = new QSlider(Qt::Horizontal);
	spinBox->setRange(0, 130);
	slider->setRange(0, 150);
	QLabel *label = new QLabel("label");

	//pay attention to SIGNAL and SLOT function's name
	QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
	spinBox->setValue(35);
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window->setLayout(layout);
	window->show();
	spinBox->setValue(40);
	return app.exec();
}