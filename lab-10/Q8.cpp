#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){

    ofstream f("config.txt");
    f<<"AAAAABBBBBCCCCC";
    f.close();

    fstream file("config.txt",ios::in|ios::out);
    file.seekp(5);

    file<<"XXXXX";
    file.close();

    ifstream infile("config.txt");
    string content;
    getline(infile,content);
    cout<<"Updated content: "<<content<<endl;
    infile.close();

    return 0;
}
