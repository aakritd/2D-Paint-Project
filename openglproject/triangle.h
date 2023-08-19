#pragma once



#pragma once


#pragma once

float tr_a = 0.0f;
float tr_b = 0.0f;
float tr_c = 0.0f;
float tr_d = 0.0f;

class tr_node
{
public:
	float tr_color[3];
	float tr_vertex[8];
	int pr;
	tr_node* next;
	tr_node* prev;


	tr_node(float x1, float y1, float x2, float y2)
	{
		tr_color[0] = current_color[0];
		tr_color[1] = current_color[1];
		tr_color[2] = current_color[2];

		tr_vertex[0] = (x1 + x2) / 2;
		tr_vertex[1] = y1;

		tr_vertex[2] = x1;
		tr_vertex[3] = y2;

		tr_vertex[4] = x2;
		tr_vertex[5] = y2;

		tr_vertex[6] = (x1 + x2) / 2;
		tr_vertex[7] = y1;





		pr = global_priority;

		next = NULL;
		prev = NULL;
	}


};





void inserting_at_tail_tr(tr_node*& tr_head, tr_node*& tr_tail, float x1, float y1, float x2, float y2)
{
	switch_for_tredit = 'y';


	cout << " X! AND Y! : " << x1 << "," << y1 << endl;
	tr_node* n = new tr_node(x1, y1, x2, y2);//making a node object using pointer dynamically.
	if (tr_tail == NULL)//if no elements have been inserted.
	{
		tr_head = n;
		tr_tail = n;
		return;
	}

	tr_tail->next = n;
	n->prev = tr_tail;
	cout << "hahaha" << endl;
	tr_tail = n;
}


void display_tr(tr_node*& tr_head)
{

	tr_node* temp = tr_head;
	while (temp != NULL)
	{

		cout << tr_a << "," << tr_b << "," << tr_c << "," << tr_d << "->";
		cout << temp->pr;
		temp = temp->next;

		cout << endl;
	}

	cout << endl;
}



void tr(GLFWwindow* window, int& count, tr_node*& tr_head, tr_node*& tr_tail)
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
			tr_a = mouseXpos;
			tr_b = mouseYpos;



			//cout << "Vertices[0] , vertices[1] = " << vertices1[0] << "," << vertices1[1] << endl;


			//rightMousePressed = false;
			//rightMouseReleased == true;

			count = 1;
			cout << "COUNT : " << count << endl;

		}



		if (leftMouseReleased == true && count == 1)
		{
			tr_c = mouseXpos;
			tr_d = mouseYpos;

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
			if (tr_a != tr_c && tr_b != tr_d)
				inserting_at_tail_tr(tr_head, tr_tail, tr_a, tr_b, tr_c, tr_d);
			count = 0;
		}






	}

}



void edit_tr(GLFWwindow* window, tr_node*& tr_head, tr_node*& tr_tail)
{
	if (mouseXpos <= tr_tail->tr_vertex[0] + 0.05 && mouseXpos >= tr_tail->tr_vertex[0] - 0.05 && mouseYpos <= tr_tail->tr_vertex[1] + 0.05 && mouseYpos >= tr_tail->tr_vertex[1] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 1;


		}

	}

	else if (mouseXpos <= tr_tail->tr_vertex[2] + 0.05 && mouseXpos >= tr_tail->tr_vertex[2] - 0.05 && mouseYpos <= tr_tail->tr_vertex[3] + 0.05 && mouseYpos >= tr_tail->tr_vertex[3] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 2;
		}
	}

	else if (mouseXpos <= tr_tail->tr_vertex[4] + 0.05 && mouseXpos >= tr_tail->tr_vertex[4] - 0.05 && mouseYpos <= tr_tail->tr_vertex[5] + 0.05 && mouseYpos >= tr_tail->tr_vertex[5] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 3;
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

				switch_for_tredit = 'n';

			}
		}
	}


	if (leftMouseReleased && count_edit == 1)
	{

		//tr_tail->tr_vertex[0] = mouseXpos;
		tr_tail->tr_vertex[1] = mouseYpos;
		//tr_tail->tr_vertex[6] = mouseXpos;
		tr_tail->tr_vertex[7] = mouseYpos;

		count_edit = 0;

	}
	if (leftMouseReleased && count_edit == 2)
	{

		tr_tail->tr_vertex[2] = mouseXpos;
		tr_tail->tr_vertex[3] = mouseYpos;

		tr_tail->tr_vertex[0] = (mouseXpos + tr_tail->tr_vertex[4]) / 2;
		tr_tail->tr_vertex[6] = (mouseXpos + tr_tail->tr_vertex[4]) / 2;

		tr_tail->tr_vertex[5] = mouseYpos;
		count_edit = 0;

	}

	if (leftMouseReleased && count_edit == 3)
	{

		tr_tail->tr_vertex[4] = mouseXpos;
		tr_tail->tr_vertex[5] = mouseYpos;

		tr_tail->tr_vertex[0] = (mouseXpos + tr_tail->tr_vertex[2]) / 2;
		tr_tail->tr_vertex[6] = (mouseXpos + tr_tail->tr_vertex[2]) / 2;

		tr_tail->tr_vertex[3] = mouseYpos;

		count_edit = 0;

	}





}



