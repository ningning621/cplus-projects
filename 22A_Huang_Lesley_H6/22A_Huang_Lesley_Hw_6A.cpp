/**
   Defining and using functions in a C++ program:

       void funA(void);               // No paramaters, no return value
       void funB(char, int, double);  // PASS BY VALUE
       int  funC(void);               // return a value
       int  funD(int, int);           // receive values and a return

   This program will output the circumference and area
   of a circle with a given radius.

   Lesley Huang
*/

#include <iostream>

using namespace std;

const  double PI = 3.14;

void displayWelcome(void); ///function declaration
void displayEndMessage(void);
void printResults(double radius, double circ, double area);
/// can also be void printResults(double, double, double);

double getRadius(void);
double calcCirc(double radius);
double calcArea(double radius);

void calcCircle(double radius, double &area, double &circ);

int main()
{
    double radius;
	double area, circ;

    displayWelcome(); /// function call

    // get data
    radius = getRadius();

    // calculations
   // circ = calcCirc(radius);
   // area = calcArea(radius);
    calcCircle(radius, area, circ);
   // Output


   printResults(radius, circ, area);

   displayEndMessage();

   return 0;
}
///function definition
/**
    This function displays the welcome message.
*/
void displayWelcome(void) {
    cout << "WELCOME to the CIRCLE calculator!\n\n"
         << "This program will output the\n"
         << "\tcircumference and\n"
         << "\tarea\n"
         << "of a circle with a given radius.\n\n";
}

/**
    This function displays the end message.
*/
void displayEndMessage(void) {
    cout << "\n\n"
        << "\t ~~*~~ The END ~~*~~ \n\n"
        << "\t        ~~*~~ \n"
        << "\t      Thank you\n\tfor using my program!\n";
}

/**
    This function prints out the results for area, circumference
    and radius of a circle
*/
void printResults(double radius, double circ, double area) {
        cout << "\n\nRESULTS\n";
        cout << "\tRadius = " << radius << endl;
        cout << "\tCircumference = " << circ << endl;
        cout << "\tArea = " << area << endl;
   }

/**
    This function gets a radius of the circle from the user
*/
double getRadius(void) {
    double radius;
    do{
        cout << "Enter radius (must be > 0): ";
        cin  >> radius;
    } while (radius <= 0);

    return radius;
    }

/**
    This function calculates and returns the value of circumference
*/
double calcCirc(double radius) {
        return (2 * PI * radius);
    }

/**
    This function calculates and returns the value of the area
*/
double calcArea(double radius) {
        return (PI * radius * radius);
    }

/**
    This function calculates the area and circumference
*/
void calcCircle(double radius, double &area, double &circ) {
    circ = 2 * PI * radius;
    area = PI * radius * radius;
}

/**
OUTPUT:

WELCOME to the CIRCLE calculator!

This program will output the
        circumference and
        area
of a circle with a given radius.

Enter radius (must be > 0): 10


RESULTS
        Radius = 10
        Circumference = 62.8
        Area = 314


         ~~*~~ The END ~~*~~

                ~~*~~
              Thank you
        for using my program!
*/
