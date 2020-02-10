#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * dest = NULL;
    build(head);
    display(head);


    display(dest);
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
    int count = count_LLL(head);
    int num_arr[count];
    copy_unique_into_array(head, num_arr[]);
    for(int index = 0; num_index[index] != "" && index < count; ++index)
        cout << "Number: " << num_arr[index] << endl;

    return count;
}

int copy_unique_into_array(node * & head, int num_arr[])
{
    if(!head)
        return 0;
    if(compare(head, head))
    {
        num_


int count_LLL(node * head)
{
    if(!head)
        return 0;
    
    int count = count_LLL(head -> next);
    ++count;
    return count;
}
