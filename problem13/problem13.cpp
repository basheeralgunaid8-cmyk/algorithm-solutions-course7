#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillOrderMatrix(int arr1[3][3],int rows, int cols)
{
   
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            
            arr1[i][j] = RandomNumber(0,1);
            
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

bool CheckIdenetityMatrix(int arr[3][3], int rows, int cols)
{

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j && arr[i][j] != 1)
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
    srand((unsigned)time(NULL));
    int arr1[3][3];

    FillOrderMatrix(arr1, 3, 3);
    PrintMatrix(arr1, 3, 3);
    if (CheckIdenetityMatrix(arr1, 3, 3))
        cout << "Yes , it is an identity matrix" << endl;
    else
        cout << "No , it is not an identity matrix" << endl;

    return 0;
}
