// Too High / Too Low --- This program generates a three-alphabetic code and requires user to bet; the program will tell whether the Alphabet is higher or lower than the code until the user gets it right
// By the way, neither is good (DON'T GET HIGH, ALSO DON'T GET LOW)
// Melinda Chen -- Comp. Sci 30S
// 2020-05-12

#include<iostream>
#include<Windows.h>
#include<chrono>
#include"colours.h"
#include<conio.h>
using namespace std;

//Constants
const int CODESIZE = 3;

// Function Prototypes
void seek_random();         // this function seek random numbers

//Main
int main()
{
	int pos;   // Position in the word
	int times; // times of tries
	char correct[4];  // the correct code
	char guess[4];    //the guess from the user
	char playagain;
	char letters[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	// Use function
	seek_random();

	//Initialize
	times = 0;
	do
	{
		text_colour(f_green, b_black);
		cout << "WELCOME TO GUESSING HIGH OR LOW, WHICH IS---HELLO----GAME!!!" << endl;
		for (pos = 0;pos <= CODESIZE;pos++)
			correct[pos] = letters[rand() % strlen(letters)];
		// Add zeros character
		correct[pos-1] = '\0';

		do
		{
			// Get user guess...
			text_colour(f_white, b_black);
			cout << "Guess the 3-letter combo: ";
			for (pos = 0;pos < CODESIZE;pos++)
				guess[pos] = toupper(_getwch());
			//Add zeros character
			guess[pos] = '\0';

			//Print out the results
			text_colour(f_dcyan, b_black);
			cout << guess << " ";
			// Validate
			// Check if too high
			if (strncmp(guess, correct, CODESIZE) > 0)
			{
				text_colour(f_dred, b_black);
				cout << " - TOO HIGH" << endl;
			}
			else if (strncmp(guess, correct, CODESIZE) < 0)
			{
				text_colour(f_dblue, b_black);
				cout << " - TOO LOW" << endl;
			}
			times++;
		} while (strncmp(guess, correct, CODESIZE) != 0);

		cout << endl;
		cout << "YOU GOT IT IN " << times << " TRIES - YOUR RATING IS ... ";
		//Get ratings
		if (times <= 5)
		{
			text_colour(f_red, b_black);
			cout << " A++; YOU ARE A MIRACLE!!!";
		}

		else if (times > 5 && times <= 10)
		{
			text_colour(f_cyan, b_black);
			cout << " A+; YOU ARE A GENIUS!!!";
		}
			
		else if (times > 10 || times <= 15)
		{
			text_colour(f_blue, b_black);
			cout << " A; CONGRATULATIONS!!!";
		}

		else if (times > 15 && times < 20)
		{
			text_colour(f_magenta, b_black);
			cout << " B; BETTER LUCK NEXT TIME!!!";
		}

		else if (times > 20 && times <= 25)
		{
			text_colour(f_dgray, b_black);
			cout << " C; BETTER LUCK NEXT TIME!!!";
		}

		else if (times > 25)
		{
			text_colour(f_white, b_black);
			cout << " Ohhhh, what a pity!!!";
		}
		// Ask if the player wants to play again...
		cout << endl;
		text_colour(f_white, b_black);
		cout << "Do you want to Play Again? (Y/N)";
		playagain = toupper(_getwche());
		if (playagain == 'Y')
			times = 0;
		while (playagain != 'Y' && playagain != 'N')
		{
			cout << endl;
			text_colour(f_dred, b_black);
			cout << "Invalid choice!!! Do you want to play again? (Y/N) ";
			playagain = toupper(_getwche());
		}
		cout << endl;
	} while (playagain == 'Y');

	// Reset colour
	text_colour(f_white, b_black);
}

// this function seek random numbers
void seek_random()
{
	int i;                  // Loop counter

   // Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();

}

