#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string input;
    cout << "Enter your String: "<<endl;
    getline(cin, input);
    return input;
}

   void  PrintfirstLetterInWord(string S1)
{
    bool IsFirstLetter = true;
    cout << "\nConverting First letter of this string: \n";
    for (int i = 0; i < S1.length(); i++)
    {

        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }

        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }

    cout << S1 << endl;
}


int main()
{

    PrintfirstLetterInWord(ReadString());

    system("pause>0");
}

