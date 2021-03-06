//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"

Venue::Venue()
{
    meal = NULL;
    name = NULL;
    price = 0;
    rating = 0;
    review = NULL;
    category = NULL;
}

Venue::~Venue()
{
    if(meal)
    {
        delete meal;
        meal = NULL;
    }
    if(name)
    {
        delete name;
        name = NULL;
    }
    if(review)
    {
        delete review;
        review = NULL;
    }
    if(category)
    {
        delete category;
        category = NULL;
    }
}

int Venue::get_venue(a_venue & new_venue)
{
    meal = new char[strlen(new_venue.meal) + 1];
    strcpy(meal, new_venue.meal);
    name = new char[strlen(new_venue.name) + 1];
    strcpy(name, new_venue.name);
    price = new_venue.price;
    rating = new_venue.rating;
    review = new char[strlen(new_venue.review) + 1];
    strcpy(review, new_venue.review);
    category = new char[strlen(new_venue.category) + 1];
    strcpy(category, new_venue.category);
    return 0;
}

bool Venue::copy_venue(Venue & add_venue)
{
    if(!add_venue.meal)
        return false;
    meal = new char[strlen(add_venue.meal) + 1];
    strcpy(meal, add_venue.meal);
    name = new char[strlen(add_venue.name) + 1];
    strcpy(name, add_venue.name);
    price = add_venue.price;
    rating = add_venue.rating;
    review = new char[strlen(add_venue.review) + 1];
    strcpy(review, add_venue.review);
    category = new char[strlen(add_venue.category) + 1];
    strcpy(category, add_venue.category);
    return true;
}


int Venue::compare(char * is_match)
{
    if(strcmp(meal, is_match) == 0)
        return 0;
    else if(strcmp(meal, is_match) > 0)
        return 1;
    else
        return -1;
}

void Venue::display()
{
    cout << "\nMeal Name: " << meal
         << "\nVenue Name: " << name
         << "\nPrice: " << price
         << "\nRating: " << rating
         << "\nReview: " << review
         << "\nType of Venue: " << category << endl;
}

void Venue::destory()
{

    if(meal)
    {
        delete meal;
        meal = NULL;
        delete name;
        name = NULL;
        delete review;
        review = NULL;
        delete category;
        category = NULL;
    }

    return;
}

int menu()
{
    cout << "\nPlease choose from the following menu options:\n"
         << "(1) Add meal\n(2) Search for a meal\n(3) Remove an entry based on meal name\n"
         << "(4) Retrieve by Meal Name \n(5) Display all by meal\n(6) Display all \n(7) Get Height of BST"
         << "\n(8) Is tree insertion efficiecnt? \n(9) Quit\nChoices(1-9): ";

    int choice = 0;
    cin >> choice;
    cin.ignore(100, '\n');
    return choice;
}
