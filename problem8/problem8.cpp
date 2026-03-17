#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillOrderMatrix(int arr1[3][3], int arr2[3][3], int rows, int cols)
{
    int counter = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            counter++;
            arr1[i][j] = counter;         
            arr2[i][j] = RandomNumber(1, 9); 
        }
    }
}

void PrintMatrix(int arr[3][3], int rows, int cols, string matrixName)
{
    cout << matrixName << ":" << endl;
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

void MultiplyMatrices(int arr1[3][3], int arr2[3][3], int rows, int cols)
{
   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<< arr1[i][j] * arr2[i][j]<<" ";
        }
        cout << endl;
    }
    
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3];

    FillOrderMatrix(arr1, arr2, 3, 3);

    
    
    PrintMatrix(arr1, 3, 3, "Matrix A (Ordered)");
    PrintMatrix(arr2, 3, 3, "Matrix B (Random)");
    cout << "Multiply Matrices" << endl;
    MultiplyMatrices(arr1, arr2, 3, 3);

    return 0;
}
