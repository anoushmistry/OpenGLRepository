#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cmath>
#include<ShaderH.h>
#include<iostream>

using namespace std;

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 800;

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow* window);

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height); //Helps when re-sizing to incorporate the size of the triangles
}
void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Escape key input
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main()
{
	glfwInit();
	glfwWindowHint(GL_MAJOR_VERSION, 3);
	glfwWindowHint(GL_MINOR_VERSION, 3);
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TWO TRIANGLES", NULL, NULL);


	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);

	if (window == NULL)
	{
		cout << "Window failed";
		glfwTerminate();
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Not initialized"<<endl;
		glfwTerminate();
	}
	Shader FirstTriangleShader = Shader("myVertex.shader", "myfragment.shader");
	Shader SecondTriangleShader = Shader("myVertex.shader", "myfragment2.shader");


	float vertices[] = {
		-0.3,0.2f,0.0f, // left vertex triangle 1
		-0.5f,-0.1f,0.0f, // right vertex triangle 1
		-0.1f,-0.1f,0.0f	//Top Vertex triangle 1
	};
	float vertices2[] = {
		0.3f,0.2f,0.0f,	//left vertex triangle 2 
		0.5f,-0.1f,0.0f, // right vertex triangle 2
		0.1f,-0.1f,0.0f		// Top vertex triangle 2
	};

	unsigned int VBO[2], VAO[2];

	glGenBuffers(2, VBO);
	glGenVertexArrays(2, VAO);

	//First Triangle VBO Binding with data
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//First Triangle VAO generation
	glBindVertexArray(VAO[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);


	//Second Triangle VBO binding and data
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2),vertices2,GL_STATIC_DRAW);

	//Second Triangle VAO generation
	glBindVertexArray(VAO[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	//Starting render loop
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		

		glClearColor(0.1f, 0.3f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		FirstTriangleShader.use();
		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		SecondTriangleShader.use();
		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
