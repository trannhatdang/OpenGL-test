#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
	if(!glfwInit())
	{
		printf("init failed\n");
		
	}
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		printf("Window creation failed\n");
	}

	glfwDestroyWindow(window);

	glfwTerminate();
}
