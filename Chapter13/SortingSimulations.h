#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);
//string inputString(string prompt, bool spaces);

class SortingSimulations{
private:
	//creating a dynamic array and fill with random elements (double)
	vector<double> data;
	//will hold a copy of the data that we are creating the random elements from
	vector<double> realData;
	int size;
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

	//member function to perform insertion sort (ascending or descending)
	void performInsertionSortAscending(int newSize, int& countSwaps);
	void performInsertionSortDescending(int newSize, int& countSwaps);

	//member function to perform quick sort (ascending or descending)
	void performQuickSortAscending(int newSize, int& countSwaps);
	void quickSortAscending(int low, int high,int& countSwaps);
	int partionTheAscending(int low, int high, int& countSwaps);

	void performQuickSortDescending(int newSize, int& countSwaps);
	void quickSortDescending(int low, int high, int& countSwaps);
	int partionTheDescending(int low, int high, int& countSwaps);

	//member function to perform merge sort (ascending or descending)
	void performMergeSortAscending(int newSize, int& countSwaps);
	void performMergeSortA(int begin, int end,int& countSwaps);
	void performMergeAscending(int left, int mid, int right,int& countSwaps);

	void performMergeSortDescending(int newSize, int& countSwaps);
	void performMergeSortD(int begin, int end, int& countSwaps);
	void performMergeDescending(int left, int mid, int right, int& countSwaps);

	//member function to perform heap sort (ascending or descending)
	void performHeapSortAscending(int newsIZE, int& countSwaps);
	void heapifyAscending(int n, int i);
	void heapSortAscending(int& countSwaps);

	void performHeapSortDescending(int newsIZE, int& countSwaps);
	void heapifyDescending(int n, int i);
	void heapSortDescending(int& countSwaps);

	//main menu information
	void mainInformation();


};

