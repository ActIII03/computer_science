//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "stack_and_queue.h"

stack::stack()
{
    head = NULL;
    top_index = 0;
}

stack::~stack()
{
    
    node * temp;
    while(head)
    {
        temp = head;
        head = head -> next;
        delete temp;
    }
        head = NULL;
}

node::node()
{
    next = NULL;
    card_arr = new queue * [5];
    for(int index = 0; index < 5; ++index)
        card_arr[index] = NULL;
}


//Get help on this
node::~node()
{
    for(int index = 0; index < 5; ++index)
        if(card_arr[index])
            delete card_arr[index];
    delete [] card_arr;

}

queue::queue()
{
    rear = NULL;
}

//Recursive
void queue::queue_dest(q_node * & rear)
{

    if(rear == this -> rear)   //Is this right?
    {
        delete rear;
        rear = NULL;
        return;
    }

    queue_dest(rear -> next);
    //Check each mbr for delete and delete them if present
    delete rear;
    
}

queue::~queue()
{
    if(rear)
        queue_dest(rear -> next);
    else
        rear = NULL;
        
}

q_node::q_node()
{
    answer = NULL;
    question = NULL;
    next = NULL;
}

q_node::~q_node()
{
    if(answer)
    {
        delete [] answer;
        answer = NULL;
    }
    if(question)
    {
        delete [] question;
        question = NULL;
    }
}

//Push to the stack of queue objects
int stack::push(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[])  
{
    int MAX = 5;

    //Update top_index
    if(!head)   //Base case: Allocate mem for queue obj
    {
        head = new node; //Mem leak here: new operator
        head -> card_arr[top_index] = new queue;
        head -> card_arr[top_index] -> enqueue(q_1, q_2, q_3, a_1, a_2, a_3);
        ++top_index;
    }
    else if(top_index < MAX)  //Increment here
    {
        head -> card_arr[top_index] = new queue;
        head -> card_arr[top_index] -> enqueue(q_1, q_2, q_3, a_1, a_2, a_3); 
        ++top_index;
    }

    else if(top_index == MAX)  //Eval top_index and create new node *ADD at head*
    {
        node * n_node = new node;  
        n_node -> next = head;
        head = n_node;
        top_index = 0;
        head -> card_arr[top_index] = new queue;
        n_node -> card_arr[top_index] -> enqueue(q_1, q_2, q_3, a_1, a_2, a_3);
        top_index = 1;
    }

    return 0;
}

//Returns a pointer that points to the most recently added "card" and decrements the top index. Sets that decrement index's rear pointer to NULL
queue * stack::pop()
{
    if(!head)
       return NULL;
   
    queue * n_queue; 
    --top_index;
    n_queue = head -> card_arr[top_index];
    head -> card_arr[top_index] = NULL;
    
    if(top_index == 0)
    {
        node * temp = head;
        head = head -> next;
        delete temp;
    }

    return n_queue; //return the queue ptr
}

void queue::copy(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[]) 
{
 
       strcpy(q_1,  rear -> question); 
       strcpy(a_1,  rear -> answer); 
       strcpy(q_2,  rear -> next -> question); 
       strcpy(a_2,  rear -> next -> answer); 
       strcpy(q_3,  rear -> next -> next -> question); 
       strcpy(a_3,  rear -> next -> next -> answer); 

}

int queue::enqueue(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[])
{

    //Check for !rear (if-state)
    if(!rear)
    {
        rear = new q_node;  //Mem leak here: new operator
        rear -> question = new char[strlen(q_1)+1];
        strcpy(rear -> question, q_1);
        rear -> answer = new char[strlen(a_1)+1];
        strcpy(rear -> answer, a_1);
    
        //Create nodes to add after first node
        q_node * n_node = new q_node;
        rear -> next = n_node;
        n_node -> next = rear;
        n_node -> question = new char[strlen(q_2)+1];
        strcpy(n_node -> question, q_2);
        n_node -> answer = new char[strlen(a_2)+1];
        strcpy(n_node -> answer, a_2);

        n_node = new q_node;
        n_node -> next = rear -> next;
        rear -> next = n_node;
        n_node -> question = new char[strlen(q_3)+1];
        strcpy(n_node -> question, q_3);
        n_node -> answer = new char[strlen(a_3)+1];
        strcpy(n_node -> answer, a_3);
    }
    
    return 0;
}

int queue::dequeue()
{
    //Check !rear
    //q_node * f_ptr = rear;

    //If only one item
    if(rear -> next == rear)
    {
        delete rear;
        rear = NULL;
    }

    //Multiple
    /*else
    {
        do
        {
            rear = rear -> next;
            delete f_ptr;
            f_ptr = rear;
        }
        while(
    }*/

    return 0;
}

/*
int queue::isempty()
{
    //Stub
    if(rear)
        return 1;
    return 0;
}

int queue::isfull()
{
    //Stub
    if(rear)
        return 1;
    return 0;
}*/


int queue::display_pub(int & question, char answer[])
{
    if(!rear)
        return 0;
    int value = 0;
    value = display(rear, question, answer);
    
    return value;
}

int queue::display(q_node * rear, int & question, char answer[])
{

    if(!rear)
        return 0;
    q_node * temp = rear;

    switch(question){
        case 0:
            cout << "Question (" << (question + 1) << "): " << temp->question << endl;
            strcpy(answer, temp->answer);
            break;
        case 1:
            cout << "Question (" << (question + 1) << "): " << temp->next->question << endl;
            strcpy(answer, temp->next->answer);
            break;
        case 2:
            cout << "Question (" << (question + 1) << "): " << temp->next->next->question << endl;
            strcpy(answer, temp->next->next->answer);
            break;
    }
    return 0;
}
