#pragma once

void buttons(GLFWwindow* window,int &colorUniformLocation2)
{

	float vertices2[] =
	{
		//for pencil button
		0.95f,0.95f,0.0f,
		0.95f,1.0f,0.0f,
		1.0f,0.95f,0.0f,

		0.95f,1.0f,0.0f,
		1.0f,0.95f,0.0f,
		1.0f,1.0f,0.0f,
		//for line button
		0.95f,0.85f,0.0f,
		0.95f,0.90f,0.0f,
		1.0f,0.85f,0.0f,

		0.95f,0.90f,0.0f,
		1.0f,0.85f,0.0f,
		1.0f,0.90f,0.0f,

		//for rectangle
		0.95f,0.75f,0.0f,
		0.95f,0.80f,0.0f,
		1.0f,0.75f,0.0f,

		0.95f,0.80f,0.0f,
		1.0f,0.75f,0.0f,
		1.0f,0.80f,0.0f,

		//for normal triangle
		0.95f,0.65f,0.0f,
		0.95f,0.70f,0.0f,
		1.0f,0.65f,0.0f,

		0.95f,0.70f,0.0f,
		1.0f,0.65f,0.0f,
		1.0f,0.70f,0.0f,

		//for right angled triangle
		0.95f,0.55f,0.0f,
		0.95f,0.60f,0.0f,
		1.0f,0.55f,0.0f,

		0.95f,0.60f,0.0f,
		1.0f,0.55f,0.0f,
		1.0f,0.60f,0.0f,



		//for colors
		
		//for red color button
		-1.0f,-1.0f,0.0f,
		-1.0f,-0.95f,0.0f,
		-0.95f,-1.0f,0.0f,

		-1.0f,-0.95f,0.0f,
		-0.95f,-1.0f,0.0f,
		-0.95,-0.95f,0.0f,
		//for green color button
		-0.90f,-1.0f,0.0f,
		-0.90f,-0.95f,0.0f,
		-0.85f,-1.0f,0.0f,

		-0.90f,-0.95f,0.0f,
		-0.85f,-1.0f,0.0f,
		-0.85,-0.95f,0.0f,

		//for blue

		-0.80f,-1.0f,0.0f,
		-0.80f,-0.95f,0.0f,
		-0.75f,-1.0f,0.0f,

		-0.80f,-0.95f,0.0f,
		-0.75f,-1.0f,0.0f,
		-0.75,-0.95f,0.0f,

		//for yellow
		-0.70f,-1.0f,0.0f,
		-0.70f,-0.95f,0.0f,
		-0.65f,-1.0f,0.0f,

		-0.70f,-0.95f,0.0f,
		-0.65f,-1.0f,0.0f,
		-0.65,-0.95f,0.0f,

		//for magenta

		-0.60f,-1.0f,0.0f,
		-0.60f,-0.95f,0.0f,
		-0.55f,-1.0f,0.0f,

		-0.60f,-0.95f,0.0f,
		-0.55f,-1.0f,0.0f,
		-0.55,-0.95f,0.0f,

		//for cyan

		-0.50f,-1.0f,0.0f,
		-0.50f,-0.95f,0.0f,
		-0.45f,-1.0f,0.0f,

		-0.50f,-0.95f,0.0f,
		-0.45f,-1.0f,0.0f,
		-0.45,-0.95f,0.0f,

		//for orange

		-0.40f,-1.0f,0.0f,
		-0.40f,-0.95f,0.0f,
		-0.35f,-1.0f,0.0f,

		-0.40f,-0.95f,0.0f,
		-0.35f,-1.0f,0.0f,
		-0.35,-0.95f,0.0f,

		//for gray

		-0.30f,-1.0f,0.0f,
		-0.30f,-0.95f,0.0f,
		-0.25f,-1.0f,0.0f,

		-0.30f,-0.95f,0.0f,
		-0.25f,-1.0f,0.0f,
		-0.25,-0.95f,0.0f,

		//for teal

		-0.20f,-1.0f,0.0f,
		-0.20f,-0.95f,0.0f,
		-0.15f,-1.0f,0.0f,

		-0.20f,-0.95f,0.0f,
		-0.15f,-1.0f,0.0f,
		-0.15,-0.95f,0.0f,

		//for purple
		
		-0.10f,-1.0f,0.0f,
		-0.10f,-0.95f,0.0f,
		-0.05f,-1.0f,0.0f,

		-0.10f,-0.95f,0.0f,
		-0.05f,-1.0f,0.0f,
		-0.05,-0.95f,0.0f,

		//for white
		
		0.00f,-1.0f,0.0f,
		0.00f,-0.95f,0.0f,
		0.05f,-1.0f,0.0f,

		0.0f,-0.95f,0.0f,
		0.05f,-1.0f,0.0f,
		0.05,-0.95f,0.0f,


		//for features
		//button for clearall
		-1.0f,1.0f,0.0f,
		-1.0f,0.95f,0.0f,
		-0.95f,0.95f,0.0f,

		-1.0f,1.0f,0.0f,
		-0.95f,0.95f,0.0f,
		-0.95f,1.0f,0.0f,
		//button for undo
		-0.90f,1.0f,0.0f,
		-0.90f,0.95f,0.0f,
		-0.85f,0.95f,0.0f,

		-0.90f,1.0f,0.0f,
		-0.85f,0.95f,0.0f,
		-0.85f,1.0f,0.0f,

		//button for eraser

		-0.80f,1.0f,0.0f,
		-0.80f,0.95f,0.0f,
		-0.75f,0.95f,0.0f,

		-0.80f,1.0f,0.0f,
		-0.75f,0.95f,0.0f,
		-0.75f,1.0f,0.0f,


		//button for fill

		-0.70f,1.0f,0.0f,
		-0.70f,0.95f,0.0f,
		-0.65f,0.95f,0.0f,

		-0.70f,1.0f,0.0f,
		-0.65f,0.95f,0.0f,
		-0.65f,1.0f,0.0f,
	};


	unsigned int VBO_2;
	unsigned int VAO_2;
	unsigned int EBO_2;

	unsigned int vertexShader2;
	unsigned int fragmentShader2;
	unsigned int shaderProgram2;


	glGenBuffers(1, &VBO_2);
	glGenVertexArrays(1, &VAO_2);
	glGenBuffers(1, &EBO_2);


	glBindBuffer(GL_ARRAY_BUFFER, VBO_2);//Binds the buffer object to its type
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);//joins the buffer object with the vertices that is previously defined

	glBindVertexArray(VAO_2);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_2);

	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	// 1. then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	vertexShader2 = glCreateShader(GL_VERTEX_SHADER);
	//attach the shade rsource code to the shader object
	glShaderSource(vertexShader2, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader2);


	//same for fragment sahder
	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader2);

	shaderProgram2 = glCreateProgram();

	glAttachShader(shaderProgram2, vertexShader2);
	glAttachShader(shaderProgram2, fragmentShader2);
	glLinkProgram(shaderProgram2);


	// to use shader program
	glUseProgram(shaderProgram2);

	colorUniformLocation2 = glGetUniformLocation(shaderProgram2, "color");

	//Oh yeah, and don't forget to delete the shader objects once we've linked them into the program object; we no longer need them anymore:
	glDeleteShader(vertexShader2);
	glDeleteShader(fragmentShader2);


	//FOR OBJECTS
	if(choice == 'a')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 3, 3);

	if (choice == 'b')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color


	glDrawArrays(GL_TRIANGLES, 6, 3);
	glDrawArrays(GL_TRIANGLES, 9, 3);

	if (choice == 'c')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color


	glDrawArrays(GL_TRIANGLES, 12, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 15, 3);//this is also not rendering

	if (choice == 'd')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color


	glDrawArrays(GL_TRIANGLES, 18, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 21, 3);//this is also not rendering


	if (choice == 'e')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color


	glDrawArrays(GL_TRIANGLES, 24, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 27, 3);//this is also not rendering


	//FOR COLOR BUTTONS


	glUniform4f(colorUniformLocation2, 1.0f, 0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 30, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 33, 3);//this is also not rendering

	glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 36, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 39, 3);//this is also not rendering


	
	glUniform4f(colorUniformLocation2, 0.0f, 0.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 42, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 45, 3);//this is also not rendering

	glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 48, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 51, 3);//this is also not rendering

	glUniform4f(colorUniformLocation2, 1.0f, 0.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 54, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 57, 3);//this is also not rendering


	


	glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 60, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 63, 3);//this is also not rendering

	glUniform4f(colorUniformLocation2, 1.0f, 0.5f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 66, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 69, 3);//this is also not rendering

	glUniform4f(colorUniformLocation2, 0.5f, 0.5f, 0.5f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 72, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 75, 3);//this is also not rendering

	glUniform4f(colorUniformLocation2, 0.0f, 0.5f, 0.5f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 78, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 81, 3);//this is also not rendering
	

	
	glUniform4f(colorUniformLocation2, 0.5f, 0.0f, 0.5f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 84 ,3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 87, 3);//this is also not rendering


	
	glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 90, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 93, 3);//this is also not rendering

	//FOR FEATURES BUTTON
	if (feature_choice == 'p')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color


	glDrawArrays(GL_TRIANGLES, 96, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 99, 3);//this is also not rendering



	if (feature_choice == 'u')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color
	
	glDrawArrays(GL_TRIANGLES, 102, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 105, 3);//this is also not rendering


	if (choice == 'f')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color
;
	glDrawArrays(GL_TRIANGLES, 108, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 111, 3);//this is also not rendering


	if (feature_choice == 'f')
		glUniform4f(colorUniformLocation2, 1.0f, 1.0f, 0.0f, 1.0f);
	else
		glUniform4f(colorUniformLocation2, 0.0f, 1.0f, 0.0f, 1.0f); // Green color

	glDrawArrays(GL_TRIANGLES, 114, 3);//this is not rendering
	glDrawArrays(GL_TRIANGLES, 117, 3);//this is also not rendering




}

