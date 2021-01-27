//AdvancedCENSORsensability---- This program is an updated version of the previous CENSOR program., we could replace one character in the sentence which user input into a special character.
//Melinda Chen Comp Sci 30S
//2020-05-03

#include<iostream>
#include<cstring>
#include<Windows.h>
#include<chrono>
using namespace std;

//Constant for program
const int MAXSIZE = 80;          //maximum size of a line

//Prototypes
void replace(char string[80], char badchar, char newchar);         //replace all occurances of "badchar" into "goodchar"
void get_string(char string[MAXSIZE]);           //This function reads in the string

 

int main()
{
	char string[80];              //phrase to be censor
	char badchar;                 // the character which will be replaced
	char newchar;                 // the character replaced with
	int howmany;                 //the number of rounds which the user want to play
	char Anotherreplacement;     //ask the user whether to do another replacement
	int i,j;                       //Loop Counter

	cout << "How many strings are there? ";
	cin >> howmany;
	while (howmany < 1)
	{
		cout << "Invalid number, please re-enter the number correctly: ";
		cin >> howmany;
		cout << endl;
	}
	//Clear the buffer
	cin.ignore();

	// Set postition to zero
	j = 0;
	for (i = 1;i <= howmany;i++)
	{
		cout << "Enter string #" << i << ": ";
		get_string(string);
		cout << endl;
		//Loop through as many replacement as wanted
		do
		{
			cout << "Enter character to replace: ";
			badchar = _getwche();
			cout << endl;

			cout << "What should " << badchar << " be replaced with?";
			newchar = _getwche();
			replace(string, badchar, newchar);
			cout << endl;
			cout << "Do you want another replacement? (Y/N) ";
			Anotherreplacement = toupper(_getwche());
			cout << endl; 
			while (Anotherreplacement != 'Y' && Anotherreplacement != 'N')
			{
				cout << "INVALID CHOICE!!! Please re-enter Y/N only! ";
				Anotherreplacement = toupper(_getwche());
				cout << endl;
			}
		} while (Anotherreplacement =='Y');
		// Print out the final string
		cout << "The final string is: " << string << endl;
		cout << endl;
	}//for
	return 0;
}//Main


// get_string - This function reads in the phrase and changes it to upper case
// phrase - phrase to read in
void get_string(char string[80])
{
	int pos;                 // position in the string

	// Set position to zero
	pos = 0;
	// Read in the string
	do
	{
		string[pos] = _getwche();
		pos++;
	} while (string[pos - 1] != '\r');
	// Add zeros characters
	string[pos - 1] = '\0';

} // get_string

//replace- This function replaces all occurances of "badchar" into "goodchar"
//string[80]--an array contains a maximum of 80 characters
//badchar--the character needs to be replaced
//newchar--the character replacement
void replace(char string[80], char badchar, char newchar)
{
	int pos;     //overall position in string

	for (pos = 0;pos <= strlen(string);pos++)
	{
		while (string[pos] == badchar)
     		string[pos] = newchar;
	}
}