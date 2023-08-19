#pragma once


#include<list>
int insert_count = 0;


std::list<float> brushList;

class brush_node
{
public:
	float brush_color[3];
	float vertex[2];
	int pr;
	brush_node* next;
	brush_node* prev;


	brush_node()
	{
		brush_color[0] = current_color[0];
		brush_color[1] = current_color[1];
		brush_color[2] = current_color[2];

		vertex[0] = mouseXpos;
		vertex[1] = mouseYpos;

		pr = global_priority;

		next = NULL;
		prev = NULL;
	}


};





void inserting_at_tail(brush_node*& brush_head, brush_node*& brush_tail)
{
	insert_count++;

	brush_node* n = new brush_node();//making a node object using pointer dynamically.

	if (brush_tail == NULL)//if no elements have been inserted.
	{
		brush_head = n;
		brush_tail = n;
		return;
	}

	brush_tail->next = n;
	n->prev = brush_tail;

	brush_tail = n;

}


void display(brush_node* head)
{

	brush_node* temp = head;
	while (temp != NULL)
	{
		cout << temp->brush_color[0] << "," << temp->brush_color[1] << "," << temp->brush_color[2] << "->";
		cout << temp->vertex[0] << "," << temp->vertex[1] << "->";
		cout << temp->pr;
		temp = temp->next;

		cout << endl;
	}

	cout << endl;
}

void brush(GLFWwindow* window, brush_node*& brush_head, brush_node*& brush_tail)
{

	if (mouseXpos > -0.95f && mouseXpos <0.95f && mouseYpos >-0.95f && mouseYpos < 0.95f)
	{

		//glClear(GL_COLOR_BUFFER_BIT);

		if (leftMousePressed == true)
		{

			if (!leftMouseReleased)
			{
				global_priority++;
				leftMouseReleased = !leftMouseReleased;
				
			}
			inserting_at_tail(brush_head, brush_tail);

		}

	}



}

void render_brush_items(brush_node*& brush_head, brush_node*& brush_tail)
{
	// Access two elements in each iteration


	brush_node* temp = brush_head;

	while (temp != NULL && temp->next != NULL)
	{
		if (temp->pr == temp->next->pr)
		{
			vertices[0] = temp->vertex[0];
			vertices[1] = temp->vertex[1];

			vertices[2] = float(-temp->pr) / 100;

			vertices[3] = temp->next->vertex[0];
			vertices[4] = temp->next->vertex[1];

			vertices[5] = float(-temp->next->pr) / 100;



			// Bind the VAO and shader program
			glBindVertexArray(VAO);
			glUseProgram(shaderProgram);

			// Update buffer data
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			// Set uniform color and other parameters
			set_color();
			glUniform4f(colorUniformLocation, temp->brush_color[0], temp->brush_color[1], temp->brush_color[2], 1.0f);

			// Set point size and draw the point
			glLineWidth(1);
			//glEnable(GL_POINT_SMOOTH);
			glDrawArrays(GL_LINES, 0, 2);

			//glDisable(GL_POINT_SMOOTH);

				// Unbind the VAO and shader program
			glBindVertexArray(0);
			glUseProgram(0);
		}
		

		temp = temp->next;
	}

}