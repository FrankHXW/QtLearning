#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Spreadsheet :public QTableWidget
{
	Q_OBJECT
public:
	Spreadsheet(QWidget *parent = 0);
	bool autoRecalculate() const{ return autoRecalc; }

public slots:
	void cut();
	void copy();
	void paste();
	void del();
	void selectCurrentRow();
	void selectCurrentColumn();
	void recalculate();
	void setAutoRecalculate(bool recalc);

private:
	bool autoRecalc;
};

#endif