#pragma once

void undo()
{

    switch_for_lineedit = 'z';
    switch_for_recedit = 'z';
    switch_for_tredit = 'z';
    switch_for_rttredit = 'z';

    while (brush_tail != NULL && brush_tail->pr == global_priority)
    {

        brush_node* temp = brush_tail;


        if (brush_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        brush_tail = temp->prev;

       
        if (brush_tail == NULL)
        {
            brush_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        brush_tail->next = NULL;


        delete(temp);

        cout << "BRUSH TAIL -> pr : " << brush_tail->pr << endl;

        


        
        cout << "DELETING PENCIL" << endl;
    }

    

    while (line_tail != NULL && line_tail->pr == global_priority)
    {

        line_node* temp = line_tail;


        if (line_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        line_tail = temp->prev;


        if (line_tail == NULL)
        {
            line_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        line_tail->next = NULL;


        delete(temp);

        cout << "LINE TAIL -> pr : " << line_tail->pr << endl;





        cout << "DELETING LINE" << endl;
    }

    while (eraser_tail != NULL && eraser_tail->pr == global_priority)
    {

        eraser_node* temp = eraser_tail;


        if (eraser_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        eraser_tail = temp->prev;


        if (eraser_tail == NULL)
        {
            eraser_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        eraser_tail->next = NULL;


        delete(temp);

        cout << "DELETING LINE" << endl;
    }

    while (render_fill_tail != NULL && render_fill_tail->pr == global_priority)
    {

        render_fill_node* temp = render_fill_tail;


        if (render_fill_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        render_fill_tail = temp->prev;


        if (render_fill_tail == NULL)
        {
            render_fill_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        render_fill_tail->next = NULL;


        delete(temp);

        cout << "DELETING LINE" << endl;
    }
    


    while (rec_tail != NULL && rec_tail->pr == global_priority)
    {

        rec_node* temp = rec_tail;


        if (rec_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        rec_tail = temp->prev;


        if (rec_tail == NULL)
        {
            rec_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        rec_tail->next = NULL;


        delete(temp);

        cout << "DELETING LINE" << endl;
    }


    while (tr_tail != NULL && tr_tail->pr == global_priority)
    {

        tr_node* temp = tr_tail;


        if (tr_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        tr_tail = temp->prev;


        if (tr_tail == NULL)
        {
            tr_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        tr_tail->next = NULL;


        delete(temp);

        cout << "DELETING LINE" << endl;
    }

    while (rt_tr_tail != NULL && rt_tr_tail->pr == global_priority)
    {

        rt_tr_node* temp = rt_tr_tail;


        if (rt_tr_tail == NULL)
        {
            cout << "Underflow!" << endl;
            return;
        }

        cout << "temp1->pr : " << temp->pr << endl;


        rt_tr_tail = temp->prev;


        if (rt_tr_tail == NULL)
        {
            rt_tr_head = NULL;
            delete(temp);
            global_priority--;
            feature_choice = 'z';
            return;
        }

        rt_tr_tail->next = NULL;


        delete(temp);

        cout << "DELETING LINE" << endl;
    }

    if (global_priority > -1)
    {
        global_priority--;
    }


    feature_choice = 'z';
    
}
