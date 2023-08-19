

#pragma once

float rt_tr_a = 0.0f;
float rt_tr_b = 0.0f;
float rt_tr_c = 0.0f;
float rt_tr_d = 0.0f;

class rt_tr_node
{
public:
	float rt_tr_color[3];
	float rt_tr_vertex[8];
	int pr;
	rt_tr_node* next;
	rt_tr_node* prev;


	rt_tr_node(float x1, float y1, float x2, float y2)
	{
		rt_tr_color[0] = current_color[0];
		rt_tr_color[1] = current_color[1];
		rt_tr_color[2] = current_color[2];

		rt_tr_vertex[0] = x1;
		rt_tr_vertex[1] = y1;

		rt_tr_vertex[2] = x1;
		rt_tr_vertex[3] = y2;

		rt_tr_vertex[4] = x2;
		rt_tr_vertex[5] = y2;

		rt_tr_vertex[6] = x1;
		rt_tr_vertex[7] = y1;





		pr = global_priority;

		next = NULL;
		prev = NULL;
	}


};





void inserting_at_tail_rt_tr(rt_tr_node*& rt_tr_head, rt_tr_node*& rt_tr_tail, float x1, float y1, float x2, float y2)
{


	switch_for_rttredit = 'y';

	cout << " X! AND Y! : " << x1 << "," << y1 << endl;
	rt_tr_node* n = new rt_tr_node(x1, y1, x2, y2);//making a node object using pointer dynamically.
	if (rt_tr_tail == NULL)//if no elements have been inserted.
	{
		rt_tr_head = n;
		rt_tr_tail = n;
		return;
	}

	rt_tr_tail->next = n;
	n->prev = rt_tr_tail;
	cout << "hahaha" << endl;
	rt_tr_tail = n;
}


void display_rt_tr(rt_tr_node*& rt_tr_head)
{

	rt_tr_node* temp = rt_tr_head;
	while (temp != NULL)
	{

		cout << rt_tr_a << "," << rt_tr_b << "," << rt_tr_c << "," << rt_tr_d << "->";
		cout << temp->pr;
		temp = temp->next;

		cout << endl;
	}

	cout << endl;
}



void rt_tr(GLFWwindow* window, int& count, rt_tr_node*& rt_tr_head, rt_tr_node*& rt_tr_tail)
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
			rt_tr_a = mouseXpos;
			rt_tr_b = mouseYpos;



			//cout << "Vertices[0] , vertices[1] = " << vertices1[0] << "," << vertices1[1] << endl;


			//rightMousePressed = false;
			//rightMouseReleased == true;

			count = 1;
			cout << "COUNT : " << count << endl;

		}



		if (leftMouseReleased == true && count == 1)
		{
			rt_tr_c = mouseXpos;
			rt_tr_d = mouseYpos;

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
			inserting_at_tail_rt_tr(rt_tr_head, rt_tr_tail, rt_tr_a, rt_tr_b, rt_tr_c, rt_tr_d);
			count = 0;
		}






	}

}



