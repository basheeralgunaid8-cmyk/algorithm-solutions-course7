#include <iostream>
#include<string>
#include<vector>
using namespace std;

string JoinString(vector<string>vString, string dilem)
{
    string S1 = " ";

    for (string& s : vString)
    {
        S1 = S1 + s + dilem;
    }

    return S1.substr(0,S1.length() - dilem.length());
}
int main()
{
    vector<string>vString = { "ali","salah","fadi" };

    cout << "Vector after joining : " << endl;
    cout << JoinString(vString, " ");

    system("pause>0");
}
