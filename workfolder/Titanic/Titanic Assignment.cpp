// Titanic Assignment-- This program search and sort numbers in a randomly generated array
// Melinda Chen Comp. Sci 30S
// 2020-05-23

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<chrono>
#include"colours.h"
#include<stdio.h>
using namespace std;

// Constant
const int MAXSIZE = 100;              //the maximum size of an array
const int MAXNUMBER = 1000;           // the number choice from 1 to 1000

// Function Prtotypes
char Print_menu(void);                                                  // Prints out the choices based on menu
void Create_List(int& howmany, int Titanic[MAXSIZE+1]);                // ask the player about the length and create a random list
void Print_Current_List(int howmany,int Titanic[MAXSIZE + 1]);        // print out the current numbers in the list and the position of each number
void print_list(int howmany, int Titanic[MAXSIZE + 1]);                // specific way of printing list in sorting
void Bubble_Sort(int howmany, int Titanic[MAXSIZE + 1]);              // sort the numbers in an asecnding order or a descending order using bubble sort
void Insert_Sort(int howmany, int Titanic[MAXSIZE + 1]);             // sort the numbers in an ascending order or a descending order using Insert Sort
void Selection_Sort(int howmany, int Titanic[MAXSIZE + 1]);          // sort the numbers in an ascending order or a descending order using Selection Sort
void Shell_Sort(int howmany, int Titanic[MAXSIZE + 1]);             // sort the numbers in an ascending order or a descending order using Shell Sort
int Linear_Search(int howmany, int Titanic[MAXSIZE + 1],int key);          // Search a number wanted in the array using Linear Search
int Binary_Search(int howmany, int Titanic[MAXSIZE + 1],int key);         // Search a number wanted in the array using Binary Search
int Range(int howmany, int Titanic[MAXSIZE + 1]);                 // finds out the range of the given array 
int Average(int howmany, int Titanic[MAXSIZE + 1]);              // finds out the average of all numbers in an array
int Variance(int howmany, int Titanic[MAXSIZE + 1]);             // finds out the variance of all numbers in an array
void seek_random();                                             // seek random numbers

