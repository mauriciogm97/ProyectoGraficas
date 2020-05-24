#include <GL/glew.h>
#include <GLFW/glfw3.h>

void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        // Cara frontal
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Tracera
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Izquierda

        // Cara Izquierda
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Dereccha
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Derecha
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Superior
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Inferior
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  // Abajo Izquierda
    };
    //Arreglo para agregar color
    GLfloat colour[] = {
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
    };

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
    glEnable(GL_DEPTH_TEST); //Agregar la proyecci�n de profundidad
    glDepthMask(GL_TRUE);//Agregar la proyecci�n de profundidad
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour); //Buffer de color
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
