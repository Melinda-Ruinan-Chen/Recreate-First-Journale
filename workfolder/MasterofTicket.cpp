// MasterOfTicket -- This program stimulates the process of selling tickets in a venue, it also uses files to store data beyond the execution of the program. so that the user could keep track of Venue Statistics
//Melinda Chen - Comp Sci 40S
// 2021-05-06


#include<iostream>
#include<Windows.h>
#include"colours.h"
#include<fstream>
#include "colours.h"
using namespace std;

//enumerated structures
enum status { sold, unsold };    //Each seat can either be sold or unsold
//structure for each seat in the venue
struct seat
{
	status seat_status;    //wondering if the seat sold yet
	int price;            //price of this ticket
};

//The venue to sell tickets at
struct venue
{
	int rows;             //The number of rows at the venue(max=10)
	int columns;          //the number of columns per row(max=10)
	seat seats[10][10];   //max venue size = 10*10
	int rowprices[10];    //Gives the price for tix in each row
};

//function prototypes
char menu(void);                       // menu of options
void Initialize(venue& MCTheatre);                 // Initialize all values
void input_venue(venue& MCTheatre);               // allow the user to enter the venue size (number of rows and columns) and the price for tickets in each row
void Print_Status(venue MCTheatre);             //print the current status of the venue. This should clearly indicate whether each seat is sold or not, and the prices for any unsold seats
void Sell_Tickets(venue& MCTheatre);            // ask the user for how many tickets they're looking for, the price tickets they can choose from, especially for consecutive seats
void Venue_Statistics(venue& MCTheatre);       // the total number of seats in the venue, number of sold/available
void saveVenue(venue MCTheatre);             // write the current venue to a file
void loadVenue(venue& MCTheatre);            // load a previously saved venue


//main
void main()
{
	venue MCTheatre;
	char choice;
	
	//Let's get ht emovie rolling!!!
	cout << WHITE<<B_BLACK<<"Welcome to the world's largest MCTheatre!!! AND MOST UNIQUE TOO!!!" << endl;
	
	//Initialize
	Initialize(MCTheatre);
	do
	{
		//print out the menu
		choice = menu();
		switch (choice)
		{
		case 'I': input_venue(MCTheatre);
			break;
		case 'P': 
			if (MCTheatre.rows != 0&&MCTheatre.columns!=0)
				Print_Status(MCTheatre);
			else
				cout << BOLDRED << B_BLACK << "INVALID OPTION!! Please input the venue first! (hint: go to input_venue function)" << endl;
			break;
		case 'T':
			if (MCTheatre.rows != 0 && MCTheatre.columns != 0)
				Sell_Tickets(MCTheatre);
			else
				cout << BOLDRED << B_BLACK << "INVALID OPTION!! Please input the venue first! (hint: go to input_venue function)" << endl;
			break;
		case 'V':
			if (MCTheatre.rows != 0 && MCTheatre.columns != 0)
				Venue_Statistics(MCTheatre);
			else
				cout << BOLDRED << B_BLACK << "INVALID OPTION!! Please input the venue first! (hint: go to input_venue function)" << endl;
			break;
		case 'S': saveVenue(MCTheatre);     // Save the venue_statistics to a file
			break;
		case 'L': loadVenue(MCTheatre);    // Load the venue_statistics from a file
			break;
		}
	} while (choice != 'E');
	//change the colour back
	cout << WHITE << B_BLACK;
}

// Initialize --- set all rows and columns and seat_status to unsold, and the assign the price for each seat according to the number of rows
// MCTheatre -- The stimulated theatre contains all data
void Initialize(venue& MCTheatre)
{
	int pos1, pos2;     //Loop counter
	for (pos1 = 0;pos1 < 10;pos1++)
	{
		for (pos2 = 0;pos2 < 10;pos2++)
		{
			MCTheatre.seats[pos1][pos2].seat_status = unsold;
			MCTheatre.seats[pos1][pos2].price = -1;
		}
	}
	// set all # of rows and columns to zero
	MCTheatre.rows = 0;
	MCTheatre.columns = 0;
}

