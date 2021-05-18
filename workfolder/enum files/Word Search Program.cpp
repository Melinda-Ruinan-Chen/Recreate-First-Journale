// Word Search --- This program stimulates a word puzzle for user to find a word either horizontally or vertically; and it allows user to save data to a file and/or resume data from a file
// Melinda Chen Comp Sci 40S
// 2020-04-18


#include<iostream>
#include<Windows.h>
#include"colours.h"
#include<conio.h>
#include<chrono>
#include<fstream>
using namespace std;

//enumerated type
enum status {spot_found, spot_not_found};

//A spot in the puzzle
struct spot
{
	char letter;           // The letter in that spot
	status spot_status;    // tells if this spot has been found yet
};

//puzzle contains all words
struct puzzle
{
	int numrows;                // # of rows in the puzzle
	int numcolumns;             // # of columns in the puzzle
	spot entry[10][10];        // tells if this spot has been found yet
    int numwordsfound;         // how many words have been found
    char wordlist[25][11];     //matrix of found words -max of 25
};

//function prototypes
char Menu(void);                            //Menu contains several choice function
void initialize(puzzle& mypuzzle);         // This funtion initializes the puzzle to be empty
void Create_Puzzle(puzzle& mypuzzle);  //creates a new puzzle by asking user for puzzle size and then giving the user the option to either enter the letters or use random letters
void Resume_Puzzle(puzzle& mypuzzle);  //resumes a previous puzzle by reading the previous puzzle in from a file
void Write_Puzzle(puzzle mypuzzle);  //writes the current puzzle to the file for possible retrieval later
void Print_Puzzle(puzzle mypuzzle);  //prints the current puzzle (including colours) and wordlist, or tells the user they haven¡¯t yet entered a puzzle
bool Find_Word(puzzle& mypuzzle, char checkword[10]);  //checks to ensure there is a puzzle, and then returns true/false depending on whether or not the word that the user enters was found. If found, you need to add the new word to the word list
bool horizontal_forward(puzzle& mypuzzle, char checkword[10]);  //checks to see if checkword can be found horizontally. If so, this routine needs to update the colours. It will return true/false depending on whether the word was found
bool vertical_downward(puzzle& mypuzzle, char checkword[10]);  //checks to see if checkword can be found vertically. If so, this routine needs to update the colours. It will return true/false depending on whether the word was found
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


//main
void main()
{
    puzzle mypuzzle;            // The overall puzzle        
    char choice,choice2;      //ask the player's choice in the menu; and the choice to re-create a puzzle
    char checkword[10];       // it stores the word to check
    bool puzzlecreated;       // check if the puzzle is created
    bool wordfound, hf, vd;   //horizontal_forward, vertical_downward
    int rows, columns;        //loop counter
    bool checkempty;          // see if the checkword is empty


    //seek random numbers
    seek_random();
    //initialize
    puzzlecreated = false;
    checkempty = true;
    initialize(mypuzzle);
    //Let's begin!
    cout << BLUE << B_WHITE << "Welcome to MC's Word Search Program!" << endl;

    do
    {
        //Get user's choice
        choice = Menu();
        switch (choice)
        {
        case'C':
            if (puzzlecreated)
            {
                cout << BOLDRED << B_BLACK << "(* WARNING!!! THIS OPTION WILL DESTROY ANY PREVIOUS PUZZLE THAT'S ALREADY EXISTED *)" << endl;
                cout << "Are you sure about your choice? (Y/N) ";
                cout << WHITE << B_BLACK;
                choice2 = toupper(_getwche());
                while (choice2 != 'Y' && choice2 != 'N')
                {
                    cout << BOLDRED << B_BLACK << "INVALID CHOICE!!! PLEASE RE-ENTER YOUR CHOICE: ";
                    cout << WHITE << B_BLACK;
                    choice2 = toupper(_getwche());
                    cout << endl;
                }//while
                if (choice2 == 'Y')
                    Create_Puzzle(mypuzzle);
                else
                    cout << YELLOW << B_BLACK << "Your puzzle has been reserved..." << endl;
            }
            else 
                Create_Puzzle(mypuzzle);
            puzzlecreated = true;
            break;
        case 'P':
            if (mypuzzle.numcolumns == 0|| mypuzzle.numrows == 0)
                cout << BOLDRED << B_BLACK << "No puzzle existed...please create a puzzle first!" << endl;
            else
                Print_Puzzle(mypuzzle);
            break;
        case 'F':
            if(puzzlecreated)
            {
                wordfound = Find_Word(mypuzzle, checkword);
                if (wordfound)
                    cout << GREEN << B_BLACK << checkword << " was found!" << endl;
                else 
                    cout << MAGENTA << B_BLACK << checkword << " was NOT found!" << endl;     
                checkempty = false;
            }
            else
                cout << BOLDRED << B_BLACK << "No puzzle existed...please create a puzzle first!" << endl;
            break;
        case 'R':
            Resume_Puzzle(mypuzzle);                 // resume a previous puzzle
            if (mypuzzle.numcolumns != 0)
                puzzlecreated = true;
            break;
        case 'W':
            Write_Puzzle(mypuzzle);                 // write the current puzzle to a file
            break;
        case 'H':
            if(puzzlecreated)
            {
                if (checkempty)
                    cout << BOLDRED <<B_BLACK<< "No word to check, please enter the word first (hint: go to Find_word)" << endl;
                else
                {
                    hf = horizontal_forward(mypuzzle, checkword);
                    if (hf)
                        cout << YELLOW << B_BLACK << checkword << " can be found horizontally" << endl;
                    else
                        cout << MAGENTA << B_BLACK << checkword << " cannot be found horizontally" << endl;
                }
            }
            else
                cout << BOLDRED << B_BLACK << "No puzzle existed...please create a puzzle first!" << endl;
            break;
        case 'V':
            if (puzzlecreated)
            {
                if(checkempty)
                    cout << BOLDRED << B_BLACK << "No word to check, please enter the word first (hint: go to Find_word)" << endl;
                else
                {
                    vd = vertical_downward(mypuzzle, checkword);
                    if (vd)
                        cout << GREEN << B_BLACK << checkword << " can be found vertically" << endl;
                    else
                        cout << MAGENTA << B_BLACK << checkword << " cannot be found vertically" << endl;
                }  
            }
            else
                cout << BOLDRED << B_BLACK << "No puzzle existed...please create a puzzle first!" << endl;
            break;
        }//switch choices
    } while (choice!= 'Q');

    //change the colour to original
    cout << WHITE << BLACK;
    
}//main

