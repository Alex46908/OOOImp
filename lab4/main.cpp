#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int getLineWithMaxOne(int** matrix, int rows, int cols) {
    int 
        maxLine = 0,
        maxCol = 0;

    for (int i = 0; i < rows; ++i) {
        int col = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                col++;
            }
        }

        if (maxCol < col) {
            maxLine = i + 1;
            maxCol = col;
        }
    }

    return maxLine;
}


bool rowsIsSimilar(int* row1, int* row2, int cols) {
    for (int step = 0; step < cols; step++) {
        bool isSimilar = true;

        for (int i = 0; i < cols - step; i++) {
            if (row1[i] != row2[i + step]) {
                isSimilar = false;
                break;
            }
        }

        for (int i = 0; i < step; i++) {
            if (row1[i + (cols - step)] != row2[i]) {
                isSimilar = false;
                break;
            }
        }

        if (isSimilar) {
            return true;
        }
    }

    return false;
}

void similarRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int i1 = i + 1; i1 < rows; i1++) {
            if (rowsIsSimilar(matrix[i], matrix[i1], cols)) {
                cout << i + 1 << " строка и " << i1 + 1 << " строка одинаковы!" << endl; 
            }
        }
    }
}

int main() {
    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    string answer;

    cout << "Сгенерировать автоматически? Y/N" << endl;
    cin >> answer;

    if (answer == "Y" || answer == "y") {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, 111221311);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) { 
                int el = dist(gen) % 2 == 0;

                matrix[i][j] = el;
            }
        }
    } else {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) { 
                cout << i + 1 << " строка " << j + 1 << " столбец: (0 или 1)" << endl;
                int el;
                cin >> el;

                if (el != 0) {
                    el = 1;
                }

                matrix[i][j] = el;
            }
        }
    }

    cout << "Ваша Матрица:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << i + 1 << "  ";
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    similarRows(matrix, rows, cols);

    cout << "Строка с максимальным количеством 1: " << getLineWithMaxOne(matrix, rows, cols) << endl;

    return 0;
}