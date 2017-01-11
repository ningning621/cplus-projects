/**~*~*
  Project: Star Search
  A particular talent competition has five judges, each of whom awards a score between
  0 and 10 to each performer. Fractional scores, such as 8.3, are allowed.
  A performer's final score is determined by dropping the highest and the lowest score
  received, then averaging the three remaining scores. Write a program that calculates
  the score of each performer and determines the winner.
  Assume there's only one winner!

  Input: Read data from an input file named performers.txt.
  Output: Write the number of participants, the name of the winner and winner’s score to
  the screen. Write to a file named results.txt the names of the performers and their
  final score.

  Lesley Huang

*~**/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void welcome(void);
bool getScores(ifstream &, string &, double &, double &, double &, double &, double &);
double calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);
void writeScore(ofstream &, double, string);
void farewell(void);

int main()
{
    int numPlayers = 0;

   string winnerName;
   double winnerScore = 0.0;

   string tempName;
   double tempScore1 = 0.0;
   double tempScore2 = 0.0;
   double tempScore3 = 0.0;
   double tempScore4 = 0.0;
   double tempScore5 = 0.0;
   double tempTotalScore = 0.0;

   ofstream outFile;
   ifstream inFile;

   welcome();

   // open the input file + validation
   inFile.open("performers.txt");

    if(!inFile){
        cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        return 1;
    }

   // open the output file + validation
    outFile.open("results.txt");

    if(!outFile){
        cout << "\a\a~*~ ERROR opening the input file! ~*~\n";
        return 1;
    }

   while (getScores(inFile, tempName, tempScore1, tempScore2, tempScore3, tempScore4, tempScore5)){
      tempTotalScore = calcScore(tempScore1, tempScore2, tempScore3, tempScore4, tempScore5);
      // determine the winner so far
      if (winnerScore < tempTotalScore) {
        winnerName = tempName;
        winnerScore = tempTotalScore;
      }
    //  cout << "\nThe winner's name is " << winnerName << endl;
    //  cout << "The winner's score is " << winnerScore << endl;
      numPlayers++;
      writeScore(outFile, tempTotalScore, tempName);
   }
   // close the input file
   inFile.close();
   // close the output file
   outFile.close();

   // display the number of participants
   cout << "\nThe number of performers is " << numPlayers << endl;
   // display the winner and the winner's score
   cout << fixed << setprecision(2);
   cout << "\nThe winner is " << winnerName << " and the winning score is " << winnerScore << endl;
   farewell();
   return 0;
}

/**
This function displays the welcome message
for the Star Search program.
*/
void welcome(void) {
    cout << "Welcome to Star Search, a program that calculates the " << endl;
    cout << "scores of each performer and determines the winner!" << endl;
}

/**
This function retrieves the name of the performer and the
scores from the inputFile and assign them to local variables in
the main function. It will return false if there is nothing more
to read in the input file.
*/
bool getScores(ifstream &inFile, string &n, double &num1, double &num2, double &num3, double &num4, double &num5) {
    if (inFile) {
        inFile >> n >> num1 >> num2 >> num3 >> num4 >> num5;

        if (inFile.eof()) {
            return false;

        } else {
/// debug statements
/**        cout << "\nThis is the getScores function" << endl;
        cout << "name: " << n << endl;
        cout << "scores are " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl; **/
        return true;
        }
    }
}

/**
This function calculates the performer's score by removing the
highest and lowest score from the total score before averaging
the remaining three scores to get the final score of the
performer. The final score is returned.
*/
double calcScore(double num1, double num2, double num3, double num4, double num5){
//    cout << "\nThis is the calcScore function" << endl;

    double min = findLowest(num1, num2, num3, num4, num5);
    double max = findHighest(num1, num2, num3, num4, num5);

    double total = (num1 + num2 + num3 + num4 + num5 - min - max) / 3.0;
/// debug statements
///    cout << "The total is " << total << endl;
    return total;
}

/**
This function finds and returns the lowest score
out of the set of five.
*/
double findLowest(double v, double w, double x, double y, double z){
    double min = v;
    if (min > w) {
        min = w;
    }
    if (min > x) {
        min = x;
    }
    if (min > y) {
        min = y;
    }
    if (min > z) {
        min = z;
    }
/// debug statements
//     cout << "\n\tThis is the findLowest function" << endl;
///    cout << "The lowest score is " << min << endl;
    return min;
}

/**
This function finds and returns the highest score
out of a set of five.
*/
double findHighest(double v, double w, double x, double y, double z){
    double max = v;
    if (max < w) {
        max = w;
    }
    if (max < x) {
        max = x;
    }
    if (max < y) {
        max = y;
    }
    if (max < z) {
        max = z;
    }
/// debug statements
//     cout << "\n\tThis is the findHighest function" << endl;
///    cout << "The highest score is " << max << endl;
    return max;
}

/**
This function writes the performer's name and score to
the output file.
*/
void writeScore(ofstream &outFile, double score, string name){
/// debug statements
//    cout << "This is the writeScore function" << endl;
    outFile << fixed << setprecision(2);
    outFile << "Name: " << name << "\tScore: " << score << endl;
}

/**
This function leaves a farewell message for
the Star Search Program.
*/
void farewell(void){
    cout << "Details of individual results are available in results.txt" << endl;
    cout << "Thank you for using Star Search!" << endl;
}

/**
OUTPUT:
Welcome to Star Search, a program that calculates the
scores of each performer and determines the winner!

The number of performers is 8

The winner is Ann and the winning score is 9.13
Details of individual results are available in results.txt
Thank you for using Star Search!

*/
