// Bike Share Program -- This program stimulates a system which people are able to borrow and return bikes from 20 different stations
// admin password: COMPSCIROCKS
// Melinda Chen Comp Sci 40S
// 2021-02-22




#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"colours.h"
using namespace std;

//Constants
const int NUM_USERS = 20;                             //NUM_USERS: max number of users (within 20)
const int NUM_STATIONS = 20;                            //NUM_STATIONS: max number of available stations
const char realadminpassword[13] = { "COMPSCIROCKS" }; //adminpassword

//function prototypes
void seed_random();                                                                                                                                     //this function seeds random numbers
char Print_menu(void);                                                                                                                                  // this function prints out the admin menu and the user menu
void Admin_Menu(int bikes_available[NUM_STATIONS], bool station_active[NUM_STATIONS]);                                                                 // admin menu makes a station active and transfer bikes from one station to another
void User_Menu(int bikes_available[NUM_STATIONS], int user_passwords[NUM_USERS], bool station_active[NUM_STATIONS], bool user_has_bike[NUM_USERS]); // user_menu allows users to create an account, so that they could take/return a bike
void Print_Stats(int bikes_available[NUM_STATIONS], bool station_active[NUM_STATIONS]);                                                                // this function prints out all statistics, including bikes in one and all station(s), activated stations percentage
void Initiate(bool station_active[NUM_STATIONS], int user_passwords[NUM_USERS], int bikes_available[NUM_STATIONS],bool user_has_bike[NUM_USERS]);   // initiate all value
void validate_number(int& num);                                                                                                                       //validate the number of station and user account number (1-20)
void validate_station(int& statnum, bool stationactive[NUM_STATIONS]);                                                                               // check whether the station is active or not



//this function seeds random number
void seed_random()
{
	int i;                  // Loop counter

// Seed the random number generator use the timer
	srand((unsigned)time(NULL));
	for (i = 0; i < rand(); i++)
		rand();
}

//initiate-- this function sets all station as inactive and user passwords from 1-20
//station_active -- check whether the station is active
// user_passwords -- the randomly generated password for each user
// bikes_available -- check how many bikes are available in the assigned station
// user_has_bike -- set all users have no bike initially
void Initiate(bool station_active[NUM_STATIONS], int user_passwords[NUM_USERS], int bikes_available[NUM_STATIONS],bool user_has_bike[NUM_USERS])
{
	int pos1, pos2;         //loop counter
	int num_array[5], number;
	//Initiate
	for (pos1 = 0;pos1 < NUM_STATIONS;pos1++)
	{
		station_active[pos1] = false;
		user_has_bike[pos1] = false;
		bikes_available[pos1] = 0;
	}

	// SET THE PASSWORD FOR EACH USER
	for (pos1 = 0;pos1 < NUM_USERS;pos1++)
	{
		for (pos2 = 0;pos2 < 5;pos2++)
		{
			num_array[pos2] = rand() % 3 + 1;
		}
		user_passwords[pos1] = 10000 * num_array[0] + 1000 * num_array[1] + 100 * num_array[2] + 10 * num_array[3] + num_array[4];
	}
}

//main
void main()
{
	char choice;                                                     //user's choice on menu
	int pos;                                                         //loop counter 
	char adminpassword[13];                                         // check if the admin enter correct password
	int bikes_available[NUM_STATIONS];                              //check how many bikes are available in the assigned station
	bool station_active[NUM_STATIONS];                              //check whether the station is active
	int user_passwords[NUM_USERS];                                  //the randomly generated password for each user
	bool user_has_bike[NUM_USERS];                              // see if user has bike

	//seed random numbers
	seed_random();

	//Initiate
	Initiate(station_active,user_passwords, bikes_available, user_has_bike);
	//LOOP
	do
	{
		choice = Print_menu();
		//choices
		switch(choice)
		{
		case 'A':
			cout << YELLOW <<"Welcome to Admin Menu! Please enter admin password: ";
			//match the admin password
			do
			{
				pos = 0;
				do
				{
					adminpassword[pos] = toupper(_getwche());
					pos++;
				} while (adminpassword[pos - 1] != '\r');
				// Add zeros character
				adminpassword[pos - 1] = '\0';
				cout << endl;
				if (strcmp(adminpassword, realadminpassword) != 0)
					cout << BOLDRED <<"Admin password ERROR, Re-enter your admin password: ";
			} while (strcmp(adminpassword, realadminpassword) != 0);
			Admin_Menu(bikes_available, station_active);
			break;
		case 'U':
			cout << BOLDWHITE;
			cout << "Welcome to User Menu" << endl;
			User_Menu(bikes_available, user_passwords, station_active, user_has_bike);
			break;
		case 'P': Print_Stats(bikes_available, station_active);
			break;
		}//switch
	} while (choice != 'X');

	//set the colour back
	cout << WHITE << B_BLACK;
}


