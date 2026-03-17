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
short CountLetter(string S1,char character)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] == character)
        {
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
        system("pause>0");
    
    
}

