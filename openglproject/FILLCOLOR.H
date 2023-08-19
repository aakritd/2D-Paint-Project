#pragma once

#include<list>
#include<cmath>

float x, y;

float surround_color[3] = {
    0.0f,0.0f,0.0f
};




class fill_node
{
public:
    float vertex[2];
    int pr;
    fill_node* next;
    fill_node* prev;


    fill_node(float p, float q)
    {
        vertex[0] = p;
        vertex[1] = q;

        next = NULL;
        prev = NULL;
    }


};

void inserting_at_tail_fill(fill_node*& fill_head, fill_node*& fill_tail, float p, float q)
{


    fill_node* n = new fill_node(p, q);//making a node object using pointer dynamically.

    if (fill_tail == NULL)//if no elements have been inserted.
    {
        fill_head = n;
        fill_tail = n;
        return;
    }

    fill_tail->next = n;
    n->prev = fill_tail;

    fill_tail = n;

}



void deleting_at_tail_fill(fill_node*& fill_head, fill_node*& fill_tail)
{
    fill_node* temp = fill_tail;
    fill_tail = temp->prev;

    if (fill_tail == NULL)
    {
        fill_head = NULL;
    }
    delete(temp);
}



bool IsEmpty(fill_node*& fill_head, fill_node*& fill_tail)
{
    if (fill_head == NULL && fill_tail == NULL)
        return false;
    else
        return true;
}


GLfloat base_color[] =
{
    0.0f,0.0f,0.0f
};

float location[] =
{
    0.0f,0.0f,0.0f
};




class render_fill_node
{
public:
    float vertex[2];
    int pr;
    render_fill_node* next;
    render_fill_node* prev;
    float render_fill_color[3];

    render_fill_node(float p, float q)
    {
        vertex[0] = p;
        vertex[1] = q;

        render_fill_color[0] = current_color[0];
        render_fill_color[1] = current_color[1];
        render_fill_color[2] = current_color[2];

        pr = global_priority;

        next = NULL;
        prev = NULL;
    }
};





void inserting_at_tail_renderfill(render_fill_node*& render_fill_head, render_fill_node*& render_fill_tail, float p, float q)
{


    render_fill_node* n = new render_fill_node(p, q);//making a node object using pointer dynamically.

    if (render_fill_tail == NULL)//if no elements have been inserted.
    {
        render_fill_head = n;
        render_fill_tail = n;
        return;
    }

    render_fill_tail->next = n;
    n->prev = render_fill_tail;

    render_fill_tail = n;

}

void render_fill_color_items(render_fill_node*& render_fill_head, render_fill_node*& render_fill_tail)
{
    render_fill_node* temp = render_fill_head;

    while (temp != NULL)
    {
        if (temp->vertex != nullptr)
        {
            vertices[0] = temp->vertex[0];
            vertices[1] = temp->vertex[1];
        }
        vertices[2] = float(-temp->pr) / 100;


        // Bind the VAO and shader program
        glBindVertexArray(VAO);
        glUseProgram(shaderProgram);

        // Update buffer data
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Set uniform color and other parameters
        set_color();
        glUniform4f(colorUniformLocation, temp->render_fill_color[0], temp->render_fill_color[1], temp->render_fill_color[2], 1.0f);

        // Set point size and draw the point


        glDrawArrays(GL_POINTS, 0, 1);


        // Unbind the VAO and shader program
        glBindVertexArray(0);
        glUseProgram(0);

        temp = temp->next;

        glBindVertexArray(0);
        glUseProgram(0);

    }
}


class Vertex {
public:
    float x;
    float y;

    Vertex(float x_val, float y_val) : x(x_val), y(y_val) {}
};

class HashTable {
private:
    static const int tableSize = 500; // Choose an appropriate size

    // Array of lists to store vertices
    std::list<Vertex> table[tableSize];

    // Hash function
    int hashFunction(float x, float y) {
        // A simple hash function example
        return static_cast<int>(abs(x + y) * 98765) % tableSize;
    }



public:
    // Insert a vertex into the hash table
    void insert(Vertex v) {
        int index = abs(hashFunction(v.x, v.y));
        table[index].push_back(v);
        cout << "INDEX : " << index << endl;
    }

    // Search for a vertex in the hash table
    bool search(float x, float y) {
        int index = hashFunction(x, y);
        for (std::list<Vertex>::const_iterator it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->x == x && it->y == y) {
                return true;
            }
        }
        return false;
    }
};




unsigned char pixel[3];
std::list<float> filling_list;