// Admin_Menu - This function allows admin/user (with permission) to activate a station and transfer bikes
// bikes_available -- check how many bikes are available in the assigned station
//station_active -- check whether the station is active
void Admin_Menu(int bikes_available[NUM_STATIONS], bool station_active[NUM_STATIONS])
{
	//int pos2;                  //loop counter
	int stationnum,bikenum;          //activate the station number and the number of bike be putting in 
	int station1, station2,tbike;         // station 1 is the bike transfer from; station2 is where the bike transfer to; tbike is the number of bikes transfer
	char choice;             // get user's choice to whether make a station active OR transfer bikes
	char choice2;            // see if the user want to continue browsing the admin menu

	//initiate
	stationnum = 0;
	bikenum = 0;
	tbike = 0;
	do
	{		//cout two choices on admin menu
		cout << CYAN << "Admin Menu: " << endl;
		cout << "*(A)ctivate stations" << endl;
		cout << "*(T)ransfer bikes   " << endl;
		cout << "*(P)rint Stats   " << endl;
		cout << "enter your choice: ";
		choice = toupper(_getwche());
		while (choice != 'A' && choice != 'T'&&choice!='P')
		{
			cout << RED<<"INVALID!!! Re-enter your choice (A/T): ";
			choice = toupper(_getwche());
		}
		cout << endl;
		//activate a station
		if (choice == 'A')
		{
			cout << BOLDYELLOW << "Enter the station number you want to activate (1-20): ";
			cin >> stationnum;
			validate_number(stationnum);
			//set the station active
			if (!station_active[stationnum - 1])
			{
				cout << BOLDYELLOW << "Enter the number of bicycles you want to placed there (1-20): ";
				cin >> bikenum;
				validate_number(bikenum);
				bikes_available[stationnum - 1] = bikenum;
				station_active[stationnum - 1] = true;
			}
			else if (station_active[stationnum - 1])
				cout << "The station has already been activated!" << endl;
			//(see if it requires validation)
		}//choice=='A'

		//transfer bikes option
		else if (choice == 'T')
		{
			cout << YELLOW << "Welcome to the transfer bikes page.... (Warning: please transfer bikes within activated stations!)" << endl;
			cout << LIYELLOW << "Enter the number of station you want to transfer bikes from (1-20): ";
			cin >> station1;
			validate_number(station1);
			validate_station(station1, station_active);
			cout << LIYELLOW << "Enter the number of station you want to transfer bikes to (1-20): ";
			cin >> station2;
			validate_number(station2);
			validate_station(station2, station_active);
			cout << LIYELLOW << "How many bikes do you want to transfer? (1-20) ";
			cin >> tbike;
			validate_number(tbike);
			if (tbike > bikes_available[station1 - 1] || (tbike + bikes_available[station2 - 1]) > 20)
			{
				cout << "Transaction failed!" << endl;
			}
			else
			{
				bikes_available[station1 - 1] -= tbike;
				bikes_available[station2 - 1] += tbike;
				cout << CYAN << "Transaction succeed!" << endl;
			}
			cout << endl;
			//(see if all bikes transferring from one station to another)
		}//else if
		//for convenience, set an extra button hear for admin to check the stats
		else if (choice == 'P')
			Print_Stats(bikes_available, station_active);

		// ask whether to continue the admin menu
		cout << CYAN<<"Continue browsing the admin menu? (Y/N) ";
		choice2 = toupper(_getwche());
		cout << endl;
		while (choice2 != 'Y' && choice2 != 'N')
		{
			cout << BOLDRED<<"INVALID CHOICE!!! Continue browsing the admin menu? (Y/N) ";
			choice2 = toupper(_getwche());
		}
	} while (choice2 != 'N');
}// admin_menu



