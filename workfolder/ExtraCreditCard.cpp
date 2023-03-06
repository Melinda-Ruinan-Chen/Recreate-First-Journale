// extraCREDITCARD - This program implements a credit card including
//    purchases, repayments, balances, and a loyalty program
#include <iostream>
#include <conio.h>
#include "CreditCardObject.h"
using namespace std;

int main(void)
{
	CreditCard* myCard;                     // Example of a single card
	CreditCard* manyCards[10];          // Example of an array of cards
	char choice;                                      // choice from menu
	int acct_num;                                   // inputted account number
	float amount;                                    // amount of limit/purchase/repayment/pts
	int howmanycards;                          // Number of cards so far
	int pos;                                             // position in the array

	// Show how 1 card would work
	myCard = new CreditCard(12345, 1000);    // creates card 123 with $1000 limit
	myCard->MakePurchase(400);             // Make $400 purchase
	myCard->MakePurchase(700);          // Try $700 purchase (no room)
	myCard->MakePayment(300);         // Make $300 Repyament
	myCard->PrintBalance();                 // Print Balance on card
	delete myCard;                                 // Delete card

	// Show how a bunch of cards might work
	howmanycards = 0;                   // So far, 0 cards
	// Loop until user quits
	do
	{
		cout << "(N)ew card, (B)uy something, (R)epayment, (P)rint balance, " <<
			"(U)se points, or e(X)it ";
		choice = toupper(_getwche());
		cout << endl;             // could/should validate, but you're quarantined - time is of the essance!

		// Based on choice, perform action
		switch (choice)
		{
		case 'N': // New Card - ask for acct # and balance 
			cout << "What is the account number? ";
			cin >> acct_num;           // Note - we should validate to see if unique, but again - no time!!!!
			cout << "What is the credit limit for account #" << acct_num << "? ";
			cin >> amount;
			// Create new account - yet again, we didn't check to make sure < 10 accounts
			manyCards[howmanycards] = new CreditCard(acct_num, amount);
			howmanycards++;               // increment number of cards
			break;
		case 'B': // Try to buy something
			cout << "what account do you want to make purchase on? ";
			cin >> acct_num;
			// Loop to see if that account exists
			pos = 0;
			while (pos < howmanycards && manyCards[pos]->Acct() != acct_num)
				pos++;
			// Check if found
			if (pos == howmanycards)
				cout << "Acct #" << acct_num << " does not exist! Nice try, scammer!" << endl;
			else
			{// ask for purchase amount
				cout << "What amount do you want to purchase on acct #" << acct_num << "? ";
				cin >> amount;
				// Attempt to make purchase
				manyCards[pos]->MakePurchase(amount);
			} // else
			break;
		case 'R': // Make a repayment
			cout << "What account do you want to make a payment on? ";
			cin >> acct_num;
			// Loop to see if that account exists
			pos = 0;
			while (pos < howmanycards && manyCards[pos]->Acct() != acct_num)
				pos++;
			// Check if found
			if (pos == howmanycards)
				cout << "Acct #" << acct_num << " does not exist! Nice try, scammer!" << endl;
			else
			{// ask for purchase amount
				cout << "What amount do you want to repay on acct #" << acct_num << "? ";
				cin >> amount;
				// Make repayment
				manyCards[pos]->MakePayment(amount);
			} // else
			break;
		case 'P': // Try to buy something
			cout << "what account do you want to print? ";
			cin >> acct_num;
			// Loop to see if that account exists
			pos = 0;
			while (pos < howmanycards && manyCards[pos]->Acct() != acct_num)
				pos++;
			// Check if found
			if (pos == howmanycards)
				cout << "Acct #" << acct_num << " does not exist! Nice try, scammer!" << endl;
			else
			{// Print The Balance
				manyCards[pos]->PrintBalance();
			} // else
			break;
		case 'U': // Use Loyalty Points
			cout << "What account do you want to use points for? ";
			cin >> acct_num;
			// Loop to see if that account exists
			pos = 0;
			while (pos < howmanycards && manyCards[pos]->Acct() != acct_num)
				pos++;
			// Check if found
			if (pos == howmanycards)
				cout << "Acct #" << acct_num << " does not exist! Nice try, scammer!" << endl;
			else
			{// use those points
				manyCards[pos]->RedeemLoyaltyPoints();
			} // else
			break;
		} // switch
	} while (choice != 'X');
	return 0;
} // main