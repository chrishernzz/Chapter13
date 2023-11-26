#include "SortingSimulations.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
SortingSimulations::SortingSimulations() : size(0.0) {}

//precondition: going to pass in a parameter
//postcondition: the parameter is going to then be used for the for loop, going to return the data and realData which are the dynamic array
void SortingSimulations::createArray(int newSize) {
	srand(time(0));
	//for loop through the newSize which is the user enter
	for (int i = 0; i < newSize; ++i) {
		//this will let me store the random numbers in both data and realData
		int randDoubles = rand() % 100;
		//you will now push back (append) the random elements
		data.push_back(randDoubles);
		//this will hold a copy of the random elements 
		realData.push_back(randDoubles);
	}
	//set the size to the vector data size which holds the random elements
	size = data.size();
}
//precondition: going to keep track of the data
//postcondition: going to then return the random elements we started with from when we created the size of the array elements
void SortingSimulations::orginalArray() {
	//set the data to realData as where realData has the elements that we first started with
	data = realData;
	//set the size as well
	size = data.size();
}
//precondition: going to show the output
//postcondition: going to then return the data which holds the random element
void SortingSimulations::displayArray() {
	cout << "\n\t\t";
	for (double i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the bubble sort in ascending and the count swaps
void SortingSimulations::performBubbleSortAscending(int newSize, int& countSwaps) {
	//base case saying it is sorted
	if (newSize == 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	//using the bubble sort ascending method (ascending first)
	for (int i = 0; i < newSize - 1; ++i) {
		if (data[i] > data[i + 1]) {
			//increment the count swaps
			++countSwaps;
			// Swap data[i] and data[i + 1]
			//built in function
			swap(data[i], data[i + 1]);
		}
	}
	//with reduced array size
	performBubbleSortAscending(newSize - 1, countSwaps);
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the bubble sort in descending and the count swaps
void SortingSimulations::performBubbleSortDescending(int newSize, int& countSwaps) {
	//base case saying it is sorted
	if (newSize == 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	//using the bubble sort descending method (descending second)
	for (int i = 0; i < newSize - 1; ++i) {
		if (data[i] < data[i + 1]) {
			//increment the count swaps
			++countSwaps;
			// Swap data[i] and data[i + 1]
			//built in function
			swap(data[i], data[i + 1]);
		}
	}
	//need to reduced the dynamic array size by 1 
	performBubbleSortDescending(newSize - 1, countSwaps);
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the selection sort in ascending and count the swaps (will grab the min and the max and swap them right away)
void SortingSimulations::performSelectionSortAscending(int newSize, int& countSwaps){
	//base case saying it is sorted
	if (newSize <= 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	int minIndex, minValue;
	for (int i = 0; i < newSize - 1; i++) {
		minIndex = i;
		minValue = data[i];
		for (int j = i + 1; j < newSize; j++) {
			if (data[j] < minValue) {
				minValue = data[j];
				minIndex = j;
			}
		}
		if (minIndex != i) {
			++countSwaps;
			swap(data[minIndex], data[i]);
		}
	}
	//need to a reduced the dynamic array size by 1
	performSelectionSortAscending(newSize - 1, countSwaps);
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the selection sort in descending and count the swaps (will grab the max and the min and swap them right away)
void SortingSimulations::performSelectionSortDescending(int newSize, int& countSwaps){
	//base case saying it is sorted
	if (newSize <= 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	int minIndex, minValue;
	for (int i = 0; i < newSize - 1; i++) {
		minIndex = i;
		minValue = data[i];
		for (int j = i + 1; j < newSize; j++) {
			if (data[j] > minValue) {
				minValue = data[j];
				minIndex = j;
			}
		}
		if (minIndex != i) {
			++countSwaps;
			swap(data[minIndex], data[i]);
		}
	}
	//need to a reduced the dynamic array size by 1
	performSelectionSortDescending(newSize - 1, countSwaps);
}


//precondition: going to print the information
//postcondition: going to create a menu that has options 
void SortingSimulations::mainInformation() {
	system("cls");
	char choice;
	do {
	beginning:
		cout << "\n\t1> Sort Simulations";
		cout << "\n\t" << string(82, char(205));
		cout << "\n\t\tA> Create a dynamic array and fill with random elements";
		cout << "\n\t\tB> Display the unsorted array";
		cout << "\n\t\tC> Perform BubbleSort";
		cout << "\n\t\tD> Perform SelectionSort";
		cout << "\n\t\tE> Perform InsertionSort";
		cout << "\n\t\tF> Perform QuickSort";
		cout << "\n\t\tG> Perform MergeSort";
		cout << "\n\t\tH> Perform HeapSort";
		cout << "\n\t" << string(82, char(205));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(82, char(205)) << "\n";
		choice = inputChar("\t\tOption: ", static_cast<string>("ABCDEFGH0"));

		switch (toupper(choice)) {
		case 'A': {
			int arraySize = inputInteger("\n\t\tEnter the size of the dynamic array: ");
			createArray(arraySize);
			cout << "\n\t\tDynamic array's size of " << arraySize << " has been created with random elements.\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'B': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			cout << "\n\t\tUnsorted dynamic array:";
			displayArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'C': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int countSwaps = 0;
			cout << "\n\t\tBubbleSort:\n";
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				cout << "\n\t\tAscending:\t\t";
				//call my displayArray() to show the ascending sorted
				performBubbleSortAscending(size, countSwaps);
				displayArray();
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performBubbleSortDescending(size, countSwaps);
				//call my displayArray() to show the descending sorted
				displayArray();
			}
			//going to then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'D': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int countSwaps = 0;
			cout << "\n\t\tSelectionSort:\n";
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				cout << "\n\t\tAscending:\t\t";
				//call my displayArray() to show the ascending sorted
				performSelectionSortAscending(size, countSwaps);
				displayArray();
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performSelectionSortDescending(size, countSwaps);
				//call my displayArray() to show the descending sorted
				displayArray();
			}
			//going to then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'E': {

		}
				break;
		case 'F': {

		}
				break;
		case 'G': {

		}
				break;
		case 'H': {

		}
				break;
		case '0': {
			return;
		}
		}
	} while (true);
}