void edit_rttr(GLFWwindow* window, rt_tr_node*& rttr_head, rt_tr_node*& rttr_tail)
{
	if (mouseXpos <= rttr_tail->rt_tr_vertex[0] + 0.05 && mouseXpos >= rttr_tail->rt_tr_vertex[0] - 0.05 && mouseYpos <= rttr_tail->rt_tr_vertex[1] + 0.05 && mouseYpos >= rttr_tail->rt_tr_vertex[1] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 1;


		}

	}

	else if (mouseXpos <= rttr_tail->rt_tr_vertex[2] + 0.05 && mouseXpos >= rttr_tail->rt_tr_vertex[2] - 0.05 && mouseYpos <= rttr_tail->rt_tr_vertex[3] + 0.05 && mouseYpos >= rttr_tail->rt_tr_vertex[3] - 0.05)
	{
		glfwSetCursor(window, glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR));

		choice = 'z';


		if (leftMousePressed && count_edit == 0)
		{
			count_edit = 2;
		}
	}

	else if (mouseXpos <= rttr_tail->rt_tr_vertex[4] + 0.05 && mouseXpos >= rttr_tail->rt_tr_vertex[4] - 0.05 && mouseYpos <= rttr_tail->rt_tr_vertex[5] + 0.05 && mouseYpos >= rttr_tail->rt_tr_vertex[5] - 0.05)
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

				switch_for_rttredit = 'n';

			}
		}
	}


	if (leftMouseReleased && count_edit == 1)
	{

		rttr_tail->rt_tr_vertex[0] = mouseXpos;
		rttr_tail->rt_tr_vertex[1] = mouseYpos;

		rttr_tail->rt_tr_vertex[6] = mouseXpos;
		rttr_tail->rt_tr_vertex[7] = mouseYpos;

		count_edit = 0;

	}
	if (leftMouseReleased && count_edit == 2)
	{

		rttr_tail->rt_tr_vertex[2] = mouseXpos;
		rttr_tail->rt_tr_vertex[3] = mouseYpos;

		rttr_tail->rt_tr_vertex[0] = mouseXpos;
		rttr_tail->rt_tr_vertex[6] = mouseXpos;

		rttr_tail->rt_tr_vertex[5] = mouseYpos;
		count_edit = 0;

	}

	if (leftMouseReleased && count_edit == 3)
	{

		rttr_tail->rt_tr_vertex[4] = mouseXpos;
		rttr_tail->rt_tr_vertex[5] = mouseYpos;

		rttr_tail->rt_tr_vertex[3] = mouseYpos;

		count_edit = 0;

	}





}






void render_rt_tr_items(GLFWwindow* window, rt_tr_node*& rt_tr_head, rt_tr_node*& rt_tr_tail)
{

	rt_tr_node* temp_rt_tr = rt_tr_head;



	while (temp_rt_tr != NULL)
	{

		if (temp_rt_tr->rt_tr_vertex != NULL)
		{
			vertices2[0] = temp_rt_tr->rt_tr_vertex[0];
			vertices2[1] = temp_rt_tr->rt_tr_vertex[1];


			vertices2[3] = temp_rt_tr->rt_tr_vertex[2];
			vertices2[4] = temp_rt_tr->rt_tr_vertex[3];

			vertices2[6] = temp_rt_tr->rt_tr_vertex[4];
			vertices2[7] = temp_rt_tr->rt_tr_vertex[5];

			vertices2[9] = temp_rt_tr->rt_tr_vertex[6];
			vertices2[10] = temp_rt_tr->rt_tr_vertex[7];
		}

		vertices2[2] = float(-temp_rt_tr->pr) / 100;
		vertices2[5] = float(-temp_rt_tr->pr) / 100;
		vertices2[8] = float(-temp_rt_tr->pr) / 100;
		vertices2[11] = float(-temp_rt_tr->pr) / 100;

		if (switch_for_rttredit == 'y')
		{
			vertices2[12] = rt_tr_tail->rt_tr_vertex[0];
			vertices2[13] = rt_tr_tail->rt_tr_vertex[1];

			vertices2[15] = rt_tr_tail->rt_tr_vertex[2];
			vertices2[16] = rt_tr_tail->rt_tr_vertex[3];

			vertices2[18] = rt_tr_tail->rt_tr_vertex[4];
			vertices2[19] = rt_tr_tail->rt_tr_vertex[5];
		}

		//cout << "POINTS : " << vertices1[0] << "," << vertices1[1] << "-----" << vertices1[3] << "," << vertices1[4] << endl;

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices2), vertices2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		set_color();
		glUniform4f(colorUniformLocation1, temp_rt_tr->rt_tr_color[0], temp_rt_tr->rt_tr_color[1], temp_rt_tr->rt_tr_color[2], 1.0f);
		glEnable(GL_LINE_WIDTH);
		glLineWidth(1); // Set the line width to 5 pixels


		glDrawArrays(GL_LINES, 0, 2);

		glDrawArrays(GL_LINES, 1, 2);

		glDrawArrays(GL_LINES, 2, 2);


		if (switch_for_rttredit == 'y')
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

		temp_rt_tr = temp_rt_tr->next;

	}

	if (switch_for_rttredit == 'y')
	{
		edit_rttr(window, rt_tr_head, rt_tr_tail);

	}
	if (switch_for_rttredit == 'n')
	{
		choice = 'e';
		switch_for_rttredit = 'z';
		leftMousePressed = false;
	}
}



