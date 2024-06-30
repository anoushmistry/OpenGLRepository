#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>
#include<ShaderH.h>
using namespace std;

void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow* window);

const unsigned int scrWidth = 640;
const unsigned int scrHeight = 640;

int main()
{
	// GLFW Initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//

	// Window Creation
	GLFWwindow* window = glfwCreateWindow(scrWidth, scrHeight, "Polygon Render", NULL, NULL);

	if (window == NULL)
	{
		cout << "Failed To Create Window." << endl;

		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);
	//

	// Glad Initialization
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "GLAD not initialized" << endl;

		glfwTerminate();
		return -1;
	}
	//

	Shader TriShader = Shader("Vertex.shader", "fragment.shader");

	// Polygon Calulations
	const float radius = 0.6f;
	const int noOfDivs = 6;
	float twoPi = 4 * acos(0.0f); // 2 * pi. ( acos(0.0f) = pi / 2 )
	float vertices[noOfDivs * 3];

	int i = 0;
	float col = 0.0f;

	while (i < noOfDivs)
	{
		
		float xValue = cos((twoPi * i) / noOfDivs) * radius;
		float yValue = sin((twoPi * i) / noOfDivs) * radius;

		//XYZ Coords
		vertices[(i * 3)] = xValue;
		vertices[(i * 3) + 1] = yValue;
		vertices[(i * 3) + 2] = 0.0f;

		i++;
	}

	//-------------------

	//VBO - Vertex Buffer Object || VAO - Vertex Array Object
	unsigned int VBO, VAO;

	//VBO Declaration
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//VAO Declaration
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); //Unbinding the current allocated Buffer
	glBindVertexArray(0); //Unbinding the current allocated VAO

	// Render Loop
	while (!glfwWindowShouldClose(window))
	{
		// Inputs
		ProcessInput(window);
		float timeT = glfwGetTime();
		// Render
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		/*glClearColor(sinf(timeT), cosf(timeT), sinf(timeT * 2), 1.0f);*/
		glClear(GL_COLOR_BUFFER_BIT);
		
		//glLineWidth(5.0f);
		TriShader.use();
		
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLE_FAN, 0, noOfDivs); // draw and fill polygon
		//glDrawArrays(GL_LINE_LOOP, 0, noOfDivs); // draw only outline

		// BufferSwapping and Event Tracking
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
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