#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  // Attempt to init glfw fail if error
  if (!glfwInit())
    exit(EXIT_FAILURE);

  /* -------------------------------------------------------------------------*/
  // Create and init a opengl context in the form of a window
  int winWidth = 1024, winHeight = 768;
  GLFWwindow *window = nullptr;
  window = glfwCreateWindow(winWidth, winHeight, "glfw", NULL, NULL);

  if (!window) {
    glfwTerminate();
    std::cout << "Window that was created is not valid !" << std::endl;
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);

  /* -------------------------------------------------------------------------*/
  // Now that our context exists we can init glew
  glewExperimental = true; // flag helps prevent errors with modern opengl
  GLenum glewError = glewInit();
  if (glewError != GLEW_OK) {
    std::cout << "glew init error: " << glewGetErrorString(glewError)
              << std::endl;
  }

  if (!GLEW_VERSION_2_1) {
    std::cout << "OpenGL 2.1 not supported!" << std::endl;
    return -1;
  }

  /* -------------------------------------------------------------------------*/
  // Now that we know glew supports the version of opengl we want we can now
  // query opengl
  const GLubyte *glVersion = glGetString(GL_VERSION);
  std::cout << "Graphics Driver: " << glVersion << std::endl;

  const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cout << "GLSL Version: " << glslVersion << std::endl;

  // check for some specific funtionality
  if (GLEW_ARB_vertex_array_object) {
    std::cout << "genVertexArrays supported" << std::endl;
  }

  if (GLEW_APPLE_vertex_array_object) {
    std::cout << "getVertexArrayAPPLE supported" << std::endl;
  }

  /* -------------------------------------------------------------------------*
  // MAIN LOOP
  while (!glfwWindowShouldClose(window)) {

    glViewport(0, 0, winWidth, winHeight); // set view port in pixels
    glClearColor(1, 0, 0, 1);              // clear window contents
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // put drawing code here

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Destroy the window and terminate glfw
  glfwDestroyWindow(window);
  glfwTerminate();

  */

  return 0;
}
