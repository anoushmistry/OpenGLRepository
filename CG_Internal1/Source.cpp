//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//#include<cmath>
//#include<ShaderH.h>
//
//void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
//void ProcessInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 640;
//const unsigned int SCR_HEIGHT = 640;
//
//int main()
//{
//	//GLFW Initilization--------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//----------------------------------------
//
//	//Window Creation------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Practice Render", NULL, NULL); // NULL ,NULL are the parameters are used when using multiple screens
//	if (window == NULL)
//	{
//		std::cout << "FAILED TO CREATE THE WINDOW!!" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
//	//---------------------------------------------
//	//GLAD Initialization
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "GLAD is not initialized!!" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	//Shader TriangleShader1 = new Shader("myVertex.shader", "myFragment.shader");
//	Shader TriShader = Shader("Vertex.shader","fragment.shader");
//
//	float vertices[] = {
//		-0.3,0.2f,0.0f, // left vertex -0th STRIDE
//		-0.5f,-0.1f,0.0f, // right vertex - 1st STRIDE
//		-0.1f,-0.1f,0.0f	//Top Vertex - 2nd STRIDE
//	};
//	float vertices2[] = {
//		0.3f,0.2f,0.0f,
//		0.5f,-0.1f,0.0f,
//		0.1f,-0.1f,0.0f
//	};
//
//	//VBO - Vertex Buffer Object - Creating empty buffer (space)in the GPU to store values
//	// VAO - Vertex Array Object - 
//	unsigned int VBO[2], VAO[2];
//
//	//VBO Declaration 
//	glGenBuffers(2, VBO);
//	glGenVertexArrays(2, VAO); // Generating two VAOs
//	//Binding Buffers for first triangle
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//	//VAO Generation for first triangle
//	glBindVertexArray(VAO[0]);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0); //unbindin the current allocated VBO
//	glBindVertexArray(0); // unbinding the correct allocated VAO
//
//	//VBO for second triangle
//	glBindVertexArray(VAO[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	
//
//    
//	//Render loop
//	while (!glfwWindowShouldClose(window))
//	{
//		//Inputs
//		ProcessInput(window);
//
//		//float time = sinf(glfwGetTime());
//
//		//Render
//		glClearColor(1.0f, 0.4f, 0.6f, 1.0f);//RGBA Color space value
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		TriShader.use();
//		glBindVertexArray(VAO[0]);
//		glDrawArrays(GL_TRIANGLES,0,3);
//
//		glBindVertexArray(VAO[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		
//
//		//Buffer Swapping And Event Tracking
//		glfwSwapBuffers(window); // Constantly refresh screen and refresh buffers
//		glfwPollEvents();		//Tracking events from keyboard
//
//	}
//
//	glfwTerminate();  //Close the window
//	return 0;
//}
//
//void frameBufferSizeCallBack(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height); //Width and height will be given when re-sizing window
//}
//void ProcessInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //When we press Escape then window should close
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}