// seed random numbers
void seek_random()
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
	int Titanic[MAXSIZE+1];    // An array contains a maximum of 100 numbers
	int i;                      //loop counter
	char choice;               // gets user's choice from menu
	char choice2;              // gets user's choice to create a new list
	int howmany;              // how many numbers in the arrays
	int average;              // the average of all numbers from the given list
	int variance;             // the variance of all numbers in the list
	int range;                // the subtraction of the biggest number and the smallest number
	int position_result;      // the position which the number wanted located (use for searching numbers)
	int key;                  // the target number

	// random....
	seek_random();
	//Initialize
	howmany = 0;
	position_result = 0;
	i = 0;
	// The voyage begins...
	text_colour(f_cyan, b_black);
	cout << "*******************************" << endl;
	cout << "WELCOME TO THE TITANIC TOUR!!!" << endl;
	// Loop until the user quit the game
	do
	{
		choice = Print_menu();
		switch (choice)
		{
		case 'C': 
			while (howmany == 0)
			{
				Create_List(howmany, Titanic);
				text_colour(f_magenta, b_black);
				cout << "(* WARNING!!! RE-ENTERING THIS OPTION WILL DESTROY ANY PREVIOUS LIST THAT'S ALREADY EXISTED *)" << endl<<endl;
				text_colour(f_dyellow, b_black);
				cout << "=========================" << endl<<endl<<endl;
			}
			i++;
			while (i>1&&howmany!=0)
			{
				text_colour(f_magenta, b_black);
				cout << "(* WARNING!!! THIS OPTION WILL DESTROY ANY PREVIOUS LIST THAT'S ALREADY EXISTED *)" << endl;
				text_colour(f_red, b_black);
				cout << "Are you sure about your choice? (Y/N) ";
				choice2 = toupper(_getwche());
				cout << endl;
				while (choice2 != 'Y' && choice2 != 'N')
				{
					text_colour(f_white, b_black);
					cout << "INVALID CHOICE!!! PLEASE RE-ENTER YOUR CHOICE: ";
					choice2 = toupper(_getwche());
					cout << endl;
				}//while
				if (choice2 == 'Y')
					Create_List(howmany, Titanic);
				else
				{
					text_colour(f_yellow, b_black);
					cout << "Your table has been reserved..." << endl;
				}//else
				i = 1;
				text_colour(f_dyellow, b_black);
				cout << "=========================" << endl<<endl<<endl;
			}
			break;
		case 'P': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl;
				cout << endl << endl;
			}
			else
			{
				text_colour(f_white, b_black);
				cout << "========================" << endl<<endl;
				text_colour(f_yellow, b_black);
				cout << "Here is your 'table': " << endl;
				cout << endl;
				Print_Current_List(howmany, Titanic);
				cout << endl;
				text_colour(f_white, b_black);
				cout << "========================" << endl<<endl;
				cout << endl << endl;
			}
				break;
		case 'L': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl;
				cout << endl << endl;
			}
			else
			{
				text_colour(f_cyan, b_black);
				cout << "=====================================" << endl;
				text_colour(f_white, b_black);
				cout << "Welcome to Linear Search!!!!" << endl;
				text_colour(f_green, b_black);
				cout << "Which key are you going to find? (HINT: What number do you want to find in the array?) ";
				cin >> key;
				//Validate
				while (key < 1 || key>1000)
				{
					text_colour(f_dred, b_black);
					cout << "INVALID CHOICE!!! PLEASE CHOOSE NUMBERS FROM 1 TO 1000: ";
					cin >> key;
					cout << endl;
				}
				position_result = Linear_Search(howmany, Titanic,key);
				if (position_result == -1)
				{
					text_colour(f_dred, b_gray);
					cout << "Ooops!!! Couldn't find your key after "<< (howmany + 1) << " compare(s) "<< "... (Number not found) " << endl;
					cout << endl << endl;
				}
				else 
				{
					text_colour(f_dmagenta, b_cyan);
					cout << "Your number is located in position " << (position_result+1) <<" after "<<(position_result+1)<<" compare(s)."<< endl;
					cout << endl<<endl;
				}
			}
			break;
		case 'E': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl;
				cout << endl << endl;
			}
			else
			{
				//Begin the game
				text_colour(f_white, b_black);
				cout << "=====================" << endl;
				cout << "Welcome to Binary Search Game!!! Please enter the key you are going to search for: ";
				cin >> key;
				//validate
				while (key < 1 || key>1000)
				{
					text_colour(f_dred, b_black);
					cout << "INVALID KEY!!! PLEASE ENTER NUMBER FROM 1 TO 1000: ";
					text_colour(f_green, b_black);
					cin >> key;
					cout << endl;
				}
				position_result=Binary_Search(howmany, Titanic,key);
				if(position_result!=-1)
				{
					text_colour(f_dmagenta, b_cyan);
					cout <<" after "<<position_result<<" compare(s)." << endl;
					cout << endl << endl;
				}
			}
				break;
		case 'B':
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}
			else
				Bubble_Sort(howmany, Titanic);break;			
		case 'I': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}
			else
				Insert_Sort(howmany, Titanic);break;			
		case 'S': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}
			else
				Selection_Sort(howmany, Titanic);break;
		case 'T': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}
			else
				Shell_Sort(howmany, Titanic);break;
		case 'R': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}
			else
				range=Range(howmany, Titanic);
			break;
		case 'A': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}
			else
			{
				text_colour(f_gray, b_black);
				cout << "*Welcome to the AVERAGE part!!!*" << endl;
				average=Average(howmany, Titanic);
				text_colour(f_magenta, b_black);
				cout << "The average of all " << howmany << " number(s) is ... ";
				Sleep(1000);
				cout << average << endl;
				cout << endl;
				text_colour(f_dblue, b_black);
				cout << "=============================" << endl << endl << endl;
			}
			break;
		case 'V': 
			if (howmany == 0)
			{
				text_colour(f_yellow, b_black);
				cout << "UN-OH, please register first... (HINT: Create a list first)" << endl<<endl<<endl;
			}//if
			else if (howmany == 1)
			{
				text_colour(f_dred, b_dgray);
				cout << "Variance only exists within two or more numbers." << endl;
				cout << endl << endl;
			}
			else
			{
				variance = Variance(howmany, Titanic);
			}//else
				
			break;
		}			
	} while (choice != 'Q');

	if (choice == 'Q')
	{
		text_colour(f_cyan, b_black);
		cout << "How is your Titanic Tour? Thumbs up if you are satisfied!!! (LOL~) " << endl;
	}
	//switch the colour back
	text_colour(f_white, b_black);
}// Main

 // Print_menu-- This function prints out user's choice based on the menu
