#include<iostream>
using namespace std;

int FabSeries(int Num)
{
    
    if (Num == 0 || Num == 1)
        return Num;

    
    return FabSeries(Num - 1) + FabSeries(Num - 2);
}
//wihout using recursive 

void PrintFabSeries(short Number)
{

    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "0  1 ";
    for (short i = 1; i < Number; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber <<"  ";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    
    for (int i = 0; i <= 10; i++)
    {
        cout << FabSeries(i) << "  ";
    }
    cout << endl;
    cout<< endl <<"without using recursive : " << endl;
    
    PrintFabSeries(10);
    system("pause>0");
    return 0;
}