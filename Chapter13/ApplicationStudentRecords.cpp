#include "ApplicationStudentRecords.h"

//precondition: scope class and calling my default constructor and initializing
//postcondition: going to pass in the Student class
ApplicationStudentRecords::ApplicationStudentRecords(){
	//call the student default constructor
	//if there are no size available there, then default
	Student defualtCon;
}
//precondition: going to read from file
//postcondition: going to then use ifstream to read, open the text, push_back the information
void ApplicationStudentRecords::readFromFile(string& fileName){
	ifstream readFile;
	string theName, studentMajor, studentGPA;
	string studentId;
	Student newStudent;
	//open the file
	readFile.open(fileName);
	//while it is not the end of the file
	while (!readFile.fail()) {
		//read until there is a comma encounter
		getline(readFile, studentId, ',');
		newStudent.setStudentID(stoi(studentId));
		getline(readFile, theName, ',');
		newStudent.setName(theName);
		getline(readFile, studentMajor, ',');
		newStudent.setMajor(studentMajor);
		getline(readFile, studentGPA);
		newStudent.setGPA(stod(studentGPA));
		//push back the elements you read (getting the setters)
		data.push_back(newStudent);
		//this will hold a copy of the random elements 
		realData.push_back(newStudent);
		//end of file, then don't push_back an extra element
		if (readFile.eof()) {
			break;
		}
	}
	cout << "\n\t\tData have been read from " << fileName;
	cout << "\n\n";
	system("pause");
	system("cls");
}
//precondition: going to make sure it displays
//postcondition: going to then return all the information from the file, calling the data that has the information of students records
void ApplicationStudentRecords::displayRecords(){
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << endl;
	}
	cout << "\n";
	system("pause");
	system("cls");
}
//precondition: going to keep track of the data
//postcondition: going to then return the random elements we started with from when we created the size of the array elements
void ApplicationStudentRecords::orginalArray(){
	//set the data to realData as where realData has the elements that we first started with
	data = realData;
}
//precondition: going to pass in the Student class
//postcondition: going to then return a new record for a Student information that has id,name,major,GPA
void ApplicationStudentRecords::insertRecord(){
	Student insertStudent;
	insertStudent.setStudentID(inputInteger("\n\t\tEnter a new student ID: ", true));
	insertStudent.setName(inputString("\t\tEnter the student's name: ", true));
	insertStudent.setMajor(inputString("\t\tEnter the student's major: ", true));
	insertStudent.setGPA(inputDouble("\t\tEnter the student's GPA: ", 0.0, 4.0));
	//push back the new student record to the  back
	data.push_back(insertStudent);
	//this will hold a copy of the random elements 
	realData.push_back(insertStudent);
	cout << "\n";
	system("pause");
	system("cls");
}
//precondition: going to pass in a parameter to compare if the student is there
//postcondition: going to then call my getter and check if its equal to the student name, if it is then you will have to erase it (erase one only)
void ApplicationStudentRecords::removeRecord(string studentName){
	bool found = false;
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getName() == studentName) {
			data.erase(data.begin() + i);
			//you will then need to remove from the copy of the elements
			//set the copy = to data since data removed it
			realData = data;
			//flag it to true
			found = true;
			cout << "\n\t\tThe student record has been removed.";
			break;
		}
	}
	if (!found) {
		cout << "\n\t\tThe student record cannot be found to be removed.";
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}

