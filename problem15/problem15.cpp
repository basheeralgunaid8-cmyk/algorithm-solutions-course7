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

int  CountNumberInMatrix(int arr[3][3], int rows, int cols,int number)
{
    int counter = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr[i][j]==number)
            {
                counter++;
            }
        }

    }
     return counter;
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
   cout<<"The number is repeated : "<<  CountNumberInMatrix(arr1, 3, 3, number)<< endl;
    return 0;
}
