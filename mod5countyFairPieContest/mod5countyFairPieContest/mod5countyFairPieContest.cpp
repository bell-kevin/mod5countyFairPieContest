// mod5countyFairPieContest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Each line in the file holds the contestant's first and last name, and 3 scores stored as doubles
class PieContestant
{
private:
	string firstName;
	string lastName;
	double score1;
	double score2;
	double score3;
	double averageScore;
	
public:
	
	//Default constructor
	PieContestant()
	{
		firstName = "";
		lastName = "";
		score1 = 0.0;
		score2 = 0.0;
		score3 = 0.0;
		averageScore = 0.0;
	}
	
	PieContestant(string firstName, string lastName, double score1, double score2, double score3)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->score1 = score1;
		this->score2 = score2;
		this->score3 = score3;
		this->averageScore = (score1 + score2 + score3) / 3;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	double getScore1()
	{
		return score1;
	}
	double getScore2()
	{
		return score2;
	}
	double getScore3()
	{
		return score3;
	}
	double getAverageScore()
	{
		return averageScore;
	}
};

int main()
{
    std::cout << "Module 5 Competency Project by Kevin Bell\n\n";
	//read in the input file
	ifstream inFile;
	inFile.open("PieContest.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	else {
		cout << "Sorted list\n\n";
	}
	//create an array of PieContestant objects
	PieContestant contestants[10];
	//read in the data from the file
	string firstName, lastName;
	double score1, score3, score2;
	int i = 0;
	while (inFile >> firstName >> lastName >> score1 >> score2 >> score3) {
		contestants[i] = PieContestant(firstName, lastName, score1, score2, score3);
		i++;
	} // end while
	inFile.close();
	//bubble sort the array in descending order by average score
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (contestants[j].getAverageScore() < contestants[j + 1].getAverageScore()) {
				PieContestant temp = contestants[j];
				contestants[j] = contestants[j + 1];
				contestants[j + 1] = temp;
			} // end if
		} // end for
	} // end for loop and bubble sort
	//display array with decimal precision of 2
	cout << fixed << setprecision(2);
	cout << "Contestant\tScore 1\tScore 2\tScore 3\tAverage Score\n";
	//line
	cout << "------------------------------------------------------\n";
	for (int i = 0; i < 10; i++) {
		cout << contestants[i].getFirstName() << " " << contestants[i].getLastName() << "\t" << contestants[i].getScore1() << "\t" << contestants[i].getScore2() << "\t" << contestants[i].getScore3() << "\t" << contestants[i].getAverageScore() << endl;
	} // end for
	cout << endl;
	//display the top 3 contestants
	cout << "Winners\n\n";
	//format well
	cout << "Gold Medal:\t" << contestants[0].getFirstName() << " " << contestants[0].getLastName() << "\t" << fixed << setprecision(2) << contestants[0].getAverageScore() << endl;
	cout << "Silver Medal:\t" << contestants[1].getFirstName() << " " << contestants[1].getLastName() << "\t" << fixed << setprecision(2) << contestants[1].getAverageScore() << endl;
	cout << "Bronze Medal:\t" << contestants[2].getFirstName() << " " << contestants[2].getLastName() << "\t" << fixed << setprecision(2) << contestants[2].getAverageScore() << endl;
	cout << endl;
	system("pause");
	return 0;
} // end main