#include <QWidget>
#include "2.3_gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");   //provide pattern matching using regular expressions
	lineEdit->setValidator(new QRegExpValidator(regExp, this));
	
	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
	okButton->setEnabled(lineEdit->hasAcceptableInput());
}