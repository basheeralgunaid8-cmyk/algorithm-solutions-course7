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
string  UpperLetterInWord(string S1)
{

    for (int i = 0; i < S1.length(); i++)
    {

        S1[i] = toupper(S1[i]);

    }

    return S1;
}
string  LowerLetterInWord(string S1)
{
   
    for (int i = 0; i < S1.length(); i++)
    {

    S1[i] = tolower(S1[i]);
       
    }

    return S1;
}


int main()
{
    string S = ReadString();
    cout << "\nString after conversion TO lower case:\n";
    S = LowerLetterInWord(S);
    cout << S << endl;
    cout << endl;
    string S2= ReadString();
    cout << "\nString after conversion TO Upper case:\n";
    S2 = UpperLetterInWord(S2);
    cout << S2 << endl;
    system("pause>0");

}

