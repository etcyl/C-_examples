#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int const SIZE = 21, TEXT = 93;

struct question
{
      int questionNumber;
      char complete[SIZE], questionType[SIZE], questionText[TEXT];

};

void dispType(question qList[], int num);

int main()
{

   int qNum, fileExists, dispT;
   char ch, repeat, dispResponse, qType[SIZE], qText[TEXT], isComp[SIZE];
   question qList[20];
   ifstream in_file, file_in;
   ofstream file_out;

   cout << "This program allows you to write and read questions related to CS 162." << endl
        << "You can enter a question number (1 - 20), a type, a text, and a is-complete notation."

    do
     {
     cout << "Enter the question number: ";
     cin >> qNum;
     cin.ignore(100, '\n');
     qList[qNum].questionNumber = qNum;

     cout << "Enter the question type (e.g. loop, conditional, class, struct, etc.): ";
     cin.get(qType, SIZE, '\n');
     cin.ignore(100, '\n');
     strcpy(qList[qNum].questionType, qType);

     cout << "Enter the question text: ";
     cin.get(qText, TEXT, '\n');
     cin.ignore(100, '\n');
     strcpy(qList[qNum].questionText, qText);

     cout << "Enter C if this question should be marked as complete, or enter IN if should be marked as incomplete: ";
     cin.get(isComp, SIZE, '\n');
     cin.ignore(100, '\n');
     strcpy(qList[qNum].complete, isComp);

     cout << "Should these questions be saved to an existing file? Enter 1 if a file exists already, or enter 2 if a file does not yet exist: ";
     cin >> fileExists;
     cin.ignore(100, '\n');
     if(fileExists == 2)
       {
        file_out.open("practice.txt");
        if(!file_out)
           cout << "Error " << endl;
           else
              {
               file_out << "Question Number: " << qList[qNum].questionNumber << '\n' << "Question Type: " << qList[qNum].questionType
                        << '\n' << "Complete / Incomplete (C/IN): " << qList[qNum].complete << '\n' << "Question: "
                        << qList[qNum].questionText << endl << endl;
               file_out.close();
              }
       }
     else if(fileExists == 1)
       {
        file_out.open("practice.txt", ios::app);
        if(!file_out)
           cout << "Error " << endl;
        else
           {
            file_out << "Question Number: " << qList[qNum].questionNumber << '\n' << "Question Type: " << qList[qNum].questionType
                     << '\n' << "Complete / Incomplete (C/IN): " << qList[qNum].complete << '\n' << "Question: "
                     << qList[qNum].questionText << endl << endl;
            file_out.close();
           }
       }

     cout << "Would you like to display the recorded questions? Enter Y for yes and N for no: ";
     cin >> dispResponse;
     cin.ignore(100, '\n');
     if(dispResponse == 'N')
       cout << "N entered . . . ";
     else if(dispResponse == 'Y')
     {
     in_file.open("practice.txt");
     if(in_file)
     {
     ch = in_file.get();
     while(in_file && !in_file.eof())
     {
          cout << ch;
          ch = in_file.get();
     }

     }
     in_file.close();
     in_file.clear();

     }

     cout << "Would you like to display questions by type? Enter 1 for if types, 2 for loops, 3 for arrays, 4 for funcs, 5 for structs, 6 for files, and 7 for data, or enter 0 for no: ";
     cin >> dispT;
     cin.ignore(100, '\n');
     if(dispResponse == 0)
       cout << "N entered . . . ";
     else
        dispType(qList, dispT);

     cout << "Would you like to continue adding questions? Enter Y for yes: ";
     cin >> repeat;
     cin.ignore(100, '\n');

     }while( repeat == 'Y');

 return 0;
}

void dispType(question list[], int num)
{
     char typeIf[SIZE] = "if", typeLoop[SIZE] = "loop", typeArray[SIZE] = "array", typeFunc[SIZE] = "func", typeStruct[SIZE] = "struct", typeFile[SIZE] = "file", typeData[SIZE] = "data";

     if(num == 1)
     {
        for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeIf) == 0)
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
         }
       }
     else if(num == 2)
     {
         for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeLoop) == 0)
             {
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
             }
         }
     }

     else if(num == 3)
     {
         for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeArray) == 0)
             {
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
             }
         }
         }

     else if(num == 4)
     {
        for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeFunc) == 0)
             {
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
             }
         }
     }

     else if(num == 5)
     {
        for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeStruct) == 0)
             {
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
             }
         }
     }

     else if(num == 6)
     {
        for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeFile) == 0)
             {
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
             }
         }
     }

     else if(num == 7)
     {
        for (int i = 1; i < 20; ++i)
         {
             if(strcmp(list[i].questionType, typeData) == 0)
             {
                cout << endl << endl
                     << "Question number: " << list[i].questionNumber
                     << endl << endl
                     << list[i].questionText
                     << endl
                     << "Question complete: " << list[i].complete
                     << endl
                     << "Question type: " << list[i].questionType
                     << endl;
             }
         }
     }


}
