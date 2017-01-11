/**
 PART B

 Write a program that will do the following steps (pseudo-code):

 1.	Display a welcome message and a title, such as “Working with random numbers and simple mathematical functions”. Then display the name of the library functions you are going to use in this program and the header files needed for each function.

 2.	Generate 4 random numbers between 5 and 25 inclusive
 // r1, r2, r3, r4

 3.	Generate one random number between 2 and 8 inclusive, name it x

 4.	Calculate pwr as  r1 to the power of x

 5.	Calculate the average of the 4 random numbers

 6.	Calculate the square root of the average

 7.	Calculate the geometric mean of the random numbers (the product of these numbers to the power of 1 / 4)

 8.	Display a line of asterisks, such as “********************\n”

 9.	Display the following (with description):
 •	 r1, r2, r3, r4
 •	 r1, x, and pwr
 •	average of the 4 numbers with 2 digits after the decimal point
 •	square root of the average with 4 digits after the decimal point
 •	geometric mean of the random numbers with 4 digits after the decimal point

 Note: Please define and use as many variables you consider useful.

 Run the program twice.



Lesley Huang

*/
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    cout << "Working with random numbers and simple mathematical functions" << endl;
    cout << "The library functions that I will use in this program are: ";
    cout << "rand() & srand(), pow(), setprecision(), time()" << endl;
    cout << "Their respective headers are: ";
    cout << "<cstdlib>, <math.h>, <iomanip>, <time.h>" << endl;

    srand(time(NULL));  // rand() was producing the same string of random numbers. after doing some research, I learned that using srand() + time() will
                        // prevent the same string of pseudo-random numbers from appearing. I'm not quite sure if using srand() is the purpose of this
                        // assignment; however, I used srand() to provide actual random numbers.
    int r1, r2, r3, r4;
    r1 = rand() % 21 + 5;
    r2 = rand() % 21 + 5;
    r3 = rand() % 21 + 5;
    r4 = rand() % 21 + 5;

    int x = rand() % 7 + 2;
    double pwr = pow(r1,x);
    double avg = (r1 + r2 + r3 + r4) / 4.0;
    double squareRoot = pow(avg, 0.5);
    double geoMean = pow(r1 * r2 * r3 * r4, 0.25);

    cout << "\n****************************\n\n";
    cout << "The four random numbers from 5 to 25 (inclusive) are " << r1 << ", " << r2 << ", " << r3 << ", and " << r4 << endl;
    cout << "r1 is " << r1 << " and x is " << x << ", so pwr is equal to " <<  pwr << endl;
    cout << fixed << setprecision(2);
    cout << "The average of the four random numbers is " << avg << endl;
    cout << fixed << setprecision(4);
    cout << "The square root of the average is " << squareRoot << endl;
    cout << "The geometric mean of the average is " << geoMean << endl;

   return 0;
}
/*********************************************************************************
Working with random numbers and simple mathematical functions
The library functions that I will use in this program are: rand() & srand(), pow(), setprecision(), time()
Their respective headers are: <cstdlib>, <math.h>, <iomanip>, <time.h>

****************************

The four random numbers from 5 to 25 (inclusive) are 13, 15, 24, and 23
r1 is 13 and x is 7, so pwr is equal to 6.27485e+007
The average of the four random numbers is 18.75
The square root of the average is 4.3301
The geometric mean of the average is 18.1131
*/


/*********************************************************************************
Working with random numbers and simple mathematical functions
The library functions that I will use in this program are: rand() & srand(), pow(), setprecision(), time()
Their respective headers are: <cstdlib>, <math.h>, <iomanip>, <time.h>

****************************

The four random numbers from 5 to 25 (inclusive) are 19, 13, 25, and 22
r1 is 19 and x is 5, so pwr is equal to 2.4761e+006
The average of the four random numbers is 19.75
The square root of the average is 4.4441
The geometric mean of the average is 19.1984
*/
