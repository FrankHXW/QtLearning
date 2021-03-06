#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class SpreadsheetCompare;

class Spreadsheet :public QTableWidget
{
	Q_OBJECT
public:
	Spreadsheet(QWidget *parent = 0);
	
	bool autoRecalculate() const{ return autoRecalc; }
	QString currentLocation() const;
	QString currentFormula() const;
	QTableWidgetSelectionRange selectedRange() const;
	void clear();
	bool readFile(const QString &fileName);
	bool writeFile(const QString &fileName);
	void sort(const SpreadsheetCompare &compare);


public slots:
	void cut();
	void copy();
	void paste();
	void del();
	void selectCurrentRow();
	void selectCurrentColumn();
	void recalculate();
	void setAutoRecalculate(bool recalc);
	void findNext(const QString &str, Qt::CaseSensitivity cs);
	void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private:
	bool autoRecalc;
};


class SpreadsheetCompare
{
public:
	bool operator()(const QStringList &row1, const QStringList &row2) const;
	enum {KeyCount=3};
	int keys[KeyCount];
	bool ascending[KeyCount];
};

#endif