char Print_menu(void)
{
	char choice;
	text_colour(f_dcyan, b_gray);
	cout << "******************************" << endl;
	cout << "*    Special for Today       *" << endl;
	cout << "*                            *" << endl;
	cout << "*   (C)reate List            *" << endl;
	cout << "*   (P)rint Current List     *" << endl;
	cout << "*   (L)inear Search          *" << endl;
	cout << "*    Binary S(E)arch         *" << endl;
	cout << "*   (B)ubble Sort            *" << endl;
	cout << "*   (I)nsertion Sort         *" << endl;
	cout << "*   (S)election Sort         *" << endl;
	cout << "*    Shell Sor(T)            *" << endl;
	cout << "*   (R)ange Calculation      *" << endl;
	cout << "*   (A)verage Calculation    *" << endl;
	cout << "*   (V)ariance Calculation   *" << endl;
	cout << "*   (Q)uit the Game          *" << endl;
	cout << "*                            *" << endl;
	cout << "*              From Chef Chen*" << endl;
	cout << "******************************" << endl;
	
	text_colour(f_cyan,b_black);
	choice = toupper(_getwch());
	while (choice != 'C' && choice != 'P' && choice != 'L' && choice != 'E' && choice != 'B' && choice != 'I' && choice != 'S' && choice != 'T' && choice != 'R' && choice != 'A' && choice != 'V' && choice != 'Q')
	{
		text_colour(f_dred, b_black);
		cout << "INVALID CHOICE!!! Please re-enter your choice: ";
		text_colour(f_green, b_black);
		choice = toupper(_getwche());
		cout << endl;
	}
	cout << endl << endl;
	return choice;
}//Print_Menu();
// Create_List-- This function asks the player the length of the array for computer to create a random list
 // howmany-- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
