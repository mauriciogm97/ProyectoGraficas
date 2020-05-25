#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

void drawCube(GLfloat centerX, GLfloat width, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]);
void drawTrapezoid(GLfloat centerX, GLfloat lowerWidth, GLfloat upperWidth, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]);

void drawCube(GLfloat centerX, GLfloat width, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]) {
    drawTrapezoid(centerX, width, width, centerY, height, centerZ, depth, color);
}

void drawTrapezoid(GLfloat centerX, GLfloat lowerWidth, GLfloat upperWidth, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]) {

    const GLfloat halfLowerWidth = lowerWidth / 2.0;
    const GLfloat halfUpperWidth = upperWidth / 2.0;
    const GLfloat halfHeight = height / 2.0;
    const GLfloat halfDepth = depth / 2.0;

    GLfloat vertices[] = {
        // Cara frontal
        centerX - halfUpperWidth, centerY + halfHeight, centerZ + halfDepth,  // Arriba Izquierda.
        centerX + halfUpperWidth, centerY + halfHeight, centerZ + halfDepth,  // Arriba Derecha.
        centerX + halfLowerWidth, centerY - halfHeight, centerZ + halfDepth,  // Abajo Derecha.
        centerX - halfLowerWidth, centerY - halfHeight, centerZ + halfDepth,  // Abajo Izquierda.

        // Cara Tracera
        centerX - halfUpperWidth, centerY + halfHeight, centerZ - halfDepth,  // Arriba Izquierda.
        centerX + halfUpperWidth, centerY + halfHeight, centerZ - halfDepth,  // Arriba Derecha.
        centerX + halfLowerWidth, centerY - halfHeight, centerZ - halfDepth,  // Abajo Derecha.
        centerX - halfLowerWidth, centerY - halfHeight, centerZ - halfDepth,  // Abajo Izquierda.

        // Cara Izquierda
        centerX - halfUpperWidth, centerY + halfHeight, centerZ + halfDepth,  // Arriba Izquierda.
        centerX - halfUpperWidth, centerY + halfHeight, centerZ - halfDepth,  // Arriba Derecha.
        centerX - halfLowerWidth, centerY - halfHeight, centerZ - halfDepth,  // Abajo Derecha.
        centerX - halfLowerWidth, centerY - halfHeight, centerZ + halfDepth,  // Abajo Izquierda.

        // Cara Derecha
        centerX + halfUpperWidth, centerY + halfHeight, centerZ + halfDepth,  // Arriba Izquierda.
        centerX + halfUpperWidth, centerY + halfHeight, centerZ - halfDepth,  // Arriba Derecha.
        centerX + halfLowerWidth, centerY - halfHeight, centerZ - halfDepth,  // Abajo Derecha.
        centerX + halfLowerWidth, centerY - halfHeight, centerZ + halfDepth,  // Abajo Izquierda.

        // Cara Superior
        centerX - halfUpperWidth, centerY + halfHeight, centerZ + halfDepth,  // Arriba Izquierda.
        centerX - halfUpperWidth, centerY + halfHeight, centerZ - halfDepth,  // Arriba Derecha.
        centerX + halfUpperWidth, centerY + halfHeight, centerZ - halfDepth,  // Abajo Derecha.
        centerX + halfUpperWidth, centerY + halfHeight, centerZ + halfDepth,  // Abajo Izquierda.

        // Cara Inferior
        centerX - halfLowerWidth, centerY - halfHeight, centerZ + halfDepth,  // Arriba Izquierda.
        centerX - halfLowerWidth, centerY - halfHeight, centerZ - halfDepth,  // Arriba Derecha.
        centerX + halfLowerWidth, centerY - halfHeight, centerZ - halfDepth,  // Abajo Derecha.
        centerX + halfLowerWidth, centerY - halfHeight, centerZ + halfDepth,  // Abajo Izquierda.
    };

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
    glEnable(GL_DEPTH_TEST); //Agregar la proyecci�n de profundidad
    glDepthMask(GL_TRUE);//Agregar la proyecci�n de profundidad
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, color); //Buffer de color
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
