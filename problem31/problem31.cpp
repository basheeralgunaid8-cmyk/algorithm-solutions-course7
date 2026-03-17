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
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1; return Ch1;
}
short CountLetter(string S1, char character)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if ( S1[i]== character )
        {
            counter++;
        }   
    }
    return counter;
}
char  InvertLetterCase(char char1) 
{ 
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
short CountLetter2(string S1, char character)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]) || islower(S1[i]) && S1[i] == character)
        {
            counter++;
        }

    }
    return counter;
}
// another way to solve 
short CountLetter3(string S1, char character,bool MatchCase =true)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == character)
                counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(character))
                counter++;
        }
    }
    return counter;
}
int main()
{

    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1);
    cout << "\nLetter \'" << Ch1 << "\' or "<< InvertLetterCase(Ch1)<< " Count = " << CountLetter2(S1, Ch1);
    system("pause>0");


}

