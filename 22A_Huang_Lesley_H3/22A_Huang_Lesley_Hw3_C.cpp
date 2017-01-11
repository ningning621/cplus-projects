/**
  Part C

  Find and fix the errors
  Run the program once and save the output as a comment at the end
  of the source file.

  Lesley Huang
*/

#include <iostream>
using namespace std;

int main()
{
   int begInv;
   int sold;
   int store1, store2, store3;

   // Get the beginning inventory for all the stores.
   cout << "One week ago, 3 new widget stores opened \n";
   cout << "at the same time with the same beginning \n";
   cout << "inventory. What was the beginning inventory? ";
   cin >> begInv;

   // Set each store's inventory.
   store1 = store2 = store3 = begInv;

   // Get the number of widgets sold at store 1.
   cout << "How many widgets has store 1 sold? ";
   cin >> sold;
   store1 -= sold; // Adjust store 1's inventory.

   // Get the number of widgets sold at store 2.
   cout << "How many widgets has store 2 sold? ";
   cin >> sold;
   store2 -= sold; // Adjust store 2's inventory.

   // Get the number of widgets sold at store 3.
   cout << "How many widgets has store 3 sold? ";
   cin >> sold;
   store3 -= sold; // Adjust store 3's inventory.

   // Display each store's current inventory.
   cout << "\nThe current inventory of each store:\n";
   cout << "Store 1: "  << store1 << "\n";
   cout << "Store 2: "  << store2 << "\n";
   cout << "Store 3: "  << store3 << "\n";
   return 0;
}
/***********************************************************************
One week ago, 3 new widget stores opened
at the same time with the same beginning
inventory. What was the beginning inventory? 500
How many widgets has store 1 sold? 320
How many widgets has store 2 sold? 100
How many widgets has store 3 sold? 20

The current inventory of each store:
Store 1: 180
Store 2: 400
Store 3: 480


 */
