//Name: Armant Touche
//Class: CS 163
//Instructor: Karls Fant
//Description:

#include "graph.h"

table::table(int size)
{

    list_size = size;
    adjacency_list = new vertex[list_size];
    
    for(int index = 0; index < list_size; ++index)
    {
        adjacency_list[index].new_task = NULL;
        adjacency_list[index].head = NULL;
    }

}

table::~table()
{


}


int table::insert_vertex(TasksToDo & new_tasks)
{


    return 0;

}

int table::find_location(char * key)
{

    return 0;

}

int table::insert_path(char * vertex, char * to_attach)
{


    return 0;

}

int table::display_adjacent(char * key)
{

    return 0;

}

int table::display_all()
{

    return 0;

}
