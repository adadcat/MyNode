#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open..."),this);
    openAction->setShortcut(QKeySequence::Open);
    //设置该动作在状态栏上的提示文本
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    //菜单栏
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    //工具栏
    //一般来说，一个窗口一个菜单栏；但可以多个工具栏
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    //如可添加第二个工具栏
    /*
    QToolBar *toolBar2 = addToolBar(tr("&Tool Bar 2"));
    toolBar->addAction(openAction);
    */

    //添加状态栏
    statusBar() ;
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