void fill(float p, float q, fill_node*& fill_head, fill_node*& fill_tail, render_fill_node*& render_fill_head, render_fill_node*& render_fill_tail)
{

    x = winX/2 + p * winX/2;
    y = winY/2 + q * winY/2;

    HashTable hashTable;


    glReadPixels(static_cast<int>(x), static_cast<int>(y), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);



    base_color[0] = static_cast<int>(pixel[0]) / 255;
    base_color[1] = static_cast<int>(pixel[1]) / 255;
    base_color[2] = static_cast<int>(pixel[2]) / 255;
    std::cout << "The Base Color is : " << base_color[0] << "," << base_color[1] << "," << base_color[2] << endl;


    inserting_at_tail_fill(fill_head, fill_tail, p, q);
    inserting_at_tail_renderfill(render_fill_head, render_fill_tail, p, q);
    hashTable.insert(Vertex(p, q));


    float perm_p = p;
    float perm_q = q;

    while (IsEmpty(fill_head, fill_tail))
    {

        cout << "HELLO??" << endl;
        p = fill_tail->vertex[0];

        q = fill_tail->vertex[1];




        deleting_at_tail_fill(fill_head, fill_tail);


        //right
        x = winX/2 + (p + pixelX) * winX /2;
        y = winY /2 + q * winY /2;
        glReadPixels(static_cast<int>(x), static_cast<int>(y), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        surround_color[0] = static_cast<int>(pixel[0]) / 255;
        surround_color[1] = static_cast<int>(pixel[1]) / 255;
        surround_color[2] = static_cast<int>(pixel[2]) / 255;


        if (surround_color[0] == base_color[0] && surround_color[1] == base_color[1] && surround_color[2] == base_color[2] && !hashTable.search(p + pixelX, q))
        {
            inserting_at_tail_fill(fill_head, fill_tail, p + pixelX, q);
            inserting_at_tail_renderfill(render_fill_head, render_fill_tail, p + pixelX, q);
            hashTable.insert(Vertex(p + pixelX, q));
        }



        //down
        x = winX /2 + (p) *winX /2;
        y = winY/2 + (q - pixelY) * winY/2;
        glReadPixels(static_cast<int>(x), static_cast<int>(y), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        surround_color[0] = static_cast<int>(pixel[0]) / 255;
        surround_color[1] = static_cast<int>(pixel[1]) / 255;
        surround_color[2] = static_cast<int>(pixel[2]) / 255;

        if (surround_color[0] == base_color[0] && surround_color[1] == base_color[1] && surround_color[2] == base_color[2] && !hashTable.search(p, q - pixelY))
        {
            inserting_at_tail_fill(fill_head, fill_tail, p, q - pixelY);
            inserting_at_tail_renderfill(render_fill_head, render_fill_tail, p, q - pixelY);
            hashTable.insert(Vertex(p, q - pixelY));
        }

        //left
        x = winX/2 + (p - pixelX) * winX/2;
        y = winY/2 + q * winY/2;
        glReadPixels(static_cast<int>(x), static_cast<int>(y), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        surround_color[0] = static_cast<int>(pixel[0]) / 255;
        surround_color[1] = static_cast<int>(pixel[1]) / 255;
        surround_color[2] = static_cast<int>(pixel[2]) / 255;

        if (surround_color[0] == base_color[0] && surround_color[1] == base_color[1] && surround_color[2] == base_color[2] && !hashTable.search(p - pixelX, q))
        {
            inserting_at_tail_fill(fill_head, fill_tail, p - pixelX ,q);
            inserting_at_tail_renderfill(render_fill_head, render_fill_tail, p - pixelX, q);
            hashTable.insert(Vertex(p - pixelX, q));
        }


        //up
        x = winX/2 + (p) * winX/2;
        y = winY/2 + (q + pixelY) * winY/2;
        glReadPixels(static_cast<int>(x), static_cast<int>(y), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        surround_color[0] = static_cast<int>(pixel[0]) / 255;
        surround_color[1] = static_cast<int>(pixel[1]) / 255;
        surround_color[2] = static_cast<int>(pixel[2]) / 255;

        if (surround_color[0] == base_color[0] && surround_color[1] == base_color[1] && surround_color[2] == base_color[2] && !hashTable.search(p, q + pixelY))
        {
            inserting_at_tail_fill(fill_head, fill_tail, p, q + pixelY);
            inserting_at_tail_renderfill(render_fill_head, render_fill_tail, p, q + pixelY);
            hashTable.insert(Vertex(p, q + pixelY));
        }



    }





    feature_choice = 'z';

}

void fillcolor(GLFWwindow* window, int& colorUniformLocation4, fill_node*& fill_head, fill_node*& fill_tail, render_fill_node*& render_fill_head, render_fill_node*& render_fill_tail)
{

   
    switch_for_lineedit = 'z';
    switch_for_recedit = 'z';
    switch_for_tredit = 'z';
    switch_for_rttredit = 'z';


    if (leftMousePressed)
    {
        //to get color of the pixels where we want to fill

        float p, q;


        p = mouseXpos;
        q = mouseYpos;

        std::cout << "FILL FOLOW USED AT " << mouseXpos << "," << mouseYpos << endl;

        if (!leftMouseReleased)
        {
            global_priority++;
            leftMouseReleased = !leftMouseReleased;
        }

        fill(p, q, fill_head, fill_tail, render_fill_head, render_fill_tail);



    }


}