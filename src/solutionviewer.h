#ifndef SOLUTIONVIEWER_H
#define SOLUTIONVIEWER_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
class SolutionViewer;
}

class SolutionViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SolutionViewer(QWidget *parent = nullptr);
    ~SolutionViewer() override;

private:
    QScopedPointer<Ui::SolutionViewer> m_ui;
};

#endif // SOLUTIONVIEWER_H
