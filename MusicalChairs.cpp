//MusicalChairs--This program simulates the musical chairs, which up to 10 players competiting for chairs and tells who is the winner
//Melinda Chen -- Comp. Sci 30S
//2020-03-24 --- one day before my birthday

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<chrono>
#include<cctype>
#include<time.h>
using namespace std;

//Function prototypes
void Play_Round(int num_players, int& money);          //This function simulate a full round of musical chairs
void seed_random();                                    //this function seeds random number

//main
int main(void)
{    
	int num_players;      //the number of players set in an array or number of players who participate
	int money;            //the remained money
	char choice;            //whether the player will play the game again
	int i;                //loop counter

	//Initialize
	money = 888;
	num_players = 10;



	do
	{
		cout << "---------" << "Welcome to Digital Musical Chairs!!!" << "----------" << endl;
		cout << "How many players are playing (from 2-10)?";
		cin >> num_players;
		if ((num_players < 2) || (num_players > 10))
		{
			cout << "Invalid CHOICE! ";
			cout << "How many players are playing (from 2-10)?";
			cin >> num_players;
		}

		for (i = 0;i < 9999999;)
		{
			Play_Round(num_players, money);
			cout << "Do you want to play again (Y/N)?";
			choice = toupper(_getche());
			if (choice != 'Y' && choice != 'N')
			{
				cout << "INVALID CHOICE " << "Enter Y/N again";
				choice = toupper(_getche());
			}
			if (choice == 'Y')
			{
				i++;
				cout << endl;
			}
			else if (choice == 'N')
				i=9999999;
		}
		while (money <= 0)
		{
			cout << "You're broke!! Better Luck Next Time!!" << endl;
		}
	} while ( money>0 && choice=='Y');

}//main



 //this function seeds random number
void seed_random()
{
	int i;                  // Loop counter

// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
}

//Play_Round--this function simulate how to play a round of musical chairs
//num_players-the number of players participate in the game
//money--the remained money which user could bet
void Play_Round(int num_players, int& money)
{
	bool alive[10];   //the array of number of living players
	int pos;          //loop counter
	int Bet_winner;   //the winner whom is on bet
	int alive_winner;       //the players who luckily survived
	int round;        //loop counter  
	bool include[10];  //the array which includes all the players alive
	int spot;          //loop counter
	int seated;        //loop counter
	int change_money;   //the amount of money wins or loss
	int inputmoney;     //the money which player bets on

	//function prototype
	seed_random();

	//set all players to alive
	for (pos = 0;pos < num_players;pos++)
		alive[pos] = true;

	//Get and validate player's bet and who they pick to win
	cout << "You have $" << money << " " << "- how much do tou want to bet ($1 -$" << money << ")?";
	cin >> inputmoney;
	//validate the amount of money
	if (inputmoney > money)
	{
		cout << "INVALID BET " << "- how much do tou want to bet ($1 -$" << money << ")?";
		cin >> inputmoney;
	}

	//the money whether the player is going to win or lose
	change_money = inputmoney * (num_players - 1);

	cout << "Which player do you think will win (1-" << num_players << ")?";
	cin >> Bet_winner;
	//validate the winner
	if ((Bet_winner < 1) || (Bet_winner > num_players))
	{
		cout << "INVALID PLAYER " << "-";
		cout << "Which player do you think will win (1-" << num_players << ")?";
		cin >> Bet_winner;
	}

	//play n-1 rounds(until a winner)
	for (round = 1;round < num_players;round++)
	{
		cout << "Round" << round << endl;
		cout << "PLAYERS SEATED: ";
		//include all players still alive
		for (spot = 0;spot < num_players;spot++)
			include[spot] = alive[spot];

		//seat x-1 players (where x is number left)
		for (seated = 1;seated <= num_players - round;seated++)  
		{
			//pick random number
			alive_winner = rand() % num_players;

			//validate if that player is still in the game
			while (!include[alive_winner])
				alive_winner = rand() % num_players;
			
			//player seated-delay for dramatic effect
			cout << "   ";
			cout<<alive_winner  + 1<<"  ";
			Sleep(1000);
			//Update that spot
			include[alive_winner] = false;

		}//for seated

		//Tell who was eliminated
		spot = 0;
		while (!include[spot])
			spot++;
		cout << "So player" << spot + 1 << " was eliminated!" << endl;
		cout << "Press any key to continue..."<<endl;
		_getwche();
		//Update eliminated player's status
		alive[spot] = false;
	}//for round

	//Tell who won
	spot = 0;
	while (!alive[spot])
		spot++;
	cout << " So player " << spot + 1 << " WINS!!!";


	if (alive[Bet_winner-1] )
	{
		money += change_money;
		cout << "so you win $" << change_money << " and now have $" << money << endl;
	}
	else if(!alive[Bet_winner-1])
	{
		money -= inputmoney;
		cout << "so you loss $" << inputmoney << " and now have $" << money << endl;
	}
}