//menu -- This function includes several choices like input, print_status,sell_tickets...
// MCTheatre -- The stimulated theatre contains all data
char menu(void)
{
	char choice;
	cout << YELLOW << B_BLACK;
	cout << "---------------------" << endl;
	cout << "|     (I)nput        |" << endl;
	cout << "|     (P)rint        |" << endl;
	cout << "|   Sell (T)ickets   |" << endl;
	cout << "| (V)enue Statistics |" << endl;
	cout << "|     (S)ave         |" << endl;
	cout << "|     (L)oad         |" << endl;
	cout << "|     (E)xit         |" << endl;
	cout << "---------------------" << endl;
	cout << "Your choice: ";
	choice = toupper(_getwche());
	cout << endl;
	while (choice != 'I' && choice != 'P' && choice != 'T' && choice != 'V' && choice != 'S' && choice != 'L'&&choice!='E')
	{
		cout << BOLDRED<<"INVALID CHOICE! Your choice: ";
		choice = toupper(_getwche());
		cout << endl;
	}
	return choice;
}//menu

// input_venue -- allow the user to enter the venue size (number of rows and columns) and the price for tickets in each row
// MCTheatre -- The stimulated theatre contains all data
void input_venue(venue& MCTheatre)
{
	int i;     //loop counter
	int pos1, pos2;
	cout << "Enter the number of rows: ";
	cin >> MCTheatre.rows;
	cout << "Enter the number of columns: ";
	cin >> MCTheatre.columns;

	//ask the price for each row
	for (i = 0;i < MCTheatre.rows;i++)
	{
		cout << CYAN << B_BLACK << "Price for Row #" << (i + 1) << ": ";
		cin >> MCTheatre.rowprices[i];
	}//assign the price of each row to each seat
	for (pos1 = 0;pos1 < MCTheatre.rows;pos1++)
		for (pos2 = 0;pos2 < MCTheatre.columns;pos2++)
			MCTheatre.seats[pos1][pos2].price=MCTheatre.rowprices[pos1];
}

//Print_Status -- print the current status of the venue. This should clearly indicate whether each seat is sold or not, and the prices for any unsold seats
// MCTheatre -- The stimulated theatre contains all data
void Print_Status(venue MCTheatre)
{
	int pos1, pos2,i;     //loop counter

	//print the price for each row
	for (pos1 = 0;pos1 < MCTheatre.rows;pos1++)
	{
		cout << BOLDBLACK << B_LIGREEN << "  ROW" << (pos1 + 1) << "  ";
		for (pos2 = 0;pos2 < MCTheatre.columns;pos2++)
		{//if the seats are sold, print "S"
			if (MCTheatre.seats[pos1][pos2].seat_status == sold)
			{
				cout << BOLDRED << B_BLACK << "S  ";
				for (i = 0;i < log10(MCTheatre.rowprices[0]);i++)
					cout <<  " ";
			}//if
			else
			{
				cout << CYAN << B_BLACK << MCTheatre.seats[pos1][pos2].price<<"  ";
				if (MCTheatre.rowprices[0] >= MCTheatre.rowprices[pos1])
				{
					for (i = 0;i <= log10(MCTheatre.rowprices[0])-log10(MCTheatre.rowprices[pos1]);i++)
						cout << " ";
				}
			}//else
		}//for
		cout << endl;
	}
	//print the top of each column
	cout << "        ";
	for (pos1 = 0;pos1 < MCTheatre.columns;pos1++)
	{
		cout << WHITE << B_LIBLUE << " C" << (pos1 + 1);
		for (i = 0;i < log10(MCTheatre.rowprices[0]);i++)
			cout << " ";
	}
	cout << endl;
}//print tickets