void Create_List(int& howmany, int Titanic[MAXSIZE + 1])
{
	int pos;                  // position in the array

	//ask how many numbers wanted
	text_colour(f_green, b_black);
	cout << "Welcome to our registration service! Please choose your LUCKY NUMBER on the list. (HINT: How many numbers do you want TO SHOW on the table) " << endl;
	cin >> howmany;
	cout << endl;
	//Validate
	while (howmany < 1 || howmany>100) 
	{
		text_colour(f_dred, b_black);
		cout << "INVALID CHOICE; Please enter the number from 1 to 100: ";
		text_colour(f_green, b_black);
		cin >> howmany;
		cout << endl;
	}
	// Generates a list
	for (pos = 0;pos < howmany;pos++)
		Titanic[pos] = rand() % MAXNUMBER + 1;
}//Create_List();
 // Print_Current_List-- this function prints out the current numbers in the list and the position of each number
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
void Print_Current_List(int howmany,int Titanic[MAXSIZE + 1])
{
	int pos1;    //the position in the list
	int pos2;    // the number in the position

	//Initialize
	pos2 = 0;

	// Print out the table
	for (pos1 = 1;pos1 <= howmany;)
	{
		while (pos2 <= howmany - 1)
		{
			if (pos1 >= 1 && pos1 < 10)
				cout << " ";
			text_colour(f_dgray, b_black);
			cout << "(" << pos1 << ")";
			text_colour(f_blue, b_black);
			cout << Titanic[pos2];
			text_colour(f_cyan, b_black);
			cout << "*  ";
			if (Titanic[pos2] >= 1 && Titanic[pos2] < 10)
				cout << "  ";
			if (Titanic[pos2] >= 10 && Titanic[pos2] <= 99)
				cout << " ";
			pos2++;
			if (pos1 % 8 == 0)
				cout << endl;
			pos1++;
		}
	}//for
	cout << endl;
}
// print_list--This function has a specific way of printing list in sorting
// howmany-- # of numbers wanted in the list
// Titanic[]--This array contains randomly generated numbers
void print_list(int howmany, int Titanic[MAXSIZE + 1])
{
	int a;             //Loop counter
	for (a = 1;a <= howmany;a++)
	{
		text_colour(f_dgray, b_black);
		cout << "( " << a << " )";
		text_colour(f_blue, b_black);
		cout << Titanic[a - 1];
		if (Titanic[a - 1] >= 1 && Titanic[a - 1] < 10)
			cout << "    ";
		if (Titanic[a - 1] >= 10 && Titanic[a - 1] <= 99)
			cout << "   ";
		if (Titanic[a - 1] > 99 && Titanic[a - 1] < 1000)
			cout << "  ";
		if (a % 6 == 0)
		{
			cout << endl;
			cout << "                                                       ";
		}//if
	}
}
// Bubble_Sort--This function sorts all numbers in an ordered list through multi-pass. Each time it switches any adjacent items that are out of order, until two adjacent numbers are placed in the required order (ascending/ descending according to user's choice)
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
void Bubble_Sort(int howmany, int Titanic[MAXSIZE + 1])
{
	int i;             // loop counter
	int j;             // the position in the array
	int a;             //loop counter [for printing]
	int temp;          // the middle contractor (help exchange position due to their values)
	char choice;       //choice of choosing ascending or descending order
	int copy[MAXSIZE + 1];   //make a copy of Titanic array
	// Initialize
	i = 0;

	// Ask the user whether they want the number placing in an ascending order or a descending order
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	text_colour(f_green, b_black);
	cout << "Do you want the number to be placed in an (A)scending order or a (D)escending order? ";
	choice = toupper(_getche());
	// Validate
	while (choice != 'A' && choice != 'D')
	{
		cout << endl;
		text_colour(f_dred, b_black);
		cout << "Invalid choice!! Please re-enter the order you want to be:  ";
		text_colour(f_green, b_black);
		choice = toupper(_getche());
		cout << endl;
	}
	cout << endl;
	//make a copy of Titanic array
	for (i = 0;i < howmany;i++)
		copy[i] = Titanic[i];

	//Ascending order
	if (choice == 'A')
	{
		for (i = 0;i < howmany - 1;i++)            // if there are "n" numbers in the array, each round requires "n-1" times to re-arrange order
		{
			for (j = howmany - 1;j > i;j--)        // Loop from the back to the front, so the first letter has been set after the first round, when i increases, the less sorting needed because the first few numbers are set
			{
				if (copy[j - 1] > copy[j])
				{
					temp = copy[j - 1];
					copy[j - 1] = copy[j];
					copy[j] = temp;
				}//if
			}//for
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Ascending Bubble Sort after " << (i + 1) << " round(s) is: ";
			print_list(howmany, copy);
			cout << endl;
		}//for
	}//while

	// Descending order
	else if (choice == 'D')
	{
		for (i = 0;i < howmany - 1;i++)                  // if there are "n" numbers in the array, each round requires "n-1" times to re-arrange order
		{
			for (j = 0;j < (howmany-i);j++)             // the last number has been sorted out and set, therefore when i increases, the less sorting needed because the first few numbers are set
			{
				if (copy[j] < copy[j + 1])              // exchange if the number afterwards is bigger than the number beforehead 
				{
					temp = copy[j];
					copy[j] = copy[j + 1];
					copy[j + 1] = temp;
				}//if
			}//for
						//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Descending Bubble Sort after " << (i + 1) << " round(s) is: ";
			print_list(howmany, copy);
			cout << endl;
		}//for
	}//if (descending bubble sort)
	// set back to zero
	i = 0;
	text_colour(f_white, b_black);
	cout << "The final result is: " << endl;
	Print_Current_List(howmany, copy);
	//Ending...
	cout << endl << endl;
	text_colour(f_white, b_black);
	cout << "====================" << endl;
	cout << endl << endl;
}
// Insert_Sort--This function placed one item each time, part of the list is sorted, and part of the listed remained unsorted, each time a number in the unsorted list is being inserted into the sorted list in an (ascending/descending) order, however, the numbers in the sorted list are in a correct order
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
void Insert_Sort(int howmany, int Titanic[MAXSIZE + 1])
{
	int i;             // loop counter
	int j;             // the position in the array
	int a;              // loop counter (for printing)
	int temp;          // the middle contractor (help exchange position due to their values)
	char choice;       //choice of choosing ascending or descending order
	int copy[MAXSIZE + 1];   //make a copy of Titanic array
	// Initialize
	i = 0;

	// Ask the user whether they want the number placing in an ascending order or a descending order
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	text_colour(f_yellow, b_black);
	cout << "Do you want the number to be placed in an (A)scending order or a (D)escending order? ";
	choice = toupper(_getche());
	// Validate
	while (choice != 'A' && choice != 'D')
	{
		cout << endl;
		text_colour(f_dred, b_black);
		cout << "Invalid choice!! Please re-enter the order you want to be:  ";
		text_colour(f_green, b_black);
		choice = toupper(_getche());
		cout << endl;
	}
	cout << endl;
	//make a copy of Titanic array
	for (i = 0;i < howmany;i++)
		copy[i] = Titanic[i];
	// Ascending order
	if (choice == 'A')
	{
		for (i = 1;i < howmany;i++)
		{
			temp = copy[i];
			j = i - 1;
			while (j >= 0 && temp < copy[j])        // make rooms for smaller number to insert
			{
				copy[j + 1] = copy[j];             //actually this means the bigger number has been put one grid/lattice backwards 
				j--;
			}// while
			copy[j + 1] = temp;                   // this copy[j+1] is actually the final copy[j] in the while loop,([j--] meaning copy[j+1] becomes the new copy[j]), insertion completed
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Ascending Insertion Sort after " << i << " round(s) is: ";
			print_list(howmany, copy);
			cout << endl;
		}
	}// if

	//Descending order
	else if (choice == 'D')
	{
		for (i = 1;i < howmany;i++)
		{
			temp = copy[i];
			j = i - 1;
			while (j >= 0 && temp > copy[j])         // make rooms for bigger number to insert
			{
				copy[j + 1] = copy[j];               
				j--;
			}// while
			copy[j + 1] = temp;
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Descending Insertion Sort after " << i << " round(s) is: ";
			print_list(howmany, copy);
			cout << endl;
		}//for
	}//else if

	// set back to zero
	text_colour(f_white, b_black);
	cout << "The final result is: " << endl;
	Print_Current_List(howmany, copy);
	//Ending...
	cout << endl << endl;
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	cout << endl << endl;
}
// Selection_Sort--This function find the lowest or the highest number in the list each time, therefore, a spot in the list has been set after each time
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
void Selection_Sort(int howmany, int Titanic[MAXSIZE + 1])
{
	int i;             // loop counter
	int j,k;             // the position in the array
	int a;              // loop counter (for printing)
	int temp;          // the middle contractor (help exchange position due to their values)
	char choice;       //choice of choosing ascending or descending order
	int copy[MAXSIZE + 1];   //make a copy of Titanic array
	// Initialize
	i = 0;
	k = 0;
	// Ask the user whether they want the number placing in an ascending order or a descending order
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	text_colour(f_yellow, b_black);
	cout << "Do you want the number to be placed in an (A)scending order or a (D)escending order? ";
	choice = toupper(_getche());
	// Validate
	while (choice != 'A' && choice != 'D')
	{
		cout << endl;
		text_colour(f_dred, b_black);
		cout << "Invalid choice!! Please re-enter the order you want to be:  ";
		text_colour(f_green, b_black);
		choice = toupper(_getche());
		cout << endl;
	}
	cout << endl;
	//make a copy of Titanic array
	for (i = 0;i < howmany;i++)
		copy[i] = Titanic[i];

	// Ascending order
	if (choice == 'A')
	{
		for (i = 0;i < howmany - 1;i++)
		{
			k = i;
			for (j = i + 1;j < howmany;j++)
			{
				if (copy[j] < copy[k])
					k = j;
			}//for
			if (k != i)                  //exchange
			{
				temp = copy[i];
				copy[i] = copy[k];
				copy[k] = temp;
			}//if
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Ascending Selection Sort after " << (i+1) << " round(s) is: ";
			print_list(howmany, copy);			
			cout << endl;
		}//for
	}// ascending for

	
	//descending order
    if (choice == 'D')
	{
		for (i = 0;i < howmany - 1;i++)
		{
			k = i;
			for (j = i + 1;j < howmany;j++)
			{
				if (copy[j] > copy[k])
					k = j;
			}//for
			//exchange
			if (k != i)
			{
				temp = copy[i];
				copy[i] = copy[k];
				copy[k] = temp;
			}//if
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Descending Selection Sort after " << (i+1) << " round(s) is: ";
			print_list(howmany, copy);
			cout << endl;
		}//for
	}//else if

	// Print out the result
	text_colour(f_white, b_black);
	cout << "The final result is: " << endl;
	Print_Current_List(howmany, copy);
	//Ending...
	cout << endl << endl;
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	cout << endl << endl;
}

