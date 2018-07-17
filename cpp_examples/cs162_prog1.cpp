/*Matt Fleetwood, 4-14-2016, CS 162, Program #1
  This program has three phases:
  1) allows the user to decide which money conversion to perform
  (US --> CNY, CNY --> US) or exit to the next phase;
  2) allows the user to enter a US dollar amount and  displays
  the equivalent paper denominations in CNY;
  3) allows the user to enter a CNY amount, displays the
  equivalent paper denominations in US dollars, and allows
  the user to repeat from 1) if desired.
*/

#include <cctype>
#include <iostream>
using namespace std;

int main()
{
    const float RATE = 6.50824;
    char userResponse;;
    float usDollars, cnyDollars, totAmount, amtCopy;
    bool temp;
    int hundreds, fifties, twenties, tens, fives, ones;

    cout << endl <<  " Hello! This program has 3 phases. Phase 1 asks if" << endl
         << " you would like to convert US money to CNY money,"  << endl
         << " if you would like to convert CNY to US, or repeat. Phase 2" << endl
         << " asks you for an amount in US dollars and displays" << endl
         << " the equivalent paper denomination in CNY. Phase 3 asks" << endl
         << " you for paper denominations in CNY and displays the equivalent" << endl
         << " total in US dollars." << endl << endl
         << " Would you like to convert a US amount to CNY? Please" << endl
         << " enter Y for yes or N for no: ";
     cin >> userResponse;
     cin.ignore(100, '\n');
     while('Y' != userResponse && 'N' != userResponse)
          {
          cout << " Error, enter Y for yes or N for no: ";
           cin >> userResponse;
           cin.ignore(100, '\n');
          }

    if('Y' == userResponse)
      {
      cout << endl << " US to CNY conversion selected, enter an amount in US"
           << " dollars: $";
       cin >> usDollars;
       cin.ignore(100, '\n');
       cnyDollars = usDollars*RATE;
      cout << " The amount of CNY dollars for the given US is: $" << cnyDollars << endl;
      }

    cout << endl << " Would you like to make a conversion from CNY to US?" << endl
         << " Please enter Y for yes or N for no: ";
     cin >> userResponse;
     cin.ignore(100, '\n');
     while('Y' != userResponse && 'N' != userResponse)
          {
          cout << " Error, enter Y for yes or N for no: ";
           cin >> userResponse;
           cin.ignore(100, '\n');
          }

    if('Y' == userResponse)
      {
      cout << endl << " CNY to US conversion selected, enter an amount in CNY"
           << " dollars: $";
       cin >> cnyDollars;
       cin.ignore(100, '\n');
       usDollars = cnyDollars/RATE;
      cout << " The amount of US dollars for the given CNY is: $" << usDollars << endl;
      }
    cout << endl << " Would you like to repeat the conversion process? Enter"
         << " Y for yes or N for no: ";
     cin >> userResponse;
     cin.ignore(100, '\n');
     while('Y' != userResponse && 'N' != userResponse)
          {
          cout << " Error, enter Y for yes or N for no: ";
           cin >> userResponse;
           cin.ignore(100, '\n');
          }
     if('Y' == userResponse)
       main();
    cout << endl << " No selected, proceeding to next phase . . . " << endl << endl
         << " Enter an amount in US dollars to show the equivalent" << endl
         << " paper money denominations in CNY: $";
     cin >> totAmount;
     cin.ignore(100, '\n');
    while(totAmount <= 0)
         {
         cout << " Error, enter an amount greater than 0: $";
          cin >> totAmount;
          cin.ignore(100, '\n');
         }
    cnyDollars = totAmount*RATE;
    amtCopy = cnyDollars;
    hundreds = cnyDollars/100;
    cnyDollars = cnyDollars -(100*hundreds);
    fifties = cnyDollars/50;
    cnyDollars = cnyDollars - (50*fifties);
    twenties = cnyDollars/20;
    cnyDollars = cnyDollars - (20*twenties);
    tens = cnyDollars/10;
    cnyDollars = cnyDollars - (10*tens);
    fives = cnyDollars/5;
    cnyDollars = cnyDollars - (5*fives);
    ones = cnyDollars/1;

   cout << endl << " The total amount in US dollars is: $" << totAmount << endl
        << " The total amount in CNY dollars is: $" << amtCopy << endl
        << " The number of hundreds are: $" << hundreds << endl
        << " The number of fifties are: $" << fifties << endl
        << " The number of twenties are: $" << twenties << endl
        << " The number of tens are: $" << tens << endl
        << " The number of fives are: $" << fives << endl
        << " The number of ones are: $" << ones << endl << endl
        << " Proceeding to next phase . . . " << endl << endl;

   cout << " Enter the number of CNY hundreds: $";
    cin >> hundreds;
    cin.ignore(100, '\n');
   cout << " Enter the number of CNY fifites: $";
    cin >> fifties;
    cin.ignore(100, '\n');
   cout << " Enter the number of CNY twenties: $";
    cin >> twenties;
    cin.ignore(100, '\n');
   cout << " Enter the number of CNY tens: $";
    cin >> tens;
    cin.ignore(100, '\n');
   cout << " Enter the number of CNY fives: $";
    cin >> fives;
    cin.ignore(100, '\n');
   cout << " Enter the number of CNY ones: $";
    cin >> ones;
    cin.ignore(100, '\n');

   cout << endl << "You entered: " << endl << hundreds << " hundreds,"
        << endl << fifties << " fifties,"
        << endl << twenties << " twenties,"
        << endl << tens << " tens,"
        << endl << fives << " fives,"
        << endl << "and " << ones << " ones.";

   hundreds = hundreds*100;
   fifties = fifties*50;
   twenties = twenties*20;
   tens = tens*10;
   fives = fives*5;
   totAmount = hundreds + fifties + twenties + tens + fives+ ones;
   amtCopy = totAmount;
   totAmount = totAmount/RATE;

   cout << endl << "The total amount in CNY dollars is: $" << amtCopy
        << endl << "The total amount in US dollars is: $" << totAmount
        << endl << endl;
   cout << " Would you like to repeat the program? Enter Y for yes or "
        << " N for no: ";
    cin >> userResponse;
    cin.ignore(100, '\n');
    while('Y' != userResponse && 'N' != userResponse)
         {
         cout << " Error, enter Y for yes or N for no: ";
          cin >> userResponse;
          cin.ignore(100, '\n');
         }
    if('Y' == userResponse)
      main();

   cout << endl << endl << " Program terminating, goodbye! . . . " << endl << endl;

    return 0;
}
