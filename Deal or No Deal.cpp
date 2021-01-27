//Deal or No Deal--This program simulates the actual gambling game, which a player chooses one briefcase from a selection of 10. Each briefcase contains a value from $1 -$1000000, the player could choose 'deal' to quit the game or 'no deal' to continue the game.
//Melinda Chen Comp. Sci-30s
//2020-04-02

#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<chrono>
#include"colours.h"
using namespace std;

//Function Prototypes
void initialize(int cases[10], bool taken[10]);     //put money into cases at start
int expectedvalue(int cases[10], bool taken[10], int chosen);     //return the expected value of remaining cases (including the one which the user chose)
void seed_random(); //seed random numbers

 //seed random numbers
void seed_random()
{
	int i;                  // Loop counter

// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
}

//Main
int main()
{
	int cases[10];     //ten different cases
	bool taken[10];    //tells if the case is taken or not
	int choice1;        //the choice which player pick on
	int choice2;        //the choice which happens in a round
	int i;             //loop counter
	int offer;         //the amount of money banker offers
	char dealnodeal;   //ask the player to deal or no deal

	//Initialize values
	initialize(cases, taken);
	
	text_colour(f_cyan, b_black);
	cout << "Welcome to Dakota Deal or No Deal.What case do you want(1 - 10) ?"<<endl;
	cin >> choice1;
	while (choice1 < 1 || choice1 >10)
	{
		text_colour(f_red,b_black);
		cout << "That＊s not between 1 and 10! What case do you want (1-10)?";
		cin >> choice1;
	}

	//Play round 1
	text_colour(f_magenta, b_black);
	cout << "Okay-now you need to choose 3 more cases, ";
	for (i = 0;i < 3;i++)
	{
		text_colour(f_green, b_black);
		cout << "what cases do you want ? " << endl;
		cin >> choice2;
		//validate choice
		while (choice2 < 1 || choice2>10 || !taken[choice2 - 1]||choice2==choice1)
		{
			text_colour(f_red, b_black);
			cout << "That case has already been chosen or isn＊t between 1 and 10 每 what case do you want?" << endl;
			cin >> choice2;
		}

     	cout << "Case" << choice2 << "contains $" << cases[choice2 - 1] << endl;
		// Update taken status
		taken[choice2 - 1] = false;
	}
	//Deal or no deal?
	offer = expectedvalue(cases, taken, choice1);
	text_colour(f_blue, b_black);
	cout << "The banker is offering you $" << offer << " - Deal or No deal(D/N)?" << endl;
	dealnodeal = toupper(_getche());
	//get and validate choice
	while (dealnodeal != 'D' && dealnodeal != 'N')
	{
		text_colour(f_red, b_black);
		cout << "INVALID CHOICE!!! Enter 'D' or 'N'";
		dealnodeal = toupper(_getche());
	}

	if (dealnodeal == 'D')
	{
		cout << "You get $" << offer << " , and your case (case " << choice1 << ")" << " contained....";
		Sleep(1000);
		cout << "$" << cases[choice1 - 1] << "You leave with $" << offer << "!" << endl;
		cout << "Here's what $$$ was in each case:" << endl;
		for (i = 0;i < 10;i++)
		{
			cout << "Case " << i + 1 << " had $ " << cases[i];
			cout << endl;
		}
	}
	else
	{
		//Play round 2
		text_colour(f_magenta, b_black);
		cout << "Okay-now you need to choose 3 more cases, ";
		for (i = 0;i < 3;i++)
		{
			cout << "what cases do you want ? " << endl;
			cin >> choice2;
			//validate choice
			while (choice2 < 1 || choice2>10 || !taken[choice2 - 1]||choice2==choice1)
			{
				text_colour(f_red, b_black);
				cout << "That case has already been chosen or isn＊t between 1 and 10 每 what case do you want?" << endl;
				cin >> choice2;
			}
			cout << "Case" << choice2 << "contains $" << cases[choice2 - 1] << endl;
			// Update taken status
			taken[choice2 - 1] = false;
		}
		//Deal or no deal?
		offer = expectedvalue(cases, taken, choice1);
		text_colour(f_blue, b_black);
		cout << "The banker is offering you $" << offer << " - Deal or No deal(D/N)?" << endl;
		dealnodeal = toupper(_getche());

		while (dealnodeal != 'D' && dealnodeal != 'N')
		{
			cout << "INVALID CHOICE!!! Enter 'D' or 'N'";
			dealnodeal = toupper(_getche());
		}//while
		if (dealnodeal == 'D')
		{
			cout << "You get $" << offer << " , and your case (case " << choice1 << ")" << " contained....";
			Sleep(1000);
			cout << "$" << cases[choice1 - 1] << "You leave with $" << offer << "!" << endl;
			cout << "Here's what $$$ was in each case:" << endl;
			for (i = 0;i < 10;i++)
			{
				cout << "Case " << i + 1 << " had $ " << cases[i];
				cout << endl;
			}
		}//if
		else
		{
			//Play round 3
			text_colour(f_yellow, b_black);
			cout << "Okay-now you need to choose 3 more cases, ";
			for (i = 0;i < 3;i++)
			{
				cout << "what cases do you want ? " << endl;
				cin >> choice2;
				//validate choice
				while (choice2 < 1 || choice2>10 || !taken[choice2 - 1]||choice2==choice1)
				{
					text_colour(f_red, b_black);
					cout << "That case has already been chosen or isn＊t between 1 and 10 每 what case do you want?" << endl;
					cin >> choice2;
				}
				cout << "Case" << choice2 << "contains $" << cases[choice2 - 1] << endl;
				// Update taken status
				taken[choice2 - 1] = false;
			}//for
			text_colour(f_blue, b_black);
			cout << "That means your case (case" << choice1 << ") contains $" << cases[choice1 - 1] << "!" << "You leave with $" << cases[choice1 - 1] << "!";
		}//else-round 3
	}
}