// initialize -this function initialize the puzzle to be empty
// mypuzzle - The puzzle holding the data
void initialize(puzzle& mypuzzle)
{
    int pos1, pos2;
    //set the puzzle rows&columns to zero
    mypuzzle.numcolumns = 0;
    mypuzzle.numrows = 0;
    mypuzzle.numwordsfound = 0;
    for (pos1 = 0;pos1 < 25;pos1++)
        for (pos2 = 0;pos2 < 11;pos2++)
            mypuzzle.wordlist[pos1][pos2] = -1;
}

//checks to see if checkword can be found horizontally. If so, this routine needs to update the colours. It will return true/false depending on whether the word was found
//mypuzzle -- a data structure contains the puzzle
//checkword[10] -- an array containing the word we wanna check
bool horizontal_forward(puzzle& mypuzzle, char checkword[10])
{
	int rowstart=0;                // Loop counter (row)
	bool found=false;             // set the word is initially not found
    int colstart;                // Loop counter (column)
    int pos;                    //Loop counter
    // loop until found or no more rows to check   
    while ((!found) && (rowstart < mypuzzle.numrows))
    {
        colstart = 0;
        while ((!found) && ((colstart + strlen(checkword) <= mypuzzle.numcolumns)))
        { // check if word here
            found = true;
                for (pos = 0; pos < strlen(checkword); pos++)
                    if (mypuzzle.entry[rowstart][colstart + pos].letter != checkword[pos])
                        found = false;
            if (found)
            {
                // We found the word!
                // set to found so colours will print right later
                for (pos = 0; pos < strlen(checkword); pos++)
                {
                    mypuzzle.entry[rowstart][colstart + pos].spot_status = spot_found;
                }
            } //if
            else
                colstart++;
        } // while colstart
        rowstart++;   // move to next row
    } // while rowstart
    if (found)
        return true;
    else
        return false;
}//horizontal


//checks to see if checkword can be found vertically. If so, this routine needs to update the colours. It will return true/false depending on whether the word was found
// //mypuzzle -- a data structure contains the puzzle
//checkword[10] -- an array containing the word we wanna check
bool vertical_downward(puzzle& mypuzzle, char checkword[10])
{
    int pos;                      //Loop counter
    int colstart = 0;            // Loop counter (column)
    int rowstart;                // Loop counter (row)
    bool found = false;          // set the word is initially not found
    //loop until found or no more columns to check
    while ((!found) && (colstart < mypuzzle.numcolumns))
    {
        rowstart = 0;
        while ((!found) && (rowstart + strlen(checkword) <= mypuzzle.numrows))
        {
            //check if the word is here
            found = true;
            for (pos = 0;pos < strlen(checkword);pos++)
                if (mypuzzle.entry[rowstart + pos][colstart].letter != checkword[pos])
                    found = false;
            if (found)
            {
                //We found the word!
                //set to found so we can print the letters in different colour
                for (pos = 0;pos < strlen(checkword);pos++)
                    mypuzzle.entry[rowstart + pos][colstart].spot_status = spot_found;
            }//if
            else
                rowstart++;
        }//while rowstart
        colstart++;
    }//while colstart
    if (found)
        return true;
    else
        return false;
}//vertically_down

 //creates a new puzzle by asking user for puzzle size and then giving the user the option to either enter the letters or use random letters