void render_tr_items(GLFWwindow* window, tr_node*& tr_head, tr_node*& tr_tail)
{

	tr_node* temp_tr = tr_head;



	while (temp_tr != NULL)
	{

		if (temp_tr->tr_vertex != NULL)
		{
			vertices2[0] = temp_tr->tr_vertex[0];
			vertices2[1] = temp_tr->tr_vertex[1];


			vertices2[3] = temp_tr->tr_vertex[2];
			vertices2[4] = temp_tr->tr_vertex[3];

			vertices2[6] = temp_tr->tr_vertex[4];
			vertices2[7] = temp_tr->tr_vertex[5];

			vertices2[9] = temp_tr->tr_vertex[6];
			vertices2[10] = temp_tr->tr_vertex[7];
		}

		vertices2[2] = float(-temp_tr->pr) / 100;
		vertices2[5] = float(-temp_tr->pr) / 100;
		vertices2[8] = float(-temp_tr->pr) / 100;
		vertices2[11] = float(-temp_tr->pr) / 100;

		if (switch_for_tredit == 'y')
		{
			vertices2[12] = tr_tail->tr_vertex[0];
			vertices2[13] = tr_tail->tr_vertex[1];

			vertices2[15] = tr_tail->tr_vertex[2];
			vertices2[16] = tr_tail->tr_vertex[3];

			vertices2[18] = tr_tail->tr_vertex[4];
			vertices2[19] = tr_tail->tr_vertex[5];
		}



		//cout << "POINTS : " << vertices1[0] << "," << vertices1[1] << "-----" << vertices1[3] << "," << vertices1[4] << endl;

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices2), vertices2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		set_color();
		glUniform4f(colorUniformLocation1, temp_tr->tr_color[0], temp_tr->tr_color[1], temp_tr->tr_color[2], 1.0f);
		glEnable(GL_LINE_WIDTH);
		glLineWidth(1); // Set the line width to 5 pixels


		glDrawArrays(GL_LINES, 0, 2);

		glDrawArrays(GL_LINES, 1, 2);

		glDrawArrays(GL_LINES, 2, 2);


		if (switch_for_tredit == 'y')
		{
			glPointSize(15);
			glUniform4f(colorUniformLocation1, 1.0f, 1.0f, 0.0f, 1.0f);
			glDrawArrays(GL_POINTS, 4, 1);
			glDrawArrays(GL_POINTS, 5, 1);
			glDrawArrays(GL_POINTS, 6, 1);
			//glDrawArrays(GL_POINTS, 7, 1);
			glPointSize(1);

		}

		// Unbind the VAO and shader program
		glBindVertexArray(0);
		glUseProgram(0);

		temp_tr = temp_tr->next;

	}

	if (switch_for_tredit == 'y')
	{
		edit_tr(window, tr_head, tr_tail);

	}
	if (switch_for_tredit == 'n')
	{
		choice = 'd';
		switch_for_tredit = 'z';
		leftMousePressed = false;
	}
}
