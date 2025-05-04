#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){

    ifstream f;
    f.open("actual_vehicles.txt");
    if(!f.is_open()){
        cout<<"Couldn't open the file"<<endl;
        return 0;
    }

    string line;
    while(getline(f,line)){
        if(line.empty() || line[0]=='/') continue;

        string make, model, type, year, extraData, certification;
        istringstream ss(line);

        getline(ss,make,',');
        getline(ss,model,',');
        getline(ss,type,',');
        getline(ss,year,',');
        getline(ss,extraData,',');
        getline(ss,certification,',');

        if(make=="Autonomous Car"){
            size_t pos= extraData.find(":");
            if(pos != string::npos){
                string version= extraData.substr(pos+1);
                float softwareVersion= stof(version);
                cout<<"-------------------"<<endl;
                cout<<"Vehicle ID: "<<model<<endl;
                cout<<"Software Version: "<<softwareVersion<<endl;
            }
        }

        else if(make=="ElectricVehicle"){
            size_t pos= extraData.find(":");
            if(pos != string::npos){
                string capacity= extraData.substr(pos+1);
                int batteryCapacity= stoi(capacity);
                cout<<"-------------------"<<endl;
                cout<<"Vehicle ID: "<<model<<endl;
                cout<<"Battery Capacity: "<<batteryCapacity<<endl;
            }
        }
    }

    f.close();
    return 0;
}