void Create_Puzzle(puzzle& mypuzzle)
{
    char option;          // ask the player to enter the letters or use random letters
    int pos1, pos2;      //loop counter

    // ask the user to create a puzzle
    cout << LIYELLOW << B_BLACK;
    cout << "The number of rows is:  ";
    cin >> mypuzzle.numrows;
    cout << "The number of columns is:  ";
    cin >> mypuzzle.numcolumns;
    while (mypuzzle.numrows < 1 || mypuzzle.numrows>10 || mypuzzle.numcolumns < 1 || mypuzzle.numcolumns>10)
    {
        cout <<BOLDRED<<B_BLACK<< "Enter the number from 1 to 10!!!" << endl;
        cout << "The number of rows is:  ";
        cin >> mypuzzle.numrows;
        cout << "The number of columns is:  ";
        cin >> mypuzzle.numcolumns;
    }
    cout << LIYELLOW << B_BLACK<< "Do you want to create your (O)wn puzzle or generate a (R)andom puzzle?  ";
    option = toupper(_getwche());
    while (option != 'O' && option != 'R')
    {
        cout << "INVALID OPTION! Do you want to create your (O)wn puzzle or generate a (R)andom puzzle?  (Enter O or R)  ";
        option = toupper(_getwche());
        cout << endl;
    }
    cout << endl;
    //if create your own puzzle
    if (option == 'O')
    {
        for (pos1 = 0;pos1 < mypuzzle.numrows;pos1++)
        {
            cout << YELLOW << B_BLACK << "Insert row # " << (pos1 + 1) << " : ";
            for (pos2 = 0;pos2 < mypuzzle.numcolumns;pos2++)
            {
                mypuzzle.entry[pos1][pos2].letter = toupper(_getwche());
                mypuzzle.entry[pos1][pos2].spot_status = spot_not_found;
            }
            cout << endl;
        }
        cout << endl;
    }//option='O'

    //if the option is to generate a random puzzle
    else if (option == 'R')
    {
        for (pos1 = 0;pos1 < mypuzzle.numrows;pos1++)
        {
            for (pos2 = 0;pos2 < mypuzzle.numcolumns;pos2++)
            {
                mypuzzle.entry[pos1][pos2].letter = rand()% 26 + 65;
                mypuzzle.entry[pos1][pos2].spot_status = spot_not_found;
            }         
        }
    }//option='R'
}// create_puzzle


//resume_puzzle -- resumes a previous puzzle by reading the previous puzzle in from a file
//mypuzzle -- a data structure contains the puzzle
void Resume_Puzzle(puzzle& mypuzzle)
{
    ifstream inputpuzzle;                 // file to read from
    char confirm;                        // Allows the user to confirm the loading

    // Ask the user to confirm 
    cout << "This operation will delete any current data. Continue? (Y/N) ";
    confirm = toupper(_getwche());
    cout << endl;

    //load the previous puzzle
    if (confirm == 'Y')
    {
        inputpuzzle.open("puzzle.DAT", ios::in);
        if (inputpuzzle)
        {
            inputpuzzle.read((char*)&mypuzzle, sizeof(mypuzzle));
            inputpuzzle.close();
            //print message
            cout << "The previous puzzle has been Loaded!" << endl;
        } // if
        else
        {
            cout << "ERROR! Perhaps the puzzle does not exist!" << endl;
        } // else
    }// if confirm
}


//writes the current puzzle to the file for possible retrieval later
//mypuzzle -- a data structure contains the puzzle
void Write_Puzzle(puzzle mypuzzle)
{
    ofstream outputpuzzle;

    //open file
    outputpuzzle.open("puzzle.DAT", ios::out);

    //check to see if puzzle error
    if (outputpuzzle)
    {
        //write the structure to file and close the puzzle file
        outputpuzzle.write((char*)&mypuzzle, sizeof(mypuzzle));
        outputpuzzle.close();
        cout << "The puzzle has been Saved! " << endl;
    }
    else
    {
        cout << "You might make some errors..." << endl;
    }  
}//write_puzzle

