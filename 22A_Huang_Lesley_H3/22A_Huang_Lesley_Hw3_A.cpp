/**
 PART A

 There are three seating categories at a stadium. For a softball game, Class A seats cost $15.50, Class B seats cost $12.99, and Class C seats costs $9.25. Write a program that asks how many tickets for each class of seats were sold, then displays the amount in fixed-point notation, with two decimals of precision, and be sure the decimal point is always displayed. It also calculates and displays the amount paid for all tickets. Define and use named constants in your program.
 Output should be aligned as shown below (notice that the decimal points are all aligned).

 ===========================
 Softball Game Ticket Prices
 ===========================
      Class A:  15.50
      Class B:  12.99
      Class C:   9.25
 ===========================

 Please enter the number of tickets:
      Class A: 3 //⇐ this is the user’s input
      Class B: 10
      Class C: 2

 Total Class A:    46.50
 Total Class B:   129.90
 Total Class C:    18.50
               =========
         Total:   194.90

 Run the program twice: first time enter the data above, the second time enter the following data:
 35 Class A tickets sold, 53 Class B tickets sold, and 100 Class C tickets sold.


Lesley Huang
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double PRICEA = 15.50;
    const double PRICEB = 12.99;
    const double PRICEC = 9.25;
    int numOfTicketsA, numOfTicketsB, numOfTicketsC;

    cout << " ===========================\n" << " Softball Game Ticket Prices\n" << " ===========================" << endl;
    cout << fixed << setprecision(2);
    cout << "      Class A:" << setw(7) << PRICEA << endl;
    cout << "      Class B:" << setw(7) << PRICEB << endl;
    cout << "      Class C:" << setw(7) << PRICEC << endl;
    cout << " ===========================\n\n";

    cout << " Please enter the number of tickets:" << endl;
    cout << "      Class A: ";
    cin >> numOfTicketsA;
    cout << "      Class B: ";
    cin >> numOfTicketsB;
    cout << "      Class C: ";
    cin >> numOfTicketsC;

    cout << "\n Total Class A:" << setw(9) << numOfTicketsA * PRICEA << endl;
    cout << " Total Class B:" << setw(9) << numOfTicketsB * PRICEB << endl;
    cout << " Total Class C:" << setw(9) << numOfTicketsC * PRICEC << endl;
    cout << setw(24) << "=========" << endl;
    cout << setw(15) << "Total:" << setw(9) << numOfTicketsA * PRICEA + numOfTicketsB * PRICEB + numOfTicketsC * PRICEC << endl;


    return 0;
}
/***********************************************************************
 ===========================
 Softball Game Ticket Prices
 ===========================
      Class A:  15.50
      Class B:  12.99
      Class C:   9.25
 ===========================

 Please enter the number of tickets:
      Class A: 3
      Class B: 10
      Class C: 2

 Total Class A:    46.50
 Total Class B:   129.90
 Total Class C:    18.50
               =========
         Total:   194.90


*/


/***********************************************************************
 ===========================
 Softball Game Ticket Prices
 ===========================
      Class A:  15.50
      Class B:  12.99
      Class C:   9.25
 ===========================

 Please enter the number of tickets:
      Class A: 35
      Class B: 53
      Class C: 100

 Total Class A:   542.50
 Total Class B:   688.47
 Total Class C:   925.00
               =========
         Total:  2155.97

*/
