#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string input;
    cout << "Enter your String: ";
    getline(cin, input);
    return input;
}

void  PrintfirstLetterInWord(string S1)
{
    bool IsFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (int i = 0; i < S1.length(); i++)
    {

        if (S1[i] != ' ' && IsFirstLetter)
        {
            cout << S1[i] << endl;
        }
      
        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }
   
}

int main()
{
   
    PrintfirstLetterInWord(ReadString());

    system("pause>0");
}

