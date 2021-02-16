//The Factor Game ---- This program plays between two players and take turns picking numbers until there were no numbers left. Meanwhile, if one player choose a number which its factors remained on the board, the other player gets the factors.
//Melinda Chen    Comp-Sci 30s
//2020/03/22

#include<iostream>
#include<windows.h>
#include<math.h>
#include"colours.h"
using namespace std;

//Function Prototype
void Print_Board(bool taken[101], int max_num);                                           //print the current board
void initialize(bool taken[101], int max_num);                                            //set the initial board
void pick_num(int turn, int& pick_team, int& other_team, bool taken[101], int max_num);   //plays a game that picks one number each time
bool more_numbers(bool taken[101], int max_num);                                          //check if there is any numbers left to play another round

//main
int main()
{
	int pos;                 //loop counter
	bool taken[101];         //the array of number taken
	int p1_score, p2_score;  //the score of player 1 and player 2
	int max_num;             //the maximum number to play with

	//the game begins
	cout << "--------------Welcome to the Fator Game!!!!!!------------------" << endl;
	cout << "Enter the maximum number for the game";
	cin >> max_num;
	//validate the maximum number
	while (max_num < 1 || max_num>100)
	{
      cout << "INVALID MAXIMUM NUMBER" << " enter the maximum number again";
	  cin >> max_num;
	}

	//Initialize all spots and scores
	p1_score = 0;
	p2_score = 0;
	initialize(taken, max_num);
	  
	while (more_numbers(taken, max_num))
	{
		pick_num(1, p1_score, p2_score,taken, max_num);
		if(more_numbers(taken, max_num))
			pick_num(2, p2_score, p1_score, taken, max_num);
	}

	//Give final results
	text_colour(f_green, b_black);
	if (p1_score > p2_score)
		cout << "Victory goes to team 1!!! wins " << p1_score << "to " << p2_score;
	else if(p2_score > p1_score)
		cout << "Victory goes to team 2!!! wins " << p2_score << "to " << p1_score;
}//main

//Print_Board--this function print out the board of numbers 
//taken[101]--this function tells if the number is taken away or not
//max_num--maximum number the player wants to play with
void Print_Board(bool taken[101], int max_num)
{
	int pos;   //loop counter
	int i;     //loop counter
	pos = 1;
    for(pos = 1;pos <= max_num;pos++)
	{
		if (!taken[pos])
		{
			text_colour(f_cyan, b_black);
			cout << " " << pos << "     ";
		}
		else if (taken[pos])
		{
			text_colour(f_dred, b_black);
			cout << "XXXX";
		}
	}
	cout << endl;
}

//initialize - This function initializes the board
//taken[]-set all spot as not taken
//max_num- the maximum number which the players want to play with
void initialize(bool taken[101], int max_num)
{
	int pos;
	for (pos = 0;pos <= max_num;pos++)
		taken[pos] = false;
}

//pick_num- This function asks the player to pick a number in the array
//turn- tells whether player 1 or player 2 is playing
//pick_team- this team switch between player 1 and player 2, represent the score of the player who picks the number in a round
//other_team-this team switch between player 1 and player 2, represent the score of the player who didn't picks the number in a round
//taken[101]-tells if the number is taken by the player or not
//max_num- the maximum number which the players want to play with
void pick_num(int turn, int& pick_team, int& other_team, bool taken[101], int max_num)
{
	int choice;    //the user's choice to pick number
	int points;    //the points which user get
	int i;         //loop counter


	//print board to show what's left
	Print_Board(taken, max_num);
	cout << endl;
	//Get user pick
	text_colour(f_yellow, b_black);
	cout << "Team #" << turn << " what number do you pick?";
	cin >> choice;
	//validate choice
	if (choice<1 || choice>max_num || taken[choice])
	{
		cout << "INCALID CHOICE-pick the number again" << endl;
		cin >> choice;
	}//while
	//set choice to taken
	taken[choice] = true;

	//user has chosen-see what point other team gets
	points = 0;
	text_colour(f_black, b_white);
	cout << "you picked " << choice << " So other team gets ";

	//loop counter
	for (i = 1;i <= choice / 2;i++)
	{
		//is it a factor and not taken
		if (choice % i == 0 && !taken[i])
		{
			//points for other team
			cout << i << " ";
			points += i;
			taken[i] = true;    //set to taken
		}//if
	}

	//check if the other team get the points or not
	if (points == 0)
	{
		text_colour(f_black, b_white);
		cout << "0 points" << endl;
	}
		
	else
	{
		text_colour(f_black, b_white);
		cout << "for a total of " << points << " points" << endl;
	}


	//update scores
	pick_team += choice;
	other_team += points;

	//print current score...
	if (turn == 1)
	{
		text_colour(f_magenta, b_black);
		cout << "Team #" << turn << " get the total number of " << pick_team << endl;
		text_colour(f_yellow, b_black);
		cout << "Team #" << turn + 1 << " get the total number of " << other_team << endl;
	}
	else if (turn == 2)
	{
		text_colour(f_yellow, b_black);
		cout << "Team #" << turn << " get the total number of " << pick_team << endl;
		text_colour(f_magenta, b_black);
		cout << "Team #" << turn - 1 << " get the total number of " << other_team << endl;
	}

}

//more_numbers-This function returns true if there are more numbers remaining in the game
//taken[101]- the maximum length of the board, tells if the numbers are all taken
//max_num- the maximum number which the players want to play with
bool more_numbers(bool taken[101], int max_num)
{
	int pos;   //loop counter

	//check if any numbers left
	for (pos = 1;pos < max_num;pos++)
		if (!taken[pos])
			return true;
	return false;
}
