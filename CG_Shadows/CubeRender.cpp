#include<CubeRender.h>

#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

unsigned int indices[] ={
	0,1,2, // First triangle elements
	2,3,0  // Second trinangle elements
};

unsigned int VBO, VAO, EBO;

unsigned int shaderID;

unsigned int texture1,texture2;

glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
};

void InitCubeVerts(float x, float y, float length)
{	
	//X,Y,Z - R,G,B - U,V
	float vertices[] = {
	   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	
		
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	/*glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	//Sending data to the 0th attribute location
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//Sending data to the 1st attribute location
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	////Sending data to the 2nd attribute location
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//glEnableVertexAttribArray(2);

	//int width, height, clrChannels;
	//unsigned char* data;
	////Loading and creating the Texture1
	//{
	//	glGenTextures(1, &texture1);
	//	glBindTexture(GL_TEXTURE_2D, texture1);
	//	//Settting of Texture wrapping parameters.
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//	//Settting of Texture filtering parameters.
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//	//Loading the image file
	//	

	//	stbi_set_flip_vertically_on_load(true);

	//	data = stbi_load("Demon.jpg", &width, &height, &clrChannels, STBI_rgb_alpha);
	//	if (data)
	//	{
	//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	//		glGenerateMipmap(GL_TEXTURE_2D);
	//	}
	//	else
	//	{
	//		std::cout << "FAILED TO LOAD THE IMAGE!" << std::endl;
	//	}
	//	stbi_image_free(data);
	//}

	////Loading and creating the Texture2
	//{
	//	glGenTextures(1, &texture2);
	//	glBindTexture(GL_TEXTURE_2D, texture2);
	//	//Settting of Texture wrapping parameters.
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//	//Settting of Texture filtering parameters.
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//	
	//	stbi_set_flip_vertically_on_load(true);

	//	data = stbi_load("Nezuko.png", &width, &height, &clrChannels, STBI_rgb_alpha);
	//	if (data)
	//	{
	//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	//		glGenerateMipmap(GL_TEXTURE_2D);
	//	}
	//	else
	//	{
	//		std::cout << "FAILED TO LOAD THE IMAGE!" << std::endl;
	//	}
	//	stbi_image_free(data);
	//}



	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void RenderCube(const char* vertex, const char* fragment)
{
	Shader myShader(vertex, fragment);
	shaderID = myShader.ID;
	myShader.use();

	
	myShader.use();
	myShader.setVec3("color1", glm::vec3(0.9f, 0.9f, 0.9f));     // Light checker color
	myShader.setVec3("color2", glm::vec3(0.3f, 0.3f, 0.3f));     // Dark checker color
	myShader.setVec3("shadowColor", glm::vec3(0.3f, 0.3f, 0.3f)); // Darker overlay color for shadows
	myShader.setVec2("checkerSize", glm::vec2(1.0f, 1.0f));      // Checker square size

	// Set light position above ground and a bit to the side for shadow effect
	glm::vec3 lightPosition(5.0f, 10.0f, 5.0f); // Example light position
	glm::mat4 shadowProj = glm::mat4(1.0f);

	// Configure shadow projection matrix to project onto ground (XZ plane)
	shadowProj[1][1] = 0.0f;                     // Flatten shadow on Y-axis (ground plane)
	shadowProj[3][1] = -1.0f / lightPosition.y;  // Adjust based on light position height

	myShader.setMat4("shadowProj", shadowProj);


	for (unsigned int i = 0; i < 10; i++) {
		

		// Pass the time to the shader for potential animated effects
		float timeValue = glfwGetTime();
		myShader.setFloat("time", timeValue);

		// Create transformations
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);

		myShader.setMat4("model", model);
		myShader.setMat4("view", view);
		myShader.setMat4("projection", projection);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}


void DeleteCubeData()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderID);
}