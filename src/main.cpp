#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
using std::cout; using std::cin; using std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); //func for resize window
void keyLog(GLFWwindow* window);
void Erys(); //prod

const int WIDTH = 1280;
const int  HEIGHT = 720;
float ke_color;

int main() {
	
	//Erys(); //Prod

<<<<<<< Updated upstream
	glfwInit(); // Команда инициализации
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Senior digit (1 argument)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // Younger digit (1 argumment)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //if MacOS
	
	 
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "jlto", NULL, NULL);
	glfwMakeContextCurrent(window);
=======
    SetConsoleOutputCP(CP_UTF8); //ru-encoding for console
    sqlite3* db;
    int rc = sqlite3_open("F:/Feed the Machine/cpp/JLTO/src/sql/storyline.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return rc;
    }
>>>>>>> Stashed changes

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "GLAD not initialized" << endl;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window)){ //Rendering
		keyLog(window); // buttons
		glfwSwapBuffers(window); // fps
		glfwPollEvents();

		glClearColor(ke_color, 0.3f, 0.3f, 1.0f); // background color
		glClear(GL_COLOR_BUFFER_BIT); // backgroud set
		
	}
	glfwTerminate(); // End glfw
}

void keyLog(GLFWwindow* window) { //button callback
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true); //Escape
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		ke_color += 0.001; //color
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}