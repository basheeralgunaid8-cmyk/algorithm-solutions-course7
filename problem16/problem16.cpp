#include <iostream>
#include <string>

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

short CountNumberInMatrix(int arr[3][3],int number, int rows, int cols)
{
    int countNum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] == number)
            {
                countNum++;
            }
        }

    }
   
    return countNum;
}

bool CheckSparseMatrix(int arr[3][3], int rows, int cols)
{
    short MaxSize = rows * cols;

    return (CountNumberInMatrix(arr, 0, 3, 3) >= ceil((float) (MaxSize / 2)));

}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3] = { {3,0,0},{2,0,0},{1,0,0} };

    PrintMatrix(arr1, 3, 3);
    CheckSparseMatrix(arr1, 3, 3);
    if (CheckSparseMatrix(arr1, 3, 3))
        cout << "Yes, it is a sparse matrix" << endl;
    else
        cout << "No , it is not a sparse matrix" << endl;

    return 0;
}
