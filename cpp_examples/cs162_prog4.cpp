//Preprocessor directives:
#include "cs162_prog4.h"

using namespace std;

int const SIZE = 41;

//Matt Fleetwood, CS 162, Program 4
//This program uses classes or structs to contain information about dog parks, such as name of the park,
//general location, description (muddy, hills, benches), if the park is fenced, and size (small, med., large).
//A class is then created that stores a collection of dog parks (i.e. a collection of parks and their info).

//Implementation of member functions:

//Constructor sets the parkList pointer to NULL and the count for the number of items in the list to zero
dogParks::dogParks()
{
        parkList = NULL;
        count = 0;
}

//Deconstructor de-allocates (deletes) all of the (dynamically allocated) arrays
dogParks::~dogParks()
{
	for(int i = 0; i < count; ++i)
	{
            delete parkList[i].parkName;
            delete parkList[i].location;
            delete parkList[i].description;
            delete parkList[i].fence;
            delete parkList[i].size;
	}

        delete parkList;
}

//addPark() func adds a park to the (dynamically allocated) array / list of dog parks
void dogParks::addPark()
{
        char name[SIZE], location[SIZE], description[SIZE], fenced[SIZE], size[SIZE];
        count++;

        //Get the park info name to store in temporary arrays
        cout << endl << endl << "Enter the park name: ";
        cin.get(name, SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Enter the park location (e.g. the city name): ";
        cin.get(location, SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Enter the park description (e.g. if it is muddy, hilly, and there are benches then enter muddy, hilly, benches): ";
        cin.get(description, SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Enter if the park is fenced (not at all, partially, completely): ";
        cin.get(fenced, SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Enter the park size (small, medium, large): ";
        cin.get(size, SIZE, '\n');
        cin.ignore(100, '\n');

        //If there are no items in the park list (i.e. the list hasn't been made yet)
        if(count == 1)
        {
            parkList = new dogPark[count];
        }
        //There is at least one item in the list and the user asked to append / add parks to the list
        else
        {  //Copy the last item(s) in the list to add to the new (dynamically allocated) list that will have
           //all previous items and the newly appended / added item
           dogPark* copyList;
           copyList = new dogPark[count - 1];
           for(int i = 0; i <= count - 2; ++i)
              {
              copyList[i].parkName = new char[strlen(parkList[i].parkName)];
              strcpy(copyList[i].parkName, parkList[i].parkName);
              copyList[i].location = new char[strlen(parkList[i].location)];
              strcpy(copyList[i].location, parkList[i].location);
              copyList[i].description = new char[strlen(parkList[i].description)];
              strcpy(copyList[i].description, parkList[i].description);
              copyList[i].fence = new char[strlen(parkList[i].fence)];
              strcpy(copyList[i].fence, parkList[i].fence);
              copyList[i].size = new char[strlen(parkList[i].size)];
              strcpy(copyList[i].size, parkList[i].size);
              }
        //Delete the copy list since this list cannot be seen by the destructor
	for(int i = 0; i < count; ++i)
	{
            delete parkList[i].parkName;
            delete parkList[i].location;
            delete parkList[i].description;
            delete parkList[i].fence;
            delete parkList[i].size;
	}

	delete parkList;
        parkList = new dogPark[count];

        //Copy all items before the newly appended / added items into the new list
        for(int i = 0; i <= count - 2; ++i)
              {
              parkList[i].parkName = new char[strlen(copyList[i].parkName)];
              strcpy(parkList[i].parkName, copyList[i].parkName);
              parkList[i].location = new char[strlen(copyList[i].location)];
              strcpy(parkList[i].location, copyList[i].location);
              parkList[i].description = new char[strlen(copyList[i].description)];
              strcpy(parkList[i].description, copyList[i].description);
              parkList[i].fence = new char[strlen(copyList[i].fence)];
              strcpy(parkList[i].fence, copyList[i].fence);
              parkList[i].size = new char[strlen(copyList[i].size)];
              strcpy(parkList[i].size, copyList[i].size);
              }
        //Delete copyList items since they cannot be viewed by the destructor
        for(int i = 0; i < count - 1; ++i)
	{
            delete copyList[i].parkName;
            delete copyList[i].location;
            delete copyList[i].description;
            delete copyList[i].fence;
            delete copyList[i].size;
	}
	delete copyList;
        }

        //Add the newest park item into the park list
        parkList[count - 1].parkName = new char[strlen(name)];
        strcpy(parkList[count - 1].parkName, name);

        parkList[count - 1].location = new char[strlen(location)];
        strcpy(parkList[count - 1].location, location);

        parkList[count - 1].description = new char[strlen(description)];
        strcpy(parkList[count - 1].description, description);

        parkList[count - 1].fence = new char[strlen(fenced)];
        strcpy(parkList[count - 1].fence, fenced);

        parkList[count - 1].size = new char[strlen(size)];
        strcpy(parkList[count - 1].size, size);
}

//disp() func displays all of the parks and their info
void dogParks::disp()
{
     for(int i = 0; i < count; ++i)
        {
        cout << "Displaying all . . . " << endl
             << parkList[i].parkName << endl
             << parkList[i].location << endl
             << parkList[i].description << endl
             << parkList[i].fence << endl
             << parkList[i].size << endl << endl;
        }
}

//getInfo() func uses a park name passed from the user to the func to find a park (if it is in this list)
//by name, and then displays that park's info
void dogParks::getInfo(char parkName[])
{
     for(int i = 0; i < count; ++i)
        {
        if(strcmp(parkName, parkList[i].parkName) == 0)
          {
          cout << "Match found!" << endl
               << parkList[i].parkName << endl
               << parkList[i].location << endl
               << parkList[i].description << endl
               << parkList[i].fence << endl
               << parkList[i].size << endl << endl;

         return;
         }
       }
        cout << "No match found. Try adding this new park to the list!" << endl << endl;
}
