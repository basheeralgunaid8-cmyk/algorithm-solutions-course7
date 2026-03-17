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


bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

void  CountVowelLetter(string S)
{
   

    for (int i = 0; i < S.length(); i++)
    {
        if (IsVowel(S[i]))
            cout << S[i]<<" ";
    }
    cout << endl;
}
int main()
{

    string S = ReadString();
    CountVowelLetter(S);

    system("pause>0");
}