//precondition: going to pass in one parameter which is the size
//postcondition: going to call my quickSortAscendingByID() function that does the recursive
void ApplicationStudentRecords::performQuickSortAscendingByID(int newSize){
	quickSortAscendingByID(0, newSize - 1);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to then check if the low is less than the high if its then call the partionTheAscendingByID() function
void ApplicationStudentRecords::quickSortAscendingByID(int low, int high){
	//base case saying its sorted so do not continue the recursion
	if (low >= high) {
		return;
	}
	// pi is the partition return index of pivot
	int pi = partionTheAscendingByID(low, high);
	// smaller element than pivot goes right and
	// higher element goes left
	quickSortAscendingByID(low, pi - 1);
	quickSortAscendingByID(pi + 1, high);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to get the pivot and put all the low values that are greater than the pivot to the left and smaller values to the right
int ApplicationStudentRecords::partionTheAscendingByID(int low, int high){
	//choose the pivot
	int pivot = data[high].getStudentID();
	//index of smaller element and indicate
	//the right position of pivot found so far
	int i = (low - 1);
	for (int j = low; j <= high; j++) {
		//if current element is smaller than the pivot
		if (data[j].getStudentID() < pivot) {
			//increment index of smaller element
			i++;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[high]);
	return (i + 1);
}

//precondition: going to pass in one parameter which is the size
//postcondition: going to call my quickSortDescendingByID() function that does the recursive
void ApplicationStudentRecords::performQuickSortDescendingByID(int newSize) {
	quickSortDescendingByID(0, newSize - 1);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to then check if the low is less than the high if its then call the partionTheDescendingByID() function
void ApplicationStudentRecords::quickSortDescendingByID(int low, int high) {
	//base case saying its sorted so do not continue the recursion
	if (low >= high) {
		return;
	}
	// pi is the partition return index of pivot
	int pi = partionTheDescendingByID(low, high);
	// smaller element than pivot goes right and
	// higher element goes left
	quickSortDescendingByID(low, pi - 1);
	quickSortDescendingByID(pi + 1, high);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to get the pivot and put all the low values that are greater than the pivot to the left and smaller values to the right
int ApplicationStudentRecords::partionTheDescendingByID(int low, int high) {
	//choose the pivot
	int pivot = data[high].getStudentID();
	//index of smaller element and indicate
	//the right position of pivot found so far
	int i = (low - 1);
	for (int j = low; j <= high; j++) {
		//if current element is greater than the pivot
		if (data[j].getStudentID() > pivot) {
			//increment index of smaller element
			i++;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[high]);
	return (i + 1);
}

//precondition: going to pass in one parameter which is the size
//postcondition: going to call my quickSortAscendingByName() function that does the recursive
void ApplicationStudentRecords::performQuickSortAscendingByName(int newSize){
	quickSortAscendingByName(0, newSize - 1);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to then check if the low is less than the high if its then call the partionTheAscendingByName() function
void ApplicationStudentRecords::quickSortAscendingByName(int low, int high){
	//base case saying its sorted so do not continue the recursion
	if (low >= high) {
		return;
	}
	// pi is the partition return index of pivot
	int pi = partionTheAscendingByName(low, high);
	// smaller element than pivot goes right and
	// higher element goes left
	quickSortAscendingByName(low, pi - 1);
	quickSortAscendingByName(pi + 1, high);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to get the pivot and put all the low values that are greater than the pivot to the left and smaller values to the right
int ApplicationStudentRecords::partionTheAscendingByName(int low, int high){
	//choose the pivot
	string pivot = data[high].getName();
	//index of smaller element and indicate
	//the right position of pivot found so far
	int i = (low - 1);
	for (int j = low; j <= high; j++) {
		//if current element is smaller than the pivot
		if (data[j].getName() < pivot) {
			//increment index of smaller element
			i++;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[high]);
	return (i + 1);
}
//precondition: going to pass in one parameter which is the size
//postcondition: going to call my quickSortDescendingByName() function that does the recursive
void ApplicationStudentRecords::performQuickSortDescendingByName(int newSize){
	quickSortDescendingByName(0, newSize - 1);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to then check if the low is less than the high if its then call the partionTheDescendingByName() function
void ApplicationStudentRecords::quickSortDescendingByName(int low, int high){
	//base case saying its sorted so do not continue the recursion
	if (low >= high) {
		return;
	}
	// pi is the partition return index of pivot
	int pi = partionTheDescendingByName(low, high);
	// smaller element than pivot goes right and
	// higher element goes left
	quickSortDescendingByName(low, pi - 1);
	quickSortDescendingByName(pi + 1, high);
}
//precondition: going to pass in two parameters which are the low and high
//postcondition: going to get the pivot and put all the low values that are greater than the pivot to the left and smaller values to the right
int ApplicationStudentRecords::partionTheDescendingByName(int low, int high){
	//choose the pivot
	string pivot = data[high].getName();
	//index of smaller element and indicate
	//the right position of pivot found so far
	int i = (low - 1);
	for (int j = low; j <= high; j++) {
		//if current element is greater than the pivot
		if (data[j].getName() > pivot) {
			//increment index of smaller element
			i++;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[high]);
	return (i + 1);
}

//precondition: going to print the information
//postcondition: going to create a menu that has options 
void ApplicationStudentRecords::mainInformation(){
	system("cls");
	char choice;
	string readFileName = "students.dat";
	do {
		beginning:
		cout << "\n\t2> Application of sorting student records";
		cout << "\n\t" << string(82, char(205));
		cout << "\n\t\tA> Read in data file";
		cout << "\n\t\tB> Display records";
		cout << "\n\t\tC> Insert a record";
		cout << "\n\t\tD> remove a record";
		cout << "\n\t\tE> Sort records by ID, name, major or GPA";
		cout << "\n\t\tF> Write out data file";
		cout << "\n\t" << string(82, char(205));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(82, char(205)) << "\n";
		choice = inputChar("\t\tOption: ", static_cast<string>("ABCDEF0"));

		switch (toupper(choice)) {
		case 'A': {
			readFromFile(readFileName);
		}
				break;
		case 'B': {
			//check if file has been open and there is data 
			if (data.empty()) {
				cout << "\n\t\tERROR, file has not been read for data.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			cout << "\n\t\tStudent records:\n";
			displayRecords();
		}
				break;
		case 'C': {
			//check if file has been open and there is data 
			if (data.empty()) {
				cout << "\n\t\tERROR, file has not been read for data.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			insertRecord();
		}
				break;
		case 'D': {
			//check if file has been open and there is data 
			if (data.empty()) {
				cout << "\n\t\tERROR, file has not been read for data.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			string studentName = inputString("\n\t\tEnter the student's name to remove: ", true);
			removeRecord(studentName);
		}
				break;
		case 'E': {
			//check if file has been open and there is data 
			if (data.empty()) {
				cout << "\n\t\tERROR, file has not been read for data.";
				cout << "\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			char orderChoice = inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("AD"));
			if (toupper(orderChoice) == 'A') {
				char optionObjectA = inputChar("\t\tChoose by (I)-ID, (N)-name, (M)-major or (G)-GPA: ",static_cast<string>("INMG"));
				cout << "\n\t\tAscending:\n";
				switch (toupper(optionObjectA)) {
				case 'I': {
					performQuickSortAscendingByID(data.size());
				}
						break;
				case 'N': {
					performQuickSortAscendingByName(data.size());
				}
						break;
				case 'M': {
				}
						break;
				case 'G': {
				}
						break;
				}
			}
			else {
				char optionObjectD = inputChar("\t\tChoose by (I)-ID, (N)-name, (M)-major or (G)-GPA: ", static_cast<string>("INMG"));
				cout << "\n\t\tDescending:\n";
				switch (toupper(optionObjectD)) {
				case 'I': {
					performQuickSortDescendingByID(data.size());
				}
						break;
				case 'N': {
					performQuickSortDescendingByName(data.size());
				}
						break;
				case 'M': {
				}
						break;
				case 'G': {
				}
						break;
				}
			}
			//call my displayArray() to show the ascending or descending sorted
			displayRecords();
			//then reset the ascending or descending back to their original data which are the random elements we started with
			orginalArray();
		}
				break;
		case 'F': {

		}
				break;
		case '0': {
			return;
		}
		}
	} while (true);
}
