#include <iostream>

using namespace std;


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

bool CheckaScalarMatrix(int arr[3][3], int rows, int cols)
{
    int FirstDigitElement = arr[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j && arr[i][j] != FirstDigitElement)
            {
                return 0;
            }
            else  if (i != j && arr[i][j] != 0)
            {
                return 0;
            }

        }

    }
    return 1;
}

int main()
{
   
    int arr1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };

    PrintMatrix(arr1, 3, 3);
    if (CheckaScalarMatrix(arr1, 3, 3))
        cout << "Yes , it is a scalar matrix" << endl;
    else
        cout << "No , it is not a scalar matrix" << endl;

    return 0;
}
