#include<QtGui>

#include"spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent)
{

}

QString Spreadsheet::currentLocation() const
{
	QString str;
	return str;
}

QString Spreadsheet::currentFormula() const
{
	QString str;
	return str;
}

QTableWidgetSelectionRange Spreadsheet::selectedRange() const
{
	QTableWidgetSelectionRange range;
	return range;
}

void Spreadsheet::clear()
{

}


bool Spreadsheet::readFile(const QString &fileName)
{
	return true;
}

bool Spreadsheet::writeFile(const QString &fileName)
{
	return true;
}








void Spreadsheet::cut()
{

}

void Spreadsheet::copy()
{

}

void Spreadsheet::paste()
{

}

void Spreadsheet::del()
{

}


void Spreadsheet::selectCurrentRow()
{

}

void Spreadsheet::selectCurrentColumn()
{

}

void Spreadsheet::recalculate()
{

}

void Spreadsheet::setAutoRecalculate(bool recalc)
{

}

void Spreadsheet::findNext(const QString &str, Qt::CaseSensitivity cs)
{

}

void Spreadsheet::findPrevious(const QString &str, Qt::CaseSensitivity cs)
{

}