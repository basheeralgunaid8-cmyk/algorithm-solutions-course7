#include <iostream>
#include<string>
#include<vector>
using namespace std;
void ReplaceString(string S1, string StringToReplace, string ReplaceTo)
{
    int pos = S1.find(StringToReplace);

    while (pos != string::npos)
    {
        S1 = S1.substr(0, pos) + ReplaceTo + S1.substr(pos + StringToReplace.length());
        pos = S1.find(StringToReplace, pos + ReplaceTo.length());

    }

    cout << S1 << endl;
}
//using another way to solve !!!
vector<string> SplitFuction(string S1, string delim = " ")
{
    vector<string>vstring;
    
    short pos = 0;
    string Sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        Sword = S1.substr(0, pos);

        if (Sword != " ")
        {
            vstring.push_back(Sword);

        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        vstring.push_back(S1);
    }

    return vstring;
}

string JoinString(vector<string>vString, string dilem)
{
    string S1 = " ";

    for (string& s : vString)
    {
        S1 = S1 + s + dilem;
    }

    return S1.substr(0, S1.length() - dilem.length());
}

string LowerAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}
string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    vector<string>vstring = SplitFuction(S1, " ");
    for (string& s : vstring)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = sRepalceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sRepalceTo;
            }
        }
    }
    return JoinString(vstring, " ");
 }
int main()
{

    string S1 = "Welcome to China , China is a nice country!";
    string StringToReplace = "china";
    string ReplaceTo = "USA";
    cout << "\nOriginal String:\n" << S1;   
    cout << "\n\nReplace with match case: ";   
    cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);    
    cout << "\n\nReplace with dont match case: ";    
    cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);
    system("pause>0");
}

