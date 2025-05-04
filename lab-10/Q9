#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
using namespace std;

int main() {
    
    ofstream f1("large_log.txt");
    f1<<"This is the first line.\nThis is the second line.\nThis is the third line.\n";
    f1.close();

    ifstream f2("large_log.txt");
    if (!f2){
        cout<<"Could not open file for reading."<<endl;
        return 0;
    }

    string line;
    getline(f2,line);
    cout<<"First line: "<<line<<endl;
    streampos pos1=f2.tellg();
    cout<<"Position after first read: "<<pos1<< endl;

    getline(f2,line);
    cout<<"Second line: " <<line<<endl;
    streampos pos2=f2.tellg();
    cout<<"Position after second read: "<<pos2<<endl;

    f2.close();
    return 0;
}
