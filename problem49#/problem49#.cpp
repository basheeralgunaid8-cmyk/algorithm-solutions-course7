#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const string FileClientName = "Client.txt";

struct stClientRecord
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string S1, string delim) {
    vector<string> vResult;
    size_t pos = 0;
    string token;

    while ((pos = S1.find(delim)) != string::npos) {
        token = S1.substr(0, pos);
        if (!token.empty()) {
            vResult.push_back(token);
        }
        S1.erase(0, pos + delim.length());
    }

    if (!S1.empty()) {
        vResult.push_back(S1);
    }
    return vResult;
}

stClientRecord ConvertRecordToLine(string Line, string Seperator = "#//#") {
    stClientRecord RecordLine;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    if (vClientData.size() >= 5) {
        RecordLine.AccountNumber = vClientData[0];
        RecordLine.PinCode = vClientData[1];
        RecordLine.Name = vClientData[2];
        RecordLine.Phone = vClientData[3];
        RecordLine.AccountBalance = stod(vClientData[4]);
    }
    return RecordLine;
}

string ConvertClientToLine(stClientRecord Client, string Seperator = "#//#") {
    string DataLine = "";
    DataLine += Client.AccountNumber + Seperator;
    DataLine += Client.PinCode + Seperator;
    DataLine += Client.Name + Seperator;
    DataLine += Client.Phone + Seperator;
    DataLine += to_string(Client.AccountBalance);
    return DataLine;
}

vector<stClientRecord> LoadDataFromFile(string FileName) {
    vector<stClientRecord> vClients;
    fstream Myfile;
    Myfile.open(FileName, ios::in);

    if (Myfile.is_open()) {
        string line;
        stClientRecord client;
        while (getline(Myfile, line)) {
            if (!line.empty()) {
                client = ConvertRecordToLine(line);
                vClients.push_back(client);
            }
        }
        Myfile.close();
    }
    return vClients;
}

void SaveClientToFile(stClientRecord Client, string FileName) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open()) {
        string DataLine = ConvertClientToLine(Client);
        MyFile << DataLine << endl;
        MyFile.close();
    }
}

void PrintClientCard(stClientRecord Client) {
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string accountNum, stClientRecord& client) {
    vector<stClientRecord> vClients = LoadDataFromFile(FileClientName);

    for (stClientRecord& C : vClients) {
        if (C.AccountNumber == accountNum) {
            client = C;
            return true;
        }
    }
    return false;
}

bool IsAccountNumberExist(string AccountNumber) {
    vector<stClientRecord> vClients = LoadDataFromFile(FileClientName);
    for (stClientRecord& Client : vClients) {
        if (Client.AccountNumber == AccountNumber) {
            return true;
        }
    }
    return false;
}

stClientRecord ReadNewClient() {
    stClientRecord Client;

    do {

        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);

        if (IsAccountNumberExist(Client.AccountNumber))
        {
            cout << "Account Number already exists! Please enter a different one.\n";
        }
    } while (IsAccountNumberExist(Client.AccountNumber));

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    cin.ignore();

    return Client;
}

string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    cin.ignore();
    return AccountNumber;
}

void PrintPattern() {
    cout << "____________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Number"
        << "| " << left << setw(10) << "Pin Code"
        << "| " << left << setw(25) << "Client Name"
        << "| " << left << setw(15) << "Phone"
        << "| " << left << setw(10) << "Balance" << endl;
    cout << "____________________________________________________________________________________\n";
}

void PrintClientRecords(vector<stClientRecord>& vClients) {
    cout << "\n\t\tClient List (" << vClients.size() << ") Client(s).\n";
    PrintPattern();

    for (stClientRecord& client : vClients) {
        cout << "| " << left << setw(15) << client.AccountNumber
            << "| " << left << setw(10) << client.PinCode
            << "| " << left << setw(25) << client.Name
            << "| " << left << setw(15) << client.Phone
            << "| " << left << setw(10) << client.AccountBalance << endl;
    }
    cout << "____________________________________________________________________________________\n";
}

void AddNewClient() {
    stClientRecord Client = ReadNewClient();
    SaveClientToFile(Client, FileClientName);
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

int main()
{
    stClientRecord Client;
    AddClients();
    vector<stClientRecord> vClients = LoadDataFromFile(FileClientName);
    PrintClientRecords(vClients);
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientCard(Client);
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }

    system("pause>0");
    return 0;
}
