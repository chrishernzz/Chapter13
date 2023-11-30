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
	cout << "\n\t\tStudent records:\n";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << endl;
	}
	cout << "\n";
	system("pause");
	system("cls");
}
//precondition: going to pass in the Student class
//postcondition: going to then return a new record for a Student information that has id,name,major,GPA
void ApplicationStudentRecords::insertRecord(){
	Student insertStudent;
	insertStudent.setStudentID(stoi(inputString("\n\t\tEnter a new student ID: ", true)));
	insertStudent.setName(inputString("\t\tEnter the student's name: ", true));
	insertStudent.setMajor(inputString("\t\tEnter the student's major: ", true));
	insertStudent.setGPA(inputDouble("\t\tEnter the student's GPA: ", 0.0, 4.0));
	//push back the new student record to the  back
	data.push_back(insertStudent);
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
			string studentName = inputString("\t\tEnter the student's name to remove: ", true);
			removeRecord(studentName);
		}
				break;
		case 'E': {

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
