/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 06: 06008_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat Apr 20 21:37:07 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06008_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list:
{"include", "for", "while", "goto"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/* Write the recursive function returning the index of
the first appearance of the key in the array */
int recursiveSearch(int* arr, int numberOfElements, int key) {
    if (numberOfElements == 0)return -1;
	if (arr[numberOfElements - 1] == key)
    return numberOfElements - 1;
recursiveSearch(arr, numberOfElements - 1, key);

}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include", "for", "while", "goto"};
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
	    int key, numberOfElements;
	    fileIn >> key >> numberOfElements;
	    int* arr = new int[numberOfElements];
        for (int i = 0; i < numberOfElements; i++) fileIn >> arr[i];
	    cout << recursiveSearch(arr, numberOfElements, key);
        fileIn.close();
        delete[] arr;
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

