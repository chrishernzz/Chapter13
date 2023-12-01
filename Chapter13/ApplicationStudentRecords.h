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

	//member function to perform quick sort by name (ascending or descending)
	void performQuickSortAscendingByName(int newSize);
	void quickSortAscendingByName(int low, int high);
	int partionTheAscendingByName(int low, int high);

	void performQuickSortDescendingByName(int newSize);
	void quickSortDescendingByName(int low, int high);
	int partionTheDescendingByName(int low, int high);

	//member function to perform quick sort by major (ascending or descending)
	void performQuickSortAscendingByMajor(int newSize);
	void quickSortAscendingByMajor(int low, int high);
	int partionTheAscendingByMajor(int low, int high);

	void performQuickSortDescendingByMajor(int newSize);
	void quickSortDescendingByMajor(int low, int high);
	int partionTheDescendingByMajor(int low, int high);

	//member function to perform quick sort by GPA (ascending or descending)
	void performQuickSortAscendingByGPA(int newSize);
	void quickSortAscendingByGPA(int low, int high);
	int partionTheAscendingByGPA(int low, int high);

	void performQuickSortDescendingByGPA(int newSize);
	void quickSortDescendingByGPA(int low, int high);
	int partionTheDescendingByGPA(int low, int high);

	//member function to write to file
	void writeToFile(string& fileName);

	//main menu information
	void mainInformation();

};

