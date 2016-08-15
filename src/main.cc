#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  // Attempt to init glfw fail if error
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // Create a GLFWwindow with our desired settings
  int winWidth = 1024, winHeight = 768;
  GLFWwindow *window = nullptr;
  window = glfwCreateWindow(winWidth, winHeight, "glfw", NULL, NULL);

  // Ensure window we created is valid
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Make our created window the current context
  glfwMakeContextCurrent(window);

  std::cout << "Hello world!" << std::endl;

  // ------- MAIN LOOP -------------------------------------------------------
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

  return 0;
}
