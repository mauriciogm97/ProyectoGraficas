#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

class Trapezoid {
private:
    GLfloat vertices[72];
    GLfloat color[216];

public:
    Trapezoid() {}

    Trapezoid(GLfloat centerX, GLfloat lowerWidth, GLfloat upperWidth, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[]) {
        GLfloat halfLowerWidth = lowerWidth / 2.0;
        GLfloat halfUpperWidth = upperWidth / 2.0;
        GLfloat halfHeight = height / 2.0;
        GLfloat halfDepth = depth / 2.0;

        int cont = 0;

        // Cara frontal
        vertices[cont++] = centerX - halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ + halfDepth;  // Arriba Izquierda.
        vertices[cont++] = centerX + halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ + halfDepth;  // Arriba Derecha.
        vertices[cont++] = centerX + halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ + halfDepth;  // Abajo Derecha.
        vertices[cont++] = centerX - halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ + halfDepth;  // Abajo Izquierda.

        // Cara Tracera
        vertices[cont++] = centerX - halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ - halfDepth;  // Arriba Izquierda.
        vertices[cont++] = centerX + halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ - halfDepth;  // Arriba Derecha.
        vertices[cont++] = centerX + halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ - halfDepth;  // Abajo Derecha.
        vertices[cont++] = centerX - halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ - halfDepth;  // Abajo Izquierda.

        // Cara Izquierda
        vertices[cont++] = centerX - halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ + halfDepth;  // Arriba Izquierda.
        vertices[cont++] = centerX - halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ - halfDepth;  // Arriba Derecha.
        vertices[cont++] = centerX - halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ - halfDepth;  // Abajo Derecha.
        vertices[cont++] = centerX - halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ + halfDepth;  // Abajo Izquierda.

        // Cara Derecha
        vertices[cont++] = centerX + halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ + halfDepth;  // Arriba Izquierda.
        vertices[cont++] = centerX + halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ - halfDepth;  // Arriba Derecha.
        vertices[cont++] = centerX + halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ - halfDepth;  // Abajo Derecha.
        vertices[cont++] = centerX + halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ + halfDepth;  // Abajo Izquierda.

        // Cara Superior
        vertices[cont++] = centerX - halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ + halfDepth;  // Arriba Izquierda.
        vertices[cont++] = centerX - halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ - halfDepth;  // Arriba Derecha.
        vertices[cont++] = centerX + halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ - halfDepth;  // Abajo Derecha.
        vertices[cont++] = centerX + halfUpperWidth; vertices[cont++] = centerY + halfHeight; vertices[cont++] = centerZ + halfDepth;  // Abajo Izquierda.

        // Cara Inferior
        vertices[cont++] = centerX - halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ + halfDepth;  // Arriba Izquierda.
        vertices[cont++] = centerX - halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ - halfDepth;  // Arriba Derecha.
        vertices[cont++] = centerX + halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ - halfDepth;  // Abajo Derecha.
        vertices[cont++] = centerX + halfLowerWidth; vertices[cont++] = centerY - halfHeight; vertices[cont++] = centerZ + halfDepth;  // Abajo Izquierda.

        for (int x = 0; x < 216; x++) {
            this->color[x] = color[x];
        }
    }
    
    void Draw() {
        //glPolygonMode( GL_FRONT_AND_BACK; GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
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
};

class Cube: public Trapezoid {
public:
    Cube() {}

    Cube(GLfloat centerX, GLfloat width, GLfloat centerY, GLfloat height, GLfloat centerZ, GLfloat depth, GLfloat color[])
        : Trapezoid(centerX, width, width, centerY, height, centerZ, depth, color) {}
};