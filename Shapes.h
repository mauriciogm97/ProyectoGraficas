#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <algorithm> 

#include <iostream>


void drawCube(GLfloat centerX, GLfloat width, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]);
void drawTrapezoid(GLfloat centerX, GLfloat lowerWidth, GLfloat upperWidth, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]);
void drawSphere(GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat diameter);

void drawSphere(GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat diameter) {

    GLfloat color[3888*3];
    for (int x = 0; x < 3888 * 3; x += 3) {
        color[x] = 0;
        color[x+1] = 255;
        color[x+2] = 0;
    }

    GLfloat radius = diameter / 2.0;
    GLfloat vertices[3888];
    int vCont = 0;
    for (int x = 1; x <= 360; x += 10) {
        for (int y = 1; y <= 360; y += 10) {
            vertices[vCont++] = centerX + (radius * cosf(x)) * cosf(y);
            vertices[vCont++] = centerY + (radius * cosf(x)) * sinf(y);
            vertices[vCont++] = centerZ + radius * sinf(x);
        }
    }

    /*GLfloat vertices2[3888];
    for (int x = 0; x < 3888; x += 3) {
        vertices
    }*/

    //std::cout << vCont << std::endl;
    //std::sort(vertices, vertices + 3888);

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
    glEnable(GL_DEPTH_TEST); //Agregar la proyecci�n de profundidad
    glDepthMask(GL_TRUE);//Agregar la proyecci�n de profundidad
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, color); //Buffer de color
    glDrawArrays(GL_QUADS, 0, 3888);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

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
