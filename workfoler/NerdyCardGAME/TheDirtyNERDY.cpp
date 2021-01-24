//dirtyNERDYONE -- This program plays a 2-player version of 31
// Melinda Chen      Comp Sci 30S
//Feb.5, 2020


#include <iostream>
#include<windows.h>
#include"colours.h"
#include<time.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

//Global identifiers
int p1c1, p1s1, p2c1, p2s1, p1c2, p1s2, p2c2, p2s2, p1c3, p1s3, p2c3, p2s3;  //3 card/suits for each player
int card, suit;
bool p1vis1, p1vis2, p1vis3, p2vis1, p2vis2, p2vis3; //tells if each card visible
int card1, suit1, card2, suit2, card3, suit3; //3 generic(general) cards

//function prototypes
void seed_random();  //seeds random numbers
void print1card(void);  //prints 1 card
void print3cardsp1();//prints all cards for player1
void print3cardsp2();  //prints all cards for player 2
float hand_value();  //value of the 3 cards
bool gameover();      //tells if the game is over yet
void deal_cards();    //deals the cards and sets initials values
int cardvalue();     //recall the value of the card


//seed_random-This function seeds the random number code
void seed_random()
{
    int i;                  // Loop counter 

   // Seed the random number generator use the timer
    srand((unsigned)time(NULL));
    for (i = 0; i < rand(); i++)
        rand();
        //printf("%d/i", rand()%54);
    
}

