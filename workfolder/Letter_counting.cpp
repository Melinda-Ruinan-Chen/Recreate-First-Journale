//Letter_counting--- This program calculates the number of each alphabet in the lines given
// Melinda Chen  Comp. Sci 30S
// 2020-05-16

#include<iostream>
#include<Windows.h>
#include<chrono>
#include"colours.h"
#include<conio.h>
using namespace std;

// Constants
const int LINESIZE = 80;        // The line holds up to 80 characters
const int NUMFREQS = 27;       // 26 letters and the space character


// Function prototypes
void initialfreqs(int letterfreqs[]);                            // set all number frequencies to zero
void processlines(int letterfreqs[], char templ8[]);            // asks how many lines as well as the letter frequencies
void printout(int letterfreqs[], char templ8[]);                // Print out the result of letter frequencies

//Main
int main()
{
	int letterfreqs[NUMFREQS];
	char templ8[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ " };

	// Initialize the frequencies of letters
	initialfreqs(letterfreqs);

	// run through the lines
	processlines(letterfreqs,templ8);
	// Print out the results
	printout(letterfreqs,templ8);
	// Reset the colour
	text_colour(f_white, b_black);
}//main

// Initialfreqs--This function set all number frequencies to zero
// letterfreqs[]-- the position of 27 characters in an array
void initialfreqs(int letterfreqs[])
{
	int pos;    // Loop counter
	// Set all numbers of characters to zero
	for (pos = 0;pos < NUMFREQS;pos++)
		letterfreqs[pos] = 0;
}
// processline-- This function asks how many lines there will be, and then updates the letter frequencies for that many lines
// letterfreqs[]-- this arrays counting the number of each alphabet in the lines
// templ8[]-- 27 characters including 26 alphabet and space
void processlines(int letterfreqs[], char templ8[])
{
	char newline[LINESIZE];  // A line read in
	int count;        // number of lines read in
	int count2;       // Loop counter
	int a, b;         // Loop counter
	int pos;          // Position in the lines
	int pos2;         // Position in the template

	// Ask how many lines
	text_colour(f_green, b_black);
	cout << "How many lines are you going to read in?";
	cin >> count;
	while (count < 1)
	{
		text_colour(f_dred, b_black);
		cout << "Invalid choice -- re-enter the lines you going to read in";
		cin >> count;
	}

	// Clean buffer
	cin.ignore();

	// Read in line...
	for (count2 = 1;count2 <= count;count2++)
	{
		text_colour(f_dcyan, b_black);
		cout << "Enter line #" << count2 << " :";
		text_colour(f_magenta, b_black);
		cin.getline(newline, LINESIZE, '\n');

		// Convert to upper case...
		for (pos = 0;pos < LINESIZE;pos++)
			newline[pos] = toupper(newline[pos]);
		// Process each character of line
		for (pos = 0;pos < strlen(newline);pos++)
		{
			// Find character in the template
			pos2 = 0;
			while (templ8[pos2] != newline[pos])
				pos2++;
			// Update frequency
			letterfreqs[pos2]++;
		}//for
	}//for
}

// Printout--This function prints out the number of each alphabet being used
// letterfreqs[]-- the total number of each character accumulated in the lines
// templ8[]-- this array contains 27 characters, including 26 alphabets and a space
void printout(int letterfreqs[], char templ8[])
{
	int pos;  // Loop counter: position in the lines
	int pos2; // Loop counter: position in the letter frequency

	// Loop through all letters
	text_colour(f_cyan, b_black);
	cout << "The following letter frequencies were present in these lines:" << endl;
	// Loop
	for (pos = 0;pos < strlen(templ8);pos++)
	{
		text_colour(f_dmagenta, b_white);
		cout << templ8[pos];
		// Print stars
		text_colour(f_yellow, b_black);
		for (pos2 = 0;pos2 < letterfreqs[pos];pos2++)
			cout << "*";
		cout << "        ";
		cout << "( " << pos2 << " )" << endl;
		Sleep(100);
	}
}