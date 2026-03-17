#include <iostream>
#include<string>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter your string:" << endl;
    getline(cin, str);

    return str;
}

void PrintEachWordInLine(string S1)
{
    string delim = " ";
    cout << "Your string words are:" << endl;
    short pos = 0;
    string Sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        Sword = S1.substr(0, pos);

        if (Sword != "")
        {
            cout << Sword << endl ;
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        cout << S1 << endl;
    }

}

int main()
{
    PrintEachWordInLine(ReadString());

   
}

