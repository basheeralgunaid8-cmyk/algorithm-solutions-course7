#include <iostream>
#include<string>
#include<vector>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter your string:" << endl;
    getline(cin, str);

    return str;
}

vector<string> SplitFuction(string S1)
{
    vector<string>vstring;
    string delim = " ";
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

void PrintVectorString(string S1)
{
        vector<string> line = SplitFuction(S1);

        cout << "Tokens = " << line.size() << endl;

        for (string &word : line)
        {
            cout << word << endl;
        }
   
}

int main()
{
    PrintVectorString(ReadString());

    system("pause>0");
}

