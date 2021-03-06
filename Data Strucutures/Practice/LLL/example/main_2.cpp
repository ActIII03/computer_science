#include "list.h"

int main()
{
    node * head = NULL;
    node * dest = NULL;
    build(head);
    display(head);

    int count = last_mpdemo(head);
    cout << "Number of two's removed: " << count << endl;
        
    display(head);
    return 0;
}

int remove_every_even(node * & head)
{
    if(!head)
        return 0;

    int count = 0;

    if(head -> data % 2 == 0)
    {
        node * temp = head -> next;
        ++count;
        delete head;
        head = temp;
        count += remove_every_even(head);
    }
    else
        count += remove_every_even(head -> next);

    return count;
}


int remove_last_node(node * & head)
{
    if(!head -> next)
    {
        node * temp = head -> next;
        delete head;
        head = temp;
        return 0;
    }
    return remove_last_node(head -> next);
}

int remove_after_two(node * & head)
{
    if(!head -> next)
        return 0;
    
    int count = 0;

    if(head -> data == 2)
    {
        ++count;
        node * temp = head -> next;
        head -> next = temp -> next;
        delete temp;
    }

    count += remove_after_two(head -> next);

    return count;
}

int copy_even_to_LLL(node * & head, node * & dest)
{
    int count = 0;

    if(!head -> next)
    {
        if(head -> data % 2 == 0)
        {
            dest = new node;
            dest -> data = head -> data;
            ++count;
        }
        dest -> next = NULL;
        return count;
    }

    else if(head -> data % 2 == 0)
    {
        dest = new node;
        dest -> data = head -> data;
        ++count;
        count += copy_even_to_LLL(head -> next, dest -> next);
    }
    else
        count += copy_even_to_LLL(head -> next, dest);

    return count;
}

int copy_unique_into_array(node * & head)
{
    if(!head)
       return 0;
    int count = count_LLL(head), index = 0;
    int num_arr[count];
    copy_unique_into_array(head, num_arr, index);
    for(int index = 0; index < count; ++index)
        cout << "Number: " << num_arr[index] << endl;

    count += (index + 1);
    return count;
}

int copy_unique_into_array(node * & head, int num_arr[], int & index)
{
    if(!head)
        return 0;
    if(!compare(head))
    {
        num_arr[index] = head -> data;
        ++index;
    }
    copy_unique_into_array(head -> next, num_arr, index);
    return 0;
}

bool compare(node * head)
{
    if(!head)
        return true;
    
    node * current = head -> next;
    bool flag = false;

    while(current)
    {
        if(head -> data == current -> data)
            flag = true;
        current = current -> next;
    }

    return flag;
}

int count_LLL(node * head)
{
    if(!head)
        return 0;
    
    int count = count_LLL(head -> next);
    if(!compare(head))
        ++count;
    return count;
}

int place_last(node * & head, int first_int)
{
    if(!head -> next)
    {
       head -> next = new node;
       node * temp = head -> next;
       temp -> data = first_int;
       temp -> next = NULL;
       return 1;
    }

    int count = place_last(head -> next, first_int);
    return count;
}

int remove_first(node * & head)
{
    if(!head)
        return 0;
    
    int count = 0, first_int = head -> data;
    node * temp = head;
    head = head -> next;
    delete temp;
    count = place_last(head, first_int);
    return count;

}

int count_last(node * head)
{
    if(!head)
        return 0;
    int last_node = 0;
    int count = count_last(head, last_node);
    return count;
}

int count_last(node * head, int & last_node)
{
    if(!head)
        return 0;

    if(!head -> next)
    {
        last_node = head -> data;
        return 0;
    }

    int count = count_last(head -> next, last_node);

    if(head -> data  == last_node)
        ++count;

    return count;
}

int copy_LLL(node * head, node * & dest)
{
    if(!head)
        return 0;

    if(!head -> next)
    {
        dest = new node;
        dest -> data = head -> data;
        dest -> next = NULL;
        return 1;
    }

    dest = new node;
    dest -> data = head -> data;
    int count = copy_LLL(head -> next, dest -> next);
    ++count;
    return count;
}

int last_mpdemo(node * & head)
{
    if(!head)
        return 0;

    int count = 0;
    remove_first_two(head, count);

    return count;
}

int remove_rest(node * & head)
{
    if(!head -> next)
    {
        if(head -> data == 2)
        {
            delete head;
            head = NULL;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if(head -> data == 2)
    {
        ++count;
        node * temp = head;
        head = head -> next;
        delete temp;
    }

    count += remove_rest(head -> next);

    return count;
}

int remove_first_two(node * & head, int & count)
{
    if(head -> data == 2 && count == 1)
    {
        count += remove_rest(head -> next);
        return count;
    }

    if(head -> data == 2)
    {
        ++count;
        node * temp = head -> next;
        delete head;
        head = temp;
    }

    count += remove_first_two(head -> next, count);
    
    return count;
}

