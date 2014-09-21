// camldevwindow.h - LemonCaml main window
// This file is part of LemonCaml - Copyright (C) 2012-2014 Corentin FERRY
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef CAMLDEVWINDOW_H
#define CAMLDEVWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QProcess>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrintDialog>
#include <QFontDialog>
#include <QTextEdit>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QTextCodec>
#include <QSplitter>
#include <QPrinter>
#include "inputzone.h"
#include "highlighter.h"
#include "camldevsettings.h"
#ifndef WIN32
#include "unistd.h"
#include "signal.h"
#endif


class CamlDevWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CamlDevWindow(QString wd = "", QWidget *parent = 0);
    ~CamlDevWindow();
    QString programTitle;
    bool startCamlProcess();
    bool camlStarted;
    bool unsavedChanges;
    QString removeComments(QString);
    QString removeUnusedLineBreaks(QString, bool isPersonalOutput);
    void openFile(QString file);
    bool saveFile(QString file);
    void appendOutput(QString str, QColor color);
    void syntaxingColoration();
    QString currentFile;
    bool exitCurrentFile();



private:
    InputZone *inputZone;
    QTextEdit *outputZone;
    QSplitter *split;
    QToolBar *toolbar;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionQuit;
    QAction *actionStopCaml;
    QAction *actionInterruptCaml;
    QAction *actionSendCaml;
    QAction *actionShowSettings;
    QAction *actionClearOutput;
    QAction *actionAutoIndent;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDelete;
    QAction *actionChangeInputFont;
    QAction *actionChangeOutputFont;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCaml;
    QMenu *menuHelp;
    QProcess *camlProcess;
    QSettings *settings;
    QPrinter *printer;
    highlighter *hilit;
    QString cwd;
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent * event);

signals:
    
public slots:
    void sendCaml();
    void readCaml();
    void stopCaml();
    void camlOK();
    void interruptCaml();
    bool saveAs();
    bool save();
    void open();
    void textChanged();
    void newFile();
    void readCamlErrors();
    void print();
    void changeInputFont();
    void changeOutputFont();
    void doPrint();
    void showSettings();
    void zoomIn();
    void zoomOut();
    void about();
    void aboutQt();
    
};

#endif // CAMLDEVWINDOW_H
