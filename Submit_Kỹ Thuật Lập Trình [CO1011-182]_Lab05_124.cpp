/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 05: 05003_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat Apr 13 20:20:34 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05003_sol.cpp"
using namespace std;
/* Please note that your code must not contain any of words in
 {"string", "include"}; */

//---------------------------------------------------------
// Begin implementation
//---------------------------------------------------------

/* Write the code to calculate and print to screen */
void hamming (char* str1, char* str2) {
    if(str1 == NULL || str2 == NULL || strlen(str1) != strlen(str2))
        cout<<"failed";
    int len = strlen(str1);
    int count = 0;
    for(int i=0; i<len; i++) {
        if(str1[i] != str2[i])
            count++;
	}
cout<<count;

}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"string", "include"};
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
        string str1, str2;
        if (!fileIn.eof()) getline(fileIn, str1);
        if (!fileIn.eof()) getline(fileIn, str2);
        char* cstr1 = new char[str1.length() + 1];
        strcpy(cstr1, str1.c_str());
        char* cstr2 = new char[str2.length() + 1];
        strcpy(cstr2, str2.c_str());
        hamming(cstr1, cstr2);
        delete[] cstr1;
        delete[] cstr2;
        fileIn.close();
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

