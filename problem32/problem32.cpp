#include <iostream>
#include<string>
using namespace std;

char ReadChar()
{
    char char1;
    cout << "Enter a character :" << endl;
    cin >> char1;
    
    return char1;
}

bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}
int main()
{
    char Ch1 = ReadChar();

    if(IsVowel(Ch1))
        cout << "\nYES Letter \'" << Ch1 << "\' is vowel";
    else 
        cout << "\nNo Letter \'" << Ch1 << "\' is not  vowel";

    system("pause>0");
}

