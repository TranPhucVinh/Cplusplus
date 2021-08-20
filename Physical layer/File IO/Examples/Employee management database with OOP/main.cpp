

#include "employee.h"

void add();
void search();
void display();
void loop();

char enteredChoice[1], enteredSearchChoice[1];

int main(){
	cout << "Employee management program \n";
	PROGRAM_OPTION:
		cout << "Enter corresponding number: \n";
		cout << "1. Add employee's information \n";
		cout << "2. Display employee's information \n";
		cout << "3. Search \n";
		cout << "4. Exit \n";
		cout << "Your choice: ";

		fgets(enteredChoice, 2, stdin);
		while ((getchar()) != '\n'); //Must have this line

		switch (enteredChoice[0])
		{
			case '1':
				add();
				break;
			case '2':
				{
					cout << "ID" << setw(20) << "Name"<< setw(20) << "Salary" << endl;
					display();
				}
				break;
			case '3':
				search();
				break;
			case '4':
				cout << "Thanks for using the program \n";
				break;
			default:	
				cout << "Sorry, you have entered wrong number. Please try again \n";
				goto PROGRAM_OPTION;	
		}
}

void add() {
	int employeeNum;
	cout << "Number of employee you wish to enter: ";
	cin >> employeeNum;
	for (int i = 0; i < employeeNum; i++) {
		Employee employee;
		employee.addInformation();
	}
	cout << "Thanks for using the program \n";
}

void search(){
	Employee employee;
	SEARCH_OPTION:
		cout << "Enter the corresponding number \n";
		cout << "1. Search by ID \n";
		cout << "2. Search by name \n";
		cout << "3. Search by salary \n";
		cout << "Your choice: ";

		fgets(enteredSearchChoice, 2, stdin);
		while ((getchar()) != '\n'); //Must have this line

		switch (enteredSearchChoice[0]){
			case '1':
				employee.searchID();
				break;
			case '2':
				employee.searchName();
				break;
			case '3':
				employee.searchSalary();
				break;
			default:
				cout << "Sorry, you have entered wrong number. Please try again \n";
				goto SEARCH_OPTION;
		}
}

void display(){
	ifstream fileStreamIn("database.txt");
	string id, name, salary;
	fileStreamIn.seekg(42); 
	while (fileStreamIn >> id >> name >> salary)
	{
		cout << id << setw(20) << name << setw(20) << salary << endl;
	}
}