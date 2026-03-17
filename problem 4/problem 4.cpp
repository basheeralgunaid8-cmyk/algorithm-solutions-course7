#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int arr[3][3], int rows, int cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
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
int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short j = 0; j <= Rows - 1; j++)
    {
        Sum += arr[j][ColNumber];
    }

    return Sum;

}
void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe the following are the sum of each column in the matrix:\n";

    for (short i = 0; i < Cols; i++)
    {
        cout << " Column " << i + 1 << " Sum = " << ColSum(arr, Cols, i) << endl;
    }

}



int main() {
    srand((unsigned)time(NULL));


    int arr[3][3];
    FillRandomMatrix(arr, 3, 3);
    cout << "Random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    PrintEachColSum(arr, 3, 3);

   
    return 0;
}
