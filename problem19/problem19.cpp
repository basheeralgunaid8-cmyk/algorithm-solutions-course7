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

            arr1[i][j] = RandomNumber(1, 100);

        }
    }
}

void PrintMatrix(int arr[3][3], int rows, int cols)
{

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << arr[i][j] <<"  ";
        }
        cout << endl;
    }
    cout << endl;
}

void  MaxNumInMatrix(int arr[3][3],  int rows, int cols)
{

    int Max= 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] > Max)
            {
                Max = arr[i][j];
            }
        }

    }
    cout << "the max value in the matrix is : " << Max << endl;
}

void  MinNumInMatrix(int arr[3][3], int rows, int cols)
{

    int Min = arr[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j] <Min)
            {
                Min = arr[i][j];
            }


        }

    }
    cout << "the min value in the matrix is : " << Min << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];

    FillOrderMatrix(arr1, 3, 3);
    PrintMatrix(arr1, 3, 3);
    
    MaxNumInMatrix(arr1, 3, 3);
    MinNumInMatrix(arr1, 3, 3);
    return 0;
}
