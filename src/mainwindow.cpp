#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_viewer = new SolutionViewer(this->centralWidget());
    // enable anit-aliasing so boxes will look less shit
    QSurfaceFormat format;
    format.setSamples(4);
    m_viewer->setFormat(format);

    m_viewer->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
