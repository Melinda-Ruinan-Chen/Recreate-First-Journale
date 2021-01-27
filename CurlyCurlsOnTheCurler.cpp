//				Darwin Alvarez					//
//				   10/11/18						//
//		  Curly Curls on the Curler		//

#include <iostream>
#include <time.h>
using namespace std;

//Prototypes                                                                                                                                                                
bool coin_toss();																		//Decides which team gets to go first
void PlayEnd(bool& first_team, int& t1score, int& t2score);		//Plays an end
void seed_random();																	//Seeds the RNG

//Main
int main()
{
	bool first_team;			//Which team plays first
	int t1score;				//Current score of team 1
	int t2score;				//Current score of team 2
	int end;						//Current end game is on

	//Seed random
	seed_random();

	//Decide which team goes first
	coin_toss();

	//Initialize scores
	t1score = 0;
	t2score = 0;

	//Print out END and team names
	cout << "END		BEASTS		HUNTERS" << endl << endl;

	//Loop through for 10 ends
	for (end = 1; end <= 10; end++)
	{
		cout << end;
		PlayEnd(first_team, t1score, t2score);
	}//FOR

	//Extra end(s)
	while(t1score == t2score)
	{
		cout << end;
		PlayEnd(first_team, t1score, t2score);
	}//IF

	//Print Results
	end--;
	cout << "--------------------------------------" << endl 
		<< end << "		" << t1score << "		" << t2score << endl << endl
		<< "Final Score:" << endl << endl;

	if (t1score > t2score)
	{
		cout << "The BEASTS win " << t1score << " - " << t2score << endl;
		cout << "Unfortunately, the hunters have been mauled. Better luck next time..." << endl << endl;
	}
	else
	{
		cout << "The HUNTERS win " << t2score << " - " << t1score << endl;
		cout << "The beasts have been slain and the hunt has ended. A new day begins..." << endl << endl;
	}

}

//PlayEnd() - This function plays an end of roulette
//first_team - Which team plays first
//t1score - Score of the first team
//t2score - Score of the second team
void PlayEnd(bool& first_team, int& t1score, int& t2score)
{
	int randnum;					//Determines what score the team gets at random

	//Get random value
	randnum = rand() % 100 + 1;

	//Find out what happened
	if (randnum <= 15)		//1-15
	{
		//Blank end
		cout << "		0		0" << endl;
	}
	else
		if (randnum <= 35)		//16-35
		{
			//Hammer team scores 1
			if (first_team)
			{
				t1score += 1;
				cout << "		1		0" << endl;
				first_team = !first_team;
			}//IF
			else
			{
				t2score += 1;
				cout << "		0		1" << endl;
				first_team = !first_team;
			}//ELSE
		}//IF
		else
			if (randnum <= 50)		//36-50
			{
				//Hammer team scores 2
				if (first_team)
				{
					t1score += 2;
					cout << "		2		0" << endl;
					first_team = !first_team;
				}//IF
				else
				{
					t2score += 2;
					cout << "		0		2" << endl;
					first_team = !first_team;
				}//ELSE
			}
			else
				if (randnum <= 60)		//51-60
				{
					//Hammer team scores 3
					if (first_team)
					{
						t1score += 3;
						cout << "		3		0" << endl;
						first_team = !first_team;
					}//IF
					else
					{
						t2score += 3;
						cout << "		0		3" << endl;
						first_team = !first_team;
					}//ELSE
				}//IF
				else
					if (randnum <= 65)		//61-65
					{
						//Hammer team scores 4
						if (first_team)
						{
							t1score += 4;
							cout << "		4		0" << endl;
							first_team = !first_team;
						}//IF
						else
						{
							t2score += 4;
							cout << "		0		4" << endl;
							first_team = !first_team;
						}//ELSE
					}//IF
					else
						if (randnum <= 84)		//66-84
						{
							//Non-hammer team scores 1
							if (first_team)
							{
								t2score += 1;
								cout << "		0		1" << endl;
							}//IF
							else
							{
								t1score += 1;
								cout << "		1		0" << endl;
							}//ELSE
						}//IF
						else
							if (randnum <= 94)		//85-94
							{
								//Non-hammer team scores 2
								if (first_team)
								{
									t2score += 2;
									cout << "		0		2" << endl;
								}//IF
								else
								{
									t1score += 2;
									cout << "		2		0" << endl;
								}//ELSE
							}//IF
							else
								if (randnum <= 99)		//95-99
								{
									//Non-hammer team scores 3
									if (first_team)
									{
										t2score += 3;
										cout << "		0		3" << endl;
									}//IF
									else
									{
										t1score += 3;
										cout << "		3		0" << endl;
									}//ELSE
								}//IF
								else
									if (randnum = 100)		//100
									{
										//Non-hammer team scores 4
										if (first_team)
										{
											t2score += 4;
											cout << "		0		4" << endl;
										}//IF
										else
										{
											t1score += 4;
											cout << "		4		0" << endl;
										}//ELSE
									}//IF
}//PlayEnd

//coin_toss() - This function simulates a coin toss and returns true or false
bool coin_toss()
{
	switch (rand() % 2)
	{
	case 0: return false; break;
	case 1: return true; break;
	}//SWITCH
}//coin_toss

//seed_random() - This functions seeds the random number generator
void seed_random()
{
	int i;			// Loop counter

					//Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i<rand(); i++)
		rand();
}//seed_random