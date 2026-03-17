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
enum enumenWhatToCount{ SmallLetters = 0, CapitalLetters = 1,All = 3 };

short CountLetters(string S1, enumenWhatToCount WhatToCount = enumenWhatToCount::All)
{
    if(WhatToCount == enumenWhatToCount::All)
    {
        return S1.length();
    }
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    { 

    if (WhatToCount == enumenWhatToCount::CapitalLetters && isupper(S1[i]))
        Counter++;

    if (WhatToCount == enumenWhatToCount::SmallLetters && islower(S1[i]))
        Counter++;

    }
    return Counter;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString Length = " << CountLetters(S1, enumenWhatToCount::All);
    cout << "\nCapital Letters Count= " << CountLetters(S1, enumenWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count= " << CountLetters(S1, enumenWhatToCount::SmallLetters);

    system("pause>0");
}

