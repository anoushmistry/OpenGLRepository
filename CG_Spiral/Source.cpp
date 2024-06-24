#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <ShaderH.h>

using namespace std;

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // GLFW Initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window Creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Spiral Window", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);

    // GLAD Initialization
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    Shader TriShader = Shader("Vertex.shader", "fragment.shader");

    //--Circle Calulations
    float radius = 0.6f;
    float a = 0.0f;
    float b = 0.01f;
    int noOfRotations = 45;
    const int divisions = 6000;
    float angle = 0.0f;
    float TotalAngle = 2 * 2 * acos(0.0f); // cos inverse 3.141518
    float vertices[divisions * 6];
    int i = 0;

    while (i < divisions)
    {
        angle = (TotalAngle * float(i)) / ((float)divisions) * noOfRotations;

        float xValue = cos(angle) * radius;
        float yValue = sin(angle) * radius;
        radius = a + b * angle;
        vertices[(i * 6)] = xValue;
        vertices[(i * 6) + 1] = yValue;
        vertices[(i * 6) + 2] = 0.0f;

        //RGB values
        vertices[(i * 6) + 3] = cos(xValue);
        vertices[(i * 6) + 4] = cos(yValue);
        vertices[(i * 6) + 5] = tan(xValue);
        i++;
    }

    //-------------------


    //VBO - VERTEX BUFFER OBJECT || VAO - VERTEX ARRAY OBJECT
    unsigned int VBO, VAO;


    //VBO DECLARATION
    glGenBuffers(1, &VBO);


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //VAO DECLARATION
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    glBindVertexArray(0); //unbinding the current allocated VAO


    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // INPUTS
        processInput(window);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        float timeH = sinf(glfwGetTime());

        float time = cosf(glfwGetTime()) * timeH;
        // RENDER
        //glClearColor(time, cosf(time), time, 1.0f);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glLineWidth(5.0f);
        TriShader.use();
        TriShader.setFloat("timeH", timeH);
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINE_LOOP, 0, divisions);
        //glDrawArrays(GL_TRIANGLE_FAN, 0, divisions);


        // BUFFER SWAPPING AND EVENT TRACKING
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
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}