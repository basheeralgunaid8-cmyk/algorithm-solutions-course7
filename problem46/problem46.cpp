#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct stClientRecord
{
    string accountnumber;
    int PinCode;
    string name;
    int PhoneNum;
    int accountBalance;
};

stClientRecord ReadClientRecord()
{
    stClientRecord S;
    cout << "Enter your account number? ";
    cin >> S.accountnumber;
    cout << "Enter your pin code? ";
    cin >> S.PinCode;
    cout << "Enter your name? ";
    cin >> S.name;
    cout << "Enter your phone number? ";
    cin >> S.PhoneNum;
    cout << "Enter your account balance? ";
    cin >> S.accountBalance;
    return S;
}

string ConvertRecordToString(stClientRecord ClientRecord, string delim = "#//#")
{
    string line = ClientRecord.accountnumber + delim
        + to_string(ClientRecord.PinCode) + delim
        + ClientRecord.name + delim
        + to_string(ClientRecord.PhoneNum) + delim
        + to_string(ClientRecord.accountBalance);
    return line;
}

vector<string> SplitString(string str, string delim)
{
    vector<string> vData;
    short pos = 0;
    string word;

    while ((pos = str.find(delim)) != string::npos)
    {
        word = str.substr(0, pos);
        if (!word.empty())
        {
            vData.push_back(word);
        }
        str.erase(0, pos + delim.length());
    }

    if (!str.empty())
    {
        vData.push_back(str);
    }

    return vData;
}

stClientRecord ConvertStringToRecord(string line, string delim = "#//#")
{
    stClientRecord Client;
    vector<string> vData = SplitString(line, delim);

   
        Client.accountnumber = vData[0];
        Client.PinCode = stoi(vData[1]);
        Client.name = vData[2];
        Client.PhoneNum = stoi(vData[3]);
        Client.accountBalance = stod(vData[4]);
    

    return Client;
}

void PrintClientRecord(stClientRecord ClientRecord)
{
    cout << "\nThe following is the extracted client record:\n";
    cout << "Account Number: " << ClientRecord.accountnumber << endl;
    cout << "Pin Code     : " << ClientRecord.PinCode << endl;
    cout << "Name         : " << ClientRecord.name << endl;
    cout << "Phone        : " << ClientRecord.PhoneNum << endl;
    cout << "Account Balance: " << ClientRecord.accountBalance << endl;
}

void DemonstrateConversion()
{
    cout << "READING CLIENT DATA" << endl;
    stClientRecord originalClient = ReadClientRecord();

    string dataLine = ConvertRecordToString(originalClient, "#//#");
    cout << dataLine << endl;

    stClientRecord convertedClient = ConvertStringToRecord(dataLine, "#//#");
    PrintClientRecord(originalClient);

    
}

int main()
{
    DemonstrateConversion();
    system("pause>0");
    return 0;
}
