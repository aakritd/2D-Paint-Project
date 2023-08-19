#pragma once


#pragma once

float rec_a = 0.0f;
float rec_b = 0.0f;
float rec_c = 0.0f;
float rec_d = 0.0f;

class rec_node
{
public:
	float rec_color[3];
	float rec_vertex[8];
	int pr;
	rec_node* next;
	rec_node* prev;


	rec_node(float x1, float y1, float x2, float y2)
	{
		rec_color[0] = current_color[0];
		rec_color[1] = current_color[1];
		rec_color[2] = current_color[2];

		rec_vertex[0] = x1;
		rec_vertex[1] = y1;

		rec_vertex[2] = x2;
		rec_vertex[3] = y1;

		rec_vertex[4] = x2;
		rec_vertex[5] = y2;

		rec_vertex[6] = x1;
		rec_vertex[7] = y2;

		pr = global_priority;

		next = NULL;
		prev = NULL;
	}


};





void inserting_at_tail_rec(rec_node*& rec_head, rec_node*& rec_tail, float x1, float y1, float x2, float y2)
{


	switch_for_recedit = 'y';



	cout << " X! AND Y! : " << x1 << "," << y1 << endl;
	rec_node* n = new rec_node(x1, y1, x2, y2);//making a node object using pointer dynamically.
	if (rec_tail == NULL)//if no elements have been inserted.
	{
		rec_head = n;
		rec_tail = n;
		return;
	}

	rec_tail->next = n;
	n->prev = rec_tail;
	cout << "hahaha" << endl;
	rec_tail = n;
}


void display_rec(rec_node*& rec_head)
{

	rec_node* temp = rec_head;
	while (temp != NULL)
	{

		cout << rec_a << "," << rec_b << "," << rec_c << "," << rec_d << "->";
		cout << temp->pr;
		temp = temp->next;

		cout << endl;
	}

	cout << endl;
}



void rec(GLFWwindow* window, int& count, rec_node*& rec_head, rec_node*& rec_tail)
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
			rec_a = mouseXpos;
			rec_b = mouseYpos;



			//cout << "Vertices[0] , vertices[1] = " << vertices1[0] << "," << vertices1[1] << endl;


			//rightMousePressed = false;
			//rightMouseReleased == true;

			count = 1;
			cout << "COUNT : " << count << endl;

		}



		if (leftMouseReleased == true && count == 1)
		{
			rec_c = mouseXpos;
			rec_d = mouseYpos;

			//cout << "Vertices[3] , vertices[4] = " << vertices1[3] << "," << vertices1[4] << endl;


			leftMouseReleased = false;

			count = 2;
			cout << "COUNT : " << count << endl;

			if (!leftMouseReleased)
			{
				global_priority++;
				leftMouseReleased = !leftMouseReleased;
			}
		}



		if (count == 2)
		{
			inserting_at_tail_rec(rec_head, rec_tail, rec_a, rec_b, rec_c, rec_d);
			count = 0;
		}






	}

}





void edit_rec(GLFWwindow* window, rec_node*& rec_head, rec_node*& rec_tail)
{
	if (mouseXpos <= rec_tail->rec_vertex[0] + 0.05 && mouseXpos >= rec_tail->rec_vertex[0] - 0.05 && mouseYpos <= rec_tail->rec_vertex[1] + 0.05 && mouseYpos >= rec_tail->rec_vertex[1] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 1;


		}

	}

	else if (mouseXpos <= rec_tail->rec_vertex[2] + 0.05 && mouseXpos >= rec_tail->rec_vertex[2] - 0.05 && mouseYpos <= rec_tail->rec_vertex[3] + 0.05 && mouseYpos >= rec_tail->rec_vertex[3] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 2;
		}
	}

	else if (mouseXpos <= rec_tail->rec_vertex[4] + 0.05 && mouseXpos >= rec_tail->rec_vertex[4] - 0.05 && mouseYpos <= rec_tail->rec_vertex[5] + 0.05 && mouseYpos >= rec_tail->rec_vertex[5] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 3;
		}
	}
	else if (mouseXpos <= rec_tail->rec_vertex[6] + 0.05 && mouseXpos >= rec_tail->rec_vertex[6] - 0.05 && mouseYpos <= rec_tail->rec_vertex[7] + 0.05 && mouseYpos >= rec_tail->rec_vertex[7] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 4;
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

				switch_for_recedit = 'n';

			}
		}
	}
	if (leftMouseReleased && count_edit == 1)
	{

		rec_tail->rec_vertex[0] = mouseXpos;
		rec_tail->rec_vertex[1] = mouseYpos;

		rec_tail->rec_vertex[3] = mouseYpos;

		rec_tail->rec_vertex[6] = mouseXpos;



		count_edit = 0;

	}
	if (leftMouseReleased && count_edit == 2)
	{

		rec_tail->rec_vertex[2] = mouseXpos;
		rec_tail->rec_vertex[3] = mouseYpos;

		rec_tail->rec_vertex[1] = mouseYpos;

		rec_tail->rec_vertex[4] = mouseXpos;
		count_edit = 0;

	}

	if (leftMouseReleased && count_edit == 3)
	{

		rec_tail->rec_vertex[4] = mouseXpos;
		rec_tail->rec_vertex[5] = mouseYpos;

		rec_tail->rec_vertex[7] = mouseYpos;

		rec_tail->rec_vertex[2] = mouseXpos;
		count_edit = 0;

	}

	if (leftMouseReleased && count_edit == 4)
	{

		rec_tail->rec_vertex[6] = mouseXpos;
		rec_tail->rec_vertex[7] = mouseYpos;

		rec_tail->rec_vertex[5] = mouseYpos;

		rec_tail->rec_vertex[0] = mouseXpos;
		count_edit = 0;

	}



}

