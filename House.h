#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void DrawCube2(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void DrawCube3(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);

void DrawHouse(GLfloat halfScreenWidth, GLfloat halfScreenHeight) {
    DrawCube(halfScreenWidth, halfScreenHeight, -200, 100);
    DrawCube2(halfScreenWidth + 50, halfScreenHeight, -200, 100);
    DrawCube3(halfScreenWidth, halfScreenHeight, -200, 100);
}

void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        // Cara frontal
        centerPosX - halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ + halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength + 100, centerPosZ + halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength, centerPosY - halfSideLength + 100, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Tracera
        centerPosX - halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ - halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength + 100, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength, centerPosY - halfSideLength + 100, centerPosZ - halfSideLength, // Abajo Izquierda

        // Cara Izquierda
        centerPosX - halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ - halfSideLength, // Arriba Dereccha
        centerPosX - halfSideLength, centerPosY - halfSideLength + 100, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength, centerPosY - halfSideLength + 100, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Derecha
        centerPosX + halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength + 100, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength + 100, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Superior
        centerPosX - halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength / 2, centerPosY + halfSideLength / 4 + 100, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Inferior
        centerPosX - halfSideLength, centerPosY - halfSideLength + 100, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength, centerPosY - halfSideLength + 100, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength + 100, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength, centerPosY - halfSideLength + 100, centerPosZ + halfSideLength // Abajo Izquierda
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

void DrawCube2(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        // Cara frontal
        centerPosX - edgeLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Derecha
        centerPosX, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Derecha
        centerPosX - edgeLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Tracera
        centerPosX - edgeLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Izquierda
        centerPosX, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX - edgeLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Izquierda

        // Cara Izquierda
        centerPosX - edgeLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - edgeLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Dereccha
        centerPosX - edgeLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX - edgeLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Derecha
        centerPosX, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Superior
        centerPosX - edgeLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - edgeLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX, centerPosY + halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX, centerPosY + halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Inferior
        centerPosX - edgeLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - edgeLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Arriba Derecha
        centerPosX, centerPosY - halfSideLength, centerPosZ - halfSideLength, // Abajo Derecha
        centerPosX, centerPosY - halfSideLength, centerPosZ + halfSideLength  // Abajo Izquierda
    };
    GLfloat colour[] = {
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
    };
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void DrawCube3(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        // Cara Frontal
        centerPosX - halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength + 10, // Arriba Izquierda
        centerPosX + halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength + 10, // Arriba Derecha
        centerPosX + halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength + 10, // Abajo Derecha
        centerPosX - halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength + 10, // Abajo Izquierda

        // Cara Posterior
        centerPosX - halfSideLength / 3, centerPosY + 30 , centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX + halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength, // Arriba Derecha
        centerPosX + halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Izquierda
        centerPosX - halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength + 10, // Arriba Izquierda
        centerPosX - halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength, // Arriba Dereccha
        centerPosX - halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Derecha
        centerPosX - halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength + 10, // Abajo Izquierda

        // Cara Derecha
        centerPosX + halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength + 10, // Arriba Izquierda
        centerPosX + halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength, // Arriba Dereccha
        centerPosX + halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Derecha
        centerPosX + halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength + 10, // Abajo Izquierda

        // Cara Superior
        centerPosX - halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength + 10, // Arriba Derecha
        centerPosX + halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength + 10, // Abajo Derecha
        centerPosX + halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength, // Abajo Izquierda

        // Cara Inferior
        centerPosX - halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength, // Arriba Izquierda
        centerPosX - halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength + 10, // Arriba Derecha
        centerPosX + halfSideLength / 3, centerPosY - halfSideLength, centerPosZ + halfSideLength + 10, // Abajo Derecha
        centerPosX + halfSideLength / 3, centerPosY + 30, centerPosZ + halfSideLength, // Abajo Izquierda

    };
    GLfloat colour[] = {
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

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

