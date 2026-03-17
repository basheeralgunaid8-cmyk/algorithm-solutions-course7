#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillOrderMatrix(int arr1[3][3], int rows, int cols)
{
    
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            
            arr1[i][j] = RandomNumber(1,100);
            
        }
    }
}

void PrintMatrix(int arr[3][3], int rows, int cols)
{
   
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int  MiddleRows(int arr[3][3], short Rows, short Cols)
{
    return arr[Rows / 2][Cols];
}
int MiddleCol(int arr[3][3], short Rows, short Cols)
{
    return arr[Rows ][Cols / 2];
}
void PrintMiddleRows(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe the following are the middle Rows in the matrix:\n";

    for (short i = 0; i < Cols; i++)
    {
        cout << MiddleRows(arr, Cols, i) << " ";
    }
    cout << endl;
}
void PrintMiddleCol(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe the following are the middle Rows in the matrix:\n";

    for (short i = 0; i < Cols; i++)
    {
        cout << MiddleCol(arr, i, Cols) << " ";
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillOrderMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    PrintMiddleRows(arr, 3, 3);
    PrintMiddleCol(arr, 3, 3);
   
  
    return 0;
}