// Sell_Tickets -- ask the user for how many tickets they're looking for, the price tickets they can choose from, especially for consecutive seats
// MCTheatre -- The stimulated theatre contains all data
void Sell_Tickets(venue& MCTheatre)
{
	int numtickets;                             // # of tickets the user are looking for
	int numrow;                                 // number of row of the seats which the user want to reserve
	int cons_seats;                            // number of consecutive seats in a row
	int pos1, pos2;                         // Loop counter
	bool consecutive[10],existconsecutive;    // check if there are consecutive seats
	bool successpurchase;                            
	char reserved;                           //ask the user whether to buy the tickets


	//Intitialize
	numtickets = 0;
	for (pos1 = 0;pos1 < 10;pos1++)
		consecutive[pos1] = false;          //set all consecutive seats to zero
	existconsecutive = false;
	successpurchase = false;

	//ask the number of tickets
	cout << WHITE << B_BLACK << "How many tickets are you looking for? ";
	cin >> numtickets;
	//validate
	while (numtickets > MCTheatre.columns||numtickets==0)
	{
		cout << BOLDRED << B_BLACK << "INVALID NUMBER!!! How many tickets are you looking for? (hint: it must be smaller than the number of columns& not equal to zero) ";
		cin >> numtickets;
		cout << endl;
	}
	//find if there are any consecutive seats
	for (pos1 = 0;pos1 < MCTheatre.rows;pos1++)
	{
		cons_seats = 0;
		for (pos2=0;pos2 < MCTheatre.columns;pos2++)
		{			
			while (MCTheatre.seats[pos1][pos2].seat_status == unsold && pos2 < MCTheatre.columns && cons_seats < numtickets)
			{
				pos2++;
				cons_seats++;
			}
			if (cons_seats == numtickets)       // if consecutive seats exist
			{
				consecutive[pos1] = true;
				existconsecutive = true;
				pos2 = MCTheatre.columns;
			}//if
		}
	}//for

	if (!existconsecutive)
		cout << "Sorry... there is no consecutive " << numtickets << " of seat presented." << endl;
	else
	{
		//Initialize
		pos1 = 0;
		pos2 = 0;
		cons_seats = 0;

		//tell the user what price tickets they can choose from
		for (pos1 = 0;pos1 < MCTheatre.rows;pos1++)
		{
			if(consecutive[pos1])
				cout << CYAN << B_BLACK << "You can choose tickets worth $" << MCTheatre.rowprices[pos1] << " from Row #" << (pos1 + 1) << endl;
		}

		//Loop
		do
		{   
			//ask the user to choose the row
			cout << LIYELLOW << B_BLACK << "Choose the row of your seats: ";
			cin >> numrow;

			//validate
			while (!consecutive[numrow - 1] || numrow == 0)
			{
				cout << LIMAGENTA << B_BLACK << "INVALID CHOICE!!! There is no consecutive seats in row# " << numrow << " Choose the row of your seats: ";
				cin >> numrow;
				cout << endl;
			}
			//ask the user whether they want to purchase the tickets
			cout << LIMAGENTA << B_BLACK << "Would you like to reserve the seats? (Y/N) [*Warning: once the seats have been reserved, your payment will be made automatically!!!]";
			reserved = toupper(_getwche());
			while (reserved != 'Y' && reserved != 'N')
			{
				cout << LIMAGENTA << B_BLACK << "INVALID CHOICE!!! Would you like to reserve the seats? (Y/N)";
				reserved = toupper(_getwche());
			}
			cout << endl;

			//if 'yes', purchase continued...
			if (reserved == 'Y')
			{
				cout << GREEN << B_BLACK << "You have successfully puchased " << numtickets << " consecutive tickets at row# " << numrow << endl;

				for (pos2 = 0;pos2 < MCTheatre.columns;pos2++)
				{
					while (MCTheatre.seats[numrow - 1][pos2].seat_status == unsold && (cons_seats < numtickets) && pos2 < MCTheatre.columns)
					{
						MCTheatre.seats[numrow - 1][pos2].seat_status = sold;
						cons_seats++;
					}// reserved == 'Y'
				}
				successpurchase = true;
			}
		} while (reserved != 'N'&& (!successpurchase));
		// if no
		if (reserved == 'N')
			cout << WHITE << B_BLACK << "Purchase cancelled!" << endl;
	}
}// Sell_Tickets

