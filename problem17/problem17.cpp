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
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool CheckNumberMatrix(int arr[3][3],int number, int rows, int cols)
{

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if ( arr[i][j] == number)
            {
                return true;
            }
           

        }

    }
    return false;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];

    FillOrderMatrix(arr1, 3, 3);
    PrintMatrix(arr1, 3, 3);
    int number;
    cout << "Enter a number to search for : ";
    cin >> number;
    if (CheckNumberMatrix(arr1,number, 3, 3))
        cout << "Yes , it is there" << endl;
    else
        cout << "No , it is not there" << endl;

    return 0;
}
