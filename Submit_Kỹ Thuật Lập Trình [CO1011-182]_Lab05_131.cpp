/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05010_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun Apr 14 16:50:19 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05010_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

struct Employee{
    int id;
    char* name;
    float salary;
};

/* Write the code to find the employeeList whose the highest salary
Return him/her an instant of Employee struct*/
Employee highestSalary(Employee employeeList[], int numberOfEmployee) {
    int max = 0;
	float max_salary = employeeList[0].salary;
	for (int i = 0; i < numberOfEmployee; i++) {
		if (employeeList[i].salary > max_salary) {
			max = i;
			max_salary = employeeList[i].salary;
		}
	}
	return employeeList[max];

}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include"};
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail()) ifs.open(FILENAME, ios::in);
    if (ifs.fail()) return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char* fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char* todoSegment = strstr(fileContent ,"// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char*);
    for (int i = 0; i < numberOfForbiddenKeyword; i++) { if (strstr(todoSegment, forbiddenKeyword[i])) return false; }
    delete[] fileContent;
    return true;
}

int main(int argc, char* argv[]) {
    if (codeCheck() == false) {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }
    // Section: read testcase
    ///Student may comment out this section for local testing
    if (argc < 2) return 0;
    ifstream fileIn;
    try {
        fileIn.open(argv[1]);
        if (fileIn.fail()) throw "Failed to open file.";
        string line;
        int numberOfEmployee;
        getline(fileIn, line);
        numberOfEmployee = stoi(line);
        Employee* employeeList = new Employee[numberOfEmployee];
        int id;
        float salary;
        for (int i = 0; i < numberOfEmployee; i++) {
            getline(fileIn, line);
            id = stoi(line);
            getline(fileIn, line);
            employeeList[i].name = new char[line.length() + 1];
            strcpy(employeeList[i].name, line.c_str());
            getline(fileIn, line);
            employeeList[i].id = id;
            employeeList[i].salary = stof(line);
        }
        // Function call
        Employee result = highestSalary(employeeList, numberOfEmployee);
        cout << "ID: " << result.id << endl;
        cout << "Name: " << (result.name ? result.name: "") << endl;
        cout << "Salary: " << result.salary;
        fileIn.close();
        // Tidy dynamic mem
        for (int i = 0; i < numberOfEmployee; i++) delete[] employeeList[i].name;
        delete[] employeeList;
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

