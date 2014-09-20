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
    void closeEvent(QCloseEvent *event);


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
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCaml;
    QMenu *menuHelp;
    QProcess *camlProcess;
    QSettings *settings;
    QPrinter *printer;
    highlighter *hilit;
    QString cwd;

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
};

#endif // CAMLDEVWINDOW_H
