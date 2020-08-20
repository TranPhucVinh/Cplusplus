#include <iostream>
#include <fstream>
#include <iomanip>

#include <ios>
#include <limits>  

using namespace std;

char enteredChoice[1];

void addInformation();
void search();

int main(){	
	cout << "Employee management program \n";
	PROGRAM_OPTION:
		cout << "Enter the corresponding number with the option \n";
		cout << "1. Add employee's information \n";
		cout << "2. Search employee's information \n";
		cout << "3. Exit \n";
		cout << "Your choice: ";

		fgets(enteredChoice, 2, stdin);
		while ((getchar()) != '\n'); //Must have this line

		switch (enteredChoice[0])
		{
			case '1':
				addInformation();
				break;
			case '2':
				search();
				break;
			case '3':
				cout << "Thanks for using the program \n";
				break;
			default:	
				cout << "Sorry, you have entered wrong number. Please try again \n";
				goto PROGRAM_OPTION;
		}		
}

void addInformation(){
	ofstream fileStreamOut;
	fileStreamOut.open("employee.txt", ios::app);

	int employeeNum;
	string id, name, salary;

	cout << "Number of employee you wish to enter: ";
	cin >> employeeNum;

	for (int i = 0; i < employeeNum; i ++) {
		cout << "Enter employee's ID: ";
		cin >> ws;//Fix bug: missing line of code

		getline(cin, id);

		cout << "Enter employee's name: ";
		getline(cin, name);

		cout << "Enter employee's salary: ";
		getline(cin, salary);

		fileStreamOut << endl << id << setw(20) << name << setw(20) << salary;
	}
	fileStreamOut.close();
	cout << "Thanks for using the program \n";
}


void searchID(){
	ifstream fileStreamIn("employee.txt");

	bool idFound = false;
	string id, findID, salary, name;

	fileStreamIn.seekg(44); // set cursor based on set(w) in file.txt

	cout << "Enter employee's ID: ";
	cin >> ws;//Fix bug: missing line of code

	getline(cin, findID);
	
	cout << "ID" << setw(20) << "Name" << setw(20) << "Salary";

	while(fileStreamIn >> id >> name >> salary)
	{
		if (findID == id){
			cout << endl << id << setw(20) <<  name << setw(20) << salary;
			idFound = true;
		}
	}

	if (!idFound) {
		cout <<  endl << "--" << setw(20) << "--" << setw(20) << "--\n";
		cout << "Sorry, we can't find the user with your entered ID \n";
	}
	fileStreamIn.close();
}

void searchName(){
	ifstream fileStreamIn("employee.txt");
	bool nameFound = false;
	string findName, id, salary, name;

	fileStreamIn.seekg(44);
	cout << "Enter employee's name: ";
	cin >> ws;//Fix bug: missing line of code
	getline(cin, findName);

	cout << "ID" << setw(20) << "Name" << setw(20) << "Salary";

	while(fileStreamIn >> id >> name >> salary)
	{
		if (findName == name){
			cout << endl << id << setw(20) <<  name << setw(20) << salary;
			nameFound = true;
	 	}
	}	

	if (!nameFound){
		cout <<  endl << "--" << setw(20) << "--" << setw(20) << "--\n";
		cout << "Sorry, we can't find the user with your entered ID \n";
	}
	fileStreamIn.close();
}


void searchSalary(){
	ifstream fileStreamIn("employee.txt");
	bool salaryFound = false;
	string id, salary, name, findSalary;
	fileStreamIn.seekg(44);

	cout << "Enter the salary number you wish to search: ";
	cin >> ws;//Fix bug: missing line of code
	getline(cin, findSalary);

	cout << "ID" << setw(20) << "Name" << setw(20) << "Salary";

	while(fileStreamIn >> id >> name >> salary)
	{
		if (findSalary == salary){
			cout << endl << id << setw(20) <<  name << setw(20) << salary;
			salaryFound = true;
		}
	}

	if (!salaryFound){
		cout <<  endl << "--" << setw(20) << "--" << setw(20) << "--\n";
		cout << "Sorry, we can't find the user with your entered ID \n";
	}

	fileStreamIn.close();
}

void search(){
	int choice;
	SEARCH_OPTION:
		cout << "Enter the corresponding number \n";
		cout << "1. Search by ID \n";
		cout << "2. Search by name \n";
		cout << "3. Search by salary \n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice){
			case 1:
				searchID();
				break;
			case 2:
				searchName();
			break;
			case 3:
				searchSalary();
				break;
			default:	
				cout << "Sorry, you have entered wrong number. Please try again \n";
				goto SEARCH_OPTION;
	}
}