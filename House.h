#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#define HOUSE_WIDTH 50
#define HOUSE_HEIGHT 100
#define HOUSE_DEPTH 50

void drawHouse(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat width, GLfloat height, GLfloat depth)
{
    // Roof height is 3/8 of the house height. 
    // Then divide by 2 because we want the half.
    const GLfloat roofHalfHeight = height * 3.0 / 8.0 / 2.0;
    const GLfloat roofHalfWidth = width / 2.0;  
    const GLfloat roofHalfDepth = depth / 2.0;

    const GLfloat boxHalfWidth = width / 2.0;  
    const GLfloat boxHalfDepth = depth / 2.0;
    // Box height is 5/8 of the house hegiht.
    const GLfloat boxHeight = height * 5.0 / 8.0;
    const GLfloat boxHalfHeight = boxHeight / 2.0;
    
    // Multiply box height times 0.7 because door height is 70% the height of the house.
    const GLfloat doorHalfHeight = boxHalfHeight * 0.7;
    // Divide door height by 3 because door width is 1/3 of the door height.
    const GLfloat doorHalfWidth = doorHalfHeight / 3.0;
    const GLfloat doorHalfDepth = 5.0;

    const GLfloat roofCenterPosY = centerPosY + roofHalfHeight;
    const GLfloat boxCenterPosY = centerPosY - boxHalfHeight;
    const GLfloat doorCenterPosY = boxCenterPosY - boxHalfHeight * 0.3;
    const GLfloat doorCenterPosZ = centerPosZ + boxHalfDepth + doorHalfDepth / 2.0;

    GLfloat vertices[] =
    {
        // Roof.

        // Cara frontal
        centerPosX - roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ + roofHalfDepth,  // Arriba Izquierda.
        centerPosX + roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ + roofHalfDepth,  // Arriba Derecha.
        centerPosX + roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ + roofHalfDepth,  // Abajo Derecha.
        centerPosX - roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ + roofHalfDepth,  // Abajo Izquierda.

        // Cara Tracera
        centerPosX - roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ - roofHalfDepth,  // Arriba Izquierda.
        centerPosX + roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ - roofHalfDepth,  // Arriba Derecha.
        centerPosX + roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ - roofHalfDepth,  // Abajo Derecha.
        centerPosX - roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ - roofHalfDepth,  // Abajo Izquierda.

        // Cara Izquierda
        centerPosX - roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ + roofHalfDepth,  // Arriba Izquierda.
        centerPosX - roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ - roofHalfDepth,  // Arriba Derecha.
        centerPosX - roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ - roofHalfDepth,  // Abajo Derecha.
        centerPosX - roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ + roofHalfDepth,  // Abajo Izquierda.

        // Cara Derecha
        centerPosX + roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ + roofHalfDepth,  // Arriba Izquierda.
        centerPosX + roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ - roofHalfDepth,  // Arriba Derecha.
        centerPosX + roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ - roofHalfDepth,  // Abajo Derecha.
        centerPosX + roofHalfWidth,       roofCenterPosY - roofHalfHeight, centerPosZ + roofHalfDepth,  // Abajo Izquierda.

        // Cara Superior
        centerPosX - roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ + roofHalfDepth,  // Arriba Izquierda.
        centerPosX - roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ - roofHalfDepth,  // Arriba Derecha.
        centerPosX + roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ - roofHalfDepth,  // Abajo Derecha.
        centerPosX + roofHalfWidth / 2.0, roofCenterPosY + roofHalfHeight, centerPosZ + roofHalfDepth,  // Abajo Izquierda.

        // Cara Inferior
        centerPosX - roofHalfWidth      , roofCenterPosY - roofHalfHeight, centerPosZ + roofHalfDepth,  // Arriba Izquierda.
        centerPosX - roofHalfWidth      , roofCenterPosY - roofHalfHeight, centerPosZ - roofHalfDepth,  // Arriba Derecha.
        centerPosX + roofHalfWidth      , roofCenterPosY - roofHalfHeight, centerPosZ - roofHalfDepth,  // Abajo Derecha.
        centerPosX + roofHalfWidth      , roofCenterPosY - roofHalfHeight, centerPosZ + roofHalfDepth,  // Abajo Izquierda.

        // Box

        // Cara frontal
        centerPosX - boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ + boxHalfDepth,  // Arriba Izquierda.
        centerPosX + boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ + boxHalfDepth,  // Arriba Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ + boxHalfDepth,  // Abajo Derecha.
        centerPosX - boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ + boxHalfDepth,  // Abajo Izquierda.

        // Cara Tracera
        centerPosX - boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ - boxHalfDepth,  // Arriba Izquierda.
        centerPosX + boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ - boxHalfDepth,  // Arriba Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ - boxHalfDepth,  // Abajo Derecha.
        centerPosX - boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ - boxHalfDepth,  // Abajo Izquierda.

        // Cara Izquierda
        centerPosX - boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ + boxHalfDepth,  // Arriba Izquierda.
        centerPosX - boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ - boxHalfDepth,  // Arriba Derecha.
        centerPosX - boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ - boxHalfDepth,  // Abajo Derecha.
        centerPosX - boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ + boxHalfDepth,  // Abajo Izquierda.

        // Cara Derecha
        centerPosX + boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ + boxHalfDepth,  // Arriba Izquierda.
        centerPosX + boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ - boxHalfDepth,  // Arriba Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ - boxHalfDepth,  // Abajo Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ + boxHalfDepth,  // Abajo Izquierda.

        // Cara Superior
        centerPosX - boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ + boxHalfDepth,  // Arriba Izquierda.
        centerPosX - boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ - boxHalfDepth,  // Arriba Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ - boxHalfDepth,  // Abajo Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY + boxHalfHeight, centerPosZ + boxHalfDepth,  // Abajo Izquierda.

        // Cara Inferior
        centerPosX - boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ + boxHalfDepth,  // Arriba Izquierda.
        centerPosX - boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ - boxHalfDepth,  // Arriba Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ - boxHalfDepth,  // Abajo Derecha.
        centerPosX + boxHalfWidth, boxCenterPosY - boxHalfHeight, centerPosZ + boxHalfDepth,  // Abajo Izquierda.

        // Door

        // Cara Frontal
        centerPosX - doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Arriba Izquierda.
        centerPosX + doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Arriba Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Abajo Derecha.
        centerPosX - doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Abajo Izquierda.

        // Cara Posterior
        centerPosX - doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Arriba Izquierda.
        centerPosX + doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Arriba Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Abajo Derecha.
        centerPosX - doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Abajo Izquierda.

        // Cara Izquierda
        centerPosX - doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Arriba Izquierda.
        centerPosX - doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Arriba Derecha.
        centerPosX - doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Abajo Derecha.
        centerPosX - doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Abajo Izquierda.

        // Cara Derecha
        centerPosX + doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Arriba Izquierda.
        centerPosX + doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Arriba Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Abajo Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Abajo Izquierda.

        // Cara Superior
        centerPosX - doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Arriba Izquierda.
        centerPosX - doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Arriba Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Abajo Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY + doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Abajo Izquierda.

        // Cara Inferior
        centerPosX - doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Arriba Izquierda.
        centerPosX - doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Arriba Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ - doorHalfDepth,  // Abajo Derecha.
        centerPosX + doorHalfWidth, doorCenterPosY - doorHalfHeight, doorCenterPosZ + doorHalfDepth,  // Abajo Izquierda.
    };
    //Arreglo para agregar color
    GLfloat colour[] = {
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
    };

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
    glEnable(GL_DEPTH_TEST); //Agregar la proyecci�n de profundidad
    glDepthMask(GL_TRUE);//Agregar la proyecci�n de profundidad
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour); //Buffer de color
    glDrawArrays(GL_QUADS, 0, 72);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
