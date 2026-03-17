#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void FillOrderMatrix(int arr[3][3], int rows, int cols)
{
    int counter=0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            counter++  ;
            arr[i][j]=counter;
        }
    }
}

void PrintMatrix(int arr[3][3], int rows, int cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";

        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));


    int arr[3][3];
   
   FillOrderMatrix(arr, 3, 3);
    cout << "Order matrix:" << endl;
    PrintMatrix(arr, 3, 3);

  
    return 0;
}
