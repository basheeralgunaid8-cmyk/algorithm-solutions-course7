#include <iostream>
#include<string>
using namespace std;


void PrintMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}

bool IsPalindromeMatrix(int arr[3][3],int  rows,int  cols)
{ 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols/2; j++)
        {
            if (arr[i][j] != arr[i][cols - 1 - j])
            {
                return false;
            }
        }
        cout << endl;
    }
    return true;
}


int main()
{
 int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} }; 
 cout << "\nMatrix1:\n";
 PrintMatrix(Matrix1, 3, 3); 

 if (IsPalindromeMatrix(Matrix1, 3, 3)) 
 { 
     cout << "\nYes: Matrix is Palindrome\n"; 
 } 
 else 
     cout << "\nNo: Matrix is NOT Palindrome\n"; 
 system("pause>0"); 

}



