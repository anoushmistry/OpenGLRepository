#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<ShaderH.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 1200;


glm::vec3 trianglePosition(0.0f, 0.0f, 0.0f);


int main()
{
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Triangle with Fragment Interpolation", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

   
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD has not been initialized" << std::endl;
        return -1;
    }
    Shader TriangleShader = Shader("vertex.shader", "fragment.shader");

   
    float vertices[] = {
       
         0.5f, -0.5f, 0.0f,  0.5f, 0.0f, 0.0f,  // right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  //  left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top

    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
   
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

   
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

       
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float timeT = glfwGetTime();
        TriangleShader.setFloat("timeT", timeT);

        glm::mat4 mytransform = glm::mat4(1.0f);
        mytransform = glm::translate(mytransform, trianglePosition);
        mytransform = glm::rotate(mytransform, float(glfwGetTime()), glm::vec3(0.0f, 0.0f, 0.001f));

        TriangleShader.setMat4("transform", mytransform);
        TriangleShader.use();
       
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        
       
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

  
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    const float moveSpeed = 0.001f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        trianglePosition.y += moveSpeed; // Move up
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        trianglePosition.y -= moveSpeed; // Move down
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        trianglePosition.x -= moveSpeed; // Move left
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        trianglePosition.x += moveSpeed; // Move right



}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
   
    glViewport(0, 0, width, height);
}