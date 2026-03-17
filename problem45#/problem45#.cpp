#include <iostream>
#include<string>
#include<vector>
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
    
    cout << "Enter your accoun number?";
    cin >> S.accountnumber;
    cout << "Enter your pin code?";
    cin >> S.PinCode;
    cout << "Enter your name?";
    cin >> S.name;
    cout << "Enter your phone number";
    cin >> S.PhoneNum;
    cout << "Enter your accoun balance?";
    cin >> S.accountBalance;

    return S;
}


string JoinString( stClientRecord ClientRecord, string dilem)
{
    
    string line = ClientRecord.accountnumber + dilem
        + to_string(ClientRecord.PinCode) + dilem
        + ClientRecord.name + dilem
        + to_string(ClientRecord.PhoneNum) + dilem
        + to_string(ClientRecord.accountBalance);

    return line;
}
void PrintClientRecord(stClientRecord ClientRecord, string dilem)
{
    string S1 = JoinString(ClientRecord, dilem);
    cout << S1 << endl;

}
int main()
{
    stClientRecord S1 = ReadClientRecord();

    cout << "Client Record for saving is : " << endl;
    PrintClientRecord(S1,"#//#");

    system("pause>0");
    return 0;
}
