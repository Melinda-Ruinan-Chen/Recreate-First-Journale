// BINGO FOR BONUS - This program simulate a number version of BINGO 
// Melinda Chen Comp Sci 40S
// 2021-04-22

#include<iostream>
#include<Windows.h>
#include"colours.h"
using namespace std;

enum contests {number,free_space};

struct square 
{
	contests type;
	bool picked;
	int value;
};

struct bingo_card
{
	char name[20];
	square matrix[5][5];
};

//Function Prototypes
void CreateCard(bingo_card& mycard);
void PrintCard(bingo_card& mycard);
bool Bingo(bingo_card& mycard);
void seek_random();              //seek random numbers


//This function seek random numbers
void seek_random()
{
	int i;                  // Loop counter

   // Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
}

void main()
{
	bingo_card card1;
	bingo_card card2;
	int rounds = 1;
	int called_number=0;
	bool Pick[76];
	bool winner1, winner2;       // check who is the winner
	int pos,rows,columns;

	//Initiate
	for (pos = 0;pos < 75;pos++)
		Pick[pos] = false;

	//create cards
	CreateCard(card1);
	CreateCard(card2);
	//print out the card once
	PrintCard(card1);
	PrintCard(card2);

	//This function seek random numbers
	seek_random();

	//Loop
	do 
	{

		cout << endl;
		//call a random number
		called_number = rand() % 75 + 1;
		cout << WHITE << B_BLACK << "Called number# " << rounds << " is ";
		while (Pick[called_number])
			called_number = rand() % 75 + 1;
		Pick[called_number] = true;


		//print out the called number and its belonging region
		if (called_number > 0 && called_number < 15)
			cout << "B-" << called_number << endl;
		if (called_number > 15 && called_number < 31)
			cout << "I-" << called_number << endl;
		if (called_number > 30 && called_number < 46)
			cout << "N-" << called_number << endl;
		if (called_number > 45 && called_number < 61)
			cout << "G-" << called_number << endl;
		if (called_number > 60 && called_number < 76)
			cout << "O-" << called_number << endl;

		//set the card as picked
		for (rows = 0;rows < 5;rows++)
		{
			for (columns = 0;columns < 5;columns++)
			{
				if (card1.matrix[rows][columns].value == called_number)
					card1.matrix[rows][columns].picked = true;
				if (card2.matrix[rows][columns].value == called_number)
					card2.matrix[rows][columns].picked = true;
			}//columns
		}//rows


		//print out the card
		PrintCard(card1);
		PrintCard(card2);

		//check the winner
		winner1 = Bingo(card1);
		winner2 = Bingo(card2);

		cout << WHITE << B_BLACK << "Press any key to continue...";
		_getwch();
		cout << endl;
		rounds++;
	} while (!winner1 && !winner2);

	if (winner1 && !winner2)
		cout << WHITE<<B_BLACK<<"After " << (rounds-1) << " numbers, " << card2.name << " did NOT have a BINGO, and " << card1.name << " DID have a BINGO!" << endl;

	if (!winner1 && winner2)
		cout << WHITE << B_BLACK << "After " << (rounds-1) << " numbers, " << card1.name << " did NOT have a BINGO, and " << card2.name << " DID have a BINGO!" << endl;

	if (winner1 && winner2)
		cout << WHITE << B_BLACK << "After " << (rounds-1) << " numbers, " << card1.name << " and " << card2.name << " BOTH have a BINGO!" << endl;

}//main


