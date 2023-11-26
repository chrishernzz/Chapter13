#pragma once
#include<iostream>
#include<vector>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);
//string inputString(string prompt, bool spaces);

class SortingSimulations{
private:
	//int* array;
	//creating a dynamic array and fill with random elements (double)
	vector<double> data;
	double size;
public:
	//default constructor
	SortingSimulations();

	//member function creating the array and fill with random elements
	void createArray(int size);
	//member function to display the random elements
	void displayArray();
	
	//member function to perform bubble sort (ascending or descending)
	void performBubbleSortAscending(int newSize,int countSwaps);
	void performBubbleSortDescending(int newSize, int countSwaps);

	//main menu information
	void mainInformation();


};

