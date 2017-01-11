/**
  ARRAYS and FUNCTIONS: SORTING and SEARCHING
  Project: Midterm Scores – Sort, Search, Average
*/

///  Lesley Huang

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int  searchList(string array[], int size, string target);
void selectionSort(string names[], int size, double average[]);
void displayWelcome();
bool readScores(int max, ifstream &inFile, double average[], string names[], int &numStudents);
double findHighest(double average[], int numStudents);
double findLowest(double average[], int numStudents);
double calculateClassAverage(double average[], int numStudents);
void writeSortedFile(double average[], string names[], int numStudents);
void printResults(double average[], int numStudents);
void displayFarewell();

int main()
{
    #define MAX_SIZE 50
    string names[MAX_SIZE];
    double average[MAX_SIZE];

    ifstream inFile;
    int numStudents = 0;

    double highScore;
    double lowScore;
    double classAverage;

    /// file validation
    inFile.open("midterm_scores.txt");

    if(!inFile){
        cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        return 1;
    }

    displayWelcome();

    ///terminates the program if the file is empty or has more than 50 students
    if (!readScores(MAX_SIZE, inFile, average, names, numStudents)) {
        return 1;
    }

    //for debugging
    /*for (int i = 0; i < numStudents; i++) {
        cout << names[i] << " " << average[i] << endl;
    }
    cout << "\n\n" << endl;*/

    selectionSort(names, numStudents, average);

    //for debugging
    /*for (int i = 0; i < numStudents; i++) {
        cout << names[i] << " " << average[i] << endl;
    }
    cout << "\n\n" << endl;*/

    writeSortedFile(average, names, numStudents);

    string targetName = " ";

    do {
        cout << "\n\nWho are you looking for? (type '123' to stop): ";
        cin >> targetName;
        int pos = searchList(names, numStudents, targetName);
        if (pos != -1) {
            cout << targetName << " has been found!" << endl;
            cout << targetName << "'s average midterm score is " << average[pos] << endl;
        } else if (pos == -1 && targetName != "123"){
            cout << targetName << " cannot be found!" << endl;
        }
    } while(targetName != "123");

    printResults(average, numStudents);

    displayFarewell();

    inFile.close();

    return 0;
}



