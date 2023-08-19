#pragma once



void set_color()
{

	if (color_choice == 'a')
	{
		current_color[0] = 1.0f;
		current_color[1] = 0.0f;
		current_color[2] = 0.0f;
	}

	if (color_choice == 'b')
	{
		current_color[0] = 0.0f;
		current_color[1] = 1.0f;
		current_color[2] = 0.0f;
	}

	if (color_choice == 'c')
	{
		current_color[0] = 0.0f;
		current_color[1] = 0.0f;
		current_color[2] = 1.0f;
	}

	if (color_choice == 'd')
	{
		current_color[0] = 1.0f;
		current_color[1] = 1.0f;
		current_color[2] = 0.0f;
	}
	
	if (color_choice == 'e')
	{
		current_color[0] = 1.0f;
		current_color[1] = 0.0f;
		current_color[2] = 1.0f;
	}

	if (color_choice == 'f')
	{
		current_color[0] = 0.0f;
		current_color[1] = 1.0f;
		current_color[2] = 1.0f;
	}

	if (color_choice == 'g')
	{
		current_color[0] = 1.0f;
		current_color[1] = 0.5f;
		current_color[2] = 0.0f;
	}

	if (color_choice == 'h')
	{
		current_color[0] = 0.5f;
		current_color[1] = 0.5f;
		current_color[2] = 0.5f;
	}

	if (color_choice == 'i')
	{
		current_color[0] = 0.0f;
		current_color[1] = 0.5f;
		current_color[2] = 0.5f;
	}

	if (color_choice == 'j')
	{
		current_color[0] = 0.5f;
		current_color[1] = 0.0f;
		current_color[2] = 0.5f;
	}

	if (color_choice == 'z')
	{
		current_color[0] = 1.0f;
		current_color[1] = 1.0f;
		current_color[2] = 1.0f;
	}
	 
}