#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>


#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 600

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void DrawCube2(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void DrawCube3(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void DrawScene(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
GLfloat rotationZ = 0.0f;
GLfloat translationX = 0.0f;
GLfloat translationY = 0.0f;
GLfloat translationZ = 0.0f;


int main(void)
{
    GLFWwindow* window;

    // Inicializar la librer�a
    if (!glfwInit())
    {
        return -1;
    }

    // Crear la ventana
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

    // Declarar que se recibir�n comando del teclado
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);


    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Se crea el contexto de la ventana
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, screenWidth, screenHeight); // Espec�fica en que parte de la ventana se dibujaran los elementos
    glMatrixMode(GL_PROJECTION); // Se crea la matriz de proyecci�n
    glLoadIdentity(); // Se crea de la matriz identidad
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); // Establecer el sistema de coordenadas
    glMatrixMode(GL_MODELVIEW); // Matriz de transformaci�n


    // Se establece el sistema de coordenadas dentro de la ventana
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;


    // Loop en donde se estar� dibujando la ventana
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, 0); // Coloca el cubo al centro de la pantalla
        glTranslated(translationX, translationY, translationZ); // Mueve el cubo con las variables de las teclas (Vector de Traslaci�n
        glRotatef(rotationX, 1, 0, 0); // Rotar el cubo en X
        glRotatef(rotationY, 0, 1, 0); // Rotar el cubo en Y
        glRotatef(rotationZ, 0, 0, 1);
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 0);

        DrawCube(halfScreenWidth, halfScreenHeight, -200, 100);
        DrawCube2(halfScreenWidth + 50, halfScreenHeight, -200, 100);
        DrawCube3(halfScreenWidth, halfScreenHeight, -200, 100);

        DrawScene(halfScreenWidth, halfScreenHeight, 0, 1080);


        glPopMatrix();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}


// LLamar mandar las teclas
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    const GLfloat rotationSpeed = 10;

    // Switch en donde se determinan los movimientos del cubo en base a las teclas
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotationY -= rotationSpeed;
            break;

        case GLFW_KEY_A:
            translationX -= 10;
            break;
        case GLFW_KEY_S:
            translationX += 10;
            break;
        case GLFW_KEY_W:
            translationZ += 10;
            break;
        case GLFW_KEY_X:
            translationZ -= 10;
            break;
        }
    }
}

void DrawScene(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength) {
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        // Cara frontal: verde
        0, 0, 540, // Arriba Izquierda
        1080, 0, 540, // Arriba Derecha
        1080, 600, 540, // Abajo Derecha
        0, 600, 540, // Abajo Izquierda

        // Cara Tracera: morado
        0, 0, -540, // Arriba Izquierda
        1080, 0, -540, // Arriba Derecha
        1080, 600, -540, // Abajo Derecha
        0, 600, -540, // Abajo Izquierda

        // Cara Izquierda: azul
        0, 0, 540, // Arriba Izquierda
        0, 0, -540, // Arriba Derecha
        0, 600, -540, // Abajo Derecha
        0, 600, 540, // Abajo Izquierda

        // Cara Derecha: celeste
        1080, 0, -540, // Arriba Izquierda
        1080, 0, 540, // Arriba Derecha
        1080, 600, 540, // Abajo Derecha
        1080, 600, -540, // Abajo Izquierda

        // Cara Superior
        0, 0, -540, // Arriba Izquierda
        1080, 0, -540, // Arriba Derecha
        1080, 0, 540, // Abajo Derecha
        0, 0, 540, // Abajo Izquierda

        // Cara Inferior
        0, 600, -540, // Arriba Izquierda
        1080, 600, -540, // Arriba Derecha
        1080, 600, 540, // Abajo Derecha
        0, 600, 540  // Abajo Izquierda


    };
    //Arreglo para agregar color
    GLfloat colour[] = {
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        0.0, 255.0, 0.0,
        255.0, 0.0, 255.0,
        255.0, 0.0, 255.0,
        255.0, 0.0, 255.0,
        255.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 0.0, 255.0,
        0.0, 255.0, 255.0,
        0.0, 255.0, 255.0,
        0.0, 255.0, 255.0,
        0.0, 255.0, 255.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 0.0, 0.0,
        255.0, 255.0, 0.0,
        255.0, 255.0, 0.0,
        255.0, 255.0, 0.0,
        255.0, 255.0, 0.0,
    };

    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
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



void DrawCube4(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    int width, height;          // Window width and height
    float ratio;                // Window aspect ratio
    float x_rot = 0.0f;         // X rotation scaling factor
    float y_rot = 0.0f;         // Y rotation scaling factor
    float delta_rot = 1.0f;     // Ammount rotation changes on key press
    int number_of_vertices = 3; // Number of vertices in buffer
    int buffer_size = number_of_vertices * 12;
    GLfloat vertices[] = { centerPosX -0.6f, centerPosY -0.4f, centerPosZ + 0.0f, // vertex coordinates
             centerPosX + 0.6f, centerPosY -0.4f,centerPosZ + 0.0f,
              centerPosX + 0.0f,centerPosY + 0.6f, centerPosZ + 0.0f };
    GLfloat colors[] = { 255.0f, 255.0f, 255.0f,     // vertex colors
            255.0f, 255.0f, 255.0f,
            255.0f, 255.0f, 255.0f };
    GLuint vertex_buffer_id, color_buffer_id; // vertex buffer id's
    

    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // Se coment� esta linea para quitar poder hacer solidos a los objetos
    glEnable(GL_DEPTH_TEST); //Agregar la proyecci�n de profundidad
    glDepthMask(GL_TRUE);//Agregar la proyecci�n de profundidad
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors); //Buffer de color
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
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
