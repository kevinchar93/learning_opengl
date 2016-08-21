#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action,
    int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{

    // --------------------------------------------------------------------------------------------------
    // init GLFW and set up all the settings for our window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // create the window based on earlier settings & set it as the current context
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // set up the callbacks that are needed
    glfwSetKeyCallback(window, key_callback);

    // --------------------------------------------------------------------------------------------------
    // init the glew library before we begin calling any opengl functions
    glewExperimental = GL_TRUE; // so GLEW know to use modern approach for getting func ptrs & extensions
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // set up the viewport that will will be rendering to
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // --------------------------------------------------------------------------------------------------
    // the main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // check and call events
        glfwPollEvents();

        // Rendering commangs here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap the front and back buffer
        glfwSwapBuffers(window);
    }

    // clean up any alloced resources
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scanecode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
