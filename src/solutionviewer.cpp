#include "solutionviewer.h"
#include "ui_solutionviewer.h"

SolutionViewer::SolutionViewer(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::SolutionViewer)
{
    m_ui->setupUi(this);
}

SolutionViewer::~SolutionViewer() = default;
