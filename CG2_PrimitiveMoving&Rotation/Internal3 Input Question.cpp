#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>
#include<ShaderH.h>
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow* window);
void InputFromKey(GLFWwindow* window);

const unsigned int SCR_WIDTH = 640;
const unsigned int SCR_HEIGHT = 640;

glm::mat4 transform = glm::mat4(1.0f);

int main()
{
	//GLFW Initilization--------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//----------------------------------------

	//Window Creation------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Input Sqaure Render", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "FAILED TO CREATE THE WINDOW!!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//---------------------------------------------
	//GLAD Initialization
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD is not initialized!!" << std::endl;
		glfwTerminate();
		return -1;
	}

	Shader myShader = Shader("Vertex.shader", "Fragment.shader");


	float vertices[] = {        
		0.5f,  0.5f, 0.0f,    // top right
		0.5f, -0.5f, 0.0f,     // bottom right
	   -0.5f, -0.5f, 0.0f,  // bottom left
	   -0.5f,  0.5f, 0.0f,       // top left 
	};
	unsigned int indices[] = { 
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	//VBO - Vertex Buffer Object || VAO - Vertex Array Object || EBO - Element Buffer Object
	unsigned int VBO, VAO, EBO;

	//VBO Declaration
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//VAO Declaration
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//EBO Declaration
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	
	myShader.use();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); 
	
	while (!glfwWindowShouldClose(window))
	{
		//Inputs with the function to take input from keyss
		ProcessInput(window);
		InputFromKey(window);
		//Render
		glClearColor(0.6f, 0.5f, 0.8f, 1.0f);//RGBA Color space value
		glClear(GL_COLOR_BUFFER_BIT);

		
		myShader.setMat4("transform", transform);
		myShader.use();


		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//Buffer Swapping And Event Tracking
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
void InputFromKey(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		transform = glm::translate(transform, glm::vec3(0.001f, 0.0f, 0.0f));
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		transform = glm::translate(transform, glm::vec3(-0.001f, 0.0f, 0.0f));
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		transform = glm::translate(transform, glm::vec3(0.0f, -0.001f, 0.0f));
	}
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		transform = glm::translate(transform, glm::vec3(0.0f, 0.001f, 0.0f));
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		transform = glm::rotate(transform, glm::radians(10.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	}
	else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		transform = glm::rotate(transform, glm::radians(10.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	}
	else
	{
		
		//transform = glm::rotate(transform, float(glfwGetTime()), glm::vec3(0.0f, 0.0f, 0.0f));
	}
	
}
//glm::mat4 InputFromKey(GLFWwindow* window)
//{
//	glm::mat4 transform = glm::mat4(1.0f);
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	{
//		transform = glm::translate(transform, glm::vec3(0.1f, 0.0f, 0.0f));
//	}
//
//
//
//	return transform;
//}

//glm::mat4 InputFromKey(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	{
//		glm::mat4 transformhere = glm::mat4(1.0f);
//		transformhere += glm::translate(transformhere, glm::vec3(0.1f, 0.0f, 0.0f));
//		return transformhere;
//	}
//}