void render_rec_items(GLFWwindow* window, rec_node*& rec_head, rec_node*& rec_tail)
{

	rec_node* temp_rec = rec_head;



	while (temp_rec != NULL)
	{

		vertices2[0] = temp_rec->rec_vertex[0];
		vertices2[1] = temp_rec->rec_vertex[1];


		vertices2[3] = temp_rec->rec_vertex[2];
		vertices2[4] = temp_rec->rec_vertex[3];

		vertices2[6] = temp_rec->rec_vertex[4];
		vertices2[7] = temp_rec->rec_vertex[5];

		vertices2[9] = temp_rec->rec_vertex[6];
		vertices2[10] = temp_rec->rec_vertex[7];

		vertices2[12] = temp_rec->rec_vertex[0];
		vertices2[13] = temp_rec->rec_vertex[1];



		vertices2[2] = float(-temp_rec->pr) / 100;
		vertices2[5] = float(-temp_rec->pr) / 100;
		vertices2[8] = float(-temp_rec->pr) / 100;
		vertices2[11] = float(-temp_rec->pr) / 100;
		vertices2[14] = float(-temp_rec->pr) / 100;


		if (switch_for_recedit == 'y')
		{
			vertices2[15] = rec_tail->rec_vertex[0];
			vertices2[16] = rec_tail->rec_vertex[1];


			vertices2[18] = rec_tail->rec_vertex[2];
			vertices2[19] = rec_tail->rec_vertex[3];

			vertices2[21] = rec_tail->rec_vertex[4];
			vertices2[22] = rec_tail->rec_vertex[5];

			vertices2[24] = rec_tail->rec_vertex[6];
			vertices2[25] = rec_tail->rec_vertex[7];
		}

		//cout << "POINTS : " << vertices1[0] << "," << vertices1[1] << "-----" << vertices1[3] << "," << vertices1[4] << endl;

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices2), vertices2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		set_color();
		glUniform4f(colorUniformLocation1, temp_rec->rec_color[0], temp_rec->rec_color[1], temp_rec->rec_color[2], 1.0f);
		glEnable(GL_LINE_WIDTH);
		glLineWidth(1); // Set the line width to 5 pixels


		glDrawArrays(GL_LINES, 0, 2);

		glDrawArrays(GL_LINES, 1, 2);

		glDrawArrays(GL_LINES, 2, 2);

		glDrawArrays(GL_LINES, 3, 2);

		//glDrawArrays(GL_LINES, 4, 2);

		if (switch_for_recedit == 'y')
		{
			glPointSize(15);
			glUniform4f(colorUniformLocation1, 1.0f, 1.0f, 0.0f, 1.0f);
			glDrawArrays(GL_POINTS, 5, 1);
			glDrawArrays(GL_POINTS, 6, 1);
			glDrawArrays(GL_POINTS, 7, 1);
			glDrawArrays(GL_POINTS, 8, 1);

			glPointSize(1);
		}


		// Unbind the VAO and shader program
		glBindVertexArray(0);
		glUseProgram(0);

		temp_rec = temp_rec->next;

	}

	if (switch_for_recedit == 'y')
	{
		edit_rec(window, rec_head, rec_tail);

	}
	if (switch_for_recedit == 'n')
	{
		choice = 'c';
		switch_for_recedit = 'z';
		leftMousePressed = false;
	}

}
