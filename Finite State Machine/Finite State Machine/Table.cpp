/////////////////////////////////// digraph.t /////////////////////////////////////////////////////////////////////////
//
// File name          : Table.cpp
//
//
// Programmer         : EDMUND ADJEI
//
// Date created       : 11/10/2021
//
// Professor		  : Bradley J. Streller
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "table.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int Mapping(Pair<char, string>);
int main() {

	Table <Pair<char, string>, string> aTable(35, Mapping);

	Table <Pair<char, string>, string> tTable(35, Mapping);
	ifstream inFile;
	string filename, dum;
	char again = 'Y';
	Pair<Pair<char, string>, string> temp;
	Pair<char, string> look;
	/*inFile.open("transition_table.txt");
	inFile.open("action_table.txt");*/
	while (again == 'y' || again == 'Y') {
		cout << "Please enter the file path of the transition table" << endl;
		getline(cin, filename);
		inFile.open(filename);
		for (int i = 0; i < 5; i++)
		{
			inFile >> dum;
		}
		while (inFile >> temp.first.second) {
			temp.first.first = 'A';
			for (int i = 0; i < 5; i++) {
				inFile >> temp.second;
				tTable.insert(temp);
				temp.first.first++;
			}
		}

		inFile.close();
		cout << "Please enter the file path of the action table" << endl;
		getline(cin, filename);
		inFile.open(filename);
		for (int i = 0; i < 5; i++)
		{
			inFile >> dum;
		}
		while (inFile >> temp.first.second) {
			temp.first.first = 'A';
			inFile >> ws;
			if (inFile.peek() == 'o' || inFile.peek() == 'f') {
				for (int i = 0; i < 5; i++) {
					temp.second = " ";
					aTable.insert(temp);
					temp.first.first++;
				}
			}
			else {
				for (int i = 0; i < 5; i++) {
					inFile >> temp.second;
					aTable.insert(temp);
					temp.first.first++;
				}
			}
		}

		look.second = "nke";
		for (int i = 0; i < 3; i++)
		{
			cout << "Please enter a letter from the following choices: A, B, C, D, E" << endl;
			cin >> look.first;
			look.first = toupper(look.first);
			while (!cin || cin.peek() != '\n' || (look.first < 'A' || look.first > 'E'))
			{
				cout << "Invalid letter, Please refer to given choices: A, B, C, D, E " << endl;
				cin.clear();
				cin.ignore(200, '\n');
				cin >> look.first;
			}
			look.second = tTable.lookUp(look);
		}
		cout << "Please enter a letter from the following choices: A, B, C, D, E" << endl;
		cin >> look.first;
		look.first = toupper(look.first);
		while (!cin || cin.peek() != '\n' || (look.first < 'A' || look.first > 'E'))
		{
			cout << "Invalid letter, Please refer to given choices: A, B, C, D, E " << endl;
			cin.clear();
			cin.ignore(200, '\n');
			cin >> look.first;
		}
		look.second = aTable.lookUp(look);

		if (look.second == "alarm") {
			cout << "You've tripped the alarm!" << endl;
		}
		else
			cout << "You've unlocked the car!" << endl;
		cout << "Go again? (Y/N)";
		cin >> again;
		if (cin.peek() != '\n') {
			cin.ignore(200, '\n');
		}
		cin.get();
	}
	return 0;
}

int Mapping(Pair<char, string> map) 
{
	int a, b;
	if (map.first == 'A') {
		a = 0;
	}
	else if (map.first == 'B') {
		a = 7;
	}
	else if (map.first == 'C') {
		a = 14;
	}
	else if (map.first == 'D') {
		a = 21;
	}
	else 
		a = 28;

	if (map.second == "nke") {
		b = 0;
	}
	else if (map.second == "ok1") {
		b = 1;
	}
	else if (map.second == "ok2") {
		b = 2;
	}
	else if (map.second == "ok3") {
		b = 3;
	}
	else if (map.second == "fa1") {
		b = 4;
	}
	else if (map.second == "fa2") {
		b = 5;
	}
	else if (map.second == "fa3") {
		b = 6;
	}

	return a + b;
}