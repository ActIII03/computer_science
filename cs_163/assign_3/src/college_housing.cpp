//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:
#include "college_housing.h"

CollegeHousing::CollegeHousing(){

    location = NULL;
    sq_footage = 0;
    num_of_bedrm = 0; 
    dist_from_psu = 0;

}

CollegeHousing::~CollegeHousing(){

    if(name)
    {
        delete name;
        name = NULL;
    }
    if(location)
    {
        delete location;
        location = NULL;
    }

}


int CollegeHousing::add_floorplan(char * new_name, char * new_location, int new_sq_ft, int new_num_bdrm, int new_PSU_dist)
{
    
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
    location = new char[strlen(new_location) + 1];
    strcpy(location, new_location);
    sq_footage = new_sq_ft;
    num_of_bedrm = new_num_bdrm;
    dist_from_psu = new_PSU_dist;

    return 0;

}


int CollegeHousing::to_copy(CollegeHousing to_copy)
{
    
    name = new char[strlen(to_copy.name) + 1];
    strcpy(name, to_copy.name);
    location = new char[strlen(to_copy.location) + 1];
    strcpy(location, to_copy.location);
    sq_footage = to_copy.sq_footage;
    num_of_bedrm = to_copy.num_of_bedrm;
    dist_from_psu = to_copy.dist_from_psu;

    return 0;
}

int CollegeHousing::retrieve(char * retrieve, CollegeHousing & found){


    return 0;
}


int CollegeHousing::get_name(char possible_match[])
{
    strcpy(name, possible_match);
    return 0;
}

int CollegeHousing::display(CollegeHousing & found) const{

    cout << "Name: " << found.name << "\nLocation: " << found.location
         << "\nSquare footage: " << found.sq_footage << "\nNumber of bedrooms: " << found.num_of_bedrm
         << "\nDistance from PSU(miles): " << found.dist_from_psu << endl;

    return 0;
}

int menu_choice()
{
    int choice = 5;
    cout << "Which option would like?\n(1) Add Floorplan\n(2) Display Floorplans by City\n(3) Display by miles\n(4) Display by Location Name\n"
         << "(5) Quit\nChoice(1-5): ";
    cin >> choice;
    cin.ignore(100, '\n');
    return choice;
}

bool again()
{
    char choice = 'Y';

    cout << "Would you like to continue using this program?(Y/N): ";
    cin >> choice;
    cin.ignore(100, '\n');

    if(toupper(choice) == 'Y' || choice == 'y')
        return true;
    
    return false;
}