// User_Menu - This function allows user to log into their accounts and operate the bike sharing process
// bikes_available -- check how many bikes are available in the assigned station
// // user_passwords -- the randomly generated password for each user
//station_active -- check whether the station is active
// user_has_bike -- set all users have no bike initially
void User_Menu(int bikes_available[NUM_STATIONS], int user_passwords[NUM_USERS], bool station_active[NUM_STATIONS], bool user_has_bike[NUM_USERS])
{
	int pos1,pos2;                                        //loop counter
	int usernum;                                          //user number
	int acconum, enter_passwords[NUM_USERS],arr[5];        // the entered account number and passwords
	int availablesta;                                  // available stations
	char choice;                                      // choice to take or return a bike
	int takestation, returnstation;                   // the station number where the user take/return bikes 

	//Initiate
	availablesta = 0;

	cout << WHITE<< "Enter your user number (1-20): ";
	cin >> usernum;
	validate_number(usernum);
	cout << WHITE << "Your account number is " << usernum << endl;
	cout << WHITE << "Your account password is: ";
	cout << user_passwords[usernum - 1];
	cout << endl;
	cout << BLACK<< B_WHITE <<"Proceed to Log in Page....Please remember your account number and its password accordingly...(Press any key to continue)";
	_getwch(); cout << endl;
	cout << WHITE<< B_BLACK << "Enter your account number (1-20): ";
	cin >> acconum;
	validate_number(acconum); 
	cout << WHITE << "Enter your password: ";
	cin >> enter_passwords[acconum - 1];
	//validate
	while (enter_passwords[acconum - 1] != user_passwords[acconum - 1])
	{
		cout << BOLDRED << "INVALID! Re-enter password: ";
		cin >> enter_passwords[acconum - 1];
	}

	//ask for a take or return
	// tell the user his current status
	cout << YELLOW << "User# " << acconum << ", you have (";
	if (user_has_bike[acconum - 1])
		cout << "1";
	else
		cout << "0";
	cout<<" / 1) bike" << endl;

	cout<<BOLDGREEN<<"Do you want to (T)ake or (R)eturn a bike?";
	choice = toupper(_getwche());
	while (choice != 'T' && choice != 'R')
	{
		cout << BOLDRED;
		cout << "INVALID!!! Do you want to (T)ake or (R)eturn a bike?";
		choice = toupper(_getwche());
	}
	cout << endl;

	//check if there are available stations
	for (pos2 = 0;pos2 < NUM_STATIONS;pos2++)
	{
		if (bikes_available[pos2] > 0 && station_active[pos2])
		{
			availablesta++;
		}
	}//for
	//if no stations active
	if (pos2 = (NUM_STATIONS - 1) && availablesta == 0)
		cout << BOLDRED <<"NO STATION IS ACTIVE AT THIS MOMENT...PLEASE CHECK BACK LATER." << endl;
	//check if the user operate correctly
	else if(availablesta>0 && choice=='T'&& user_has_bike[acconum-1])
		cout << BOLDRED << "You already have a bike!" << endl;
	else if (availablesta > 0 && choice == 'R' && (!user_has_bike[acconum - 1]))
		cout << BOLDRED << "You do not have a bike!" << endl;
	//else
	else 
	{
		if (choice == 'T')
		{ //take a bike
			cout << BOLDGREEN << "Stations where you could take bikes from are: ";
			for (pos2 = 0;pos2 < NUM_STATIONS;pos2++)
				if (bikes_available[pos2] > 0 && station_active[pos2])
					cout << "#" << (pos2 + 1) << " ";
			cout << endl << GREEN << "Which station do you want to take a bike from? (1-20)";
			cin >> takestation;
			validate_station(takestation, station_active);
			while (bikes_available[takestation - 1] < 1)
			{
				cout << BOLDRED << "INVALID OPTION! There is no extra bike you could take from. Re-enter the station number where you want to take a bike from: ";
				cin >> takestation;
			} 
			if (!user_has_bike[acconum - 1])
			{
				bikes_available[takestation - 1]--;
				user_has_bike[acconum - 1] = true;
				cout << YELLOW << "You have successfully take a bike from station #" << takestation << "." << endl;
			}
		}//choice='T'
		else if (choice == 'R')		//return a bike
		{
			cout << BOLDBLUE << "Stations where you could return bikes to are: ";
			for (pos1 = 0;pos1 < NUM_STATIONS;pos1++)
				if (bikes_available[pos1] < 20 && station_active[pos1])
					cout << "#" << (pos1 + 1) << " ";
			cout << endl << BOLDBLUE << "Which station do you want to return a bike to? ";
			cin >> returnstation;
			validate_station(returnstation, station_active);
			while (bikes_available[returnstation - 1] == 20)
			{
				cout << BOLDRED << "INVALID OPTION! The station is full! Which station do you want to return a bike to: ";
				cin >> returnstation;
			}
			if (user_has_bike[acconum - 1])
			{
				bikes_available[returnstation - 1]++;
				user_has_bike[acconum - 1] = false;
				cout << MAGENTA << "You have successfully return a bike to station#" << returnstation << "." << endl;
			}
		}// choice=='R'
	}//else
}//User_menu
	

