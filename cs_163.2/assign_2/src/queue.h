//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "routes.h"

struct route_qnode
{
    route_qnode();
    routes route_entries;
    route_qnode * next;
};

class queue
{
    public:

        //Constructor and destructor
        queue();
        ~queue();

        //Add route to front of CLL
        int enqueue(routes & add_route, const int route_choice); //<-- Add argument

        //Remove route from CLL
        int dequeue(routes & remove_route, int route_choice); //<-- Add argument

        //Peek both routes
        int peek(routes & p_route, routes & a_route); //<-- Add argument

    private:

        int enqueue(route_qnode * & rear, routes & add_route);
        int dequeue(route_qnode * & rear, route_qnode * & current, routes & out_route, int route_choice);
        route_qnode * p_rear;
        route_qnode * a_rear;
};
