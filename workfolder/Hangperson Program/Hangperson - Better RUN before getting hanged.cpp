// HANGPERSON -GOTTA WIN before GETTING HANGED  --- This program plays a two-people version of HangPerson, the
// Melinda Chen - Computer Science 40S
// 2021-02-16

#include<iostream>
#include<windows.h>
#include<chrono>
#include<conio.h>
using namespace std;


//constant
const char letter[27] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

//Function Prototypes
void get_answer(char answer[10]);                                                         //this function gets one player's answer(correct answer)                      
void draw_picture(int num_wrong);                                                        //this function draws the hanged person if one player answer incorrectly
bool find_letter(char letter, char answer[10]);                                         //this function finds letter in the answer, if found, return true; else return false
void reveal_letters(char letter, char answer[10], bool visible[10],int& visnum);        //this function reveals the letter to visible if they are found
bool validate_letter(char letter, int guessed_number, char guessed_letter[26]);         // this function validates whether the letter is guessed
void initiate(bool visible[10], char guessed_letter[26]);                               //this function initiate the wrong number as zero and all spot as invisible initially


// initiate -- this function initiate the wrong number as zero and all spot as invisible initially
//visible[10] -- the initial visible spots are zero
void initiate(bool visible[10], char guessed_letter[26])
{
	int pos;                 //Loop counter

	for (pos = 0;pos < 10;pos++)
		visible[pos] = false;
	for (pos = 0;pos < 26;pos++)
	{
		guessed_letter[pos] = -1;
	}
}

//Main
void main()
{
	char answer[10];                                // answer array
	char letter;                                    // the letter guessed by the player
	int num_wrong,visnum;                            // number of wrong guessed and visible letters in the answer array
	bool letter_being_found, letter_validate;       // check if the letter is in answer, validate whether the letter is used
	char PlayAgain;                                 //ask whether the player want to play again
	bool visible[10];                                //check if the characters are visible or not 
	char guessed_letter[26];                        // an array putting all guessed letters in
	int guessed_number;                            // the number of guessed letters
	int pos;                                        //loop counter

	 //Game starts
		cout << "Welcome to the HangPerson World.....That's right, better RUN before getting hanged by Your life (which by the way, life can be interesting if we try) " << endl;
	do
	{
		//initiate
		initiate(visible,guessed_letter);
		num_wrong = 0;
		visnum = 0;
		guessed_number = 0;
		//Get Game initiator's word  
		get_answer(answer);
		cout << endl;
		do
		{
			cout << "What letter do you want to find? ";
			letter = toupper(_getwche());
				cout << endl;
			letter_validate = validate_letter(letter, guessed_number, guessed_letter);
			if (letter_validate)
			{
				letter_being_found = find_letter(letter, answer);
				if (letter_being_found)
				{
					cout <<"Letter "<<letter << " is in the word!" << endl;
					reveal_letters(letter, answer, visible, visnum);
				}
				else if (!letter_being_found)
				{
					cout << "There are no " << letter << "'s..." << endl;
					num_wrong++;
					draw_picture(num_wrong);
				}
				//update the guessed letters
				guessed_number++;
				for (pos = 0;pos < guessed_number;pos++)
					if (guessed_letter[pos] == -1)
						guessed_letter[pos] = letter;
			}
			else if (!letter_validate)
			{
				cout << "You already guessed " << letter << "!" << endl;
				draw_picture(num_wrong);
			}
			cout << endl;

			cout << "Guessed letters: ";
			for (pos = 0;pos < guessed_number; pos++)
				cout << guessed_letter[pos] << " ";
			cout << endl;

		} while (num_wrong < 6 && visnum < strlen(answer));

		if (num_wrong == 6 && visnum < strlen(answer))
		{
			cout << "OHHH!!! You DID NOT get it! The word was ";
			for (pos = 0;pos < strlen(answer);pos++)
				cout << answer[pos];
			cout << "! ";
		}
		else 
		{
			cout << "Congrats! You got it! The word was ";
			for (pos = 0;pos < strlen(answer);pos++)
				cout << answer[pos];
			cout << "! ";
		}
		cout << "Do you want to play again? (Y/N)" << endl;
		PlayAgain = toupper(_getwche());
		while (PlayAgain != 'Y' && PlayAgain != 'N')
		{
			cout << "INVALID! Do you want to play again? (Y/N)";
			PlayAgain = toupper(_getwche());
			cout << endl;
		}
	} while (PlayAgain != 'N');
}

//get_answer --this function gets one player's answer(correct answer)
//answer[10] -- this arrays contains the answer with a word (word length max of 10)
void get_answer(char answer[10])
{
	int pos;                   //loop counter

	//Initialize
	pos = 0;
	cout << "Enter the answer word: ";
	do
	{
		answer[pos] = toupper(_getwch());
		if (answer[pos] != '\r')
			cout << "*";
		pos++;
	} while (answer[pos - 1] != '\r');
	answer[pos - 1] = '\0';
}//get_answer

//validate_numer -- validate whether the letter is guessed
// guessed_number -- the number of guessed letters
// guessed_letters -- an array putting all guessed letters in
bool validate_letter(char letter, int guessed_number, char guessed_letter[26])
{
	int pos;       // loop counter
	for (pos = 0;pos < guessed_number;pos++)
	{
		if (letter == guessed_letter[pos])
		{
			return false;
		}
	}//for
	return true;
}

// find_letter -- this function finds letter in the answer, if found, return true; else return false
// letter- the letter that needs to be found
// answer[10] -- this arrays contains the answer with a word (word length max of 10)
bool find_letter(char letter, char answer[10])
{
	int i;          //loop counter

	for (i = 0;i < strlen(answer);)
	{
		if (letter == answer[i])
			return true;
		else
			i++;
	}//for
	return false;
}// bool find_letter

//reveal_letters -- this function reveals the letter to visible if they are found
//letter- the letter that needs to be found
// answer[10] -- this arrays contains the answer with a word (word length max of 10)
//visible[10] -- set all members of visible to false, then as each letter is found, change the visible value to true
// visnum -- update the # of visible letters in the answer
void reveal_letters(char letter, char answer[10], bool visible[10], int& visnum)
{
	int pos;              //loop counter
	char copy[10];       // a copy of the answer

	//loop
	for (pos = 0;pos < 10;pos++)
		copy[pos] = answer[pos];
	//Initiate
	visnum = 0;
	//loop
	cout << "The word is: ";
	for (pos = 0;pos < strlen(answer);pos++)
	{
		if (letter == copy[pos])
			visible[pos] = true;
		//see if the letter is visible
		if (visible[pos])
		{
			cout << answer[pos]<<" ";
			visnum++;
		}
		else if(!visible[pos])
			cout << "_ ";
	}//for
}//reveal_letter

// draw_picture -- this function draws the hanged person if one player answer incorrectly
// num_wrong -- calculate the number of wrong answers and draw the person's part out accordingly
void draw_picture(int num_wrong)
{
	char ASCII;
	int symbol;
	symbol = 92;

	ASCII = symbol;
	if (num_wrong >0)
	{
		cout << "           O                " << endl;
		if (num_wrong >1)
		{
			cout << "          "<<ASCII;
			if (num_wrong >2)
			{
				cout << "|";
				if (num_wrong >3)
				{
					cout << "/" << endl;
					if (num_wrong >4)
					{
						cout << "          / ";
						if (num_wrong >5)
						{
							cout <<ASCII<< endl;
						}//num_wrong=6
					}//if (5)
				}//num_wrong=4
			}//if (3)
		}//num_wrong=2
	}//if (1)
}