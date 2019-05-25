/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 06: 06011_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat Apr 20 23:46:48 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06011_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of words in the list:
{"include", "while", "for", "goto", "string"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Student may define some more functions as need
int i=0;



/* Implement the function to reverse the text without any loops */
void reverse(char* text) {
    if (i < strlen(text) - i - 1) {
	char number = text[i];
	text[i] = text[strlen(text) - i - 1];
	text[strlen(text) - i - 1] = number;
	i++;
	reverse(text);
}

}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include", "while", "for", "goto", "string"};
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
        getline(fileIn, line);
        char* cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        reverse(cstr);
        cout << cstr;
        fileIn.close();
        delete[] cstr;
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

