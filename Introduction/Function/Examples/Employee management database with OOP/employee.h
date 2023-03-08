#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Employee {
	public:
		string getID();
		string getName();
		string getSalary();
		void addInformation();
		void searchID();
		void searchName();
		void searchSalary();

	private: 
		string _name;
		string _id;
		string _salary;
};