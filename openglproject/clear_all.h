#pragma once



void clear_all()
{
    switch_for_lineedit = 'z';
    switch_for_recedit = 'z';
    switch_for_tredit = 'z';
    switch_for_rttredit = 'z';

    while (brush_tail != NULL)
    {
        if (brush_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }
        

        
        brush_node* temp = brush_tail;
        brush_tail = temp->prev;

        if (brush_tail == NULL)
        {
            brush_head = NULL;
            delete(temp);
            return;
        }

        brush_tail->next = NULL;

        
        delete(temp);
    }
    
    while (line_tail != NULL)
    {
        if (line_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        line_node* temp = line_tail;
        line_tail = temp->prev;

        if (line_tail == NULL)
        {
            line_head = NULL;
            delete(temp);
            return;
        }

        line_tail->next = NULL;

        

        delete(temp);
    }

    while (eraser_tail != NULL)
    {
        if (eraser_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        eraser_node* temp = eraser_tail;
        eraser_tail = temp->prev;

        if (eraser_tail == NULL)
        {
            eraser_head = NULL;
            delete(temp);
            return;
        }

        eraser_tail->next = NULL;



        delete(temp);
    }


    while (render_fill_tail != NULL)
    {
        if (render_fill_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        render_fill_node* temp = render_fill_tail;
        render_fill_tail = temp->prev;

        if (render_fill_tail == NULL)
        {
            render_fill_head = NULL;
            delete(temp);
            return;
        }

        render_fill_tail->next = NULL;



        delete(temp);
    }


    while (rec_tail != NULL)
    {
        if (rec_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        rec_node* temp = rec_tail;
        rec_tail = temp->prev;

        if (rec_tail == NULL)
        {
            rec_head = NULL;
            delete(temp);
            return;
        }

        rec_tail->next = NULL;



        delete(temp);
    }


    while (tr_tail != NULL)
    {
        if (tr_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        tr_node* temp = tr_tail;
        tr_tail = temp->prev;

        if (tr_tail == NULL)
        {
            tr_head = NULL;
            delete(temp);
            return;
        }

        tr_tail->next = NULL;



        delete(temp);
    }


    while (rt_tr_tail != NULL)
    {
        if (rt_tr_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        rt_tr_node* temp = rt_tr_tail;
        rt_tr_tail = temp->prev;

        if (rt_tr_tail == NULL)
        {
            rt_tr_head = NULL;
            delete(temp);
            return;
        }

        rt_tr_tail->next = NULL;



        delete(temp);
    }


    global_priority = -1;
    feature_choice = 'z';
}