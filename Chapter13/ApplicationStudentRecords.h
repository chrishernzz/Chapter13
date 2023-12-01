#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Student.h"
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);
string inputString(string prompt, bool spaces);
double inputDouble(string prompt, double startRange, double endRange);
int inputInteger(string prompt, bool posNeg);

//precondition:
//postcondition:
class ApplicationStudentRecords{
private:
	//going to be reading data from the Student class
	vector<Student>data;
	//will hold a copy of the data that we are creating the random elements from
	vector<Student> realData;
public:

	//default constructor
	ApplicationStudentRecords();

	//member function to read from the file
	void readFromFile(string& fileName);
	//member function to display the records
	void displayRecords();
	//member function to give me the original random numbers when we first started
	void orginalArray();
	//member function to insert a record
	void insertRecord();
	//member function to remove a record
	void removeRecord(string studentName);

	//member function to perform quick sort by ID (ascending or descending)
	void performQuickSortAscendingByID(int newSize);
	void quickSortAscendingByID(int low, int high);
	int partionTheAscendingByID(int low, int high);

	void performQuickSortDescendingByID(int newSize);
	void quickSortDescendingByID(int low, int high);
	int partionTheDescendingByID(int low, int high);




	//main menu information
	void mainInformation();

};

