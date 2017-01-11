/**
PART A
Internet Service Provider


Lesley Huang
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string name;
    char package;
    int hours;

    const double PRICEA_INITIAL = 9.95;
    const double PRICEA_ADDITIONAL = 2.00;
    const double PRICEB_INITIAL = 14.95;
    const double PRICEB_ADDITIONAL = 1.00;
    const double PRICEC_INITIAL = 19.95;

    cout << "ABC Internet Service Provider" << endl;
    cout << "=============================" << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Package: ";
    cin.get(package);

    if (package < 65 || package > 67) {
        cout << "Sorry, we don't have that type of package.";

    } else {
        if (package == 67) {
            cout << "\n" << name << endl;
            cout << "Package " << package << ":" << endl;
            cout << "\tFor $19.95 per month unlimited access is provided." << endl;
            cout << "\nTotal:\t" << PRICEC_INITIAL;

        } else {
            cout << "Hours: ";
            cin >> hours;

            if (hours > 744) {
            cout << "Sorry, you have exceeded the maximum hours.";
            } else {
                cout << "\n" << name << endl;
                cout << "Package " << package << ":" << endl;

                switch (package) {

                    case 'A':
                        cout << "\tFor $9.95 per month 10 hours of access are provided." << endl;
                        cout << "\tAdditional hours are  $2.00 per hour." << endl;
                        cout << "Hours: " << hours << endl;
                        if (hours <= 10) {
                            cout << "\t" << hours << "hours:\t" << PRICEA_INITIAL << endl;
                            cout << "\nTotal:\t" << PRICEA_INITIAL;
                        } else {
                            cout << setw(16) << "10hours:" << setw(9) << PRICEA_INITIAL << endl;
                            cout << setw(10) << (hours - 10) << "hours:" << setw(9) << fixed << setprecision(2)
                                    << PRICEA_ADDITIONAL << endl;
                            cout << "\nTotal:" << setw(19) << PRICEA_INITIAL + (hours - 10)*PRICEA_ADDITIONAL;
                        }
                        break;

                    case 'B':
                        cout << "\tFor $14.95 per month 20 hours of access are provided." << endl;
                        cout << "\tAdditional hours are $1.00 per hour." << endl;
                        cout << "Hours: " << hours << endl;
                        if (hours <= 20) {
                            cout << "\t" << hours << "hours:\t" << PRICEB_INITIAL << endl;
                            cout << "\nTotal:" << setw(7) << PRICEB_INITIAL;
                        } else {
                            cout << setw(16) << "20hours:" << setw(9) << PRICEB_INITIAL << endl;
                            cout << setw(10) << hours - 20 << "hours:" << setw(9) << fixed << setprecision(2)
                                    << PRICEB_ADDITIONAL << endl;
                            cout << "\nTotal:" << setw(19) << PRICEB_INITIAL + (hours - 20)*PRICEB_ADDITIONAL;
                        }
                        break;
                }
            }
        }
    }
    return 0;
}
/***********************************************************************
TEST CASE 1:
ABC Internet Service Provider
=============================
Name: Joe Peterson
Package: A
Hours: 14

Joe Peterson
Package A:
        For $9.95 per month 10 hours of access are provided.
        Additional hours are  $2.00 per hour.
Hours: 14
        10hours:     9.95
         4hours:     2.00

Total:              17.95


TEST CASE 2:
ABC Internet Service Provider
=============================
Name: Monica Smith
Package: A
Hours: 8

Monica Smith
Package A:
        For $9.95 per month 10 hours of access are provided.
        Additional hours are  $2.00 per hour.
Hours: 8
        8hours: 9.95

Total:  9.95


TEST CASE 3:
ABC Internet Service Provider
=============================
Name: Victor Nguyen
Package: B
Hours: 78

Victor Nguyen
Package B:
        For $14.95 per month 20 hours of access are provided.
        Additional hours are $1.00 per hour.
Hours: 78
        20hours:    14.95
        58hours:     1.00

Total:              72.95


TEST CASE 4:
ABC Internet Service Provider
=============================
Name: Sandy Oh
Package: B
Hours: 18

Sandy Oh
Package B:
        For $14.95 per month 20 hours of access are provided.
        Additional hours are $1.00 per hour.
Hours: 18
        18hours:        14.95

Total:  14.95


TEST CASE 5:
ABC Internet Service Provider
=============================
Name: Oliver Platt
Package: C

Oliver Platt
Package C:
        For $19.95 per month unlimited access is provided.

Total:  19.95


TEST CASE 6:
ABC Internet Service Provider
=============================
Name: Nora Jones
Package: D
Sorry, we don't have that type of package.


TEST CASE 7:
ABC Internet Service Provider
=============================
Name: Paul Duncan
Package: A
Hours: 789
Sorry, you have exceeded the maximum hours.


*/


