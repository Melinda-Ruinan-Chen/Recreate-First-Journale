// WAKANDA---This program calculate the defined "numeric value" of a word, each alphabet equals to its position on the alphabetic table
// 100% word: researcher; writing; sagebrush; telephone
// Melinda Chen  Comp. Sci
//2020-05-12

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<chrono>
using namespace std;

// Constants
const int MAXSIZE = 50;              // the longest length of a word

// Function Prototypes
void get_value(char word[MAXSIZE]);           // generates the numeric value of each alphabet 
bool validate_characters(char word[MAXSIZE]); // this function validate whether the word is only composed of upper case letters and lower case letters

//Main
int main()
{
	int pos;              //Loop counter
	int rounds;           //number of words user analyze
	int i;                // Loop counter
	bool validate;         // validate whether
	char word[MAXSIZE];   // an array contains one word
	
	// Ask the user to enter # of words they want to analyze
	cout << "Welcome to the Word Alphabetic Knowledge And Numberic Data Analyzer (WAKANDA)" << endl;
	cout << "How many words do you want to analyze?";
	cin >> rounds;
	// Validate
	while (rounds < 1)
	{
		cout << "INVALID NUMBER, Please re-enter the number of words you want to analyze. ";
		cin >> rounds;
	}
	// Clean the buffer
	cin.ignore();

	// Loop
	for (pos = 1;pos <= rounds;)
	{
		do
		{
			cout << "Enter word # " << pos << " : ";
			// Get the word
			cin.getline(word, MAXSIZE, '\n');
			// validate the word
			validate = validate_characters(word);
			if (!validate)
				cout << "INVALID WORD, Please ";
		} while (!validate);
		if (validate)
			get_value(word);
		pos++;
	}//for	
}
// get_value-- This function generates the numeric value of each alphabet 
// word[MAXSIZE]-- this array contains the word
void get_value(char word[MAXSIZE])  
{
	char alphabet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };  // All possible letters
	int pos;   // Postition in the word
	int pos2;  //the number which the alphabet corresponding to
	int word_value;       //the numberic value of a word

	//Initialize the value
	word_value = 0;

	// Convert the lower case into upper case
	for (pos = 0;pos < strlen(word);pos++)
		word[pos] = toupper(word[pos]);

	// Add zeros character
	word[pos] = '\0';

	// Print out the numberic value of the word
	cout << word << " has a WAKANDA value of ";
	// Loop 
	for (pos = 0;pos < strlen(word);pos++)
	{
		//Find position
		pos2 = 0;
		while (alphabet[pos2] != word[pos])
			pos2++;
		cout << (pos2 + 1);

		if (pos < (strlen(word)-1))
			cout << " + ";

		//Add up value of letter
		word_value += (pos2 + 1);
	}
	cout << " = " << word_value <<"%"<< endl;
}

// validate_characters--this function returns true if the word is composed of characters only
// word[MAXSIZE]-- the word read in
bool validate_characters(char word[MAXSIZE])
{
	int i;      // Loop counter
	int wrong_characters;  // calculate the number of wrong characters

	// Initialize
	wrong_characters= 0;
	// find out whther there are wrong characters
	for (i = 0;i < strlen(word);i++)
	{
		if (word[i] != 'A' && word[i] != 'B' && word[i] != 'C' && word[i] != 'D' && word[i] != 'E' && word[i] != 'F' && word[i] != 'G' && word[i] != 'H' && word[i] != 'I' && word[i] != 'J' && word[i] != 'K' && word[i] != 'L' && word[i] != 'M' && word[i] != 'N' && word[i] != 'O' && word[i] != 'P' && word[i] != 'Q' && word[i] != 'R' && word[i] != 'S' && word[i] != 'T' && word[i] != 'U' && word[i] != 'V' && word[i] != 'W' && word[i] != 'X' && word[i] != 'Y' && word[i] != 'Z' && word[i] != 'a' && word[i] != 'b' && word[i] != 'c' && word[i] != 'd' && word[i] != 'e' && word[i] != 'f' && word[i] != 'g' && word[i] != 'h' && word[i] != 'i' && word[i] != 'j' && word[i] != 'k' && word[i] != 'l' && word[i] != 'm' && word[i] != 'n' && word[i] != 'o' && word[i] != 'p' && word[i] != 'q' && word[i] != 'r' && word[i] != 's' && word[i] != 't' && word[i] != 'u' && word[i] != 'v' && word[i] != 'w' && word[i] != 'x' && word[i] != 'y' && word[i] != 'z')
			wrong_characters++;
	}
	if (wrong_characters >= 1)
		return false;
	else if (wrong_characters == 0)
		return true;
}
