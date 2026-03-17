 #include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool IsNumberInMatric(int arr[3][3], int number,int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == number)
            {
                return true;
            }
        }

    }
    return false;
}

void ntIntersectedNumber(int arr[3][3], int arr2[3][3], int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int Number = arr[i][j];
            if (IsNumberInMatric(arr2,Number,rows,cols))
            {
                cout <<setw(3) << Number <<"   ";
            }
        }
        
    }

}
int main()
{
    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} }; 
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33}};

    cout << "\nMatrix1:\n";  PrintMatrix(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";  PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are: \n\n";
    ntIntersectedNumber(Matrix1, Matrix2, 3, 3);

    system("pause>0");
}

