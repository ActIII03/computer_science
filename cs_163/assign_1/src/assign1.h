//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 250;

struct address
{

    char * line_1;
    char * city;
    char * state;
    int * zip_code;
};

struct food_cart
{

    char * name;
    address c_address;
    char * type;
    char * cart_food_favorite;
};

struct node{

    food_cart fd_cart;
    node * next;
};

int get_char(char & input_buffer, int & move_to_entry);
//void get_int();
void greeting();
void menu(int & decision);

class FoodCartList
{

    public:

        FoodCartList();
        ~FoodCartList();
        int add_cart();
        int add_fav_food();
        int display_by_type(); 
        int delete_fav_food(); 
        int destroy(node * & head);
        int display();

    private:

        int count(node * head); 
        node * head;
        node * tail;
};