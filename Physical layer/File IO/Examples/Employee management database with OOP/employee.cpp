#include "employee.h"

string Employee::getID() {
	return _id;
}

string Employee::getName() {
	return _name;
}

string Employee::getSalary() {
	return _salary;
}

void Employee::addInformation(){
	ofstream fileStreamOut;
	fileStreamOut.open("database.txt", ios::app);

	cout << "Enter employee's ID: ";
	cin >> ws;//Fix bug: missing line of code
	getline(cin, _id);

	cout << "Enter employee's name: ";
	getline(cin, _name);

	cout << "Enter employee's salary: ";
	getline(cin, _salary);

	fileStreamOut << endl << _id << setw(20) << _name << setw(20) << _salary;
	fileStreamOut.close();
}

void Employee::searchID(){
	ifstream fileStreamIn("database.txt");
	bool idFound = false;
	string id, name, salary, findID;
	fileStreamIn.seekg(42); // set cursor based on set(w) in file.txt
	cout << "Enter employee's ID: ";
	cin >> ws;//Fix bug: missing line of code

	getline(cin, findID);

	cout << "ID" << setw(20) << "Name" << setw(20) << "Salary";
	while(fileStreamIn >> id >> name >> salary)
	{
		if (findID == id){
			cout  << endl << id << setw(20) <<  name << setw(20) << salary;
			idFound = true;
		}
	}

	if (!idFound) {
		cout <<  endl << "--" << setw(20) << "--" << setw(20) << "--\n";
		cout << "Sorry, we can't find the user with your entered ID \n";
	}
	fileStreamIn.close();
}

void Employee::searchName(){
	ifstream fileStreamIn("database.txt");
	bool nameFound = false;
	string findName, id, salary, name;

	fileStreamIn.seekg(42);
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
		cout << "Sorry, we can't find the user with your entered name\n";
	}
	fileStreamIn.close();
}


void Employee::searchSalary(){
	ifstream fileStreamIn("database.txt");
	bool salaryFound = false;
	string name, id, salary, findSalary;

	fileStreamIn.seekg(42);
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
		cout <<  endl << "--" << setw(20) << "--" << setw(20) << "--";
		cout << "Sorry, we can't find the user with your entered ID";
	} 
	fileStreamIn.close();
}