#include <iostream>
#include <string>
using namespace std;

char ReadCharacter()
{
   char input;
    cout << "Enter your character : " << endl;
    cin >> input;
    return input;
}
char  ConvertFromUpperTOLowerAndViceVersa(char S1)
{
   
    if (isupper(S1))
    { 
        return tolower(S1);
    }
    else
    {
        return toupper(S1);
    }
}


int main()
{
    char Ch = ReadCharacter();
   Ch= ConvertFromUpperTOLowerAndViceVersa(Ch);
   cout <<"Converted character: "<< Ch << endl;
    system("pause>0");

}

