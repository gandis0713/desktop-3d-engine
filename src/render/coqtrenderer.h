#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include "qtheader.h"
#include "../coenginedefine.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include <map>

#include "shader/coshader.h"

class CoGLWidget;

class GANDISENGINE CoQtRenderer : public QObject
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

private:
    void initializeWidget();
    bool createDefaultShader();

private:
    CoGLWidget        *m_pGLWidget;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;
    std::map<EShaderType, CoShader*> m_mapShaders;

    QOpenGLFunctions_2_1    *m_pGLFunctions;

    GLuint m_nProgramID;
    GLuint m_nMatrixID;
    GLuint m_nVertexID;
    GLuint m_nColorID;
    GLuint m_nVerterBuffer;
    GLuint m_mColorbuffer;

    glm::mat4 m_mat4PerViewModel;


private slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
};

#endif // COQTRENDERER_H