//prints the current puzzle (including colours) and wordlist, or tells the user they haven¡¯t yet entered a puzzle
//mypuzzle -- a data structure contains the puzzle
void Print_Puzzle(puzzle mypuzzle)
{
    int pos1, pos2;    //loop counter

    cout << "Your puzzle is set: " << endl;
    for (pos1 = 0;pos1 < mypuzzle.numrows;pos1++)
    {
        for (pos2 = 0;pos2 < mypuzzle.numcolumns;pos2++)
        {
            if(mypuzzle.entry[pos1][pos2].spot_status==spot_not_found)
                cout << GREEN << B_BLACK << mypuzzle.entry[pos1][pos2].letter;
            else if(mypuzzle.entry[pos1][pos2].spot_status==spot_found)
                cout << BOLDWHITE <<B_LIBLUE << mypuzzle.entry[pos1][pos2].letter;
        }
        cout <<WHITE<< B_BLACK<< endl;
    }
    if (mypuzzle.numwordsfound > 0)
    {
        cout << BOLDLIMAGENTA << B_WHITE << "Word list:  ";
        for (pos1 = 0;pos1 < mypuzzle.numwordsfound;pos1++)
        {
            cout << BOLDLIMAGENTA << B_BLACK << "(" << (pos1 + 1) << ") ";
            for (pos2 = 0;pos2 < 11;pos2++)
            {
                cout << mypuzzle.wordlist[pos1][pos2];
            }
        }
    }
    cout << endl;
}//print puzzle

//checks to ensure there is a puzzle, and then returns true/false depending on whether or not the word that the user enters was found. If found, you need to add the new word to the word list
//mypuzzle -- a data structure contains the puzzle
//checkword[10] -- an array containing the word we wanna check
bool Find_Word(puzzle& mypuzzle, char checkword[10])
{
    int pos1, pos2,i,j,k;    //loop counters

                             //enter the word
    cout << LIYELLOW<<"Enter the word you want to the find: ";

   //initialize
    i = 1;
    k = 1;
    //enter the checkword
    pos1 = 0;
    do
    {
        checkword[pos1] = toupper(_getwche());
        pos1++;
    } while (checkword[pos1 - 1] != '\r');
    checkword[pos1 - 1] = '\0';      //add eos
    cout << endl;

    //if the length of the checkword is longer than both rows and columns of the puzzle, it must not exist
    if (strlen(checkword) > mypuzzle.numrows && strlen(checkword) > mypuzzle.numcolumns)
        return false;
    else
    {
        //record the place where all characters in the puzzle is the same as the first letter in the checkword[10]
        for (pos1 = 0;pos1 < mypuzzle.numrows;pos1++)
        {
            for (pos2 = 0;pos2 < mypuzzle.numcolumns;pos2++)
            {  //match the first letter in checkword with the puzzle (locate the possible place of the word)
                if (checkword[0] == mypuzzle.entry[pos1][pos2].letter)
                {
                    while (checkword[i] == mypuzzle.entry[pos1 + k][pos2].letter || checkword[i] == mypuzzle.entry[pos1][pos2 + k].letter && k < strlen(checkword))
                    {
                        i++;
                        k++;
                    }//while 
                }//if
            }
        }//for

        //check if the loop last through the entire checkword
        //if yes, then the word is found
        if (i == strlen(checkword))
        {
            mypuzzle.numwordsfound++;
            for (pos1 = 0;pos1 < mypuzzle.numwordsfound;pos1++)
                while (mypuzzle.wordlist[pos1][0] == -1)
                    for (pos2 = 0;pos2 < strlen(checkword);pos2++)
                        mypuzzle.wordlist[pos1][pos2] = checkword[pos2];
            return true;
        }
        else
            return false;
    }
}//Find_Word


//Menu -- This function print out the menu and ask for user's choice
char Menu(void)
{
    char choice;             // the choice to call the functions (menu_driven program)

    cout << BOLDCYAN << B_BLACK;
    cout << "******************************" << endl;
    cout << "*     (C)reate Puzzle        *" << endl;
    cout << "*   (P)rint Current Puzzle   *" << endl;
    cout << "*    (H)orizontal forward    *" << endl;
    cout << "*     (V)ertical downward    *" << endl;
    cout << "*       (F)ind Word          *" << endl;
    cout << "*      (R)esume Puzzle       *" << endl;
    cout << "*      (W)rite Puzzle        *" << endl;
    cout << "*     (Q)uit the game        *" << endl;
    cout << "******************************" << endl;

    cout << WHITE << B_BLACK << "Enter your choice: ";
    choice = toupper(_getwche());
    //validate
    while (choice != 'C' && choice != 'P' && choice != 'H' && choice != 'V' && choice != 'F' && choice != 'R' && choice != 'W' && choice != 'Q')
    {
        cout << BOLDRED << B_BLACK << "INVALID CHOICE! Re-Enter your choice: ";
        choice = toupper(_getwche());
        cout << endl;
    }
    cout << endl;
    return choice;
}//menu