void CreateCard(bingo_card& mycard)
{
	int rows, columns;
	int i,num;
	bool taken[76];
	for (i = 0;i < 76;i++)
		taken[i] = false;


	cout << "Enter player name ";
	cin.getline(mycard.name,20);
	for (rows = 0;rows < 5;rows++)
	{
		for (columns = 0;columns < 5;columns++)
		{
			switch (columns)
			{
			case 0: num = rand() % 15 + 1;
				while (taken[num - 1])
					num = rand()% 15 + 1;
				taken[num - 1] = true;
				mycard.matrix[rows][columns].value = num;
				mycard.matrix[rows][columns].type = number;
				mycard.matrix[rows][columns].picked = false;
				break;
			case 1: num = rand() % 15 + 16;
				while (taken[num - 1])
					num = rand() % 15 + 16;
				taken[num - 1] = true;
				mycard.matrix[rows][columns].value = num;
				mycard.matrix[rows][columns].type = number;
				mycard.matrix[rows][columns].picked = false;
				break;
			case 2: num = rand() % 15 + 31;
				while (taken[num - 1])
					num = rand() % 15 + 31;
				taken[num - 1] = true;
				mycard.matrix[rows][columns].value = num;
				mycard.matrix[rows][columns].type = number;
				mycard.matrix[rows][columns].picked = false;
				break;
			case 3: num = rand() % 15 + 46;
				while (taken[num - 1])
					num = rand() % 15 + 46;
				taken[num - 1] = true;
				mycard.matrix[rows][columns].value = num;
				mycard.matrix[rows][columns].type = number;
				mycard.matrix[rows][columns].picked = false;
				break;
			case 4: num = rand() % 15 + 61;
				while (taken[num - 1])
					num = rand() % 15 + 61;
				taken[num - 1] = true;
				mycard.matrix[rows][columns].value = num;
				mycard.matrix[rows][columns].type = number;
				mycard.matrix[rows][columns].picked = false;
				break;

			}//switch
		}//columns
	}//rows

	//set the central square as free space
	mycard.matrix[2][2].type = free_space;
	mycard.matrix[2][2].picked = true;

}
void PrintCard(bingo_card& mycard)
{
	int pos;
	int rows, columns;

	cout << CYAN << B_BLACK <<mycard.name << "'s Card:" << endl;
	cout << BOLDYELLOW << B_RED << "B   " << "I   " << "N   " << "G   " << "O   " << endl;
	for (rows = 0;rows < 5;rows++)
	{
		for (columns = 0;columns < 5;columns++)
		{	

			if (mycard.matrix[rows][columns].type == number && !mycard.matrix[rows][columns].picked)
			{
				cout << BLUE<<B_BLACK << mycard.matrix[rows][columns].value<<"  ";
			}

			if (mycard.matrix[rows][columns].type == number && (mycard.matrix[rows][columns].picked))
				cout << BOLDGREEN << B_BLACK << mycard.matrix[rows][columns].value<<"  ";

			if(mycard.matrix[rows][columns].type== free_space)
				cout << BOLDYELLOW << B_RED << " FS ";
		}//columns
		cout<<endl;
	}//rows
}
bool Bingo(bingo_card& mycard)
{
	int rows, columns;
	//bool bingo;

	//bingo = false;

	//check two diagonals
	if (mycard.matrix[0][0].picked && mycard.matrix[1][1].picked && mycard.matrix[2][2].picked && mycard.matrix[3][3].picked && mycard.matrix[4][4].picked)
		return true;

	if (mycard.matrix[0][4].picked && mycard.matrix[1][3].picked && mycard.matrix[2][2].picked && mycard.matrix[3][1].picked && mycard.matrix[4][0].picked)
		return true;

	//check rows
	if (mycard.matrix[0][0].picked && mycard.matrix[0][1].picked && mycard.matrix[0][2].picked && mycard.matrix[0][3].picked && mycard.matrix[0][4].picked)
		return true;
	if (mycard.matrix[1][0].picked && mycard.matrix[1][1].picked && mycard.matrix[1][2].picked && mycard.matrix[1][3].picked && mycard.matrix[1][4].picked)
		return true;
	if (mycard.matrix[2][0].picked && mycard.matrix[2][1].picked && mycard.matrix[2][2].picked && mycard.matrix[2][3].picked && mycard.matrix[2][4].picked)
		return true;
	if (mycard.matrix[3][0].picked && mycard.matrix[3][1].picked && mycard.matrix[3][2].picked && mycard.matrix[3][3].picked && mycard.matrix[3][4].picked)
		return true;
	if (mycard.matrix[4][0].picked && mycard.matrix[4][1].picked && mycard.matrix[4][2].picked && mycard.matrix[4][3].picked && mycard.matrix[4][4].picked)
		return true;

	//check columns
	if (mycard.matrix[0][0].picked && mycard.matrix[1][0].picked && mycard.matrix[2][0].picked && mycard.matrix[3][0].picked && mycard.matrix[4][0].picked)
		return true;
	if (mycard.matrix[0][1].picked && mycard.matrix[1][1].picked && mycard.matrix[2][1].picked && mycard.matrix[3][1].picked && mycard.matrix[4][1].picked)
		return true;
	if (mycard.matrix[0][2].picked && mycard.matrix[1][2].picked && mycard.matrix[2][2].picked && mycard.matrix[3][2].picked && mycard.matrix[4][2].picked)
		return true;
	if (mycard.matrix[0][3].picked && mycard.matrix[1][3].picked && mycard.matrix[2][3].picked && mycard.matrix[3][3].picked && mycard.matrix[4][3].picked)
		return true;
	if (mycard.matrix[0][4].picked && mycard.matrix[1][4].picked && mycard.matrix[2][4].picked && mycard.matrix[3][4].picked && mycard.matrix[4][4].picked)
		return true;

	else
		return false;
}//bool bingo