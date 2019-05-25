/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 08: 08000_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat May 04 23:07:04 2019

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#define FILENAME "08000_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of the words in the list
{"..", "~/", "expect"} even in the comment */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Student may define something as need
void read(const char*fileName){
    ifstream f(fileName);
    int temp;
    int dem=0;
    vector<int>a;
    while (f>>temp){
        if(temp!=-999) a.push_back(temp);
    }
    for(int i=0;i<a.size()-1;i++){
        for(int j=i;j<a.size();j++){
            if(a[i]>a[j]){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    int b=a[0]-1;
    cout<<setw(10)<<left<<"Number";
    cout<<setw(1)<<left<<"Count\n";
    for(int i=0;i<a.size();i++){
        if(a[i]>b){
            for(int j=i;j<a.size();j++){
                if(a[j]==a[i]) dem++;
                if(j==a.size()-1){
                    cout<<setw(10)<<left<<a[i];
                    if(a[i]==a[a.size()-1]){
                        cout<<setw(1)<<left<<dem;
                    } 
                    else cout<<setw(1)<<left<<dem<<"\n";
                }
            }
        }
        b=a[i];
        dem=0;
    }
}



/* With the given fileName, read that file and then process the data,
return true if the file exist,else return false. */
bool process(const char* fileName) {
     ifstream file(fileName);
  if(file.good())
    read(fileName);
  return file.good();

}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"..", "~/", "expect"};
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

    try {
        process(argv[1]);
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

