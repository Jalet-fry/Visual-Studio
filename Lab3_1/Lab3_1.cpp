#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>  // Добавлено для std::to_string
#include <limits>  // Добавлено для std::numeric_limits

int getUserInput(const std::string &prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {  // Явное указание пространства имен
            return -1;
        }

        // Проверяем, пуст ли ввод
        if (input.empty()) {
            return -1;
        }

        char *endptr;
        int num = std::strtol(input.c_str(), &endptr, 10);
        if (*endptr != '\0') {
            std::cout << "Это не число. Попробуйте еще раз.\n";
        } else {
            return num;
        }
    }
}

void printMatrix(const std::vector<std::vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (const auto &elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int findMaxAbsElement(const std::vector<std::vector<int>> &matrix, int &row, int &col) {
    int maxAbs = 0;

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (std::abs(matrix[i][j]) > std::abs(maxAbs)) {
                maxAbs = matrix[i][j];
                row = static_cast<int>(i);
                col = static_cast<int>(j);
            }
        }
    }
    return maxAbs;
}

std::vector<std::vector<int>> createReducedMatrix(const std::vector<std::vector<int>> &matrix, int rowToRemove, int colToRemove) {
    std::vector<std::vector<int>> reducedMatrix;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (static_cast<int>(i) == rowToRemove) continue;
        std::vector<int> newRow;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (static_cast<int>(j) == colToRemove) continue;
            newRow.push_back(matrix[i][j]);
        }
        reducedMatrix.push_back(newRow);
    }
    return reducedMatrix;
}

int main() {
    int n = getUserInput("Введите порядок квадратной матрицы: ");
    if (n <= 0) {
        std::cerr << "Некорректный порядок матрицы." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = getUserInput("Элемент [" + std::to_string(i) + "][" + std::to_string(j) + "]: ");
        }
    }

    std::cout << "Исходная матрица:\n";
    printMatrix(matrix);

    int row = -1, col = -1;
    int maxAbsElement = findMaxAbsElement(matrix, row, col);

    std::cout << "Наибольший элемент по модулю: " << maxAbsElement 
              << " в позиции [" << row + 1 << "][" << col + 1 << "]" << std::endl;

    auto reducedMatrix = createReducedMatrix(matrix, row, col);

    std::cout << "Матрица после удаления строки и столбца:\n";
    printMatrix(reducedMatrix);

    return 0;
}
