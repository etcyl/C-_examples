//Preprocessor directives:
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Header comments:
//Matt Fleetwood, CS 162, Program 4
//This header file contains code that can be included as many times as necessary throughout the source code files.
//Constants, class interface(s), and prototypes are defined in this h file.

//Constants:

//Struct definition:
struct dogPark
{
       char* parkName;              //dynamically allocated array for the park name
       char* location;              //" " for the park location
       char* description;           //" " for the park description
       char* fence;                //" " for the park being fenced, partially, or not at all
       char* size;                  //" " for the park size
};

class dogParks
{
      public:
            dogParks();            //default constructor - initializes data members to zero equivalent
            ~dogParks();                       //deconstructor
            void addPark();                    //adds a new park into the set of available parks
            void getInfo(char parkName[]);     //shows info of a park by name
            void disp();                       //shows all dog parks (name, location, etc.)

      private:
            dogPark* parkList;             //dynamically allocated array of dog parks
            int count;
};