//Main
int main(void)
{
    int nextcard, nextsuit;  //the next card and suit to show
    char keep;      //Tells whether you keep the card (Y/N)
    int spot;       //Tells which card to replace
    int count;     //Loop counter
    int nextnextcard, nextnextsuit;  //Holds next card and suit
    float p1score, p2score;    //final scores for each player
    int card1, suit1, card2, suit2, card3, suit3; //3 generic(general) cards


    //seed random numbers
    seed_random();

    //deal the cards
    deal_cards();

    //deal the top card
    nextcard = rand() % 13 + 1;
    nextsuit = rand() % 4 + 3;  

    //Loop until someone turns over all their cards
    do
    {
        //print the cards for both players
        text_colour(f_green, b_black);
        cout << "PLAYA#1" << endl;
        print3cardsp1();
        cout << endl;

        //player1's turn
        text_colour(f_green, b_black);
        cout << "The next card is:" << endl;
        card = nextcard;
        suit = nextsuit;
        print1card();
        text_colour(f_green, b_black);
        cout << "Do you want this card?(Y/N)";
        text_colour(f_black, b_green);
        keep = toupper(_getwche());
        cout << endl;

        // If not, give them the top card option
        if (keep == 'N')
        {
            // Pick top card
            nextcard = rand() % 13 + 1;
            nextsuit = rand() % 4 + 3;
            text_colour(f_green, b_black);
            cout << "The next card is:" << endl;
            card = nextcard;
            suit = nextsuit;
            print1card();
            text_colour(f_green, b_black);
            cout << "Do you want this card? (Y/N) ";
            text_colour(f_black, b_green);
            keep = toupper(_getwche());
            cout << endl;
        } // if

        //if player wants card, figure out which to replace
        if (keep == 'Y')
        {
            text_colour(f_green, b_black);
            cout << "Which card do you want to replace?(1-3)";
            text_colour(f_black, b_green);
            cin >> spot;
            //validate the spot
            while (spot < 1 || spot>3 || (spot == 1 && p1vis1) || (spot == 2 && p1vis2) || (spot == 3 && p1vis3))
            {
                text_colour(f_red, b_black);
                cout << "INVALID CHOICE-Pick an untaken card spot from 1 to 3 only-";
                text_colour(f_black, b_red);
                cin >> spot;
            }//while
            text_colour(f_green, b_black);
            cout << "In spot#" << spot << "was the card.....";
            //Delay loop
            for (count = 1;count < 1000000000;count++);
            //Choose based on spot

            switch (spot)
            {
            case 1:card = p1c1; suit = p1s1;
                print1card();
                nextnextcard = p1c1;
                nextnextsuit = p1s1;
                p1c1 = nextcard;
                p1s1 = nextsuit;
                p1vis1 = true;
                nextcard = nextnextcard;
                nextsuit = nextnextsuit;
                break;
            case 2:card = p1c2; suit = p1s2;
                print1card();
                nextnextcard = p1c2;
                nextnextsuit = p1c2;
                p1c2 = nextcard;
                p1s2 = nextsuit;
                p1vis2 = true;
                nextcard = nextnextcard;
                nextsuit = nextnextsuit;
                break;
            case 3:card = p1c3; suit= p1s3;
                print1card();
                nextnextcard = p1c3;
                nextnextsuit = p1c3;
                p1c3 = nextcard;
                p1s3 = nextsuit;
                p1vis3 = true;
                nextcard = nextnextcard;
                nextsuit = nextnextsuit;
                break;
            }//switch   
        //player 2's turn
        //see if game over
            if (!gameover())
            {
                cout << "PLAYER#2" << endl;
                print3cardsp2();
                text_colour(f_green, b_black);
                cout << "The next card is:" << endl;
                card = nextcard;
                suit = nextsuit;
                print1card();
                text_colour(f_green, b_black);
                cout << "Do you want this card?(Y/N)";
                text_colour(f_black, b_green);
                keep = toupper(_getwche());
                cout << endl;
                //if not,give them the top card option
                if (keep == 'N')
                {
                    //Pick top card
                    nextcard = rand() % 13 + 1;
                    nextsuit = rand() % 4 + 3;
                    text_colour(f_green, b_black);
                    cout << "The next card is:" << endl;
                    card = nextcard;
                    suit = nextsuit;
                    print1card();
                    text_colour(f_green, b_black);
                    cout << "Do you want this card?(Y/N)";
                    text_colour(f_black, b_green);
                    keep = toupper(_getwche());
                    cout << endl;
                }//if
                //if player wants card, figure out which to replace
                if (keep == 'Y')
                {
                    text_colour(f_green, b_black);
                    cout << "Which card do you want replace?(1-3)";
                    text_colour(f_black, b_green);
                    cin >> spot;


                    //validate the spot
                    while (spot < 1 || spot>3 || (spot == 1 && p2vis1) || (spot == 2 && p2vis2) || (spot == 3 && p2vis3))
                    {
                        text_colour(f_red, b_black);
                        cout << "INVALID CHOICE-Pick an untaken card spot from 1 to 3 only-";
                        text_colour(f_black, b_red);
                        cin >> spot;
                    }//while

                    text_colour(f_green, b_black);
                    cout << "In spot#" << spot << "was the card.....";
                    //Delay loop
                    for (count = 1;count < 1000000000;count++);
                    //Choose based on spot
                    switch (spot)
                    {
                    case 1:card = p2c1; suit = p2s1;
                        print1card();
                        nextnextcard = p2c1;
                        nextnextsuit = p2s1;
                        p2c1 = nextcard;
                        p2s1 = nextsuit;
                        p2vis1 = true;
                        nextcard = nextnextcard;
                        nextsuit = nextnextsuit;
                        break;
                    case 2:card = p2c2; suit = p2s2;
                        print1card();
                        nextnextcard = p2c2;
                        nextnextsuit = p2c2;
                        p2c2 = nextcard;
                        p2s2 = nextsuit;
                        p2vis2 = true;
                        nextcard = nextnextcard;
                        nextsuit = nextnextsuit;
                        break;
                    case 3:card = p2c3; suit = p2s3;
                        print1card();
                        nextnextcard = p2c3;
                        nextnextsuit = p2c3;
                        p2c3 = nextcard;
                        p2s3 = nextsuit;
                        p2vis3 = true;
                        nextcard = nextnextcard;
                        nextsuit = nextnextsuit;
                        break;
                    }//switch
                }//if keep('Y')
        
            }//if gameover      
        }//if keep'Y'
       
    }//do
    
    while (!gameover());
    
       //see who won
    p1vis1 = true;
    p1vis2 = true;
    p1vis3 = true;
    p2vis1 = true;
    p2vis2 = true;
    p2vis3 = true;



        card1 = p1c1;
        suit1 = p1s1;
        card2 = p1c2;
        suit2 = p1s2;
        card3 = p1c3;
        suit3 = p1s3;
        p1score = hand_value();    
        card1 = p2c1;
        suit1 = p2s1;
        card2 = p2c2;
        suit2 = p2s2;
        card3 = p2c3;
        suit3 = p2s3;
        p2score = hand_value();
        //Print final cards and resuit
        text_colour(f_green, b_black);
        cout << "PLAYER 1" << endl;
        print3cardsp1();
        cout << "PLAYER 1 HAS" <<p1score<< "POINTS" << endl;
        cout <<endl;
        text_colour(f_green, b_black);
        cout << "PLAYER 2" << endl;
        print3cardsp2();
        cout << "PLAYER 2 HAS" <<p2score<< "POINTS" << endl;
        cout << endl;
        if (p1score < p2score)
            cout << "player 2 wins!!!" << endl;
        else
            if (p1score > p2score)
                cout << "player 1 wins!!!" << endl;
            else
                cout << "it's a tie!!!settle it with a duel at 15 paces" << endl;

        //Reset colours
        text_colour(f_gray, b_black);

    return 0;

}//main


//print1card-this function prints a single card based on the contents of global identifiers
void print1card(void)
{
    char suit_pic, card_pic;   //Character values of card/suit
    char ASCII;

    //define suit /card values
    card_pic = rand() % 13 + 1;
    suit_pic = rand() % 4 + 3;
    switch (card)
    {
    case 1: cout << "A";  break;    case 2:cout << "2"; break;      case 3:cout << "3"; break;
    case 4:cout << "4";   break;    case 5:cout << "5"; break;      case 6:cout << "6";  break;
    case 7:cout << "7";   break;    case 8:cout << "8";    break;   case 9:cout << "9";   break;
    case 10:cout << "T"; break;    case 11:cout << "J";   break;   case 12:cout << "Q";   break;
    case 13:cout << "K";  break;
    }
   //switch
    ASCII = suit_pic;
    //set the colour
    if (suit_pic == 3 || suit_pic == 4)
        text_colour(f_red, b_white);
    else
        text_colour(f_black, b_white);
    //card_pic = rand();
    //print the card
    cout << card_pic << ASCII << endl;
}//print1card


