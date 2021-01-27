// NOTE: If you are having trouble reading this code, that's because you forgot
//      to play Everybody's Favouite Font-Based Game Show....
//      Wheel.... Of....Font.....une!
// CENSORsensability - This program asks the user for a number of
//        phrases, and it goes through and cesnors each prhase using
//        as many phrases as the user want to check
//  Your Name Here - Comp Sci 30S - The S stands for Sensor!
//   April 24 (More than a month away from school now!)

#include <iostream>
#include <conio.h>
using namespace std;

// Constant for program
const int MAXSIZE = 80;                            // maximum size of a line

// Prototypes
void get_phrase(char[]);                            // reads in a phrase
void censor_phrase(char inphrase[], char censor[]);                  // censors a phrase


// Main Program
int main(void)
{
	char phrase[MAXSIZE];                    // phrase to be censored
	char censor[MAXSIZE];                    // Censor to check for
	int howmany;                                     // how many phrases to censor
	int count;                                           // Loop counter
	char more;                                         // More to censor?

	// Ask for how many
	cout << "How many phrases do you want to censor? ";
	cin >> howmany;

	// Clear the buffer
	cin.ignore();                 // Comment this line out and see what happens!
	// Loop though for each phrase
	for (count = 1; count <= howmany; count++)
	{
		// Ask for next phrase
		cout << "Enter phrase to be censored #" << count << "===>";
		get_phrase(phrase);
		// Loop through as many censors as wanted
		do
		{
			// Get next censor
			cout << "Enter next censor to check for ";
			get_phrase(censor);
			// Censor the phrase
			censor_phrase(phrase, censor);
			// More?
			cout << "Another censor phrase (Y/N)? ";
			more = toupper(_getwche());
			cout << endl;
		} while (more == 'Y');
		// Print censored phrase
		cout << "The final phrase after censoring is " << phrase << endl;
	} // for
	return 0;
} // Main

// get_phrase - This function reads in the phrase and changes it to upper case
// phrase - phrase to read in
void get_phrase(char phrase[MAXSIZE])
{
	int pos;                 // position for loop counter

	// Read in - note that prompt has already been done!
	cin.getline(phrase, MAXSIZE, '\n');

	// Convert to upper case so comparisons wil be the same
	for (pos = 0; pos < strlen(phrase); pos++)
		phrase[pos] = toupper(phrase[pos]);

} // get_phrase

// censor - This function *s out all occurences of censor in inphrase
// inphrase - The original phrase
// censor - The phrase to be *d out in inphrase
void censor_phrase(char inphrase[], char censor[])
{
	int pos;                       // overall position in inphrase
	int pos2;                    // character position in censor
	char teststring[MAXSIZE];              // creates a string of correct length 

	// Set pos to start
	pos = 0;

	// Loop until no room in original string
	while (pos + strlen(censor) <= strlen(inphrase))
	{
		// Check if first character matches
		if (inphrase[pos] == censor[0])
		{
			// if so, create test string to check
			for (pos2 = 0; pos2 < strlen(censor); pos2++)
				teststring[pos2] = inphrase[pos + pos2];
			// Add eos character for string comparison
			teststring[pos2] = '\0';
			// Check to see if phrase contains censor
			if (strcmp(teststring, censor) == 0)
			{
				// They match - * out phrase in that spot
				for (pos2 = 0; pos2 < strlen(censor); pos2++)
					inphrase[pos + pos2] = '*';
				// Update main loop
				pos += strlen(censor);
			} // if
		} // if
		// Update position
		pos++;
	} // while
} // censor_phrase