// Venue_Statistics -- update and calculate the total number of seats in the venue, number of sold/available
// MCTheatre -- The stimulated theatre contains all data
void Venue_Statistics(venue& MCTheatre)
{
	int totalnum;    //total number of seats in the venue
	int tsold, tunsold;  // total number of sold seats and unsold seats in the venue
	int profit,tvalue;          //profits and total dollar value(for all ticket)
	float seatpercent, profitpercent;    // sold seat percentage & the profit percentage
	int pos1, pos2;      //loop counter

	//Initialize
	totalnum = MCTheatre.rows * MCTheatre.columns;
	tsold = 0;
	tunsold = 0;
	tvalue = 0;
	profit = 0;
	seatpercent = 0;
	profitpercent = 0;
	//loop
	for (pos1 = 0;pos1 < MCTheatre.rows;pos1++)
	{
		for (pos2 = 0;pos2 < MCTheatre.columns;pos2++)
		{
			tvalue += MCTheatre.rowprices[pos1];
			if (MCTheatre.seats[pos1][pos2].seat_status == sold)
			{
				tsold++;
				profit += MCTheatre.seats[pos1][pos2].price;
			}
			else
				tunsold++;
		}
	}
	//calculate the percentage
	seatpercent = tsold * 100.0 / totalnum;
	profitpercent = 100.0 * profit / tvalue;

	cout << GREEN << B_BLACK << "The total number of seats in the venue is " << totalnum << ". You have sold "<<tsold << " (" << seatpercent << "%)" <<" tickets, "<<tunsold << " (" << (100 - seatpercent) << "%)" <<" of seats are unsold" << endl;
	cout << BOLDYELLOW << B_BLACK << "You have earned $" << profit << ", which is " << profitpercent << "% out of the total dollar value ($" << tvalue << ")"<<endl;
}// Venue_Statistics

 // saveVenue -- write the current venue to a file
// MCTheatre -- The stimulated theatre contains all data
void saveVenue(venue MCTheatre)
{
	ofstream outfile;        //The file to write to

	/*open file*/
	outfile.open("Venuefile.DAT", ios::out);

	// Check to see if file error
	if (outfile)
	{
		/*Write structure to file and then close file*/
		outfile.write((char*)&MCTheatre, sizeof(MCTheatre));
		outfile.close();

		//Print message
		cout << GREEN<<B_BLACK<< "Sheet has been Saved!" << endl;
	}//IF
	else
	{
		//File Error - give message
		cout << "File error - You did something real bad!!! " << endl;
	}
}//saveVenue

// loadVenue -- load a previously saved venue
// MCTheatre -- The stimulated theatre contains all data
void loadVenue(venue& MCTheatre)
{
	ifstream infile;          // file to read from
	char confirm;            // Allow the user to confirm the loading

	// Ask the user to confirm
	cout << "This operation will delete any current data. Continue? (Y/N) ";
	confirm = toupper(_getwche());
	cout << endl;

	//If so, attempt to load file
	if (confirm == 'Y')
	{/* open file */
		infile.open("Venuefile.DAT", ios::in);
		if (infile)
		{/* If file opened of, read structure and close file*/
			infile.read((char*)&MCTheatre, sizeof(MCTheatre));
			infile.close();
			//print message
			cout << "Sheet has been Loaded! " << endl;
		}//if
		else
			cout << "File error! Perhaps the file does not exist!" << endl;
	}//if confirm
}//loadVenue
