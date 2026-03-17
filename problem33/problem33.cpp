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

short CountVowelLetter(string S)
{
    int counter = 0;
    
    for (int i = 0; i < S.length(); i++)
    {
        if (IsVowel(S[i]) )
            counter++;

    }
    return counter;
}
int main()
{
   
    string S = ReadString();
    cout << "Number of vowels: " << CountVowelLetter(S) << endl;

    system("pause>0");
}

