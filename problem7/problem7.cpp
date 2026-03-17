#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void FillOrderMatrix(int arr[3][3], int rows, int cols)
{
    int counter = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            counter++;
            arr[i][j] = counter;
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

void TransposeMatrix(int arr[3][3],int ArrTransposeMatrix[3][3], int rows, int cols)
{
   
    for (short i = 0; i < cols; i++)
    {
        for (short j = 0; j < rows; j++)
        {
            ArrTransposeMatrix[i][j] = arr[j][i];

        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));


    int arr[3][3];
    int ArrTransposeMatrix[3][3];
    FillOrderMatrix(arr, 3, 3);
    cout << "The following is 3*3 matrix with order matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    
    
    TransposeMatrix(arr, ArrTransposeMatrix,3, 3);
    cout << "The following is transpose of the matrix: " << endl;
    PrintMatrix(ArrTransposeMatrix, 3, 3);
    return 0;
}
