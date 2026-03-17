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
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
string  ConvertLetterCase(string S1)
{
   
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }
    return S1; 
}
int main()
{
    string S = ReadString();
    cout << "\nString after Inverting All Letters Case:\n";
    S = ConvertLetterCase(S);
    cout << S << endl;

    system("pause>0");
}