// Shell_Sort-- This function make groups of two among all numbers in the array, after comparison done in each pair of numbers,the group increased its size to 2n (n is exponents) times, until all numbers were put in a group (this function is pretty much alike whith the Insert Sort)
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
void Shell_Sort(int howmany, int Titanic[MAXSIZE + 1])
{
	int i,j;                // Loop counter in the array
	int r;                  // Loop counter for groups
	int a,x;                   // loop counter (for printing)
	int temp;               // the middel contractor
	char choice;
	int copy[MAXSIZE + 1];  //make a copy of Titanic array

	// Ask the user whether they want the number placing in an ascending order or a descending order
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	text_colour(f_yellow, b_black);
	cout << "Do you want the number to be placed in an (A)scending order or a (D)escending order? ";
	choice = toupper(_getche());
	// Validate
	while (choice != 'A' && choice != 'D')
	{
		cout << endl;
		text_colour(f_dred, b_black);
		cout << "Invalid choice!! Please re-enter the order you want to be:  ";
		text_colour(f_green, b_black);
		choice = toupper(_getche());
		cout << endl;
	}
	cout << endl;

	// make a copy
	for (i = 0;i < howmany;i++)
		copy[i] = Titanic[i];
	//Initialize
	x = 0;
	//Ascending loop
	if (choice == 'A')
	{
		for (r = howmany / 2;r >= 1;r /= 2)
		{
			for (i = r;i < howmany;i++)
			{
				temp = copy[i];
				j = i - r;
				while (j >= 0 && temp < copy[j])
				{
					copy[j + r] = copy[j];
					j -= r;
				}//while
				copy[j + r] = temp;
			}//for
			x++;
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Ascending Shell Sort after " << x << " round(s) is: ";
			print_list(howmany, copy);
			//a little delay...
			Sleep(200);
			cout << endl;
		}//for
	}//for

	//Initialize
	x = 0;
	//Descending loop
	if (choice == 'D')
	{
		for (r = howmany / 2;r >= 1;r /= 2)
		{
			for (i = r;i < howmany;i++)
			{
				temp = copy[i];
				j = i - r;
				while (j >= 0 && temp > copy[j])
				{
					copy[j + r] = copy[j];
					j -= r;
				}//while
				copy[j + r] = temp;
			}//for
			x++;
			//Print out each step
			text_colour(f_dyellow, b_black);
			cout << "The result of Descending Shell Sort after " << x << " round(s) is: ";
			print_list(howmany, copy);
			//a little delay...
			Sleep(200);
			cout << endl;
		}//for
	}//for

	// Prints out the result
	cout << endl;
	text_colour(f_white, b_black);
	cout << "The final result is: " << endl;
	Print_Current_List(howmany, copy);
	cout << endl << endl;
	//Ending...
	cout << endl << endl;
	text_colour(f_white, b_black);
	cout << "======================================" << endl;
	cout << endl << endl;
}

