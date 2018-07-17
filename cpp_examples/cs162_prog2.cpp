//Matt Fleetwood, CS 162, Program2
//This program has three levels.
//Level one shows the user a word in German that represents a number from 1 - 10,
//and if the user guesses in English correctly 5 times then they can advance to the next level.
//Level two shows the user a word in German that represents a number from 1 - 10,
//but one letter has been removed and the user must guess which letter is missing.
//After five successful guesses the user can advance to the third and final level.
//Level three is the same as level two but now two or three letters are omitted
//from the word and the user must enter the letters as they appear missing in the word.
//The user is allowed to quit after each correct or incorrect guess.
//Completing all three levels prompts the user with a congratulatory message.

#include <cctype>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 11;

//Displays the rules of the game to the user.
void helpInfo();

//Challenges the user to enter words in English that match the word in German.
void levelOne();

//Challenges the user to enter the single letter missing from the word in German.
void levelTwo();

//Challenges the user to enter to enter the multiple letters missing from the word in German.
void levelThree();

//Displays a message to the user once they have completed all three levels.
void win();

//Shows a message one time to gree the user, then calls the functions as they are listed above.
int main()
{
   cout << endl << endl << "Welcome to a program that will help you learn to count to 10 in German!";

   helpInfo();

   levelOne();

   return 0;

}

void helpInfo()
{

     cout << endl << endl << "This program has three levels." << endl << "For level 1 you are given words in German "
          << "that represent the numbers 1 - 10 and you must enter the correct word."
          << endl << "For level 2, a blank space is inserted in the word and you must enter"
          << "the correct word." << endl << "For level 3, another blank space is inserted "
          << "and you must enter the correct word. For each level you must enter the correct word 5 times to progress," << endl
          << "but you may also quit early if you would like to do so." << endl << endl;

     return;
}

void levelOne()
{

     char userResponse, guess[SIZE], word[SIZE], out[SIZE], one[SIZE] = "eins", two[SIZE] = "zwei", three[SIZE] = "drei", four[SIZE] = "vier", five[SIZE] = "funf",
          six[SIZE] = "sechs", seven[SIZE] = "sieben", eight[SIZE] = "acht", nine[SIZE] = "neun", ten[SIZE] = "zehn";
     int count = 0, num = 0;

     srand(time(0));

     cout << endl << endl << "Level one starting! Easy guessing . . ." << endl;
   do
    {
    num = rand() % 10;

    if(num == 0)
     {
      strcpy(word, "one");
      strcpy(out, one);
     }
    else if(num == 1)
     {
      strcpy(word, "two");
      strcpy(out, two);
     }
    else if(num == 2)
     {
      strcpy(word, "three");
      strcpy(out, three);
     }
    else if(num == 3)
     {
      strcpy(word, "four");
      strcpy(out, four);
     }
    else if(num == 4)
     {
      strcpy(word, "five");
      strcpy(out, five);
     }
    else if(num == 5)
     {
      strcpy(word, "six");
      strcpy(out, six);
     }
    else if(num == 6)
     {
      strcpy(word, "seven");
      strcpy(out, seven);
     }
    else if(num == 7)
     {
      strcpy(word, "eight");
      strcpy(out, eight);
     }
    else if(num == 8)
     {
      strcpy(word, "nine");
      strcpy(out, nine);
     }
    else if(num == 9)
     {
      strcpy(word, "ten");
      strcpy(out, ten);
     }

     cout << "The word is: " << out << endl << "Enter your guess in lower case letters: ";
     cin.get(guess, SIZE, '\n');
     cin.ignore(100, '\n');

     if(strcmp(guess, word) == 0)
       {
        count = count + 1;
        cout << "Right! The number " << guess << " is " << out << " in German."
             << endl << "Your score is now: " << count << endl;
        if(count == 5)
          return levelTwo();
        cout << " Would you like to keep playing to 5 points?"
             << " Enter Y for yes and enter N to quit: ";
        cin >> userResponse;
        cin.ignore(100, '\n');
       } else
        {
        cout << "Sorry, that's not right! Try again? Enter Y for yes and N to quit: ";
        cin >> userResponse;
        cin.ignore(100, '\n');
        }

     if(count == 5)
      return  levelTwo();

     } while(userResponse == 'Y');
    return;
}

