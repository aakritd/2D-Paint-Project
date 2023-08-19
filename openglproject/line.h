#pragma once

float a = 0.0f;
float b = 0.0f;
float c = 0.0f;
float d = 0.0f;

class line_node
{
public:
	float line_color[3];
	float line_vertex[4];
	int pr;
	line_node* next;
	line_node* prev;


	line_node(float x1,float y1,float x2,float y2)
	{
		line_color[0] = current_color[0];
		line_color[1] = current_color[1];
		line_color[2] = current_color[2];

		line_vertex[0] = x1;
		line_vertex[1] = y1;


		line_vertex[2] = x2;
		line_vertex[3] = y2;

		pr = global_priority;

		next = NULL;
		prev = NULL;
	}


};





void inserting_at_tail_line(line_node*& line_head, line_node*& line_tail, float x1, float y1, float x2, float y2)
{
	switch_for_lineedit = 'y';

	cout << " X! AND Y! : " << x1 << "," << y1 << endl;
	line_node* n = new line_node(x1,y1,x2,y2);//making a node object using pointer dynamically.
	if (line_tail == NULL)//if no elements have been inserted.
	{
		line_head = n;
		line_tail = n;
		return;
	}

	line_tail->next = n;
	n->prev = line_tail;

	line_tail = n;
}


void display_line(line_node*& line_head)
{

	line_node* temp = line_head;
	while (temp != NULL)
	{
		cout << temp->line_color[0] << "," << temp->line_color[1] << "," << temp->line_color[2] << "->";
		cout << temp->line_vertex[0] << "," << temp->line_vertex[1]<<","<< temp->line_vertex[2] << "," << temp->line_vertex[3]<< "->";
		cout << temp->pr;
		temp = temp->next;

		cout << endl;
	}

	cout << endl;
}



void line(GLFWwindow* window, int& count, line_node*& line_head, line_node*& line_tail)
{

	switch_for_lineedit = 'z';
	switch_for_recedit = 'z';
	switch_for_tredit = 'z';
	switch_for_rttredit = 'z';
	
		if (mouseXpos > -0.95f && mouseXpos <0.95f && mouseYpos >-0.95f && mouseYpos < 0.95f)
		{
			if (leftMousePressed == true && count == 0)
			{
				cout << mouseXpos << "," << mouseYpos << endl;
				a = mouseXpos;
				b = mouseYpos;



				//cout << "Vertices[0] , vertices[1] = " << vertices1[0] << "," << vertices1[1] << endl;


				//rightMousePressed = false;
				//rightMouseReleased == true;

				count = 1;
				cout << "COUNT : " << count << endl;

			}



			if (leftMouseReleased == true && count == 1)
			{
				c = mouseXpos;
				d = mouseYpos;

				//cout << "Vertices[3] , vertices[4] = " << vertices1[3] << "," << vertices1[4] << endl;


				leftMouseReleased = false;

				count = 2;
				cout << "COUNT : " << count << endl;

				if (!leftMouseReleased)
				{
					if (a != c && b != d)
					{
						global_priority++;
					}

					leftMouseReleased = !leftMouseReleased;
				}

			}



			if (count == 2)
			{


				if (a != c && b != d)
				{
					inserting_at_tail_line(line_head, line_tail, a, b, c, d);
				}

				count = 0;
			}






		}
	
	
}


void edit_line(GLFWwindow * window, line_node*& line_head, line_node*& line_tail)
{
	
	if (mouseXpos >= line_tail->line_vertex[0] - 0.05f  && mouseXpos <= line_tail->line_vertex[0] + 0.05f &&  mouseYpos >= line_tail->line_vertex[1] - 0.05f && mouseYpos <= line_tail->line_vertex[1] + 0.05f)
	{
		
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';

		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 1;
		}

	}
	else if (mouseXpos >= line_tail->line_vertex[2] - 0.05f && mouseXpos <= line_tail->line_vertex[2] + 0.05f && mouseYpos >=line_tail->line_vertex[3] - 0.05f && mouseYpos <= line_tail->line_vertex[3] + 0.05f)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';

		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 2;
		}

	}
	else
	{
		if (count_edit == 0)
		{
			glfwSetCursor(window, glfwCreateStandardCursor(GLFW_ARROW_CURSOR));

			if (leftMousePressed)
			{
				leftMousePressed = !leftMousePressed;

				switch_for_lineedit = 'n';
			}
		}
		
		
	}

	if (leftMouseReleased && count_edit == 1)
	{
		
		line_tail->line_vertex[0] = mouseXpos;
		line_tail->line_vertex[1] = mouseYpos;
		count_edit = 0;
	}

	if (leftMouseReleased && count_edit == 2)
	{
		line_tail->line_vertex[2] = mouseXpos;
		line_tail->line_vertex[3] = mouseYpos;
		count_edit = 0;
	}
}


void render_line_items(GLFWwindow * window, line_node*& line_head, line_node*& line_tail)
{

	line_node* temp_line = line_head;



	while (temp_line != NULL)
	{

		if (temp_line->line_vertex != NULL)
		{
			vertices1[0] = temp_line->line_vertex[0];
			vertices1[1] = temp_line->line_vertex[1];

			vertices1[3] = temp_line->line_vertex[2];
			vertices1[4] = temp_line->line_vertex[3];
		}
		vertices1[2] = float( -temp_line->pr) / 100;
		vertices1[5] = float( -temp_line->pr) / 100;

		if (switch_for_lineedit == 'y')
		{
			vertices1[30] = line_tail->line_vertex[0];
			vertices1[31] = line_tail->line_vertex[1];

			vertices1[33] = line_tail->line_vertex[2];
			vertices1[34] = line_tail->line_vertex[3];

		}

		//cout << "POINTS : " << vertices1[0] << "," << vertices1[1] << "-----" << vertices1[3] << "," << vertices1[4] << endl;

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices1), vertices1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		set_color();
		glUniform4f(colorUniformLocation1, temp_line->line_color[0], temp_line->line_color[1], temp_line->line_color[2], 1.0f);
		glEnable(GL_LINE_WIDTH);
		glLineWidth(1); // Set the line width to 5 pixels


		glDrawArrays(GL_LINES, 0, 2);

		if (switch_for_lineedit == 'y')
		{
			glPointSize(15);
			glUniform4f(colorUniformLocation1, 1.0f, 1.0f, 0.0f, 1.0f);
			glDrawArrays(GL_POINTS, 10, 1);
			glDrawArrays(GL_POINTS, 11, 1);
			
			glPointSize(1);
		}


		glDisable(GL_LINE_WIDTH);


		// Unbind the VAO and shader program
		glBindVertexArray(0);
		glUseProgram(0);

		temp_line = temp_line->next;
		glBindVertexArray(0);
		glUseProgram(0);
	}
	
	if (switch_for_lineedit == 'y')
	{
		edit_line(window, line_head, line_tail);
	}

	if (switch_for_lineedit == 'n')
	{
		choice = 'b';
		switch_for_lineedit = 'z';
		leftMousePressed = false;
	}
}