//validate_number---this function validate whether the number of station/bikes/user is in 1-20
// num -- validate the number of station/user acconut number is within 1-20
void validate_number(int& num)
{
	cout << BOLDRED;
	while (num < 1 || num >20 )
	{
		cout << "INVALID NUMBER!!! Re-enter the number (1-20): ";
		cin >> num;
	}
}

//validate_station---this function validate whether the station is active
//statum -- validate the stationnum is within 20
// station_active -- see if the station is activated
void validate_station(int& statnum, bool station_active[NUM_STATIONS])
{
	cout << BOLDRED;
	while (!station_active[statnum - 1])
	{
		cout << "INVALID NUMBER!!! The station is not activated!!! Re-enter the number of station (1-20): ";
		cin >> statnum;
	}
}


// Print_Stats -- this function tells the number of bikes available and the number of spaces avaiable of all activated stations
// bikes_available -- check how many bikes are available in the assigned station
//station_active -- check whether the station is active
void Print_Stats(int bikes_available[NUM_STATIONS], bool station_active[NUM_STATIONS])
{
	int pos1, pos2,pos3;              //loop counters
	int activestanum;            //active station number
	int totalstation, availspace, totalspace;// the total stations (20); the total possible space in all activated station
	float tpercentage_stations, percentage_space,tpercentage_available;    // percentage of activated stations over 20 stations; space available in one station, space available in all activated stations            

	//initiate
	activestanum = 0;
	totalstation = 20;
	tpercentage_stations = 0.0;
	percentage_space = 0.0;
	availspace = 0;
	totalspace = 0; 

	//print out the station map
	cout << endl;
	cout << CYAN <<"---------------------------" << endl;
	for (pos1 = 0;pos1 < NUM_STATIONS;pos1++)
	{
		cout << CYAN <<"Station #" ;
		if (pos1 < 9)
			cout << "0";
		cout << (pos1 + 1);
		if (!station_active[pos1])
		{
			for (pos2 = 0;pos2 < 20;pos2++)
				cout << BOLDRED << "| U ";
			cout << "|";
		}
		else if (station_active[pos1] && bikes_available[pos1] >= 0)
		{
			for (pos2 = 0;pos2 < bikes_available[pos1];pos2++)
				cout << GREEN << "| A ";

			for (pos3 = 0;pos3 < (20 - bikes_available[pos1]);pos3++)
				cout << BLUE << "| T ";
			cout << "|";
		}
		cout << endl;
	}//for
	cout << endl<<GREEN << "A ---- AVAILABLE" << endl;
	cout << BLUE << "T ---- TEMPORARILY UNAVAIABLE" << endl;
	cout << BOLDRED << "U ---- UNAVAILABLE, STATION NOT ACTIVE" << endl;
	cout << CYAN <<"---------------------------" << endl;
	for (pos1 = 0;pos1 < NUM_STATIONS;pos1++)
	{
		if (station_active[pos1])
		{
			cout << BOLDGREEN <<"Station #"<< (pos1 + 1) << " is active.";
			activestanum++;
			availspace += bikes_available[pos1];
			totalspace = 20 * activestanum;
			percentage_space = 100.0 * bikes_available[pos1] / 20;
			cout << "In this station, the available space is " << bikes_available[pos1] << " and the percentage of used is " << percentage_space << "%." << endl;
		}
	}//loop

	if (activestanum == 0)
	{
		cout << MAGENTA <<"None of the stations are activated. So the number of bikes and space available is zero.The percentage of available is zero (the total number of stations is 20)."<<endl;
	}
	else
	{
		cout << BOLDCYAN<<"SUMMARY: ";
		tpercentage_stations = 100.0 * activestanum / totalstation;
		tpercentage_available = 100.0 * availspace / totalspace;
		cout << "There are " << activestanum << " activated stations out of a total of " << totalstation << " stations (" << tpercentage_stations << "%)." << endl;
		cout << "There are " << availspace << " of available space in a total of " << totalspace << " space. (" << tpercentage_available << "%)." << endl;
	}
	cout << endl;
}//print_stats


//Print_menu -- this function prints out the menu and gets user's choice
char Print_menu(void)
{
	char choice;
	cout << WHITE;
	cout << "************************" << endl;
	cout << "*     (A)dmin Menu     *" << endl;
	cout << "*     (U)ser Menu      *" << endl;
	cout << "*  (P)rint Statistics  *" << endl;
	cout << "*       E(X)it         *" << endl;
	cout << "************************" << endl;
	cout<< "Enter your choice: ";
	choice = toupper(_getwche());
	while (choice != 'A' && choice != 'U' && choice != 'P' && choice != 'X')
	{
		cout << "INVALID CHOICE!!! Re-enter your choice: ";
		choice = toupper(_getwche());
	}
	cout << endl;
	return choice;
}




