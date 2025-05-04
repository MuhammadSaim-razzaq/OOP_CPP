#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){

    ifstream f;
    f.open("vehicle.txt");
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
        else if(make=="Hybrid Truck"){
            size_t pos1=extraData.find(":");
            size_t pos2=extraData.find("|");
            size_t pos3=extraData.find(":",pos2);
            if(pos1 != string::npos){
                string carg = extraData.substr(pos1+1,pos2-pos1-1);
                string batt = extraData.substr(pos3+1);
                int cargo= stoi(carg);
                int battery= stoi(batt);
                cout<<"-------------------"<<endl;
                cout<<"Vehicle ID: "<<model<<endl;
                cout<<"Battery: "<<battery<<endl;
                cout<<"Cargo: "<<cargo<<endl;
            }
        }
        else{
            cout<<"Invalid Vehicle type!"<<endl;
        }
    }

    f.close();
    return 0;
}
