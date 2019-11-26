//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
int insert(node * & root, int add_num); 
int removal(node * & root, int del_num); 
int removal_iter(node * & root);
int removal_ios_rec(node * & root);
int display_sorted(node * root);
int get_height(node * root);
int get_height_rec(node * root);
int is_max(int left, int right);
int insert_a_item(node * & root, int add_num);

