#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cmath>
#include<ShaderH.h>
#include<CubeRender.h>
#include<iostream>


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 640;

void processInput(GLFWwindow* window);


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Internal 1 CG 2", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "failed to create the window! " << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD not initialized" << std::endl;
		glfwTerminate();
		return -1;
	}
	glEnable(GL_DEPTH_TEST);

	InitCubeVerts(0.0f, 0.0f, 0.5f);
	//RENDER LOOP
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);


		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		RenderCube("vertex.shader", "fragment.shader");

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	DeleteCubeData();

	glfwTerminate();
	return 0;
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
