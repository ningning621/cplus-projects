/**~*~*
 The following program displays a text about the C++ programming language

 Lesley Huang
 */

#include <iostream>     // The Input/ Output stream header file is needed to perform C++ I/O
#include <ctime>

using namespace std;   // C++ uses namespaces to  organize the names in program entities
                      // In order for a program to use the entities in iostream, it must have access to the
                      // std (standard) namespace

// A C++ program consists of one or more functions. Every C++ program must have
int main ()           // a function called main: it is the starting point of the program.
{
    cout << endl;
    cout << "\t***************************************************\n";
    cout << "\t*    Bjarne Stroustrup is the designer of C++     *\n";
    cout << "\t***************************************************\n";
    cout << endl;
    cout << "\t C++ is a general purpose programming language "
         << "with a bias \n\t towards systems programming\n\t\tthat supports\n"
         << "\t\t\t 1. data abstraction\n\t\t\t 2. object-oriented programming\n\t\t\t 3. generic programming";
    cout << endl << endl;

    return 0;
}
/**~*~*

        ***************************************************
        *    Bjarne Stroustrup is the designer of C++     *
        ***************************************************

         C++ is a general purpose programming language with a bias
         towards systems programming
                that supports
                         1. data abstraction
                         2. object-oriented programming
                         3. generic programming


*/

