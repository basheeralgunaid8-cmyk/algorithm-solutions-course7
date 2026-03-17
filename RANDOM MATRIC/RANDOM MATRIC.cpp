#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int rows, int cols, int matrix[3][3]) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            matrix[i][j] = RandomNumber(1, 100); 
        }
    }
}

void PrintMatrix(int rows, int cols, int matrix[3][3]) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    short rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of cols: ";
    cin >> cols;

    int matrix[3][3]; // fixed maximum size
    FillRandomMatrix(rows, cols, matrix);
    cout << "Random matrix:" << endl;
    PrintMatrix(rows, cols, matrix);

    return 0;
}
