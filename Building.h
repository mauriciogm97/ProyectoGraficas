#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#include "Shapes.h"

void drawBuilding(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat width, GLfloat height, GLfloat depth)
{

    // Increase building sizes
    const GLfloat boxHeight = height * 15.0 ;
    const GLfloat boxCenterPosY = centerPosY - boxHeight / 2.0;
    GLfloat boxColor[] = {
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
    drawCube(centerPosX, width, boxCenterPosY, boxHeight*1.2, centerPosZ, depth, boxColor);
    
}
