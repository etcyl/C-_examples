//Preprocessor directives:
#include "cs162_prog4.h"

/*Matt Fleetwood, CS 162, Program 4
  This program uses a base struct to contain character arrays for information about a dog park (e.g. one array is for a park name,
  another is for the park's location, another is for the park's description (is it muddy, hilly, are there benches), another for
  whether the park is fenced (partially, completely, not fenced), and the last array is for the park size (small, medium, large).
  This base struct's arrays are sized just right by dynamically allocating the arrays and getting the right size from the user's
  entries (i.e. the user enters a park name "Park Name", and the length of that entry is used as the number for the struct array,
  park name. Similarly, a class stores a dynamically allocated array of these structs, more of which can be added to this list
  by using the class function addPark(). The class also has a constructor and destructor function, which initialize and delete the
  class data members. The last two class functions are display functions, one of which displays a park's info by getting the user
  to enter the park name and the other displays all of the parks and their info.
*/

int const TEXT = 31;

int main()
{
   //Declare main variables
   bool  usrDisp, usrRspns;
   char prkNm[TEXT];
   dogParks aList;

   //Main message for user info about the program
   cout << "This program uses a class to contain and modify info about a dog park and information about the park, " << endl
        << "such as the park name, the location (city name), description (muddy, hilly, benches), whether the park " << endl
        << "is fenced (not at all, partially, completely), and the park size (small, medium, large)." << endl << endl; 

   //Use a do-while to continue adding parks to the list until the user is satisfied
   do
    {
    //Add a park to the list
    aList.addPark();

    //Prompt user for displaying a park's info by getting from the user the park's name
    cout << "Would you like to display a park's info by the name? Enter 1 for yes and 0 for no: ";
    cin >> usrDisp;
    cin.ignore(100, '\n');
    if(usrDisp == 1)
      {
      cout << "Enter the park name: ";
      cin.get(prkNm, TEXT, '\n');
      cin.ignore(100, '\n');
      aList.getInfo(prkNm);
      }

    //Prompt user for displaying all parks and their info
    cout << "Would you like to display the parks? Enter 1 for yes or 0 for no: ";
    cin >> usrDisp;
    cin.ignore(100, '\n');
    if(usrDisp == 1)
       aList.disp();

    //Prompt user if they would like to add more parks to the list
    cout << "Continue? Enter 1 for yes and 0 for no: ";
    cin >> usrRspns;
    cin.ignore(100, '\n');
    }while(usrRspns == 1);

   return 0;

}
