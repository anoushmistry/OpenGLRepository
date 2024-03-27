#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 640;
const unsigned int SCR_HEIGHT = 640;

int main()
{
	//GLFW Initialization--------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//-------------------------------

	//Window Creation-----------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "My First Window", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create the window!!!" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);

	//---------------------------
	//GLAD Initialization--------------------

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "GLAD is not initialized!!";
		glfwTerminate();
		return -1;
	}
	//----------------------
	
	//Render Loop using While-----------------
	while (!glfwWindowShouldClose(window))
	{
		//Inputs
		ProcessInput(window);

		//Render
		glClearColor(0.0f,0.0f,0.5f,1.0f); //RGBA Color Space Value
		glClear(GL_COLOR_BUFFER_BIT);
		

		//Render Swapping and Event Tracking
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}