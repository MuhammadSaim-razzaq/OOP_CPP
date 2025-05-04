#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){

    ofstream f1("data_records.txt");
    if(!f1.is_open()){
        cout<<"Couldn't open file."<<endl;
        return 0;
    }
    f1<<"Record 1\n";
    f1<<"Record 2\n";
    f1<<"Record 3\n";
    f1<<"Record 4\n";
    f1.close();

    ifstream f2("data_records.txt");
    if(!f2.is_open()){
        cout<<"Couldn't open file."<<endl;
        return 0;
    }

    f2.seekg(20,ios::beg); //"record 1\n = 10" As moving to line 3 would require 18 bytes (2*9)
    string record;

    getline(f2,record);
    cout<<"Third Record: "<<record<<endl;
    f2.close();
    return 0;
}
