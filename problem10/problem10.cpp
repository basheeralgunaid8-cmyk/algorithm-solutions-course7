#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int arr1[3][3],  int rows, int cols)
{
    
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
           
            arr1[i][j] =  RandomNumber(1, 9);
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
   
}

int  SumMatrices(int arr1[3][3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr1[i][j];
        }
        
    }
    return sum;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3];

    FillRandomMatrix(arr1, 3, 3);
    PrintMatrix(arr1, 3, 3);
   
    cout << "The sum of the matrix is : " << SumMatrices(arr1, 3, 3) << endl;

    return 0;
}