//print3cardsp1-this function prints the 3 cards that player 1 has
void print3cardsp1()
{
    //set the global values and print each card
    //check if card is visible
    if (p1vis1)
    {
        card = p1c1;
        suit = p1s1;
        print1card();
    }//if
    else
    {
        text_colour(f_yellow, b_black);
        cout << "XX" << endl;
    }

    if (p1vis2)
    {
        card = p1c2;
        suit = p1s2;
        print1card();
    }//if
    else
    {
        text_colour(f_yellow, b_black);
        cout << "XX" << endl;
    }

    if (p1vis3)
    {
        card = p1c3;
        suit = p1s3;
        print1card();
    }//if
    else
    {
        text_colour(f_yellow, b_black);
        cout << "XX" << endl;
    }
        card = p1c1;
        suit = p1s1;
        print1card();
        card = p1c2;
        suit = p1s2;
        print1card();
        card = p1c3;
        suit = p1s3;
        print1card();
    
    
}

//print3cardsp2-this function prints the 3 cards that player 2 has
void print3cardsp2()
{
    //set the global values and print each card
    if (p2vis1)
    {
        card = p2c1;
        suit = p2s1;
        print1card();
    }//if
    else
    {
        text_colour(f_yellow, b_black);
        cout << "XX" << endl;
    }

    if (p2vis2)
    {
        card = p2c2;
        suit = p2s2;
        print1card();
    }//if
    else
    {
        text_colour(f_yellow, b_black);
        cout << "XX" << endl;
    }

    if (p2vis3)
    {
        card = p2c3;
        suit = p2s3;
        print1card();
    }//if
    else
    {
        text_colour(f_yellow, b_black);
        cout << "XX" << endl;
    }
    card = p2c1;
    suit = p2s1;
    print1card();
    card = p2c2;
    suit = p2s2;
    print1card();
    card = p2c3;
    suit = p2s3;
    print1card();
}//print3cardsp1


//hand_value-this function

float hand_value()
{
    float pts_h, pts_d,pts_c,pts_s;    //points for hearts, diamonds,clubs,and spades

    //check if all 3 the same
    if (card1 == card2 && card2 == card3)
        return 30.5;
    else
    {
        //set each suit to 0
        pts_h = 0;
        pts_d = 0;
        pts_c = 0;
        pts_s = 0;
        //add the value of each card
        card = card1;
        switch (suit1)
        {
        case 3:pts_h += cardvalue(); break;
        case 4:pts_d += cardvalue(); break;
        case 5:pts_c += cardvalue(); break;
        case 6:pts_s += cardvalue(); break;
        }//switch
        card = card2;
        switch (suit2)
        {
        case 3:pts_h += cardvalue(); break;
        case 4:pts_d += cardvalue(); break;
        case 5:pts_c += cardvalue(); break;
        case 6:pts_s += cardvalue(); break;
        }//switch
        card = card3;
        switch (suit3)
        {
        case 3:pts_h += cardvalue(); break;
        case 4:pts_d += cardvalue(); break;
        case 5:pts_c += cardvalue(); break;
        case 6:pts_s += cardvalue(); break;
        }//switch


        //return the largest score 
        if (pts_h > pts_d&& pts_h > pts_c&& pts_c > pts_s)
            return pts_h;
        else
            if (pts_d > pts_c&& pts_d > pts_s)
                return pts_d;
        if (pts_c > pts_s)
            return pts_c;
        else
            return pts_s;
     

    }//else
}//handvalue

//gameover-This function returns true if either player has all 3 cards visible
bool gameover()
{
    //check if either player is done
    if ((p1vis1 && p1vis2 && p1vis3) || (p2vis1 && p2vis2 && p2vis3))
        return true;
    else
        return false;
}//gameover
//this function gives each player 3 cards and sets all the initial values
void deal_cards()
{
    //deal player 1 3 cards
    p1c1 = rand() % 13 + 1;
    p1s1 = rand() % 4 + 3;
    p1vis1 = false;
    p1c2 = rand() % 13 + 1;
    p1s2 = rand() % 4 + 3;
    p1vis2 = false;
    p1c3 = rand() % 13 + 1;
    p1s3 = rand() % 4 + 3;
    p1vis3 = false;
    p2c1 = rand() % 13 + 1;
    p2s1 = rand() % 4 + 3;
    p2vis1= false;
    p2c2 = rand() % 13 + 1;
    p2s2 = rand() % 4 + 3;
    p2vis2 = false;
    p2c3 = rand() % 13 + 1;
    p2s3 = rand() % 4 + 3;
    p2vis3 = false;
}//deal_cards

//cardvalue-this fuction returns the numeric value of the card
int cardvalue()
{
    //return value based on card
    if (card == 1)
        return 11;  //ace
    else
        if (card > 9)
            return 10;    //10,J,Q,K
        else
            return card;  //2,3,4,5,6,7,8,9

}//cardvalue
    
   



