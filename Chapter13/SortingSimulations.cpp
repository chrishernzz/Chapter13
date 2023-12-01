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
		double randDoubles = static_cast<double>(rand()) / RAND_MAX * 100.0;
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
	//set the size to realData because that will have the size of the elements that we first started with
	size = data.size();
}
//precondition: going to show the output
//postcondition: going to then return the data which holds the random element
void SortingSimulations::displayArray() {
	//will round to the first decimal place
	cout << fixed << setprecision(1);
	cout << "\n\t\t";
	for (double i = 0; i < size; i++) {
		cout << data[i];
		//adding comma except the last one
		if (i < size - 1) {
			cout << ", ";
		}
	}
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the bubble sort in ascending and the count swaps (will start at the first index and compare to the next index. if the first index greater than second index swap. does this till sorted ascending)
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
//postcondition: going to then return the bubble sort in descending and the count swaps (will start at the first index and compare to the next index. if the first index less than the second index swap. does this till sorted descending)
void SortingSimulations::performBubbleSortDescending(int newSize, int& countSwaps) {
	//base case saying it is sorted
	if (newSize == 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	//using the bubble sort descending method (descending second)
	for (int i = 0; i < newSize - 1; ++i) {
		//changing the comparing here to get descending
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
//postcondition: going to then return the selection sort in ascending and count the swaps (will grab the min and the max and swap them right away. does this till sorted ascending)
void SortingSimulations::performSelectionSortAscending(int newSize, int& countSwaps) {
	//base case saying it is sorted
	if (newSize <= 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	int minIndex;
	for (int i = 0; i < newSize - 1; i++) {
		//this will find the min element in the array 
		minIndex = i;
		for (int j = i + 1; j < newSize; j++) {
			if (data[j] < data[minIndex]) {
				minIndex = j;
			}
		}
		//swap the found min element with the first element of the index
		if (minIndex != i) {
			//increment the count swaps
			++countSwaps;
			swap(data[minIndex], data[i]);
		}
	}
	//need to a reduced the dynamic array size by 1
	performSelectionSortAscending(newSize - 1, countSwaps);
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the selection sort in descending and count the swaps (will grab the max and the min and swap them right away. does this till sorted descending)
void SortingSimulations::performSelectionSortDescending(int newSize, int& countSwaps) {
	//base case saying it is sorted
	if (newSize <= 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	int minIndex;
	for (int i = 0; i < newSize - 1; i++) {
		//this will find the max element in the array 
		minIndex = i;
		for (int j = i + 1; j < newSize; j++) {
			//changing the comparing here to get descending
			if (data[j] > data[minIndex]) {
				minIndex = j;
			}
		}
		//swap the found max element with the first element of the index
		if (minIndex != i) {
			//increment the count swaps
			++countSwaps;
			swap(data[minIndex], data[i]);
		}
	}
	//need to a reduced the dynamic array size by 1
	performSelectionSortDescending(newSize - 1, countSwaps);
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the insertion sort in ascending and count the swaps (will check if the min index is smaller than the index before and if it is then keep swapping till it is smaller and not greater than the index that is next)
void SortingSimulations::performInsertionSortAscending(int newSize, int& countSwaps) {
	//base case saying its sorted
	if (newSize <= 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	double key, j;
	for (int i = 1; i < newSize; i++) {
		key = data[i];
		j = i - 1;
		//going to move the greater than key position ahead of the current position
		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			//increment the count swaps
			++countSwaps;
			j = j - 1;
		}
		data[j + 1] = key;
	}
	//need to a reduced the dynamic array size by 1
	performInsertionSortAscending(newSize - 1, countSwaps);
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to then return the insertion sort in ascending and count the swaps (will check if the max index is greater than the index before and if it is then keep swapping till it is greater and not smaller than the index that is next)
void SortingSimulations::performInsertionSortDescending(int newSize, int& countSwaps) {
	//base case saying its sorted
	if (newSize <= 1) {
		cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
		return;
	}
	double key, j;
	for (int i = 1; i < newSize; i++) {
		key = data[i];
		j = i - 1;
		//going to move the greater than key position ahead of the current position
		//changing the comparing here to get descending
		while (j >= 0 && data[j] < key) {
			data[j + 1] = data[j];
			j = j - 1;
			//increment the count swaps
			++countSwaps;
		}
		data[j + 1] = key;
	}
	//need to a reduced the dynamic array size by 1
	performInsertionSortDescending(newSize - 1, countSwaps);
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to call my quickSortAscending() function that does the recursive
void SortingSimulations::performQuickSortAscending(int newSize, int& countSwaps) {
	countSwaps = 0;
	quickSortAscending(0, newSize - 1, countSwaps);
	cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
}
//precondition: going to pass in three parameters which are the low, high and the swaps to keep track
//postcondition: going to then check if the low is less than the high if its then call the partionTheAscending() function
void SortingSimulations::quickSortAscending(int low, int high, int& countSwaps) {
	// when low is less than high
	if (low < high) {
		// pi is the partition return index of pivot
		int pi = partionTheAscending(low, high, countSwaps);

		//smaller element than pivot goes left and
		//higher element goes right
		quickSortAscending(low, pi - 1, countSwaps);
		quickSortAscending(pi + 1, high, countSwaps);
	}
}
//precondition: going to pass in three parameters which are the low, high and the swaps to keep track
//postcondition: going to get the pivot and put all the low values that are less than the pivot to the left and greater values to the right
int SortingSimulations::partionTheAscending(int low, int high, int& countSwaps) {
	//choose the pivot
	int pivot = data[high];
	//index of smaller element and indicate
	//the right position of pivot found so far
	int i = (low - 1);
	for (int j = low; j <= high; j++) {
		//if current element is smaller than the pivot
		if (data[j] < pivot) {
			//increment index of smaller element
			i++;
			++countSwaps;
			swap(data[i], data[j]);
		}
	}
	++countSwaps;
	swap(data[i + 1], data[high]);
	return (i + 1);
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to call my quickSortDescending() function that does the recursive
void SortingSimulations::performQuickSortDescending(int newSize, int& countSwaps) {
	countSwaps = 0;
	quickSortDescending(0, newSize - 1, countSwaps);
	cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
}
//precondition: going to pass in three parameters which are the low, high and the swaps to keep track
//postcondition: going to then check if the low is less than the high if its then call the partionTheDescending() function
void SortingSimulations::quickSortDescending(int low, int high, int& countSwaps) {
	//base case saying its sorted so do not continue the recursion
	if (low >= high) {
		return;
	}
	// pi is the partition return index of pivot
	int pi = partionTheDescending(low, high, countSwaps);
	// smaller element than pivot goes right and
	// higher element goes left
	quickSortDescending(low, pi - 1, countSwaps);
	quickSortDescending(pi + 1, high, countSwaps);

}
//precondition: going to pass in three parameters which are the low, high and the swaps to keep track
//postcondition: going to get the pivot and put all the low values that are greater than the pivot to the left and smaller values to the right
int SortingSimulations::partionTheDescending(int low, int high, int& countSwaps) {
	//choose the pivot
	int pivot = data[high];
	// index of smaller element and indicate
	// the right position of pivot found so far
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		// if current element is greater than the pivot
		if (data[j] > pivot) {
			// increment index of smaller element
			i++;
			++countSwaps;
			swap(data[i], data[j]);
		}
	}
	++countSwaps;
	swap(data[i + 1], data[high]);
	return (i + 1);
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to call my performMergeSortA() function that does the recursive
void SortingSimulations::performMergeSortAscending(int newSize, int& countSwaps){
	//base case saying its sorted
	if (newSize <= 1) {
		return;
	}

	countSwaps = 0;
	performMergeSortA(0, newSize - 1, countSwaps);
	cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
}
//precondition: going to pass in the begin, end , and swaps as parameters
//postcondition: going to be doing recursive for both left and right sides as they are merging
void SortingSimulations::performMergeSortA(int begin, int end,int& countSwaps){
	if (begin < end) {
		int mid = begin + (end - begin) / 2;

		//doing recursive calls on the left and right halves
		performMergeSortA(begin, mid, countSwaps);
		performMergeSortA(mid + 1, end, countSwaps);

		//call the merge function
		performMergeAscending(begin, mid, end, countSwaps);
	}
}
//precondition: going to pass four parameters which are the left, mid,right, and keep track of swaps
//postcondition: it is going to split the array into two halves, then you sort the left and right side by merging them
void SortingSimulations::performMergeAscending(int left, int mid, int right, int& countSwaps){
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;
	//creating temp vectors
	vector<double> leftArray(subArrayOne);
	vector<double> rightArray(subArrayTwo);

	//copy data to temp vectors leftArray and rightArray
	for (auto i = 0; i < subArrayOne; i++) {
		leftArray[i] = data[left + i];
	}
	for (auto j = 0; j < subArrayTwo; j++) {
		rightArray[j] = data[mid + 1 + j];
	}
	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	//merge the temp vectors back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			//increment the swaps
			countSwaps += subArrayOne - indexOfSubArrayOne;
		}
		indexOfMergedArray++;
	}

	//copy the remaining elements of left[], if any
	while (indexOfSubArrayOne < subArrayOne) {
		data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	//copy the remaining elements of right[], if any
	while (indexOfSubArrayTwo < subArrayTwo) {
		data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to call my performMergeSortD() function that does the recursive
void SortingSimulations::performMergeSortDescending(int newSize, int& countSwaps){
	//base case saying its sorted
	if (newSize <= 1) {
		return;
	}

	countSwaps = 0;
	performMergeSortD(0, newSize - 1, countSwaps);
	cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
}
//precondition: going to pass in the begin, end , and swaps as parameters
//postcondition: going to be doing recursive for both left and right sides as they are merging
void SortingSimulations::performMergeSortD(int begin, int end, int& countSwaps){
	if (begin < end) {
		int mid = begin + (end - begin) / 2;

		//doing recursive calls on the left and right halves
		performMergeSortD(begin, mid, countSwaps);
		performMergeSortD(mid + 1, end, countSwaps);

		//call the merge function for descending order
		performMergeDescending(begin, mid, end, countSwaps);
	}
}
//precondition: going to pass four parameters which are the left, mid,right, and keep track of swaps
//postcondition: it is going to split the array into two halves, then you sort the left and right side by merging them
void SortingSimulations::performMergeDescending(int left, int mid, int right, int& countSwaps){
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	//creating temp vectors
	vector<double> leftArray(subArrayOne);
	vector<double> rightArray(subArrayTwo);

	//copy data to temp vectors leftArray and rightArray
	for (auto i = 0; i < subArrayOne; i++) {
		leftArray[i] = data[left + i];
	}
	for (auto j = 0; j < subArrayTwo; j++) {
		rightArray[j] = data[mid + 1 + j];
	}
	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	//merge the temp vectors back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			//increment the swaps
			countSwaps += subArrayOne - indexOfSubArrayOne;
		}
		indexOfMergedArray++;
	}

	//copy the remaining elements of left[], if any
	while (indexOfSubArrayOne < subArrayOne) {
		data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	//copy the remaining elements of right[], if any
	while (indexOfSubArrayTwo < subArrayTwo) {
		data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to call my heapSortAscedning() function that does the recursive
void SortingSimulations::performHeapSortAscending(int newSize, int& countSwaps){
	heapSortAscending(countSwaps);
	cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
}
//precondition: going to pass in two parameters
//postcondition: going to then heapify a subtree rooted with node i which will be my data and the n is the size of the heap
void SortingSimulations::heapifyAscending(int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && data[l] > data[largest]) {
		largest = l;
	}
	if (r < n && data[r] > data[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(data[i], data[largest]);
		heapifyAscending(n, largest);
	}
}
//precondition: going to pass in the swaps
//postcondition: going to be doing the heap sort here calling the heapifyAscending() function
void SortingSimulations::heapSortAscending(int& countSwaps){
	int n = data.size();
	//build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapifyAscending(n, i);
	}
	//one by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		swap(data[0], data[i]);
		//call max heapify on the reduced heap
		heapifyAscending(i, 0);
		//increment the swaps
		countSwaps++;
	}
}
//precondition: going to pass in two parameters which are the size and the swaps to keep track
//postcondition: going to call my heapSortDescending() function that does the recursive
void SortingSimulations::performHeapSortDescending(int newSize, int& countSwaps) {
	heapSortDescending(countSwaps);
	cout << "\n\n\t\tnumber of swapping routines = " << countSwaps;
}

//precondition: going to pass in two parameters
//postcondition: going to then heapify a subtree rooted with node i which will be my data and the n is the size of the heap
void SortingSimulations::heapifyDescending(int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && data[l] < data[largest]) {
		largest = l;
	}
	if (r < n && data[r] < data[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(data[i], data[largest]);
		heapifyDescending(n, largest);
	}
}

//precondition: going to pass in the swaps
//postcondition: going to be doing the heap sort here calling the heapifyDescending() function
void SortingSimulations::heapSortDescending(int& countSwaps) {
	int n = data.size();
	//build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapifyDescending(n, i);
	}
	//one by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		swap(data[0], data[i]);
		//call max heapify on the reduced heap
		heapifyDescending(i, 0);
		//increment the swaps
		countSwaps++;
	}
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
				performBubbleSortAscending(size, countSwaps);
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performBubbleSortDescending(size, countSwaps);
			}
			//call my displayArray() to show the ascending or descending sorted
			displayArray();
			//then reset the ascending or descending back to their original data which are the random elements we started with
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
				performSelectionSortAscending(size, countSwaps);
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performSelectionSortDescending(size, countSwaps);
			}
			//call my displayArray() to show the ascending or descending sorted
			displayArray();
			//then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'E': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int countSwaps = 0;
			cout << "\n\t\tInsertionSort:\n";
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				cout << "\n\t\tAscending:\t\t";
				performInsertionSortAscending(size, countSwaps);
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performInsertionSortDescending(size, countSwaps);
			}
			//call my displayArray() to show the ascending or descending sorted
			displayArray();
			//then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'F': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int countSwaps = 0;
			cout << "\n\t\tQuickSort:\n";
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				cout << "\n\t\tAscending:\t\t";
				performQuickSortAscending(size, countSwaps);
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performQuickSortDescending(size, countSwaps);
			}
			//call my displayArray() to show the ascending or descending sorted
			displayArray();
			//then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'G': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int countSwaps = 0;
			cout << "\n\t\tMergeSort:\n";
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				cout << "\n\t\tAscending:\t\t";
				performMergeSortAscending(size, countSwaps);
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performMergeSortDescending(size, countSwaps);
			}
			//call my displayArray() to show the ascending or descending sorted
			displayArray();
			//then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case 'H': {
			//check if the dynamic array is empty
			if (data.empty()) {
				cout << "\n\t\tDynamic array is empty.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int countSwaps = 0;
			cout << "\n\t\tHeapSort:\n";
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				cout << "\n\t\tAscending:\t\t";
				performHeapSortAscending(size, countSwaps);
			}
			else {
				cout << "\n\t\tDescending:\t\t";
				performHeapSortDescending(size, countSwaps);
			}
			//call my displayArray() to show the ascending or descending sorted
			displayArray();
			//then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
			cout << "\n\n";
			system("pause");
			system("cls");
		}
				break;
		case '0': {
			return;
		}
		}
	} while (true);
}
