/**
   Constants, variables and arithmetic operators

   Stock Commission

   Kathryn bought 600 shares of stock at a price of $21.77 per share.
   She must pay her stock broker a 2 percent commission for the transaction.
   Write a program that calculates and displays the following:
        1. The total amount paid for the stock alone (without the commission)
        2. The amount of commission
        3. The total amount paid (for the stock and the commission)

   Lesley Huang
*/
#include <iostream>

using namespace std;

int main()
{
    const double SHARE_PRICE = 21.77;
    const int COMMISSION = 2;   // 2 percent commission

	int noShares = 600;         // number of shares
    double total;               // The total amount paid for the stock alone
    double commission;          // The amount of commission
    double finalTotal;          // The total amount paid (for the stock and the commission)

    // Calculations Section
    total = noShares * SHARE_PRICE;

    commission = (COMMISSION / 100.0) * total;

    finalTotal = total + commission;

    // Display Results Section
    // Fill in the code for the cout statement that will output (with description)
    // a welcome message
    cout << "Hello! Kathryn bought 600 shares of stock at a price of $21.77 per share." << endl;
    cout << "She must pay her stock broker a 2 percent commission for the transaction." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the number of shares
    cout << "Kathryn has " << noShares << " shares." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the price per share
    cout << "The price per share is $" << SHARE_PRICE << "." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // one or two blank lines
    cout << "\n" << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the commission percent
    cout << "The commission percent is " << COMMISSION << "%." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the total amount paid for the stock alone
    cout << "The total amount paid for the stock alone is $" << total << "." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the amount of commission
    cout << "The amount of commission is $" << commission << "." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the total amount paid (for the stock and the commission)
    cout << "The total amount paid for the stock and the commission is $" << finalTotal << "." << endl;

    // Fill in the code for the cout statement that will output (with description)
    // an "end of program" message (of your choice)
    cout << "Have a nice day!";
    return 0;
}
/*********************************************************************************
Hello! Kathryn bought 600 shares of stock at a price of $21.77 per share.
She must pay her stock broker a 2 percent commission for the transaction.
Kathryn has 600 shares.
The price per share is $21.77.


The commission percent is 2%.
The total amount paid for the stock alone is $13062.
The amount of commission is $261.24.
The total amount paid for the stock and the commission is $13323.2.
Have a nice day!


*/
