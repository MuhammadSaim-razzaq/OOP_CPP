#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream outFile("sensor_log.txt");

    if(!outFile.is_open()){
        cout<<"couldn't open file."<<endl;
        return 0;
    }

    outFile<<"Sensor 1: 25.5 C"<<endl;
    streampos pos1=outFile.tellp();
    cout<<"Write position after first line: "<<pos1<<endl;

    outFile<<"Sensor 2: 98.1 %RH"<<endl;
    streampos pos2=outFile.tellp();
    cout<<"Write position after second line: "<<pos2<<endl;

    outFile.close();
    return 0;
}
