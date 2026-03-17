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

    return S1.substr(0, S1.length() - dilem.length());
}

string JoinString(string arr[100],int length, string dilem)
{
    string S1 = " ";

    for ( int i=0;i<length;i++)
    {
        S1 = S1 +arr[i]+ dilem;
    }

    return S1.substr(0, S1.length() - dilem.length());
}

int main()
{
    vector<string>vString = { "Ali","Salah","Fadi" };
     string arr[]= { "Ali","Salah","Fadi" };
    cout << "Vector after joining : " << endl;
    cout << JoinString(vString, " ") << endl;;
    cout << endl<<"Array after joining : " << endl;
    cout << JoinString(arr, 4, " ");
    system("pause>0");
}
