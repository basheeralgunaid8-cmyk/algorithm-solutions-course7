#include <iostream>
#include<string>
using namespace std;

string ReadString()
{
    string str;
    cout << "Enter your string : " << endl;
    getline(cin, str);

    return str;
}



void PrintEachWordInString(string S1)
{
    string word = "";

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            word += S1[i]; 
        }
        else
        {
            cout << word << endl; 
            word = "";            
        }
    }

    if (word != "") 
        cout << word << endl;
}

int main()
{

    string S = ReadString();
    PrintEachWordInString(S);

    system("pause>0");
}

