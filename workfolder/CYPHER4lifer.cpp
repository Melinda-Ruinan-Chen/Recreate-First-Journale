// CIPHER4lifer - This program asks the user to type in a 27-character cipher
//           and it then allows them to use that cipher to translate phrases
// Your Name Here - Comp Sci 30S - the S stands for Sipher!
// April 24 (Which was supposed to be the Day of Silence - Shhhhh!)

#include <iostream>
#include <conio.h>
using namespace std;

// Constant
const int CIPHERSIZE = 28;                // Cipher has 26 characters + space + eos
const int MAXSIZE = 80;                   // Line can't be more than 80 characters

// Main (could have done with function, but this is fairly small!)
int main(void)
{
	char cipher[CIPHERSIZE];        // Contains cipher entered by user
	char alphabet[CIPHERSIZE] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ " };
	// All letters plus space at end
	char phrase[MAXSIZE];             // phrase to be translated
	int pos, pos2;                     // Position holders
	int count;                            // Loop counter
	int howmany;                    // how many to convert

	// Get the cipher - print letters above to help
	cout << "                                    ABCDEFGHIJKLMNOPQRSTUVWXYZ " <<
		endl << "Enter the 27-character cipher ====> ";
	cin.getline(cipher, CIPHERSIZE, '\n');
	// Note: We probably should validate, since iif the user enters a letter
	// not in the cipher, the program goes into an infinite loop. But to save time,
	// we'll assume only valid letters are entered (to validate, we'd probably
	//   go character by character, rather than using cin.getline)

	// Convert to upper case
	for (pos = 0; pos < strlen(cipher); pos++)
		cipher[pos] = toupper(cipher[pos]);

	// Ask for number of phrases
	cout << "How many words do you want to decode? ";
	cin >> howmany;
	// Again, need to clear buffer!»º³åÇø
	cin.ignore();
	// Loop through, decoding each word
	for (count = 1; count <= howmany; count++)
	{
		// Enter next word
		cout << "Enter code word #" << count << " ====> ";
		cin.getline(phrase, MAXSIZE, '\n');
		// Convert to uppercase
		for (pos = 0; pos < strlen(phrase); pos++)
			phrase[pos] = toupper(phrase[pos]);
		cout << phrase << " translates to ";
		// Convert each letter
		for (pos = 0; pos < strlen(phrase); pos++)
		{
			// Find position of letter in cipher
			pos2 = 0;
			while (cipher[pos2] != phrase[pos])
				pos2++;
			// Print next letter from alphabet
			cout << alphabet[pos2];
		} // for
		// Go to new line
		cout << endl;
	} // for

	return 0;
} // main