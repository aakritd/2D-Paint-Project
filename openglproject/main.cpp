#include<iostream>
#include<glad/glad.h>
#include <GLFW/glfw3.h>


using namespace std;

int exception = 1;
// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"uniform vec4 color;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = color;"

"}";


//Necessary Global Variables


float winX = 800;
float winY = 600;

float pixelX = 2 / winX;
float pixelY = 2 / winY;


GLuint VBO, VAO;

unsigned int vertexShader;
unsigned int fragmentShader;

unsigned int shaderProgram;


int global_priority = -1;
int main_rendering_priority = -1;

int count_edit = 0;
char switch_for_tredit;
float current_color[] =
{
	1.0f,1.0f,1.0f
};



float mouseXpos, mouseYpos;


float vertices[] = {
		0.0f,0.0f,0.0f,//brush
		0.0f,0.0f,0.0f
};




float vertices1[] = {
		0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,

		-0.95f,0.95f,0.0f,
		0.95f,0.95f,0.0f,

		0.95f,0.95f,0.0f,
		0.95f,-0.95f,0.0f,


		0.95f,-0.95f,0.0f,
		-0.95f,-0.95f,0.0f,

		-0.95f,-0.95f,0.0f,
		-0.95f,0.95f,0.0f,

		0.0f,0.0f,0.0f,//10th,30th float
		0.0f,0.0f,0.0f,
		


};

float vertices2[] = {
	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,

	0.0f,0.0f,0.0f,
	



	

};


float vertices3[] =
{
	0.0f,0.0f,0.0f,
	0.0f,0.0f,0.0f
};

bool leftMousePressed = false;
bool leftMouseReleased = false;

bool rightMousePressed = false;
bool rightMouseReleased = false;

bool enterPressed = false;

char choice = 'z';
char color_choice = 'z';
char feature_choice = 'z';

int SCREEN_WIDTH, SCREEN_HEIGHT;

int colorUniformLocation;
int colorUniformLocation1;
int colorUniformLocation2;
int colorUniformLocation3;
int colorUniformLocation4;

char switch_for_lineedit;
char switch_for_rttredit;
char switch_for_recedit;
//including header files

#include "maindrawingframe.h"

#include"color.h"

#include"buttons.h"

#include "line.h"

#include"brush.h"

#include"rectangle.h"

#include"triangle.h"

#include"rt_tr.h"

#include"eraser.h"




#include "fillcolor.h"







brush_node* brush_head = NULL;

line_node* line_head = NULL;

rec_node* rec_head = NULL;

tr_node* tr_head = NULL;

rt_tr_node* rt_tr_head = NULL;

fill_node* fill_head = NULL;

eraser_node* eraser_head = NULL;

render_fill_node* render_fill_head = NULL;



brush_node* brush_tail = NULL;

line_node* line_tail = NULL;

rec_node* rec_tail = NULL;

tr_node* tr_tail = NULL;

rt_tr_node* rt_tr_tail = NULL;

fill_node* fill_tail = NULL;

eraser_node* eraser_tail = NULL;

render_fill_node* render_fill_tail = NULL;


#include"clear_all.h"

#include"undo.h"


///////////////////////////////FUNCTIONS/////////////////////////////




//functions for mouse input
void mouse_position_callback(GLFWwindow* window, double xPos, double yPos)
{
	mouseXpos = (float)(xPos - 400.0f) / 400.0f;
	mouseYpos = (float)-(yPos - 300.0f) / 300.0f;

	//cout << "Mouse Position : " << mouseXpos << "," << mouseYpos << endl;


}





