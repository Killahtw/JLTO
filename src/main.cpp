#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
using std::cout; using std::cin; using std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); //func for resize window
void keyLog(GLFWwindow window);

const int WIDTH = 1280;
const int  HEIGHT = 720;

float ke_color;

int main() {
	
	glfwInit(); // Команда инициализации
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Старшая цифра версии (1 аргумент)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // Младшая цифра версии (1 аргумент)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //if MacOS
	
	 
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "jlto", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "GLAD not initialized" << endl;
	}
	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window)){ //Rendering
		glfwSwapBuffers(window); // fps
		glfwPollEvents();
		
		glClearColor(ke_color, 0.3f, 0.3f, 1.0f); // background attribute
		glClear(GL_COLOR_BUFFER_BIT); // backgroud set

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, true);
		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			ke_color += 0.001;
		}
	}
	glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}