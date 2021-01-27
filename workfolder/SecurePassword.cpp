//SecurePassword--This program asks the user to enter the length and the password twice in order to generate a real SECURE PASSWORD
// Melinda Chen  Comp Sci. 30S  
//2020-05-12

#include<iostream>
#include<conio.h>
#include<chrono>
#include<cstring>
#include<Windows.h>
using namespace std;

//Function Prototypes
void seek_random();  //seek the random numbers and characters
void match_or_not(char password[]);  //check if they match the password


//Constant
const int MAXSIZE = 64;      //The maximum word length is 64

//Main
int main()
{
	char possible_characters[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789" };   // All possible password characters
	int pos;     //position in the password
	int times;    // ask player to enter two randomly generated password twice
	int length;  //length of the password
	char password[MAXSIZE+1];  //the password which randomly generated

	//Use the randomdomdom.. function
	seek_random();

	// Loop through it twice
	for (times = 1;times <= 2;times++)
	{
		//Ask the user to enter the length of the password
		cout << "What length of password do you want (max = 64)? ";
		cin >> length;
		while (length < 1 || length>64)
		{
			cout << "Invalid length - choose between 1 and 64: ";
			cin >> length;
		}

		//Pick random character
		for (pos = 0;pos < length;pos++)
			password[pos] = possible_characters[rand() % strlen(possible_characters)];		
			 
		// Add zero character at the end of the string
		password[pos] = '\0';

		//Print out the new password
		cout << "Your new password is  " << password << endl;
		//check if the password match 
		match_or_not(password);
		cout << endl;
	}
}//Main

//seeek_random--this function seek the random numbers and characters
void seek_random()
{
	int i;                  // Loop counter

// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
}

//match_or_not--this function asks the player to enter the correct password twice, and validate their choice
//password[]--this array contains the password which generated randomly by the computer
void match_or_not(char password[])
{
	int pos;                 //Loop counter
	char check[MAXSIZE+1];     //check if they match the password
	char check2[MAXSIZE+1];    //double check the password

	//clean the buffer
	cin.ignore();

	//Ask the user to type in new password
	cout << "Type your new password ";
	do
	{
		pos = 0;
		do
		{
			check[pos] = _getwch();
			if(check[pos]!='\r')
				cout << "*";   //print a "*"
			pos++;
		} while (check[pos - 1] != '\r');
		// Add zeros character
		check[pos - 1] = '\0';
		cout << endl;
		// Validate
		if (strcmp(password, check) != 0)
			cout << "Passwords don't match - type your new password ";
	} while (strcmp(password, check) != 0);
	
	// Check the password again
	// Ask the user to enter the new passowrd twice
	cout << "Confirm your new password by re-typing it ";
	do
	{
		pos = 0;
		do
		{
			check2[pos] = _getwch();
			if(check2[pos]!='\r')
				cout << "*";   //print a "*"
			pos++;
		} while (check2[pos - 1] != '\r');
		// Add zeros
		check2[pos - 1] = '\0';
		cout << endl;
		//Validate
		if (strcmp(password, check2) != 0)
			cout << "Passwords don't match - re-typing your new password ";
	} while (strcmp(password, check2) != 0);

	//Reset the password
	cout << "Password reset!" << endl;
}