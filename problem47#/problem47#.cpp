#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const string FileClientName = "Client.txt";  


struct stClientRecord {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
};

stClientRecord ReadNewClient() {
    stClientRecord Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber); 

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);       
    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    getline(cin, Client.AccountBalance);

    return Client;
}


string ConvertRecordToLine(stClientRecord Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += stod(Client.AccountBalance);
    return stClientRecord;
}


void AddDataLineToFile(string FileName, string stDataLine) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app); 
    if (MyFile.is_open()) {
        MyFile << stDataLine << endl;
    }
    MyFile.close();
}

void AddNewClient() {
    stClientRecord Client = ReadNewClient();
    AddDataLineToFile(FileClientName, ConvertRecordToLine(Client));
}

void AddClients() {
    char AddMore = 'Y';
    do {
        system("cls"); 
        cout << "Adding New Client:\n\n";
        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
        cin.ignore(); 
    } while (toupper(AddMore) == 'Y');
}

int main() {
    AddClients();
    system("pause>0"); 
    return 0;
}
