#include <QtGui>

#include<QMenu>
#include<QToolBar>
#include<QLayout>
#include<QMenuBar>
#include<QStatusBar>

#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
	//create main window
	spreadsheet = new Spreadsheet;
	setCentralWidget(spreadsheet);

	//create other parts of window
	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();

	readSettings();

	findDialog = 0;

	setWindowIcon(QIcon(":/images/icon.png"));
	setCurrentFile("");
}



void MainWindow::createActions()
{
	newAction = new QAction(tr("&New"), this);
	newAction->setIcon(QIcon(":/images/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("create a new spreadsheet file"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	openAction = new QAction(tr("&Open..."), this);
	openAction->setIcon(QIcon(":/images/open.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("open an existing spreadsheet file"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(tr("&Save"), this);
	saveAction->setIcon(QIcon(":/images/save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("save the current spreadsheet file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAction = new QAction(tr("Save &As..."), this);
	saveAsAction->setStatusTip(tr("save the current file under a new name "));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

	for (int i = 0; i < MaxRecentFiles; ++i){
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("exit the application"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	cutAction = new QAction(tr("Cu&t"), this);
	cutAction->setIcon(QIcon(":/images/cut.png"));
	cutAction->setShortcut(QKeySequence::Cut);
	cutAction->setStatusTip(tr("cut the selected contents to the clipboard"));
	connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

	copyAction = new QAction(tr("&Copy"), this);
	copyAction->setIcon(QIcon(":/images/copy.png"));
	copyAction->setShortcut(QKeySequence::Copy);
	copyAction->setStatusTip(tr("copy the selected contents to the clipboard"));
	connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

	pasteAction = new QAction(tr("&Paste"), this);
	pasteAction->setIcon(QIcon(":/images/paste.png"));
	pasteAction->setShortcut(QKeySequence::Paste);
	pasteAction->setStatusTip(tr("paste the clipboard's contents into the current selection"));
	connect(pasteAction, SIGNAL(triggered()), spreadsheet, SLOT(paste()));

	deleteAction = new QAction(tr("&Delete"), this);
	deleteAction->setShortcut(QKeySequence::Delete);
	deleteAction->setStatusTip(tr("delete the selected contents"));
	connect(deleteAction, SIGNAL(triggered()), spreadsheet, SLOT(del()));

	selectRowAction = new QAction(tr("&Row"), this);
	selectRowAction->setStatusTip(tr("select all the cells in the current row"));
	connect(selectRowAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentRow()));
	
	selectColumnAction = new QAction(tr("&Column"), this);
	selectColumnAction->setStatusTip(tr("select all the cells in the current colum"));
	connect(selectColumnAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentColumn()));

	selectAllAction = new QAction(tr("&All"), this);
	selectAllAction->setStatusTip(tr("select all the cells in the spreadsheet"));
	connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll())); //selectAll() is realized by QAbstractItemView

	findAction = new QAction(tr("&Find..."), this);
	findAction->setIcon(QIcon(":/images/find.png"));
	findAction->setShortcut(QKeySequence::Find);
	findAction->setStatusTip(tr("Find a matched cell"));
	connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

	goToCellAction = new QAction(tr("&Go to Cell..."), this);
	goToCellAction->setIcon(QIcon(":/images/gotocell.png"));
	goToCellAction->setShortcut(tr("Ctrl+G"));
	goToCellAction->setStatusTip(tr("go to the specified cell"));
	connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

	recalculateAction = new QAction(tr("&Recalculate"), this);
	recalculateAction->setShortcut(tr("F9"));
	recalculateAction->setStatusTip(tr("recalculate all the spreadsheet's formulas"));
	connect(recalculateAction, SIGNAL(triggered()), spreadsheet, SLOT(recalculate()));

	sortAction = new QAction(tr("&Sort..."), this);
	sortAction->setStatusTip(tr("Sort the selected cells or all the cells"));
	connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

	showGridAction = new QAction(tr("&Show Grid"), this);
	showGridAction->setCheckable(true);
	showGridAction->setCheckable(spreadsheet->showGrid());
	showGridAction->setStatusTip(tr("show or hide the spreadsheet's grid"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

	autoRecalcAction = new QAction(tr("&Auto-Recalculate"), this);
	autoRecalcAction->setCheckable(true);
	autoRecalcAction->setCheckable(spreadsheet->autoRecalculate());
	autoRecalcAction->setStatusTip(tr("switch auto-recalculate on or off"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setAutoRecalculate(bool)));

	aboutAction = new QAction(tr("&About"), this);
	aboutAction->setStatusTip(tr("show the application's information"));
	connect(aboutAction, SIGNAL(triggerd()), this, SLOT(about()));

	aboutQtAction = new QAction(tr("About &Qt"), this);
	aboutQtAction->setStatusTip(tr("show the Qt library's information"));
	connect(aboutQtAction, SIGNAL(triggerd()), qApp, SLOT(aboutQt()));

}


void MainWindow::createMenus()
{
	fileMenu=menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	separatorAction = fileMenu->addSeparator();
	for (int i = 0; i < MaxRecentFiles; ++i){
		fileMenu->addAction(recentFileActions[i]);
	}
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(deleteAction);

	selectSubMenu = editMenu->addMenu(tr("Select"));
	selectSubMenu->addAction(selectRowAction);
	selectSubMenu->addAction(selectColumnAction);
	selectSubMenu->addAction(selectAllAction);

	editMenu->addSeparator();
	editMenu->addAction(findAction);
	editMenu->addAction(goToCellAction);

	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(recalculateAction);
	toolsMenu->addAction(sortAction);

	optionsMenu = menuBar()->addMenu(tr("&Options"));
	optionsMenu->addAction(showGridAction);
	optionsMenu->addAction(autoRecalcAction);

	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);

}

void MainWindow::createContextMenu()
{
	spreadsheet->addAction(cutAction);
	spreadsheet->addAction(copyAction);
	spreadsheet->addAction(pasteAction);
	spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);

	editToolBar = addToolBar(tr("Edit"));
	editToolBar->addAction(cutAction);
	editToolBar->addAction(copyAction);
	editToolBar->addAction(pasteAction);
	editToolBar->addSeparator();
	editToolBar->addAction(findAction);
	editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
	locationLabel = new QLabel("W999");
	locationLabel->setAlignment(Qt::AlignHCenter);
	locationLabel->setMinimumSize(locationLabel->sizeHint());

	formulaLabel = new QLabel;
	formulaLabel->setIndent(3);

	statusBar()->addWidget(locationLabel);
	statusBar()->addWidget(formulaLabel);

	connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(updateStatusBar()));
	connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));
	
	updateStatusBar();
}

void MainWindow::updateStatusBar()
{
	locationLabel->setText(spreadsheet->currentLocation());
	formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified()
{
	setWindowModified(true);
	updateStatusBar();
}