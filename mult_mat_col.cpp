#include <iostream>
#include <vector>

using namespace std;

void multiplyMatricesColumnOrder(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int M, int N, int X) {
    for (int j = 0; j < X; j++) {
        for (int i = 0; i < M; i++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void printMatrix(const vector<vector<int>>& matrix, int rows, int cols, const string& name) {
    cout << "Matriz " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int M = 2, N = 3, X = 2;

    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};

    vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};

    vector<vector<int>> C(M, vector<int>(X, 0));

    printMatrix(A, M, N, "A");
    printMatrix(B, N, X, "B");

    multiplyMatricesColumnOrder(A, B, C, M, N, X);

    printMatrix(C, M, X, "C (Resultado - Ordem de Coluna)");

    return 0;
}