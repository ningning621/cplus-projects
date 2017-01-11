/*
  A simplified version of "The Deal or No Deal" game.

  Lesley Huang
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Function prototypes
void displayWelcome();
void displayFarewell();
int getValidNum();
void shuffleCases(int a[]);
void playGame(ofstream &, int a[]);

int main()
{
    displayWelcome();

    int cases[10] = {0, 0, 0, 1, 10, 100, 1000, 10000, 100000, 1000000};
    ofstream outFile;
    outFile.open("players.txt");
    outFile << "Player" << "\tFinal Amount" << endl;
    char morePlayers = 'y';

    srand(time(0));

    do {
       shuffleCases(cases);

       ///used for debugging purposes
      /* for (int i = 0; i < 10; i++) {
        cout << cases[i] << " ";
       }*/

       playGame(outFile, cases);
       cout << "Are there more players? (y/n): ";
       cin >> morePlayers;
    }while(morePlayers == 'y');

    outFile.close();
    displayFarewell();


   return 0;
}

/**
This function displays the welcome message for the Deal or
No Deal game.
*/
void displayWelcome() {

    cout << "Welcome to Deal or No Deal!\n" << endl;
    cout << "There are 7 briefcases with the values $1, $10, $100, $1000, $10000,"
         << "\n100000, 1000000, respectively, and three empty cases."
         << "\n\nEach value is randomly assigned to a briefcase (0-9). You get three "
         << "\nchances to pick a briefcase. Each time that you pick one, you can decide"
         << "\nwhether to keep the case (\"Deal\") or pick another one (\"No Deal\")" << endl;
    cout << "\nAfter your third try, the briefcase that was opened last is your final amount!" << endl;
    cout << "\nGood luck and choose wisely!" << endl;
    cout << "\n~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~\n" << endl;
}

/**
This function displays the farewell message for the
Deal or No Deal game.
*/
void displayFarewell() {
    cout << "\n~.~Game Over! Thanks for playing~.~" << endl;
}

/**
This function checks to see if the user-inputted number is within the range
low to high. If not, the function prompts the user to enter another number.
It returns the valid number.
*/
int getValidNum(int low, int high)
{
    int n;
    bool success;
    do
    {
        cout << "Please enter a briefcase's number (" << low << " to " << high << "): ";
        success = cin >> n;
        cin.clear();          // to clear the error flag
        cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
    }while(!success || n < low || n > high);

    return n;
}

/**
This function shuffles the contents of the briefcase by using
the random number function.
*/
void shuffleCases(int a[]) {

    for (int i = 0; i < 10; i++) {
        int r = rand() % 10;
        int temp = a[r];
        a[r] = a[i];
        a[i] = temp;
    }
}

/**
This function runs the Deal or No Deal game. It prompts the user to
enter a name and then a valid briefcase number. The user gets three
tries, maximum, to pick a briefcase. After each pick, the user is
asked "deal or no "no deal". If the user picks "deal," the game ends;
if "no deal" the game continues until the 3 tries are over. The results
printed to the screen and the output file.
*/
void playGame(ofstream &outFile, int a[]) {
    string name;
    char playAgain = 'n';
    int tries = 0;
    int n;
    cout << "Enter name: ";
    cin >> name;
    do {
        n = getValidNum(0, 9);
        cout << "\nYou picked case " << n << endl;
        cout << "The value is " << a[n] << endl;

        if (tries < 2) {
            cout << "Deal or no deal? (Type 'y' for deal; 'n' for no deal): ";
            cin >> playAgain;
        }

        tries++;
    } while(playAgain == 'n' && tries < 3);

    cout << "\n" << name << ", your final amount is " << a[n] << endl;

    outFile << name << "\t" << a[n] << endl;

    cout << "\nGame over for...." << name << endl;
}

/**
OUTPUT:
Welcome to Deal or No Deal!

There are 7 briefcases with the values $1, $10, $100, $1000, $10000,
100000, 1000000, respectively, and three empty cases.

Each value is randomly assigned to a briefcase (0-9). You get three
chances to pick a briefcase. Each time that you pick one, you can decide
whether to keep the case ("Deal") or pick another one ("No Deal")

After your third try, the briefcase that was opened last is your final amount!

Good luck and choose wisely!

~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~

Enter name: Alice
Please enter a briefcase's number (0 to 9): 2

You picked case 2
The value is 0
Deal or no deal? (Type 'y' for deal; 'n' for no deal): n
Please enter a briefcase's number (0 to 9): 5

You picked case 5
The value is 0
Deal or no deal? (Type 'y' for deal; 'n' for no deal): n
Please enter a briefcase's number (0 to 9): 7

You picked case 7
The value is 1000000

Alice, your final amount is 1000000

Game over for....Alice
Are there more players? (y/n): y
Enter name: Ryan
Please enter a briefcase's number (0 to 9): 2

You picked case 2
The value is 10
Deal or no deal? (Type 'y' for deal; 'n' for no deal): n
Please enter a briefcase's number (0 to 9): 8

You picked case 8
The value is 100000
Deal or no deal? (Type 'y' for deal; 'n' for no deal): y

Ryan, your final amount is 100000

Game over for....Ryan
Are there more players? (y/n): y
Enter name: John
Please enter a briefcase's number (0 to 9): 1

You picked case 1
The value is 0
Deal or no deal? (Type 'y' for deal; 'n' for no deal): y

John, your final amount is 0

Game over for....John
Are there more players? (y/n): n

~.~Game Over! Thanks for playing~.~
*/


