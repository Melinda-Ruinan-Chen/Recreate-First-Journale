//  BaseExponent   
//Melinda Chen  ---Comptuer science 30S
//2020-02-14   Happy Valentince Day!

#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//prototypes
float power(double base, double exponent);


//main
int main(void)
{
	double  exponent1, exponent2, exponent3;   //set uo base and exponent
	float answer1,answer2,answer3;            //set up the result
	int i;                //counter
	double sum1;     //the sum for two expressions
	double base1, base2, base3;  
	float result2, result3;
	

	//set the initial value
	answer1 = 1;
	answer2 = 1;
	answer3 = 1;
	sum1 = 0;
	for (i = 1;i <= 3;i++)
	{//Enter the base	
		cout << "please enter the base" << endl;
		cin >> base1;

		//Enter the exponent
		cout << "please enter the exponent" << endl;
		cin >> exponent1;

		float answer1 = power(base1, exponent1);

		//print out the answer
		cout << "the result is" << answer1 << "  ";
	}

	//calculate the sum of two expressions
	//ask the user to enter values

	cout << "Enter the first base value:" << endl;
	cin >> base2;
	cout << "enter the first exponent value" << endl;
	cin >> exponent2;
	cout << "Enter the second base value:" << endl;
	cin >> base3;
	cout << "enter the second exponent value" << endl;
	cin >> exponent3;

	result2 = pow(base2, exponent2);
	result3 = pow(base3, exponent3);
	//caculate the sum of two sets of results
	sum1 = pow(base2, exponent2) + pow(base3, exponent3);
	//print out the answer
	answer2 = sum1;
	cout << "the sum of two sets of number is:" << answer2 << endl;

	//Calculate the power of one expression to another expression
	
	
	//put base3^power2 into a variable
	answer3 *= pow(result2, result3);
	

	//print out the answer
	cout << "the second result is:" << answer3 << endl;

	return 0;

}//main


float power(double base, double exponent)
{
	int r;  //counter
	double answer1;

	answer1 = 1;

	//check the base
	if (base == 0)   //any exponent of 0 equals to 0
	{
		return answer1;
	}//if
	//Check if the exponent is positive or negative
	if (exponent > 0)
	{
		for (r = 1; r <= exponent; r++)
		{
			answer1 *= base;
		}//for
	}//if
	else
	{
		for (r = -1; r >= exponent; r--)
		{
			answer1 *= 1/base;
		}//for
	}//else

	return answer1;
}//power
	




