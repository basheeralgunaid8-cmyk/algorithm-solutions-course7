#include <iostream>
#include<string>
using namespace std;
string ReadString()
{
    string str;
    cout << "Enter your string:" << endl;
    getline(cin, str);

    return str;
}

short PrintEachWordInLine(string S1)
{
    string delim = " ";
    cout << "Your string words are:" << endl;
    short pos = 0;
    string Sword;
    int counter = 0;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        Sword = S1.substr(0, pos);

        if (Sword != " ")
        {
            counter++;
            
        }
        
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        counter++;
    }

    return counter;
}

int main()
{
    cout<<"The number of words in your string are :  "<<PrintEachWordInLine(ReadString())<<endl;

    system("pause>0");
}

