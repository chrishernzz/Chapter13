#include "SortingSimulations.h"

SortingSimulations::SortingSimulations() : size(0.0) {}

//precondition:
//postcondition:
void SortingSimulations::createArray(int newSize) {
	srand(time(0));
	//for loop through the newSize which is the user enter
	for (int i = 0; i < newSize; ++i) {
		//you will now push back (append) the random elements
		data.push_back(rand() % 100);
	}
	//set the size to the vector data size which holds the random elements
	size = data.size();
}
//precondition:
//postcondition:
void SortingSimulations::displayArray() {
	cout << "\n\t\t";
	for (double i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
}

//precondition:
//postcondition:
void SortingSimulations::performBubbleSortAscending(int newSize, int countSwaps) {
	//base case saying it is sorted
	if (newSize == 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	//using the bubble sort ascending method (ascending first)
	for (int i = 0; i < newSize - 1; ++i) {
		if (data[i] > data[i + 1]) {
			++countSwaps;
			// Swap data[i] and data[i + 1]
			swap(data[i], data[i + 1]);
		}
	}
	//with reduced array size
	performBubbleSortAscending(newSize - 1, countSwaps);
}
//precondition:
//postcondition:
void SortingSimulations::performBubbleSortDescending(int newSize, int countSwaps) {
	//base case saying it is sorted
	if (newSize == 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	//using the bubble sort ascending method (ascending first)
	for (int i = 0; i < newSize - 1; ++i) {
		if (data[i] < data[i + 1]) {
			++countSwaps;
			// Swap data[i] and data[i + 1]
			swap(data[i], data[i + 1]);
		}
	}
	//with reduced array size
	performBubbleSortDescending(newSize - 1, countSwaps);
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
			int countSwaps = 0;
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			else {
				cout << "\n\t\tBubbleSort:\n";
				char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
				if (toupper(orderChoice) == 'A') {
					cout << "\n\t\tAscending:\t\t";
					performBubbleSortAscending(size, countSwaps);
					//cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
					//call my displayArray() to show the ascending sorted
					displayArray();
				}
				else {
					cout << "\n\t\tDescending:\t\t";
					performBubbleSortDescending(size, countSwaps);
					//call my displayArray() to show the descending sorted
					displayArray();
				}
			}
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'D': {

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
