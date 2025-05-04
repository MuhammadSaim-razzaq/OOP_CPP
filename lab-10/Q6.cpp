#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class InventoryItem{
private:
    int itemID;
    char itemName[20];
public:
    InventoryItem(){}
    InventoryItem(int id, const char *name):itemID(id){
        strncpy(itemName, name, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';
    }  
    
    void saveToFile(const string &filename){
        ofstream outfile(filename,ios::binary);
        if(!outfile){
            cout<<"Couldn't open file."<<endl;
            return;
        }
        outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
        outfile.close();
    }

    void loadFromFile(const string& filename){
        ifstream infile(filename, ios::binary);
        if(!infile){
            cout<<"Error openning file."<<endl;
            return;
        }
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        infile.close();
    }

    void display() {
        cout<<"Loaded Item ID: "<<itemID<<endl;
        cout<<"Loaded Item Name: "<<itemName<<endl;
    }
};

int main(){

    InventoryItem item1(101,"Duster");
    item1.saveToFile("inventory.dat");

    InventoryItem item2;
    item2.loadFromFile("inventory.dat");

    item2.display();
    return 0;

}
