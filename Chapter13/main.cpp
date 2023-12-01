//Name: Christian Hernandez
//Date: 12/4/2023
//subscription: CMPR131

//Credit: Christian Hernandez,Bryan Alarcon,Thanh Tran, Joe Bryant,Erik Santana, Saul Merino

#include<iostream>
#include"input (1).h"
#include"SortingSimulations.h"
#include"ApplicationStudentRecords.h"
using namespace std;

//prototypes
int menuOption();
void challenge1();
void challenge2();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}
//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption() {
	system("cls");
	cout << "\n\tCMPR131 Chapter 13: Sortings by Christian Hernandez(11/13/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Sorting simulations";
	cout << "\n\t\t2> Application of students records";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 2);
}

//precondition: going to call the Binary_Tree_Node class and then pass in a template that is a string
//postcondition: going to then allocate to get the new data
void challenge1() {
	SortingSimulations menu;
	menu.mainInformation();
}
//precondition: going to call my BTree class and create a template class that is an int
//postcondition: going to then call my main menu information that has the options to do
void challenge2() {
	ApplicationStudentRecords menu;
	menu.mainInformation();
}