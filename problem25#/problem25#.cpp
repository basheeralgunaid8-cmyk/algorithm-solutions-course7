#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string input;
    cout << "Enter your String: " << endl;
    getline(cin, input);
    return input;
}

string  LowerfirstLetterInWord(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {

        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}


int main()
{
    string S = ReadString();
    cout << "\nString after conversion:\n";


    S=  LowerfirstLetterInWord(S);
    cout << S << endl;

    system("pause>0");
}

