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
	//will hold a copy of the data that we are creating the random elements from
	vector<double> realData;
	double size;
public:
	//default constructor
	SortingSimulations();

	//member function creating the array and fill with random elements
	void createArray(int newSize);
	//member function to give me the original random numbers when we first started
	void orginalArray();
	//member function to display the random elements
	void displayArray();
	
	//member function to perform bubble sort (ascending or descending)
	void performBubbleSortAscending(int newSize,int& countSwaps);
	void performBubbleSortDescending(int newSize, int& countSwaps);

	//member function to perform selection sort (ascending or descending)
	void performSelectionSortAscending(int newSize, int& countSwaps);
	void performSelectionSortDescending(int newSize, int& countSwaps);



	//main menu information
	void mainInformation();


};