// Linear_Search--This function allows the user to serach for their wanted key by looping through every number in the array
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
int Linear_Search(int howmany, int Titanic[MAXSIZE + 1],int key)
{
	int i;                    //position in the array
	int copy[MAXSIZE + 1];    // copy of the original Titanic array

	// make a copy
	for (i = 0;i < howmany;i++)
		copy[i] = Titanic[i];

	//Set back to zero
	i = 0;
	//while
	while (i < howmany)
	{
		if (copy[i] == key)
			return i;
		else
			i++;
	}//while	
	//if nothing been found
	return -1;	
}
// Binary_Search--This function allows the user to search for key by 
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
int Binary_Search(int howmany, int Titanic[MAXSIZE + 1],int key)
{
	int i;                           // loop counter
	int j;                           // number in position
	int temp;                        // the middle contractor
	int lower;                       //the lower position
	int upper;                        //the upper position
	int search_pos;                   //find the middle position
	int copy[MAXSIZE + 1];          //copy of the Titanic array

	//make a copy
	for (i = 0;i < howmany;i++)
		copy[i] = Titanic[i];
	//Initialize
	lower = 0;
	upper = howmany - 1;
	search_pos = (lower + upper) / 2;
	
	// change the array into the ascending order (using Insertion Sort)
	for (i = 1;i < howmany;i++)
	{
		temp = copy[i];
		j = i - 1;
		while (j>=0 && temp<copy[j])
		{
			copy[j + 1] = copy[j];
			j--;
		}
		copy[j + 1] = temp;
	}//for
	//print out the ordered list
	text_colour(f_yellow, b_black);
	cout << "This is an ordered Titanic list: " << endl;
	for (i = 0;i < howmany;i++)
	{
		text_colour(f_dgray, b_black);
		cout << "( " << i + 1 << " )" << " ";
		text_colour(f_blue, b_black);
		cout << copy[i];
		if ((i+1) % 8 == 0)
			cout << endl;
	}//for
	cout << endl;
	i = 0;
	while (lower <= upper)
	{
		if (copy[search_pos] == key)
		{
			i++;
			text_colour(f_magenta, b_cyan);
			cout << "Your key is located in position " << (search_pos+1);
			return i;
		}
		else if (copy[search_pos] > key)
		{
			i++;
			upper = search_pos - 1;
		}
		else
		{
			i++;
			lower = search_pos + 1;
		}
		// lower the range down to a half
		search_pos = (upper + lower) / 2;
	}//while

	while (lower > upper)
	{
		text_colour(f_dred, b_gray);
		cout << "Ooops!!! Couldn't find your key after "<< i << " compare(s) "<< "... (Number not found) " << endl;
		cout << endl << endl;
		//Print out the result
		return -1;
	}//while
}
// Range--This function finds out the range of the given array 
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
int Range(int howmany, int Titanic[MAXSIZE + 1])
{
	int range;
	int max;        // The maximum number of the list
	int min;        // The minimum number of the list
	int pos;        // position in the arrau

	// Initialize
	max = 0;
	min = 1000;
	range = 0;

	// Loop
	for (pos = 0;pos < howmany;pos++)
	{
		if (Titanic[pos] > max)
			max = Titanic[pos];
		if (Titanic[pos] < min)
			min = Titanic[pos];
	}//for

	//Calculate the range
	range = max - min;

	// Print out the results...
	text_colour(f_gray, b_black);
	cout << "*Welcome to the Range part!!!*" << endl;
	text_colour(f_red, b_black);
	cout << "The Biggest number in the current list is ..." << max<<endl;
	text_colour(f_magenta, b_black);
	cout << "The Lowest number in the current list is ... " << min<<endl;
	text_colour(f_dcyan, b_black);
	cout << "So the range is ... ";
	text_colour(f_white, b_black);
	cout << "(Press any botton to continue...)"<<endl;
	_getwche();
	text_colour(f_dcyan, b_black);
	cout<< range << endl<<endl;
	text_colour(f_dblue, b_black);
	cout << "=============================" << endl << endl << endl;
	//Return the value
	return range;
}
// Average--This function finds out the average of all numbers in an array
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
int Average(int howmany, int Titanic[MAXSIZE + 1])
{
	int average;    // the average of all numbers in the list
	int sum;        // the sum of all numbers
	int pos;        //position in the array

	// Initialize
	average = 0;
	sum = 0;

	// Loop
	for (pos = 0;pos < howmany;pos++)
		sum += Titanic[pos];

	// Calculate the average
	average = sum / howmany;
	// Return the value
	return average;
}
// Variance--This function finds out the variance of all numbers in an array
 // howmany- # of numbers wanted in the list
// Titanic[]-- this array contains randomly generated numbers
int Variance(int howmany, int Titanic[MAXSIZE + 1])
{
	int variance;      // variance of the numbers
	int average;      // average of the numbers
	int square;        // square of the number in each position subtract average
	int sum;           // sum of the square
	int pos;          // postition in the array
	// Initialize
	variance = 0;
	square = 1;
	sum = 0;
	average = Average(howmany,Titanic);

	text_colour(f_gray, b_black);
	cout << "*Welcome to the VARIANCE part!!!*" << endl;
	//Loop
	for (pos = 0;pos < howmany;pos++)
	{
		square = (Titanic[pos] - average) * (Titanic[pos] - average);
		sum += square;
		square = 1;
	}
	variance = sum / (howmany - 1);
	text_colour(f_dgreen, b_black);
	cout << "The variance of the numbers in the list is ... ";
	Sleep(1000);
	cout << variance;
	cout<<endl<<endl;
	text_colour(f_dblue, b_black);
	cout << "=============================" << endl << endl << endl;
	return variance;
}

