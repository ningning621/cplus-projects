/**~*~*
   This program asks the user to enter a number, it performs some calculations,
   and displays the results. Run the program twice. First enter a multiple of 5, such as 25,
   then enter a number that is not a multiple of five, such as 7.

   What do you notice? Write your answer below.

   Lesley Huang
*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    int five_i, five;
    double five_d;

    cout << "Hi there!" << endl;
    cout << "Please input a number and then hit return" << endl;
    cin  >> number;

    five = number * 5;
    five_i = number / 5;
    five_d = number / 5.0;

    cout << "Your number is " << number << endl;
    cout << "Five times your number is " << five << endl;
    cout << "A fifth of your number is " << five_i << endl;
    cout << "A fifth of your number is " << five_d << endl;

    return 0;
}
/**~*~*
Hi there!
Please input a number and then hit return
25
Your number is 25
Five times your number is 125
A fifth of your number is 5
A fifth of your number is 5


Hi there!
Please input a number and then hit return
9
Your number is 9
Five times your number is 45
A fifth of your number is 1
A fifth of your number is 1.8


ANSWER: I noticed that if I entered a number that is a multiple of 5, the first "A fifth of your number" and the second one
display the same number, which in this case is 5. If I enter a number that is not a multiple of 5, like 9, the first "A fifth of
your number" displays the answer with the numbers after the decimal point truncated, meaning that it displays an integer.
The second "A fifth of your number" displays the decimal answer of the input/5.

This program shows how you can display a number with or without the numbers after the decimal point.

*/
