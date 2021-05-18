// StartSPREADingthebutterSHEET - This program uses enumerated types and structures to
//          implement a spreadsheet to keep track of a students's Comp Sci mark
//  Your Name Here - Comp Sci 40S - The S stands for Soon (for a new assignment!)
// Today's Date Here!!

#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// Globals 
enum marktype { assn, tizquest };                   // Assignments or Tizquests
struct mark                                                     // One mark in the course
{
	marktype category;                                     // Tells whether assn or tizquest
	float result;                                                    // result of the mark
	float possible;                                               // possible score
	char description[25];                                    // description of the assessment 
};
struct spreadsheet                                       // Spreadsheet for all marks
{
	int howmany;                                          // The number of marks so far
	mark assessments[10];                           // Array of assessments
};

// Prototypes
void initialize(spreadsheet& mysheet);                   // Initializes the Spreadsheet
void addMark(spreadsheet& mysheet);                  // Adds a mark to the spreadsheet
void printSheet(spreadsheet mysheet);                   // Prints the current sheet
int getMark(spreadsheet mysheet);                         // Returns the current mark
char menu();                                                              // Returns user menu choice
void saveSheet(spreadsheet mysheet);                   // Saves current sheet to a file
void loadSheet(spreadsheet& mysheet);                // Loads a previous sheet from a file

// Main
int main(void)
{
	spreadsheet mysheet;                                         // The overall spreadsheet
	char choice;                                                         // User's Menu choice

	// Initialize the spreadsheet
	initialize(mysheet);

	// Loop until the user quits
	do
	{   // Get user choice
		choice = menu();

		// Based on choice, perform action
		switch (choice)
		{
		case 'A': // Add a new mark
			addMark(mysheet);
			break;
		case 'P': // Print out the sheet
			// Check to see if any assns yet
			if (mysheet.howmany != 0)
				printSheet(mysheet);
			else
				cout << "You need to add some data first!" << endl;
			break;
		case 'C': // Calculate the current mark
			// Check to see if any assns yet
			if (mysheet.howmany != 0)
				cout << "Your current mark is " << getMark(mysheet) << endl;
			else
				cout << "You need to add some data first!" << endl;
			break;
		case 'S': // Save the sheet to a file
			saveSheet(mysheet);
			break;
		case 'L': // Load the sheet from a file
			loadSheet(mysheet);
			break;
		} // switch

	} while (choice != 'X');

	return 0;
} // main

// menu - This function gets the user menu choice, validates, and returns it
char menu()
{
	char option;                  // The user's choice

	// get choice
	cout << "(A)dd a new assessment, (P)rint the sheet, (C)alculate the mark," <<
		" (S)ave the spreadsheet, (L)oad a previous sheet, or e(X)it? ";
	option = toupper(_getwche());
	cout << endl;

	// Validate the choice
	while (option != 'A' && option != 'P' && option != 'C' && option != 'X' && option != 'S' &&
		option != 'L')
	{
		cout << "INVALID!!! Enter A, P, C, S, or L or X ONLY ";
		option = toupper(_getwche());
		cout << endl;
	} // while

	// Return the result
	return option;

} // menu

// initialize - This function intializes the spreadsheet to be empty
// mysheet - The spreadsheet holding the data
void initialize(spreadsheet& mysheet)
{
	// Set the number of items to 0
	mysheet.howmany = 0;
} // initialize

// addMark - This function adds one assesment to the spreadsheet
// mysheet - The spreadsheet holding the data
void addMark(spreadsheet& mysheet)
{
	char aort;                              // Tells if it's an Assignment or a Tizquest

	// Ask the user if Assignment or TizQuest
	cout << "Is this an (A)ssignment or a (T)izquest? ";
	aort = tolower(_getwche());
	cout << endl;

	// Depending on choice, fill in info
	if (aort == 'a')
		mysheet.assessments[mysheet.howmany].category = assn;
	else
		mysheet.assessments[mysheet.howmany].category = tizquest;

	// Get the rest of the info
	cout << "What was it out of? ";
	cin >> mysheet.assessments[mysheet.howmany].possible;
	cout << "What mark did you get out of " << mysheet.assessments[mysheet.howmany].possible << "? ";
	cin >> mysheet.assessments[mysheet.howmany].result;
	cin.ignore();
	cout << "Assessment description? ";
	cin.getline(mysheet.assessments[mysheet.howmany].description, 25, '\n');

	// Update how many assessments
	mysheet.howmany++;
}// addMark

