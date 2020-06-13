#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#include "Util.h"
#include "Shapes.h"

void drawHouse(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat width, GLfloat height, GLfloat depth)
{
    glBindTexture(GL_TEXTURE_2D, LoadTexture());

    // Roof height is 3/8 of the house height. 
    const GLfloat roofHeight = height * 3.0 / 8.0;
    const GLfloat roofCenterPosY = centerPosY + roofHeight / 2.0;
    GLfloat roofColor[] = {
        
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
        0.824f, 0.412f, 0.118f,
    };
    drawTrapezoid(centerPosX, width, width / 2.0, roofCenterPosY, roofHeight, centerPosZ, depth, roofColor);

    // Box height is 5/8 of the house hegiht.
    const GLfloat boxHeight = height * 5.0 / 8.0;
    const GLfloat boxCenterPosY = centerPosY - boxHeight / 2.0;
    GLfloat boxColor[] = {
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
        255.0, 255.0, 255.0,
       255.0, 255.0, 255.0,
    };
    drawCube(centerPosX, width, boxCenterPosY, boxHeight, centerPosZ, depth, boxColor);
    
    // Multiply box height times 0.7 because door height is 70% the height of the house.
    const GLfloat doorHeight = boxHeight * 0.7;
    // Divide door height by 3 because door width is 1/3 of the door height.
    const GLfloat doorWidth = doorHeight / 3.0;
    const GLfloat doorDepth = 5.0;
    const GLfloat doorCenterPosY = boxCenterPosY - boxHeight / 2.0 * 0.3;
    const GLfloat doorCenterPosZ = centerPosZ + depth / 2.0 + doorDepth / 4.0;
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
    drawCube(centerPosX, doorWidth, doorCenterPosY, doorHeight, doorCenterPosZ, doorDepth, doorColor);
}
