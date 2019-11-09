//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"

//Recieve the data from the file read-in from main and this function passes the data to be pushed
int trivial_pursuit::get_txt(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[])
{
    new_q_a.push(q_1, a_1, q_2, a_2, q_3, a_3); //Mem leak here: Beginning of mem leak

    return 0;
}


//Play game here and pass the deep copy to either the right or wrong stack of "cards"
int trivial_pursuit::get_answer() //Update prototype (char * q, char * a)
{
    
    int question = 0;
    char copied_answer[BUFFER];

    char question_1[BUFFER];
    char question_2[BUFFER];
    char question_3[BUFFER];

    char answer_1[BUFFER];
    char answer_2[BUFFER];
    char answer_3[BUFFER];

    queue * temp = new_q_a.pop(); 
    bool correct = false;

    // 3 question turn
    while(question < 3)
    {
        temp -> display_pub(question, copied_answer);  
        correct = is_correct(copied_answer); 
        ++question;
    }

    //Push either to correct stack or wrong stack
    if(correct)
    {
        temp -> copy(question_1, answer_1, question_2, answer_2, question_3, answer_3); 
        player_stack.push(question_1, answer_1, question_2, answer_2, question_3, answer_3);      
    }
    else
    {
        temp -> copy(question_1, answer_1, question_2, answer_2, question_3, answer_3); 
        discard_stack.push(question_1, answer_1, question_2, answer_2, question_3, answer_3);      
    }
    
    delete temp;

    return 0;
}

//Compare user's inputted answer with the actual answer, returning a true or false boolean value
bool trivial_pursuit::is_correct(char answer[])
{
    char user_answer[BUFFER];
    cout << "Please enter your answer: " << endl;
    cin.get(user_answer, BUFFER, '\n');
    cin.ignore(100, '\n');

    //If User is right, return true
    if(!(strcmp(user_answer, answer)))
    {
       cout << "You are correct!" << endl; 
       return true;
    }

    return false;
}
