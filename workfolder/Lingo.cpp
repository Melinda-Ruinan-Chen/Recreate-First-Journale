// LingoSTRINGo - This program uses strings to implement a version
//    of Lingo. In this version, one player will choose a word, and then the other 
//    player has up to 6 tries to guess the word.
// Your Name Here - Comp Sci 30S - The S stands for Solingo (of course!) 
// April 24 (How much coding can a person do in one day?)

#include <iostream>
#include <Windows.h>
#include "colours.h"
#include <conio.h>
using namespace std;

// Constant
const int WORDLENGTH = 5;     // Words are 5 letters

// Prototypes
void get_solution(char answer[WORDLENGTH + 1]);   // gets correct answer
bool play_round(char answer[WORDLENGTH + 1],
	bool results[WORDLENGTH]);    // plays next round
// NOTE: WORDLENGTH+1 to account for eos character for strings

// Main
int main(void)
{
	int round;                  // Round number
	char answer[WORDLENGTH + 1];                       // Correct answer
	bool results[WORDLENGTH];                       // Tells if each spot known yet              
	bool win;                 // tells if user won or not
	int pos;                    // Loop counter
	// Get Correct Answer
	get_solution(answer);
	// Show Legend for colours
	text_colour(f_cyan, b_black);
	cout << "RESULTS LEGEND: ";
	text_colour(f_green, b_black);
	cout << "CORRECT ";
	text_colour(f_yellow, b_black);
	cout << "WRONG PLACE ";
	text_colour(f_red, b_black);
	cout << "WRONG " << endl;
	// Set all spot excpet first one to not known yet
	results[0] = true;
	for (pos = 1; pos < WORDLENGTH; pos++)
		results[pos] = false;
	// Loop until user gets it or no more rounds
	round = 1;
	do
	{
		// Title next round
		text_colour(f_cyan, b_black);
		cout << "ROUND # " << round << " ";

		// Play round
		win = play_round(answer, results);

		// Update round #
		round++;

	} while (!win && round <= 6);

	// Print final results
	if (win)
	{
		// They won- tell how many points
		text_colour(f_green, b_black);
		cout << "YOU GOT IT IN " << round - 1 << " ROUNDS, SO YOU GET ";
		switch (round)
		{
		case 2: cout << "400 POINTS - AMAZING!!!! " << endl; break;
		case 3: cout << "250 POINTS - VERY GOOD!!!! " << endl; break;
		case 4: cout << "200 POINTS - GOOD!!!! " << endl; break;
		case 5: cout << "150 POINTS - PRETTY GOOD!!!! " << endl; break;
		case 6: cout << "100 POINTS - FAIR!!!! " << endl; break;
		case 7: cout << "50 POINTS - AT THE BUZZER!!!! " << endl; break;
		} // switch
	} // if
	else
	{ // They lost tell them the right answer
		text_colour(f_red, b_black);
		cout << "Sorry - you didn't get it - the correct answer was " <<
			answer << endl;
	} // else

	// reset colours before exit
	text_colour(f_gray, b_black);
	return 0;
} // Main

// get_solution - This function asks player 1 to enter the correct answer
//     They need to enter it twice to validate their choice
// answer - The correct answer
void get_solution(char answer[WORDLENGTH + 1])
{
	char check[WORDLENGTH + 1];           // check to see if they match
	int pos;                                                 // loop counter for uppercase

	// Loop until they match
	do
	{  // Get word first time
		text_colour(f_cyan, b_black);
		cout << "PLAYER 1, Enter a 5-letter word ";
		text_colour(f_cyan, b_cyan);         // change so it can't be seen
		// Get word second time
		cin.getline(answer, WORDLENGTH + 1, '\n');
		text_colour(f_cyan, b_black);
		cout << "PLAYER 1, Re-enter the 5-letter word to confirm";
		text_colour(f_cyan, b_cyan);         // change so it can't be seen
		cin.getline(check, WORDLENGTH + 1, '\n');
		// Convert both to uppercase for matching
		for (pos = 0; pos < WORDLENGTH; pos++)
		{
			answer[pos] = toupper(answer[pos]);
			check[pos] = toupper(check[pos]);
		}  // for
		// Check if they don't match
		if (strcmp(answer, check) != 0)
		{
			text_colour(f_red, b_black);
			cout << "THEY DIDN'T MATCH _ RE-ENTER!!" << endl;
		} // if
	} while (strcmp(answer, check) != 0);
} // get_solution

// play_round - This function plays one round of the game
//       It returns true if the player gets it and false if not
// answer - the correct answer
// results - Tells if each spot has been found yet
bool play_round(char answer[WORDLENGTH + 1], bool results[WORDLENGTH])
{
	int pos, pos2;                 // Position holders
	char guess[WORDLENGTH];                // User's guess 
	char copy[WORDLENGTH];                // Make copy to * out chars
	int display[WORDLENGTH];              // What to display in each spot (0=Exact, 1= Wrong Place, 2=Wrong)
	int num_exact;                                        // How many are exact                                    
	// Give clue based on results
	for (pos = 0; pos < WORDLENGTH; pos++)
	{
		if (results[pos])
		{ // Found already - show
			text_colour(f_green, b_black);
			cout << answer[pos] << " ";
		} // if
		else
		{ // not yet found - print _
			text_colour(f_yellow, b_black);
			cout << "_ ";
		} // else
	} // for

	// Ask for their guess
	text_colour(f_cyan, b_black);
	cout << " GUESS? ====> ";

	// Read in their guess, one character at a time
	text_colour(f_black, b_cyan);
	for (pos = 0; pos < WORDLENGTH; pos++)
		guess[pos] = toupper(_getwche());

	// Check to see how close their guess is
	// Make copy of answer to mark up
	for (pos = 0; pos < WORDLENGTH; pos++)
		copy[pos] = answer[pos];
	// Set all display spots to wrong (2)
	for (pos = 0; pos < WORDLENGTH; pos++)
		display[pos] = 2;
	// Check for exact correct
	num_exact = 0;
	for (pos = 0; pos < WORDLENGTH; pos++)
	{
		if (guess[pos] == copy[pos])
		{
			// Exact match
			num_exact++;
			results[pos] = true;
			display[pos] = 0;
			copy[pos] = '*';                // * out so it can't be re-used
		} // if
	} // for
	// check for wrong place
	for (pos = 0; pos < WORDLENGTH; pos++)
	{
		if (display[pos] != 0)           // Haven't matched this one yet
		{
			for (pos2 = 0; pos2 < WORDLENGTH; pos2++)
			{
				if (pos != pos2 && guess[pos] == copy[pos2])
				{
					// Found one in wrong place
					display[pos] = 1;
					copy[pos2] = '*';    // * out so it can't be reused
				} // if
			} // for pos2
		} // if
	} // for pos

	// Print result of guess using colours
	text_colour(f_cyan, b_black);
	cout << "  ";
	// Loop through all spots
	for (pos = 0; pos < WORDLENGTH; pos++)
	{
		// Choose colour based on display result
		switch (display[pos])
		{
		case 0: text_colour(f_green, b_black); break;
		case 1: text_colour(f_yellow, b_black); break;
		case 2: text_colour(f_red, b_black); break;
		} // switch
		// Print guess letter
		cout << guess[pos];
	} // for
	// End line
	cout << endl;
	// Check if use won
	if (num_exact == WORDLENGTH)
		return true;
	else
		return false;
} // play_round