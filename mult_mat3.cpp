#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int BLOCK_SIZE = 32;

void multiplyMatricesBlocking(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int M, int N, int X) {
    for (int i = 0; i < M; i += BLOCK_SIZE) {
        for (int j = 0; j < X; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                // Loop dentro do bloco
                for (int ii = i; ii < min(i + BLOCK_SIZE, M); ii++) {
                    for (int jj = j; jj < min(j + BLOCK_SIZE, X); jj++) {
                        int sum = 0;
                        for (int kk = k; kk < min(k + BLOCK_SIZE, N); kk++) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
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
    int M = 512, N = 512, X = 512;

    // Inicializar matrizes A, B e C
    vector<vector<int>> A(M, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(X, 2));
    vector<vector<int>> C(M, vector<int>(X, 0));

    auto start = high_resolution_clock::now();

    multiplyMatricesBlocking(A, B, C, M, N, X);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Tempo de execução: " << duration.count() << " ms" << endl;

    if (M <= 16 && X <= 16) {
        printMatrix(C, M, X, "C (Resultado - Blocking)");
    }

    return 0;
}