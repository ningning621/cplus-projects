/**
Guessing Game:

This is a simple guessing game between a computer and a player.
First, the computer prompts the player to enter his/her name then
it generates a random number between 2 and 22. The player has up
to 6 tries to guess the number. At the end, the player is asked if
he/she wants to play again. If not, the game asks for any new players.
If there is no one who wants to play, the game ends, and the results
are written to a txt file.

Lesley Huang
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    ///constants for random num generator
    const int RANDMIN = 2;
    const int RANDMAX = 22;
    const int MAXTRIES = 6;

    int randNum;
    int userNum;
    string name;
    int tries = 1;

    ///flags
    char playAgain = 'n';
    char newPlayer = 'n';
    bool numNotRight = true;

    ofstream outputFile;

    outputFile.open("GuessingGame.txt");

    ///loop for whole game
    do {
            cout << "Welcome to the guessing game!"
                 << "\nEnter your name: ";
            cin >> name;

        ///loop for just the guessing part of the game
        do {

            srand(time(0));
            randNum = rand() % (RANDMAX - RANDMIN + 1) + RANDMIN;

            tries = 1;
            numNotRight = true;

            while (tries <= MAXTRIES && numNotRight) { ///while the player guessed wrong, less than 6 times
                cout << "Guess a number between 2 and 22: ";
                cin >> userNum;

                if (userNum == randNum) {
                    cout << "\nCongratulations " << name << "! You guessed the number in "
                         << tries << " tries!" << endl;
                    numNotRight = false;
                } else {
                    tries++;
                    if (tries <= MAXTRIES) {
                        if (userNum > randNum) {
                            cout << userNum << " is too high! Try again!" << endl;
                        } else {
                            cout << userNum << " is too low! Try again!" << endl;
                        }
                    } else {
                        if (userNum > randNum) {
                            cout << userNum << " is too high!" << endl;
                        } else {
                            cout << userNum << " is too low!" << endl;
                        }
                    }
                }
            }

            if (numNotRight) {
                cout << "\nSorry " << name << ", the random number is " << randNum << endl;
                tries = 0;
            }

            ///resets playAgain
            cout << "\nDo you want to play again?\n"
                 << "Type 'Y' or 'y' for yes, anything else for no: ";
            cin >> playAgain;

            outputFile << name << " " << randNum << " " << tries << endl;

        } while (playAgain == 'Y' || playAgain == 'y');

        ///resets newPlayer
        cout << "\nNew player? Type 'Y' or 'y' for yes, anything else for no: ";
        cin >> newPlayer;

    } while (newPlayer == 'Y' || newPlayer == 'y');

    outputFile.close();

    cout << "\nThank you for playing!";
    return 0;
}

/**
OUTPUT:
Welcome to the guessing game!
Enter your name: Lesley
Guess a number between 2 and 22: 5
5 is too high! Try again!
Guess a number between 2 and 22: 3
3 is too high! Try again!
Guess a number between 2 and 22: 2

Congratulations Lesley! You guessed the number in 3 tries!

Do you want to play again?
Type 'Y' or 'y' for yes, anything else for no: y
Guess a number between 2 and 22: 15
15 is too high! Try again!
Guess a number between 2 and 22: 10
10 is too high! Try again!
Guess a number between 2 and 22: 3
3 is too low! Try again!
Guess a number between 2 and 22: 6
6 is too low! Try again!
Guess a number between 2 and 22: 9
9 is too high! Try again!
Guess a number between 2 and 22: 8
8 is too high!

Sorry Lesley, the random number is 7

Do you want to play again?
Type 'Y' or 'y' for yes, anything else for no: n

New player? Type 'Y' or 'y' for yes, anything else for no: y
Welcome to the guessing game!
Enter your name: Mark
Guess a number between 2 and 22: 4
4 is too low! Try again!
Guess a number between 2 and 22: 18

Congratulations Mark! You guessed the number in 2 tries!

Do you want to play again?
Type 'Y' or 'y' for yes, anything else for no: n

New player? Type 'Y' or 'y' for yes, anything else for no: n

Thank you for playing!
*/
