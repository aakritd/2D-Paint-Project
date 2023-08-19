#pragma once

void render_frame(GLFWwindow* window, int & colorUniformLocation3)
{
	unsigned int VBO_3, VAO_3, EBO_3;

	unsigned int vertexShader3;
	unsigned int fragmentShader3;
	unsigned int shaderProgram3;

	glGenBuffers(1, &VBO_3);
	glGenVertexArrays(1, &VAO_3);
	glGenBuffers(1, &EBO_3);




	glBindBuffer(GL_ARRAY_BUFFER, VBO_3);//Binds the buffer object to its type
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_DYNAMIC_DRAW);//joins the buffer object with the vertices that is previously defined

	glBindVertexArray(VAO_3);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	// 1. then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	vertexShader3 = glCreateShader(GL_VERTEX_SHADER);
	//attach the shade rsource code to the shader object
	glShaderSource(vertexShader3, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader3);




	//same for fragment sahder

	fragmentShader3 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader3, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader3);

	shaderProgram3 = glCreateProgram();

	glAttachShader(shaderProgram3, vertexShader3);
	glAttachShader(shaderProgram3, fragmentShader3);
	glLinkProgram(shaderProgram3);


	// to use shader program
	glUseProgram(shaderProgram3);

	colorUniformLocation3 = glGetUniformLocation(shaderProgram3, "color");
	glDeleteShader(vertexShader3);
	glDeleteShader(fragmentShader3);
	glUniform4f(colorUniformLocation3, 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_LINES, 2, 2);
	glDrawArrays(GL_LINES, 4, 2);
	glDrawArrays(GL_LINES, 6, 2);
	glDrawArrays(GL_LINES, 8, 2);
}