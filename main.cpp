// PROYECTO GRAFICAS MARTHA Y MAURICIO
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#include "Shapes.h"
#include "House.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define X_ORIGIN 0
#define X_LIMIT SCREEN_WIDTH
#define Y_ORIGIN 0
#define Y_LIMIT SCREEN_HEIGHT
#define Z_ORIGIN 0
#define Z_LIMIT SCREEN_WIDTH


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void drawScene();

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
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
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Coronavirus", NULL, NULL);

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
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 0);

        drawScene();
        drawHouse(halfScreenWidth, halfScreenHeight, -200, 120, 200, 50);

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
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX -= rotationSpeed;
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
            translationY += 10;
            break;
        case GLFW_KEY_X:
            translationY -= 10;
            break;
        }
    }
}

void drawScene() {

    //Arreglo para agregar color
    GLfloat color[] = {
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
    drawCube((X_ORIGIN + X_LIMIT) / 2.0, X_LIMIT,
        (Y_ORIGIN + Y_LIMIT) / 2.0, Y_LIMIT,
        (Z_ORIGIN + Z_LIMIT) / 2.0, (Z_ORIGIN + Z_LIMIT),
        color);


    GLfloat vertices[] =
    {
        // Cara frontal: verde
        X_ORIGIN, Y_ORIGIN, (Z_ORIGIN + Z_LIMIT)/2, // Arriba Izquierda
        X_LIMIT, Y_ORIGIN, (Z_ORIGIN + Z_LIMIT)/2, // Arriba Derecha
        X_LIMIT, Y_LIMIT, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Derecha
        X_ORIGIN, Y_LIMIT, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Izquierda

        // Cara Tracera: morado
        X_ORIGIN, Y_ORIGIN, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Izquierda
        X_LIMIT, Y_ORIGIN, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Derecha
        X_LIMIT, Y_LIMIT, -(Z_ORIGIN + Z_LIMIT)/2, // Abajo Derecha
        X_ORIGIN, Y_LIMIT, -(Z_ORIGIN + Z_LIMIT)/2, // Abajo Izquierda

        // Cara Izquierda: azul
        X_ORIGIN, Y_ORIGIN, (Z_ORIGIN + Z_LIMIT)/2, // Arriba Izquierda
        X_ORIGIN, Y_ORIGIN, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Derecha
        X_ORIGIN, Y_LIMIT, -(Z_ORIGIN + Z_LIMIT)/2, // Abajo Derecha
        X_ORIGIN, Y_LIMIT, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Izquierda

        // Cara Derecha: celeste
        X_LIMIT, Y_ORIGIN, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Izquierda
        X_LIMIT, Y_ORIGIN, (Z_ORIGIN + Z_LIMIT)/2, // Arriba Derecha
        X_LIMIT, Y_LIMIT, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Derecha
        X_LIMIT, Y_LIMIT, -(Z_ORIGIN + Z_LIMIT)/2, // Abajo Izquierda

        // Cara Superior
        X_ORIGIN, Y_ORIGIN, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Izquierda
        X_LIMIT, Y_ORIGIN, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Derecha
        X_LIMIT, Y_ORIGIN, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Derecha
        X_ORIGIN, Y_ORIGIN, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Izquierda

        // Cara Inferior
        X_ORIGIN, Y_LIMIT, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Izquierda
        X_LIMIT, Y_LIMIT, -(Z_ORIGIN + Z_LIMIT)/2, // Arriba Derecha
        X_LIMIT, Y_LIMIT, (Z_ORIGIN + Z_LIMIT)/2, // Abajo Derecha
        X_ORIGIN, Y_LIMIT, (Z_ORIGIN + Z_LIMIT)/2  // Abajo Izquierda

    };
}

