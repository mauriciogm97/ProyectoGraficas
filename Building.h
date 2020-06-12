#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#include "Shapes.h"

void drawBuilding(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat width, GLfloat height, GLfloat depth)
{

    // Increase building sizes
    const GLfloat boxHeight = height * 3.0 ;
    const GLfloat boxCenterPosY = centerPosY - boxHeight / 2.0;
    GLfloat boxColor[] = {
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
            0.824, 0.706, 0.549,
    };
    drawCube(centerPosX, width, boxCenterPosY, boxHeight*1.2, centerPosZ, depth, boxColor);
    
    //Esto fue lo que copie de house.h
    const GLfloat doorHeight = boxHeight * 0.4;
    // Divide door height by 3 because door width is 1/3 of the door height.

    const GLfloat doorWidth = doorHeight / 3.0;
    const GLfloat doorDepth = 5.0;
    const GLfloat doorCenterPosY = boxCenterPosY - boxHeight / 2.0 * 0.3;
    const GLfloat doorCenterPosZ = centerPosZ + depth / 2.0 + doorDepth / 4.0;
    //color cafe como las puertas de las casas
    GLfloat doorColor[] = {
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
            0.5f, 0.35f, 0.05f,
    };
    drawCube(centerPosX, doorWidth, doorCenterPosY-43, doorHeight, doorCenterPosZ-55, doorDepth, doorColor);
}
