#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


const string FileClientName = "Client.text";


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
    string RecordLine = "";
    RecordLine += Client.AccountNumber + Seperator;
    RecordLine += Client.PinCode + Seperator;
    RecordLine += Client.Name + Seperator;
    RecordLine += Client.Phone + Seperator;
    RecordLine += Client.AccountBalance;
    return RecordLine;
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


void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent) {
    fstream MyFile;

    MyFile.open(FileName, ios::in); 
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line)) 
        {
            vFileContent.push_back(Line);
        }
        MyFile.close();
    }
}


vector<string> SplitString(string s, string delimiter = "#//#")
{
    vector<string> vResult;
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        vResult.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    vResult.push_back(s);

    return vResult;

}

void PrintPatter()
{
    cout << "____________________________________________________________________________________\n\n";

    cout << "| " << left << setw(15) << "Account Number"
        << "| " << left << setw(10) << "Pin Code"
        << "| " << left << setw(25) << "Client Name"
        << "| " << left << setw(15) << "Phone"
        << "| " << left << setw(10) << "Balance" << endl;

    cout << "____________________________________________________________________________________\n";

}
void PrintClientRecords(vector<string>& vFileContent)
{
    cout << "\n\t\tClient List (" << vFileContent.size() << ") Client(s).\n";
    PrintPatter();

    for (string& line : vFileContent) {
        vector<string> ClientData = SplitString(line);
        if (ClientData.size() == 5) {
            cout << "| " << left << setw(15) << ClientData[0]
                << "| " << left << setw(10) << ClientData[1]
                << "| " << left << setw(25) << ClientData[2]
                << "| " << left << setw(15) << ClientData[3]
                << "| " << left << setw(10) << ClientData[4] << endl;
        }
    }

    cout << "____________________________________________________________________________________\n";
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
    vector<string> vFileContent;

    AddClients();
    LoadDataFromFileToVector(FileClientName, vFileContent);
    PrintClientRecords(vFileContent);

    system("pause>0");
    return 0;
}
