#include <iostream>
#include <glew.h>
#include <glm.hpp>
#include <glfw3.h>

#include "Grid.h"
#include "EditorCamera.h"

// Globals
GLFWwindow* window;
EditorCamera Camera;
Grid grid(10, 1.0f);

// keeps Windows fresh
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Opens and checks OpenGL Contexts
bool initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "3D Grid Renderer", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    return true;
}

void renderLoop() {
    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Camera.update(deltaTime); // Handle Camera Input

        //Refresh
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Projection Matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);

        // Set up Model to View Matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(
            Camera.getPosition().x, Camera.getPosition().y, Camera.getPosition().z,
            Camera.getPosition().x + Camera.getFront().x,
            Camera.getPosition().y + Camera.getFront().y,
            Camera.getPosition().z + Camera.getFront().z,
            Camera.getUp().x, Camera.getUp().y, Camera.getUp().z
        );

        // Render
        grid.Render();

        // Swap Buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main()
{
    std::cout << "Initializing!\n";

    if (!initialize()) {
        return -1;
    }

    Camera.setWindow(window);
    renderLoop();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

