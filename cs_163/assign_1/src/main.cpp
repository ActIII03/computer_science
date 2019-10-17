//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart and the Asbract Data Type that will hold the data will be LLL

#include "assign1.h"

//Main driver 
int main(void)
{
    //
    FoodCartList cart_list; //Food Cart Object
    d_food_cart cart_info; //Struct Variable for dummy variables

    int decision = 0;
    bool quit = false;

    greeting();
    menu(decision);

    do
    {
        //Menu Interface
        switch(decision)
        {
            //Add Cart to beginning of the LLL
            case 1:
                get_char(cart_info, decision);
                cart_list.add_cart(cart_info);
                break;

            //Display Food Cart by Food Type
            case 2:
                get_char(cart_info, decision);
                cart_list.display_by_type(cart_info);
                break;

            //Delete Favorite Food
            case 3:
                get_char(cart_info, decision);
                cart_list.delete_fav_food(cart_info);
                break;

            //Add Favorite Food
            case 4:
                get_char(cart_info, decision);
                cart_list.add_fav_food(cart_info);
                break; 

            //Display All Food Cart Entries
            case 5:
                cart_list.display();
                break;

            //Delete a food cart
            case 6:
                get_char(cart_info, decision);
                cart_list.delete_cart(cart_info);
                break; 
            
            //Quit Program
            case 7:
                quit = true;
                break;

        }
        if(quit == false) //Call Menu Interface again
            menu(decision);
    }
    while(!quit);

    return 0;
}

