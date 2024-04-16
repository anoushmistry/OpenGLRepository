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
//	Shader TriShader = Shader("Vertex.shader", "fragment.shader");
//
//	float vertices[] = {
//		-0.1,0.2f,0.0f, //  t - r
//		-0.1f,-0.1f,0.0f, // b - r
//		-0.5f,-0.1f,0.0f,	// b -l
//		-0.5f,0.2f,0.0f		// t - l
//	};
//	unsigned int indices[] = {
//		0 , 1 , 3,
//		1 , 2 , 3
//	};
//	float vertices2[] = {
//		0.5f,0.2f,0.0f,
//		0.5f,-0.1f,0.0f,
//		0.1f,-0.1f,0.0f,
//		0.1f,0.2f,0.0f,
//	};
//	unsigned int indices2[] = {
//		0, 1 , 3 ,
//		1 , 2 , 3
//	};
//
//	//VBO - Vertex Buffer Object - Creating empty buffer (space)in the GPU to store values
//	// VAO - Vertex Array Object - 
//	unsigned int VBO[2], VAO[2], EBO[2];
//
//	//VBO Declaration 
//	glGenBuffers(2, VBO);
//	glGenVertexArrays(2, VAO); // Generating two VAOs
//	glGenBuffers(2, EBO);
//
//
//	//Binding Buffers for first square
//	//EBO
//	
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	
//	//VAO Generation for first square
//	glBindVertexArray(VAO[0]);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0); //unbindin the current allocated VBO
//	glBindVertexArray(0); // unbinding the correct allocated VAO
//
//	//VBO for second square
//	
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//
//	//VAO
//	glBindVertexArray(VAO[1]);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//EBO
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
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
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glBindVertexArray(VAO[1]);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
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