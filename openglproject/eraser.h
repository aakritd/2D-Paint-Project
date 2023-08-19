#pragma once

#pragma once

class eraser_node
{
public:
	float vertex[2];
	int pr;
	eraser_node* next;
	eraser_node* prev;


	eraser_node()
	{
	
		vertex[0] = mouseXpos;
		vertex[1] = mouseYpos;

		pr = global_priority;

		next = NULL;
		prev = NULL;
	}


};





void inserting_at_tail_eraser(eraser_node*& eraser_head, eraser_node*& eraser_tail)
{
	insert_count++;

	eraser_node* n = new eraser_node();//making a node object using pointer dynamically.

	if (eraser_tail == NULL)//if no elements have been inserted.
	{
		eraser_head = n;
		eraser_tail = n;
		return;
	}

	eraser_tail->next = n;
	n->prev = eraser_tail;

	eraser_tail = n;

}


void display_eraser(eraser_node* head)
{

	eraser_node* temp = head;
	while (temp != NULL)
	{
		cout << temp->vertex[0] << "," << temp->vertex[1] << "->";
		cout << temp->pr;
		temp = temp->next;

		cout << endl;
	}

	cout << endl;
}

void eraser(GLFWwindow* window, eraser_node*& eraser_head, eraser_node*& eraser_tail)
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
			inserting_at_tail_eraser(eraser_head, eraser_tail);

		}

	}



}


void render_eraser_items(eraser_node*& eraser_head, eraser_node*& eraser_tail)
{
	eraser_node* temp_eraser = eraser_head;


	while (temp_eraser != NULL)
	{
		// Access two elements in each iteration




		if (temp_eraser->vertex != nullptr)
		{
			vertices[0] = temp_eraser->vertex[0];
			vertices[1] = temp_eraser->vertex[1];
		}

		vertices[2] = float(-temp_eraser->pr)/100;

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);


		set_color();
		glUniform4f(colorUniformLocation, 0.0f, 0.0f, 0.0f, 1.0f);

		glPointSize(15);

	
		glDrawArrays(GL_POINTS, 0, 1);

		glPointSize(1);

		temp_eraser = temp_eraser->next;

		glBindVertexArray(0);
		glUseProgram(0);

	}
}