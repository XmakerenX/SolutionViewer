#ifndef SOLUTIONVIEWER_H
#define SOLUTIONVIEWER_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMatrix4x4>
#include <vector>
#include "mesh.h"
#include "object.h"

typedef QVector3D QPoint3D;

struct BoxInfo
{
    BoxInfo(QPoint3D _startingPoint, QVector3D _color, int _boxWidth, int _boxHeight, int _boxLength)
        :startingPoint(_startingPoint), color(_color), boxWidth(_boxWidth), boxHeight(_boxHeight), boxLength(_boxLength)
    {}

    QPoint3D startingPoint;
    QVector3D color;
    int boxWidth;
    int boxHeight;
    int boxLength;
};

class SolutionViewer : public QOpenGLWidget
{
public:
    SolutionViewer(QWidget *parent);
    virtual ~SolutionViewer() override;
    void updateSolutionViewer(const std::vector<BoxInfo>& boxesToShow);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QOpenGLShaderProgram* m_boxesShader;

    QMatrix4x4 m_projection;

    Mesh* boxMesh;
    Mesh* containerMesh;
    QOpenGLTexture* containerTexture;
    QOpenGLTexture* boxTexture;

    std::vector<Object> m_boxes;

    Object* container;
};

#endif // SOLUTIONVIEWER_H