//initialize-This function set up the initial cases value
//case[10]- 10 different values separate in 10 cases
//taken[10]-tells if the case has been taken or not
void initialize(int cases[10], bool taken[10])
{
	int spot;   //loop counter

	//seed random numbers
	seed_random();

	//set all cases to not taken
	for (spot = 0;spot < 10;spot++)
		taken[spot] = false;
	//Initialize all case values
	//Assign $1000000 case
	spot = rand() % 10;
	cases[spot] = 1000000;
	taken[spot] = true;
	//Assign $500000 case
	spot = rand() % 10;
	//check to see if already taken
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 500000;
	taken[spot] = true;
	//Assign $100000 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 100000;
	taken[spot] = true;
	//Assign $10000 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 10000;
	taken[spot] = true;
	//Assign $1000 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 1000;
	taken[spot] = true;
	//Assign $100 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 100;
	taken[spot] = true;
	//Assign $50 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 50;
	taken[spot] = true;
	//Assign $10 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 10;
	taken[spot] = true;
	//Assign $5 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 5;
	taken[spot] = true;
	//Assign $1 case
	spot = rand() % 10;
	while (taken[spot])
		spot = rand() % 10;
	cases[spot] = 1;
	taken[spot] = true;

}//initialize

//The expected_value function is the one that tells what the banker will offer 每 basically, it＊s the average value of all the cases that haven＊t yet been seen in the game!
//case[10]- 10 different values separate in 10 cases
//taken[10]-tells if the case has been taken or not
//chosen-the case which the player chose randomly
int expectedvalue(int cases[10], bool taken[10], int chosen)
{
	int sum;     //the sum of all remained values
	int spot;    //loop counter
	int howmany; //the number of cases remained
	int average; //the average of remained values
	//Add up all cases that aren't yet taken
	sum = 0;
	howmany = 0;
	for (spot = 0;spot < 10;spot++)
	{
		if (taken[spot])
		{
			howmany++;
			sum += cases[spot];
		}//if
	}//for
	//Also add in value of case user chooses
	sum += cases[chosen - 1];
	//return average
	average = sum / howmany;
	return average;
}//expected_value
