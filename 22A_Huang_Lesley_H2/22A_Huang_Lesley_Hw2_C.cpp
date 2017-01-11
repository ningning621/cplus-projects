/**
   There are a number of syntax errors in the following program.
   Locate all errors, fix them, run the program and save its output.

   Lesley Huang
**/

// What is wrong with this program?

#include <iostream>

using namespace std;

int main()
{
	int x, y, z, t; // four integers

    x = 50;
    y = 10;
    z = x + y;
    t = x - y;

    cout << x << "+" << y << " = " << z << endl;
    cout << x << "-" << y << " = " << t << endl;

    return 0;

}

/*********************************************************************************
50+10 = 60
50-10 = 40


****/
