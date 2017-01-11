/**
 PART B


 First rewrite the code using proper indentation and spacing, then, find and fix the errors.
 Run the program twice and save each output as a comment at the end
 of the source file.

 The program generates a random number within the range 1 to 8 (inclusive)
 and asks the user to guess it in one or two tries.

Lesley Huang

*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int random_num;
    int num;
    srand(time(0));

    random_num = rand() % 8 + 1;
    cout << "Enter a number: ";
    cin >> num;

    if (num == random_num)  {
        cout << "Congratulations! You did it!\n\n";
    } else {
        if (num < random_num) {
            cout << "Your guess is low!";
        } else {
            cout << "Your guess is high!";
        }
        cout << " Try again!\n\n";
        cout << "Enter a number: ";
        cin >> num;

        if (num == random_num) {
            cout << "Congratulations! You did it!\n\n";
        } else {
            cout << "Sorry, the number was " << random_num;
        }
    }

    return 0;
}

/*********************************************************************************
FIRST OUTPUT:
Enter a number: 3
Your guess is low! Try again!

Enter a number: 6
Congratulations! You did it!
*/


/*********************************************************************************
SECOND OUTPUT:
Enter a number: 2
Your guess is low! Try again!

Enter a number: 6
Sorry, the number was 8
*/
