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
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j <= Cols - 1; j++)
    {
        Sum += arr[RowNumber][j];
    }

    return Sum;

}
void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe the following are the sum of each row in the matrix:\n";

    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
    }

}

void StoredRowsIn1Array(int arr[3][3], short Rows, short Cols)
{
    int rowSums[3];

    for (int i = 0; i < Rows; i++)
    {
        rowSums[i] = RowSum(arr, i, Cols);
    }

    cout << "Row sums stored in array: ";
    for (int i = 0; i < Rows; i++) {
        cout << rowSums[i] << " ";
    }
    cout << endl;
}


int main() {
    srand((unsigned)time(NULL));


    int arr[3][3];
    FillRandomMatrix(arr, 3, 3);
    cout << "Random matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    PrintEachRowSum(arr, 3, 3);

    cout << "array of matrix : " << endl;
    StoredRowsIn1Array(arr, 3, 3);
    return 0;
}