// getMark - This funcgtion calculates and returns the current overall mark in the spreadsheet
// mysheet - The current spreadsheet
int getMark(spreadsheet mysheet)
{
	int howmany_a, howmany_tq;              // how many assignmnets and tizquests
	float tot_possible_a, tot_possible_tq;   // the total of all possible assn/tizquest marks
	float tot_results_a, tot_results_tq;     // The total of all assn/tizquest results
	int pos;                                                  // The position in the spreadsheet

	// Set all to 0
	howmany_a = 0;
	howmany_tq = 0;
	tot_possible_a = 0.0;
	tot_possible_tq = 0.0;
	tot_results_a = 0.0;
	tot_results_tq = 0.0;

	// Loop through all assesments 
	for (pos = 0; pos < mysheet.howmany; pos++)
	{
		// Check if assn or tizquest
		if (mysheet.assessments[pos].category == assn)
		{
			// Update how many and the totals - assn
			howmany_a++;
			tot_possible_a += mysheet.assessments[pos].possible;
			tot_results_a += mysheet.assessments[pos].result;
		} // if
		else
		{
			// Update how many and the totals - tq
			howmany_tq++;
			tot_possible_tq += mysheet.assessments[pos].possible;
			tot_results_tq += mysheet.assessments[pos].result;
		} // if
	} // for

	// return the final average
	if (howmany_a == 0)
		return (int)(100 * tot_results_tq / tot_possible_tq);     // Only tizquests
	else
		if (howmany_tq == 0)
			return (int)(100 * tot_results_a / tot_possible_a);     // Only assns
		else
			return (int)((100 * tot_results_tq / tot_possible_tq) * (3.0 / 7.0) +
				(100 * tot_results_a / tot_possible_a) * (4.0 / 7.0));
}  // getMark

// printSheet - This function prints the contents of the current spreadsheet
// mysheet - The current spreadsheet to print
void printSheet(spreadsheet mysheet)
{
	int pos;                                    // Tells which assessment to print
	int spaces;                               // Used to line up output

	// Print a title
	cout << "ASSESSMENT DESCRIPTION    A/T  SCORE  POSSIBLE" << endl;
	// Loop through all assessments
	for (pos = 0; pos < mysheet.howmany; pos++)
	{
		// Print description
		cout << mysheet.assessments[pos].description;
		for (spaces = strlen(mysheet.assessments[pos].description); spaces < 25; spaces++)
			cout << " ";
		// Assn or TizQuest?
		if (mysheet.assessments[pos].category == assn)
			cout << "  A ";
		else
			cout << "  T ";
		// Print Result and Possible
		cout << "    " << mysheet.assessments[pos].result << "     " << mysheet.assessments[pos].possible << endl;
	} // for
	// Print Average by calling function
	cout << "CURRENT OVERALL AVERAGE = " << getMark(mysheet) << endl;
} // printSheet

// saveSheet - This function saves the current spreadsheet to a file
// mysheet - The current spreadsheet
void saveSheet(spreadsheet mysheet)
{
	ofstream outfile;                   // The file to write to

	/* open file */
	outfile.open("sheetfile.DAT", ios::out);

	// Check to see if file error
	if (outfile)
	{
		/* Write structure to file and then close file */
		outfile.write((char*)&mysheet, sizeof(mysheet));
		outfile.close();
		// Print message
		cout << "Sheet has been Saved! " << endl;
	} // if
	else
	{
		// File Error - give message
		cout << "FILE ERROR - You did something real bad!!! " << endl;
	} // else
} // saveSheet

// loadSheet - This function loads a spreadsheet from a file
// mysheet - The sheet loaded in
void loadSheet(spreadsheet& mysheet)
{
	ifstream infile;                       // File to read from
	char confirm;                        // Allows the user to confirm the loading

	// Ask the user to confirm 
	cout << "This operation will delete any current data. Continue? (Y/N) ";
	confirm = toupper(_getwche());
	cout << endl;

	// If so, attempt to load file
	if (confirm == 'Y')
	{/* open file */
		infile.open("sheetfile.DAT", ios::in);
		if (infile)
			/* If file opened ok, read structure and close file */
		{
			infile.read((char*)&mysheet, sizeof(mysheet));
			infile.close();
			// Print message
			cout << "Sheet has been Loaded!" << endl;
		} // if
		else
		{
			cout << "FILE ERROR! Perhaps the file does not exist!" << endl;
		} // else
	} // if confirm
} // loadSheet