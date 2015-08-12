#include <QtGui>

#include<QMenu>
#include<QToolBar>
#include<QLayout>
#include<QMenuBar>
#include<QStatusBar>
#include<QMessageBox>
#include<QFileDialog>

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

	setWindowIcon(QIcon("./images/icon.png"));
	setCurrentFile("");
	setAttribute(Qt::WA_DeleteOnClose);  //delete this widget's memory when the widget has accepted the close event
}



void MainWindow::createActions()
{
	newAction = new QAction(tr("&New"), this);
	newAction->setIcon(QIcon("./images/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new spreadsheet file"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	openAction = new QAction(tr("&Open..."), this);
	openAction->setIcon(QIcon("./images/open.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing spreadsheet file"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(tr("&Save"), this);
	saveAction->setIcon(QIcon("./images/save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save the current spreadsheet file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAction = new QAction(tr("Save &As..."), this);
	saveAsAction->setStatusTip(tr("Save the current file under a new name "));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

	for (int i = 0; i < MaxRecentFiles; ++i){
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}

	closeAction = new QAction(tr("&Close"), this);
	closeAction->setShortcut(QKeySequence::Close);
	closeAction->setStatusTip(tr("Close this window"));
	connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit the application"));
	connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

	cutAction = new QAction(tr("Cu&t"), this);
	cutAction->setIcon(QIcon("./images/cut.png"));
	cutAction->setShortcut(QKeySequence::Cut);
	cutAction->setStatusTip(tr("Cut the selected contents to the clipboard"));
	connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

	copyAction = new QAction(tr("&Copy"), this);
	copyAction->setIcon(QIcon("./images/copy.png"));
	copyAction->setShortcut(QKeySequence::Copy);
	copyAction->setStatusTip(tr("Copy the selected contents to the clipboard"));
	connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

	pasteAction = new QAction(tr("&Paste"), this);
	pasteAction->setIcon(QIcon("./images/paste.png"));
	pasteAction->setShortcut(QKeySequence::Paste);
	pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current selection"));
	connect(pasteAction, SIGNAL(triggered()), spreadsheet, SLOT(paste()));

	deleteAction = new QAction(tr("&Delete"), this);
	deleteAction->setShortcut(QKeySequence::Delete);
	deleteAction->setStatusTip(tr("Delete the selected contents"));
	connect(deleteAction, SIGNAL(triggered()), spreadsheet, SLOT(del()));

	selectRowAction = new QAction(tr("&Row"), this);
	selectRowAction->setStatusTip(tr("Select all the cells in the current row"));
	connect(selectRowAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentRow()));
	
	selectColumnAction = new QAction(tr("&Column"), this);
	selectColumnAction->setStatusTip(tr("Select all the cells in the current colum"));
	connect(selectColumnAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentColumn()));

	selectAllAction = new QAction(tr("&All"), this);
	selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
	connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll())); //selectAll() is realized by QAbstractItemView

	findAction = new QAction(tr("&Find..."), this);
	findAction->setIcon(QIcon("./images/find.png"));
	findAction->setShortcut(QKeySequence::Find);
	findAction->setStatusTip(tr("Find a matched cell"));
	connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

	goToCellAction = new QAction(tr("&Go to Cell..."), this);
	goToCellAction->setIcon(QIcon("./images/gotocell.png"));
	goToCellAction->setShortcut(tr("Ctrl+G"));
	goToCellAction->setStatusTip(tr("Go to the specified cell"));
	connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

	recalculateAction = new QAction(tr("&Recalculate"), this);
	recalculateAction->setShortcut(tr("F9"));
	recalculateAction->setStatusTip(tr("Recalculate all the spreadsheet's formulas"));
	connect(recalculateAction, SIGNAL(triggered()), spreadsheet, SLOT(recalculate()));

	sortAction = new QAction(tr("&Sort..."), this);
	sortAction->setStatusTip(tr("Sort the selected cells or all the cells"));
	connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

	showGridAction = new QAction(tr("&Show Grid"), this);
	showGridAction->setCheckable(true);
	showGridAction->setCheckable(spreadsheet->showGrid());
	showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

	autoRecalcAction = new QAction(tr("&Auto-Recalculate"), this);
	autoRecalcAction->setCheckable(true);
	autoRecalcAction->setCheckable(spreadsheet->autoRecalculate());
	autoRecalcAction->setStatusTip(tr("Switch auto-recalculate on or off"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setAutoRecalculate(bool)));

	aboutAction = new QAction(tr("&About"), this);
	aboutAction->setStatusTip(tr("Show the application's information"));
	connect(aboutAction, SIGNAL(triggerd()), this, SLOT(about()));

	aboutQtAction = new QAction(tr("About &Qt"), this);
	aboutQtAction->setStatusTip(tr("Show the Qt library's information"));
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
	fileMenu->addAction(closeAction);
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

void MainWindow::newFile()
{
	//if (okToContinue()){
	//	spreadsheet->clear();
	//	setCurrentFile("");
	//}
	MainWindow *mainWin = new MainWindow;
	mainWin->show();

}


bool MainWindow::okToContinue()
{
	if (isWindowModified()){
		int r = QMessageBox::warning(this, tr("Spreadsheet"), tr("The Document has been modified .\n"
			"Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (r == QMessageBox::Yes){
			return save();
		}
		else if (r == QMessageBox::Cancel){
			return false;
		}
	}
	return true;
}

void MainWindow::open()
{
	if (okToContinue()){
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"), ".", tr("Spreadsheet files(*.sp)"));
		if (!fileName.isEmpty())
			loadFile(fileName);
	}
}

bool MainWindow::loadFile(const QString &fileName)
{
	if (!spreadsheet->readFile(fileName)){
		statusBar()->showMessage(tr("Loading canceled"), 2000);
		return false;
	}
	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File loaded"), 2000);
	return true;
}

bool MainWindow::save()
{
	if (curFile.isEmpty()){
		return saveAs();
	}
	else {
		return saveFile(curFile);
	}
}

bool MainWindow::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"), ".", tr("Spreadsheet files(*.sp)"));
	if (fileName.isEmpty())
		return false;
	return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
	if (!spreadsheet->writeFile(fileName)){
		statusBar()->showMessage(tr("Saving canceled"), 2000);
		return false;
	}
	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File saved"), 2000);
	return true;
}

void MainWindow::closeEvent(QCloseEvent *event)  //re-implement QWidget::closeEvent(),to make sure close or not
{
	if (okToContinue()){
		writeSettings();
		event->accept();
	}
	else{
		event->ignore();
	}
}

void MainWindow::setCurrentFile(const QString &fileName)
{
	curFile = fileName;
	setWindowModified(false);
	QString shownName = tr("Untitled");
	if (!curFile.isEmpty()){
		shownName = strippedName(curFile);
		recentFiles.removeAll(curFile);		//Removes all occurrences of value curFile in the list
		recentFiles.prepend(curFile);		//Inserts value at the beginning of the list

		foreach(QWidget *win, QApplication::topLevelWidgets()){		//for each window call updateRecentFileActions,all window should call it.(P57)
			if (MainWindow *mainWin=qobject_cast<MainWindow *>(win))
				mainWin->updateRecentFileActions();
		}
	}
	setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}


QString MainWindow::strippedName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).fileName();	//return file name excluding path
}


void MainWindow::updateRecentFileActions()
{
	QMutableStringListIterator i(recentFiles);
	while (i.hasNext()){
		if (!QFile::exists(i.next()))   //remove the non-exist file,next() releaize iterator
			i.remove();
	}
	for (int j = 0; j < MaxRecentFiles; ++j){
		if (j < recentFiles.count()){
			QString text = tr("&%1 %2").arg(j + 1).arg(strippedName(recentFiles[j]));
			recentFileActions[j]->setText(text);				//save file name excluding path 
			recentFileActions[j]->setData(recentFiles[j]);		//QVariant::data
			recentFileActions[j]->setVisible(true);
		}
		else{
			recentFileActions[j]->setVisible(false);		//hide other action
		}
	}
	separatorAction->setVisible(!recentFiles.isEmpty());	//setting separator visible if existing more than one file
}

void MainWindow::openRecentFile()
{
	if (okToContinue()){
		QAction *action = qobject_cast<QAction *>(sender());//sender():Returns a pointer to the object that sent the signal
		if (action)											//qobject_cast:transfer pointer of QObject into pointer of QAction
			loadFile(action->data().toString());
	}
}

void MainWindow::find()
{
	if (!findDialog){
		findDialog = new FindDialog(this);
		connect(findDialog, SIGNAL(findNext(const QString &, Qt::CaseSensitivity)), spreadsheet, SLOT(findNext(const QString &, Qt::CaseSensitivity)));
		connect(findDialog, SIGNAL(findPrevious(const QString &, Qt::CaseSensitivity)), spreadsheet, SLOT(findPrevious(const QString &, Qt::CaseSensitivity)));
	}
	findDialog->show();			//show() is modeless
	findDialog->raise();		//raise the window above other window
	findDialog->activateWindow(); //An active window is a visible top-level window that has the keyboard input focus
}


void MainWindow::goToCell()
{
	GoToCellDialog dialog(this);
	if (dialog.exec()){				//exec() is modal
		QString str = dialog.lineEdit->text().toUpper();
		spreadsheet->setCurrentCell(str.mid(1).toInt() - 1, str[0].unicode() - 'A');
	}
}

void MainWindow::sort()
{
	SortDialog dialog(this);
	QTableWidgetSelectionRange range = spreadsheet->selectedRange();
	dialog.setColumnRange('A' + range.leftColumn(), 'A' + range.rightColumn());

	if (dialog.exec()){
		SpreadsheetCompare compare;
		compare.keys[0] = dialog.primaryColumnCombo->currentIndex();
		compare.keys[1] = dialog.secondaryColumnCombo->currentIndex() - 1;
		compare.keys[2] = dialog.tertiaryColumnCombo->currentIndex() - 1;
		compare.ascending[0] = (dialog.primaryOrderCombo->currentIndex() == 0);
		compare.ascending[1] = (dialog.secondaryOrderCombo->currentIndex() == 0);
		compare.ascending[2] = (dialog.tertiaryOrderCombo->currentIndex() == 0);
	}
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About Spreadsheet"), tr("<h2>Spreadsheetr 1.0</h2><p>Copyright &copy; 2015 Software Inc."
		"<p>Spreadsheet is a small application that demonstrates QAction, QMainWindow, QMenuBar, QStatusBar, "
		"QTableWidget, QToolBar,and any other Qt classes."));
}

void MainWindow::writeSettings()
{
	QSettings settings("Software Inc", "Spreadsheet");
	settings.setValue("geometry", saveGeometry());
	settings.setValue("recentFiles", recentFiles);
	settings.setValue("showGrid", showGridAction->isChecked());
	settings.setValue("autoRecalc", autoRecalcAction->isChecked());
}

void MainWindow::readSettings()
{
	QSettings settings("Software Inc", "Spreadsheet");
	restoreGeometry(settings.value("geometry").toByteArray());
	recentFiles = settings.value("recentFiles").toStringList();
	foreach(QWidget *win, QApplication::topLevelWidgets()){		//for each window call updateRecentFileActions,all window should call it.(P57)
		if (MainWindow *mainWin = qobject_cast<MainWindow *>(win))
			mainWin->updateRecentFileActions();
	}
	bool showGrid = settings.value("showGrid", true).toBool();
	showGridAction->setChecked(showGrid);

	bool autoRecalc = settings.value("autoRecalc", true).toBool();
	autoRecalcAction->setChecked(autoRecalc);
}