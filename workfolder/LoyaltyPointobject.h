// LoyaltyPointsobject - this header contains the definitions for
//           the Loyalty Scheme object
#include <iostream>
using namespace std;

class LoyaltyScheme
{
public:
	LoyaltyScheme();         // Constructor
	~LoyaltyScheme();        // Destructor
	void EarnPointsOnAmount(float amountSpent);   // Earn 1 pt/$10 spent
	void RedeemPoints(int points); // Redeems some points
	int GetPoints();           // Wrapper function to return points
private:
	int totalPoints;        // Points in Loyalty Scheme
};

// LoyaltyScheme - This is the constructor for the Loyalty Scheme
LoyaltyScheme::LoyaltyScheme()
{
	// Print message
	cout << "Congrats! This account now qualifies for a Loyalty Scheme" << endl;
	totalPoints = 0;    // Set start points to 0
} // LoyaltyScheme

// ~LoyaltyScheme - This is the destructor for the Loyalty Scheme
LoyaltyScheme::~LoyaltyScheme()
{
	// Print message
	cout << "This Loyalty Scheme is now closed." << endl;
} // ~LoyaltyScheme

// EarnPointsOnAmount - This method adds loyalty points based on purchase
// amountSpent - how much $$$$ was spent in this transaction
void LoyaltyScheme::EarnPointsOnAmount(float amountSpent)
{
	int points;           // points earned on this amount

	// Calculate points earned and add to total
	points = (int)amountSpent / 10;
	totalPoints += points;
	cout << "You earned " << points << " Loyalty Points!!!" << endl;
} // EarnPointsOnAmount

// RedeemPoints - This method allows Loyalty points to be redeemed
// points - how many points are being redeemed
void LoyaltyScheme::RedeemPoints(int points)
{
	// Check to see if thtey have enough points
	if (points <= totalPoints)
	{	// If so, redeem
		cout << "You have redeemed " << points << " points ";
		totalPoints -= points;
		cout << " so oyur balance is now " << totalPoints << endl;
	} // if
	else
		// Not enough points
		cout << "You don't have enough - you only have " <<
		totalPoints << " points!" << endl;
} // RedeemPoints

// GetPoints - This is a wrapper that returns the number of points
int LoyaltyScheme::GetPoints()
{
	// return the points
	return totalPoints;
}
