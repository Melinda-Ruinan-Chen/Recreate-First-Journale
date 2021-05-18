// Tic-Tac-Toe -- This program simulates a tic-tac-toe game in which a player play against the computer, and the one gets three consecutive in a row/column/diagonal wins
// Comp Sci 40S Melinda Chen
// 2021-03-22 


#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;



//Enumerated Types
enum square { blank, player, computer };     //player's turn OR computer's turn OR blank (meaing no winner found or a tie)

// square winner -- checks the board and sends back any winner (or "blank" if no winner has been found)
square winner(square board[3][3])
{
	//check top row
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != blank)
		return board[0][1];

	//check second row
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != blank)
		return board[1][0];

	//check bottom row
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != blank)
		return board[2][0];

	//check first column
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != blank)
		return board[0][0];

	//check second column
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != blank)
		return board[0][1];

	//check third column
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != blank)
		return board[1][2];

	//Check the diagonal start from board[0][0]
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != blank)
		return board[1][1];

	//Check the diagonal start from board[0][2]
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != blank)
		return board[0][2];

	else
		return blank;

}// square winner


//Function Prototypes
void initialize(square board[3][3]);             //set the whole board as blank
void print_board(square board[3][3]);           //prints the current state of the board
void seed_random();                             // seed the random number
void play_end(square board[3][3],int currentplayer, int taken);                                // play different rounds
int coin_toss();                              //see who gets to play first


//seed_random - This function seeds the random number generator using the timer
void seed_random()
{
	int i;                  // Loop counter

// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
}

void main()
{
	square board[3][3];                    // board
	int turn,currentplayer;    // see who plays first
	int pos, pos1;                   // loop counte
	int taken;                       //see if all grids are taken

	//set the initial points as zero
	initialize(board);
	taken = 0;
	//Seed random
	seed_random();

	// print out the board
	print_board(board);

	//see who get the turn
	currentplayer = coin_toss();

	if (currentplayer == 1)
		cout << "You gets to play first! ";
	else
		cout << "The computer gets to pick the first grid! ";
	//Let's get the the game started!
	do
	{
		play_end(board, currentplayer,taken);
		print_board(board);
		winner(board);

	} while (winner(board) == blank && taken<9);

	if (winner(board) != blank)
	{
		if (winner(board) == 1)
			cout << "The winner is the player!" << endl;
		else
			cout << "The computer wins!" << endl;
	}
	else if (winner(board) == blank)
	{
		cout << "It is a tie" << endl;
	}
}//main

//initialize --- This function sets the whole board as blank
// square board[3][3] -- the Tic-Tac-Toe board 
void initialize(square board[3][3])
{
	int a, b;
	for (a = 0;a < 3;a++)
		for (b = 0;b < 3;b++)
			board[a][b] = blank;

}//initialize


//print_board -- This function prints out the board as the game goes on
// square board[3][3] -- the Tic-Tac-Toe board 
void print_board(square board[3][3])
{
	int a, b;         //loop counter

	cout << "Current board: " << endl;
	for (a = 0;a < 3;a++)
	{
		cout << "-----------------" << endl;
		for (b = 0;b < 3;b++)
		{
			if (board[a][b] == blank)
				cout << "  "<<(3*a+b+1)<<"  |";
			else if (board[a][b] == computer)
				cout << "  O  |";
			else if (board[a][b] == player)
				cout << "  X  |";
		}//for
		cout << endl;
	}//for
	cout << "-----------------" << endl;

}//print_board



//coin_toss - This function toss a coin to see if the player becomes the current player
int coin_toss()
{
	bool currentplayer;              //weather the fist team has the hammer or not
	int turn;                       // see if the player gets the first hand

	//Seed random
	seed_random();

	//see if the player gets the first hand
	turn = rand() % 2 + 1 ;

	if (turn == 1)
	{
		currentplayer = player;
		return currentplayer;
	}//if
	else
	{
		currentplayer = computer;
		return currentplayer;
	}//else

	return currentplayer;
}//coin_toss

 // play_end: this function allows to play one two_round turn
// square board[3][3] -- the Tic-Tac-Toe board 
// currentplayer-- see whether the 
void play_end(square board[3][3], int currentplayer, int taken)
{
	int number;                  // enter the number of grid the player want to take
	int computernumber;          //let computer pick a number
	int pos;                     // Loop counter


	if (currentplayer == 1)
	{
		//ask the player which grid they want to take
		cout << "Which grid do you want to take? (enter 1-9)";
		cin >> number;
		while (number < 1 || number>9 || board[(number - 1) / 3][(number - 1) % 3] == player || board[(number - 1) / 3][(number - 1) % 3] == computer)
		{
			cout << "INVALID CHOICE!! WHICH GRID DO YOU WANT TO TAKE? (enter 1-9) ";
			cin >> number;
		}
		board[(number - 1) / 3][(number - 1) % 3] = player;

		board[(number - 1) / 3][(number - 1) % 3] = player;
		print_board(board);
		taken++;
		if (winner(board) == blank)
		{
			//the computer gets a random grid
			computernumber = rand() % 9 + 1;
			while (board[(computernumber - 1) / 3][(computernumber - 1) % 3] == player || board[(computernumber - 1) / 3][(computernumber - 1) % 3] == computer || computernumber < 1 || computernumber>9)
			{
				computernumber = rand() % 9 + 1;
			}
			cout << "The computer takes grid# " << computernumber << endl;
			board[(computernumber - 1) / 3][(computernumber - 1) % 3] = computer;
			taken++;
		}
	}//if
	else
	{
		//the computer gets a random grid
		computernumber = rand() % 9 + 1;
		while (board[(computernumber - 1) / 3][(computernumber - 1) % 3] == player || board[(computernumber - 1) / 3][(computernumber - 1) % 3] == computer || computernumber < 1 || computernumber>9)
		{
			computernumber = rand() % 9 + 1;
		}
		cout << "The computer takes grid# " << computernumber << endl;
		board[(computernumber - 1) / 3][(computernumber - 1) % 3] = computer;
		print_board(board);
		taken++;
		if (winner(board) == blank)
		{
			//ask the player which grid they want to take
			cout << "Which grid do you want to take? (enter 1-9)";
			cin >> number;
			while (number < 1 || number>9 || board[(number - 1) / 3][(number - 1) % 3] == player || board[(number - 1) / 3][(number - 1) % 3] == computer)
			{
				cout << "INVALID CHOICE!! WHICH GRID DO YOU WANT TO TAKE? (enter 1-9) ";
				cin >> number;
			}
			board[(number - 1) / 3][(number - 1) % 3] = player;

			board[(number - 1) / 3][(number - 1) % 3] = player;
			taken++;
		}
	}//else

}//play_end