void levelTwo()
{

     char userResponse, guess, word[SIZE], out[SIZE], letterOut, one[SIZE] = "eins", two[SIZE] = "zwei", three[SIZE] = "drei", four[SIZE] = "vier", five[SIZE] = "funf",
          six[SIZE] = "sechs", seven[SIZE] = "sieben", eight[SIZE] = "acht", nine[SIZE] = "neun", ten[SIZE] = "zehn";
     int count = 0, num = 0, j = 0;

     srand(time(0));

     cout << endl << endl << "Level two starting! Harder guessing . . ." << endl;
   do
    {
    num = rand() % 10;

    if(num == 0)
     {
      strcpy(word, "one");
      strcpy(out, one);
     }
    else if(num == 1)
     {
      strcpy(word, "two");
      strcpy(out, two);
     }
    else if(num == 2)
     {
      strcpy(word, "three");
      strcpy(out, three);
     }
    else if(num == 3)
     {
      strcpy(word, "four");
      strcpy(out, four);
     }
    else if(num == 4)
     {
      strcpy(word, "five");
      strcpy(out, five);
     }
    else if(num == 5)
     {
      strcpy(word, "six");
      strcpy(out, six);
     }
    else if(num == 6)
     {
      strcpy(word, "seven");
      strcpy(out, seven);
     }
    else if(num == 7)
     {
      strcpy(word, "eight");
      strcpy(out, eight);
     }
    else if(num == 8)
     {
      strcpy(word, "nine");
      strcpy(out, nine);
     }
    else if(num == 9)
     {
      strcpy(word, "ten");
      strcpy(out, ten);
     }

     j = strlen(out);
     num = rand() % j;
     letterOut = out[num];
     out[num] = '_';
     out[j] = '\0';

     cout << "The word is: " << out << endl << "Enter your letter guess in lower case: ";
     cin >> guess;
     cin.ignore(100, '\n');

     if(guess == letterOut)
       {
        count = count + 1;
        cout << "Right!"
             << endl << "Your score is now: " << count << endl;
        if(count == 5)
          return levelThree();
        cout << " Would you like to keep playing to 5 points?"
             << " Enter Y for yes and enter N to quit: ";
        cin >> userResponse;
        cin.ignore(100, '\n');
       } else
        {
        cout << "Sorry, that's not right! Try again? Enter Y for yes and N to quit: ";
        cin >> userResponse;
        cin.ignore(100, '\n');
        }
     if(count == 5)
        return  levelThree();
     } while(userResponse == 'Y');
    return;
}

void levelThree()
{

     char userResponse, guess[SIZE], word[SIZE], out[SIZE], letterOut[SIZE], one[SIZE] = "eins", two[SIZE] = "zwei", three[SIZE] = "drei", four[SIZE] = "vier", five[SIZE] = "funf",
          six[SIZE] = "sechs", seven[SIZE] = "sieben", eight[SIZE] = "acht", nine[SIZE] = "neun", ten[SIZE] = "zehn";
     int count = 0, num = 0, numFor = 2, j = 0;

     srand(time(0));

     cout << endl << endl << "Level three starting! Hardest guessing . . ." << endl;
   do
    {
    num = rand() % 10;

    if(num == 0)
     {
      strcpy(word, "one");
      strcpy(out, one);
     }
    else if(num == 1)
     {
      strcpy(word, "two");
      strcpy(out, two);
     }
    else if(num == 2)
     {
      strcpy(word, "three");
      strcpy(out, three);
     }
    else if(num == 3)
     {
      strcpy(word, "four");
      strcpy(out, four);
     }
    else if(num == 4)
     {
      strcpy(word, "five");
      strcpy(out, five);
     }
    else if(num == 5)
     {
      strcpy(word, "six");
      strcpy(out, six);
     }
    else if(num == 6)
     {
      strcpy(word, "seven");
      strcpy(out, seven);
     }
    else if(num == 7)
     {
      strcpy(word, "eight");
      strcpy(out, eight);
     }
    else if(num == 8)
     {
      strcpy(word, "nine");
      strcpy(out, nine);
     }
    else if(num == 9)
     {
      strcpy(word, "ten");
      strcpy(out, ten);
     }

     j = strlen(out);

     for(int i = 0; i < numFor; ++i)
        {
         num = rand() % j - 1;
         letterOut[i] = out[num];
         out[num] = '_';
        }
        out[j-1]= '\0';

     cout << "The word is: " << out << endl << "Enter your guess letters in lower case, one after the other, in the order they"
          << endl << " appear removed from the word (for instance, if f_v_ appeared, you would enter ie to make the word complete,"
          << endl << "i.e. five): ";
     cin.get(guess, SIZE, '\n');
     cin.ignore(100, '\n');

     if(strcmp(guess, letterOut))
       {
        count = count + 1;
        cout << "Right!"
             << endl << "Your score is now: " << count << endl;
        if(count == 5)
          return win();
        cout << " Would you like to keep playing to 5 points?"
             << " Enter Y for yes and enter N to quit: ";
        cin >> userResponse;
        cin.ignore(100, '\n');
       } else
        {
        cout << "Sorry, that's not right! Try again? Enter Y for yes and N to quit: ";
        cin >> userResponse;
        cin.ignore(100, '\n');
        }
     } while(userResponse == 'Y');
    return;
}

void win()
{

     cout << endl << endl << "Contrats, you successfully matched the words and missing letters!!11oneeleventyone"
          << endl << endl;

   return;

}