/**
This function searches an inputted array for the target name. If name is found
within the array, the position of the target is returned; otherwise, -1 is returned
Input: array[], size, target
Output: none
Return: position of target or -1
*/
int searchList(string array[], int size, string target)
{
    int index = 0;   // Used as a subscript to search array
    int pos   = -1;  // To record position of search value: -1 means not found

    while (index < size && pos == -1)
    {
        if (array[index] == target) // If the value is found
        {
            pos = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return pos; // Return the position, or -1
}

/**
This function sorts the names array using the method of selection sort.
The array is sorted from names Z-A, and the scores associated with the
names array is sorted to correspond with the changes made to names.
Input: names[], size, average[]
Output: names[], average[]
Return: void
*/
void selectionSort(string names[], int size, double average[])
{
    for (int startScan = 0; startScan < size - 1; startScan++)
    {
        ///look for largest value
        int minIndex = startScan;
        for(int index = startScan + 1; index < size; index++)
        {
            if (names[index] > names[minIndex])
                minIndex = index;
        }
        /// swap
        string tempName = names[minIndex];
        names[minIndex] = names[startScan];
        names[startScan] = tempName;

        double tempAvg = average[minIndex];
        average[minIndex] = average[startScan];
        average[startScan] = tempAvg;
    }
    return;
}

/**
This function displays the welcome message for the Midterm
Calculator program
Input: none
Output: none
Return: void
*/
void displayWelcome() {
    cout << "Welcome to the Midterm Calculator!" << endl;
}

/**
This function reads the name from the input file and writes them to
arrays: one for names. It also calculates the average of the two midterm scores
and writes them to another array for scores. If the file is empty or the file contains
too many students, the function will return false; otherwise it returns true
Input: max, inFile, average[], names[], numStudents
Output: inFile, numStudents
Return: false if empty or exceed max; true otherwise
*/
bool readScores(int max, ifstream &inFile, double average[], string names[], int &numStudents) {
    double score1;
    double score2;

    while (numStudents < max && !inFile.eof()) {
        inFile >> names[numStudents];

        if (names[numStudents] == "") {
            cout << "This is an empty file!";
            return false;
        }

        inFile >> score1;
        inFile >> score2;
        average[numStudents] = (score1 + score2) / 2.0;
        numStudents++;
    }

    if (!inFile.eof()) {
        cout << "The file contains more than 50 students!" << endl;
        return false;
    }
    return true;
}

/**
This function finds and returns the highest number in a double array
Input: average[], numStudents
Output: none
Return: highest
*/
double findHighest(double average[], int numStudents) {
    double highest = 0.0;
    for (int i = 0; i < numStudents; i++) {
        if (highest < average[i]) {
            highest = average[i];
        }
    }
    return highest;
}

/**
This function finds and returns the lowest number in a double array
Input: average[], numStudents
Output: none
Return: lowest
*/
double findLowest(double average[], int numStudents) {
    double lowest = 100.0;
    for (int i = 0; i < numStudents; i++) {
        if (lowest > average[i]) {
            lowest = average[i];
        }
    }
    return lowest;
}

/**
This function calculates the class average by adding up all the
elements in average[] and dividing the total by numStudents
Input: average[], numStudents
Output: none
Return: class average
*/
double calculateClassAverage(double average[], int numStudents) {
    double total = 0.0;
    for (int i = 0; i < numStudents; i++) {
        total += average[i];
    }
    return total / numStudents;
}


/**
This function writes all the elements of average[] and names[] into
an output file, following the three names+score per row format. The
output file is opened and closed within this function.
Input: average[], names[], numStudents
Output: none
Return: void
*/
void writeSortedFile(double average[], string names[], int numStudents) {
    ofstream outFile;
    outFile.open("sorted.txt");

    for (int i = 0; i < numStudents; i++) {
        outFile << fixed << showpoint << setprecision(1);
        outFile << setw(5) << average[i] << " " << names[i] << "\t";
        if (i % 3 == 2) {
            outFile << "\n";
        }
    }

    outFile.close();
}

/**
This function prints out the highest score, lowest score and
class average to the screen by calling the functions findHighest,
findLowest, and calculateClassAverage
Input: average[], numStudents
Output: none
Return: void
*/
void printResults(double average[], int numStudents) {
    double highScore = findHighest(average, numStudents);
    double lowScore = findLowest(average, numStudents);
    double classAverage = calculateClassAverage(average, numStudents);

    cout << "\nThere are " << numStudents << " students in the class" << endl;
    cout << fixed << setprecision(1);
    cout << "The class midterm average is " << classAverage << endl;
    cout << "The highest midterm score is " << highScore
         << " and the lowest midterm score is " << lowScore << endl;
}

/**
This function displays the farewell message for the Midterm
Calculator program
Input: none
Output: none
Return: void
*/
void displayFarewell() {
    cout << "\n\n~.~.~.~.~Thank you for using the Midterm Calculator!~.~.~.~.~" << endl;
}

/**
OUTPUT:
Welcome to the Midterm Calculator!


Who are you looking for? (type '123' to stop): Dat
Dat has been found!
Dat's average midterm score is 70.5


Who are you looking for? (type '123' to stop): John
John cannot be found!


Who are you looking for? (type '123' to stop): Paul
Paul has been found!
Paul's average midterm score is 55.5


Who are you looking for? (type '123' to stop): 123

There are 40 students in the class
The class midterm average is 79.4
The highest midterm score is 97.0 and the lowest midterm score is 9.0


~.~.~.~.~Thank you for using the Midterm Calculator!~.~.~.~.~
*/