void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		leftMousePressed = true;
		leftMouseReleased = false;
		cout << "Left mouse button pressed" << endl;

		//FOR OBJECTS TO RENDER
		if (mouseXpos >= 0.95f && mouseYpos >= 0.95f)
		{
			choice = 'a';
			leftMousePressed = false;
		}

		if (mouseXpos >= 0.95f && mouseYpos >= 0.85f && mouseYpos <= 0.90f)
		{
			choice = 'b';
			leftMousePressed = false;
		}


		if (mouseXpos >= 0.95f && mouseYpos >= 0.75f && mouseYpos <= 0.80f)
		{
			choice = 'c';
			leftMousePressed = false;
		}

		if (mouseXpos >= 0.95f && mouseYpos >= 0.65f && mouseYpos <= 0.70f)
		{
			choice = 'd';
			leftMousePressed = false;
		}

		if (mouseXpos >= 0.95f && mouseYpos >= 0.55f && mouseYpos <= 0.60f)
		{
			choice = 'e';
			leftMousePressed = false;
		}



		cout << "choice : " << choice << endl;


		//FOR COLOR OF OBJECTS
		if (mouseXpos <= -0.95f && mouseYpos <= -0.95f)
		{
			color_choice = 'a';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.90f && mouseXpos <= -0.85f && mouseYpos <= -0.95f)
		{
			color_choice = 'b';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.80f && mouseXpos <= -0.75f && mouseYpos <= -0.95f)
		{
			color_choice = 'c';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.70f && mouseXpos <= -0.65f && mouseYpos <= -0.95f)
		{
			color_choice = 'd';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.60f && mouseXpos <= -0.55f && mouseYpos <= -0.95f)
		{
			color_choice = 'e';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.50f && mouseXpos <= -0.45f && mouseYpos <= -0.95f)
		{
			color_choice = 'f';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.40f && mouseXpos <= -0.35f && mouseYpos <= -0.95f)
		{
			color_choice = 'g';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.30f && mouseXpos <= -0.25f && mouseYpos <= -0.95f)
		{
			color_choice = 'h';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.20f && mouseXpos <= -0.15f && mouseYpos <= -0.95f)
		{
			color_choice = 'i';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.10f && mouseXpos <= -0.05f && mouseYpos <= -0.95f)
		{
			color_choice = 'j';
			leftMousePressed = false;
		}

		if (mouseXpos >= 0.0f && mouseXpos <= 0.05f && mouseYpos <= -0.95f)
		{
			color_choice = 'z';
			leftMousePressed = false;
		}


		cout << "color choice : " << color_choice << endl;

		//FOR FEATURES

		if (mouseXpos <= -0.95f && mouseYpos >= 0.95f)
		{
			feature_choice = 'p';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.90f && mouseXpos <= -0.85f && mouseYpos >= 0.95f)
		{
			feature_choice = 'u';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.80f && mouseXpos <= -0.75f && mouseYpos >= 0.95f)
		{
			choice = 'f';
			leftMousePressed = false;
		}

		if (mouseXpos >= -0.70f && mouseXpos <= -0.65f && mouseYpos >= 0.95f)
		{
			feature_choice = 'f';
			leftMousePressed = false;
		}



		//TO EXECUTE SOME FEATURES

		cout << "feature choice : " << feature_choice << endl;

	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		leftMouseReleased = true;
		leftMousePressed = false;
		cout << "Left mouse button released" << endl;

		if (mouseXpos >= 0.95f && mouseYpos >= 0.95f)
		{
			leftMouseReleased = false;
		}

		if (mouseXpos >= 0.95f && mouseYpos >= 0.85f && mouseYpos <= 0.90f)
		{
			leftMouseReleased = false;
		}
		cout << "choice : " << choice << endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{

		rightMousePressed = true;
		cout << "Right mouse button pressed" << endl;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		rightMouseReleased = true;
		rightMousePressed = false;
		cout << "right mouse button released" << endl;
	}
}



//functions controlling input for keyboard and mouse

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		cout << "ENTER PRESSED" << endl;
		enterPressed = true;
	}
	glfwSetCursorPosCallback(window, mouse_position_callback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
}


///////////////////////////////////////////////////////MAIN FUNCTION////////////////////////////////////////////////////////////////////////////



int main(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glClear(GL_COLOR_BUFFER_BIT);

	// Set window hints for maximized mode
	//glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "WINDOW", NULL, NULL);

	if (window == NULL)
	{
		cout << "Failed to create Window." << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();




	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//attach the shade resource code to the shader object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	//same for fragment sahder
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//Oh yeah, and don't forget to delete the shader objects once we've linked them into the program object; we no longer need them anymore:
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	//////////////



	int count = 0;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);








	while (!glfwWindowShouldClose(window))
	{


		//Input
		processInput(window);




		//Render

		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);







		render_frame(window, colorUniformLocation3);
		//render a drawing frame.

		//FOR BUTTONS

		buttons(window, colorUniformLocation2);




		glEnable(GL_SCISSOR_TEST);
		//glScissor(80, 60, 650, 480);




		if (choice == 'a' && feature_choice == 'z')
		{
			brush(window, brush_head, brush_tail);
		}


		//////////////////////////////////////////////////////////////////////////////////////////////////

		if (choice == 'b' && feature_choice == 'z')
		{
			line(window, count, line_head, line_tail);
		}

		if (choice == 'c' && feature_choice == 'z')
		{
			rec(window, count, rec_head, rec_tail);

		}

		if (choice == 'd' && feature_choice == 'z')
		{
			tr(window, count, tr_head, tr_tail);

		}

		if (choice == 'e' && feature_choice == 'z')
		{
			rt_tr(window, count, rt_tr_head, rt_tr_tail);

		}

		cout << global_priority << endl;

		//keep rendering the contents of lines








		render_brush_items(brush_head, brush_tail);

		render_line_items(window, line_head, line_tail);

		render_rec_items(window, rec_head, rec_tail);

		render_tr_items(window, tr_head, tr_tail);

		render_rt_tr_items(window, rt_tr_head, rt_tr_tail);

		render_fill_color_items(render_fill_head, render_fill_tail);

		char temp_choice;






		if (feature_choice == 'u')
		{
			undo();
		}

		if (feature_choice == 'p')
		{
			clear_all();
		}

		if (choice == 'f')
		{
			temp_choice = choice;
			
			eraser(window, eraser_head, eraser_tail);
			//display(brush_head);
		}

		if (feature_choice == 'f')
		{
			choice = 'z';
			fillcolor(window, colorUniformLocation4, fill_head, fill_tail, render_fill_head, render_fill_tail);
		}

		render_eraser_items(eraser_head, eraser_tail);







		glDisable(GL_SCISSOR_TEST);
		

		glDisable(GL_DEPTH_TEST);

		glfwSwapBuffers(window);
		glfwPollEvents();



		// Delete the VAO and VBO when done
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);


	}


	glfwTerminate();
	return 0;
}
