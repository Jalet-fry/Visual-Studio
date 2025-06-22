#include <iostream>
#include <string>
void deleteMatrix(int**& matrix, int& n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    n = 0;
}
void printMatrix(int** matrix, int n) {
    if (n == 0) {
        std::cout << "Матрица пуста." << std::endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int correct(const std::string& prompt) {
    std::string input;
    int num;
    char* endptr;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Проверяем, пуст ли ввод
        if (input.empty()) {
            return -1; // Возвращаем -1, если ввод пустой
        }

        num = std::strtol(input.c_str(), &endptr, 10);
        if (*endptr != '\n' && *endptr != '\0') {
            std::cout << "Это не число. Попробуйте еще раз." << std::endl;
        } else {
            std::cout << "Вы ввели число: " << num << std::endl;
            return num;
        }
    }
}
long long getUserInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            return -1; 
        }
        try {
            long long num = std::stoll(input);
            return num;
        } catch (const std::invalid_argument&) {
            std::cout << "Это не число. Попробуйте еще раз.\n";
        } catch (const std::out_of_range&) {
            std::cout << "Число слишком большое. Попробуйте еще раз.\n";
        }
    }
}

int findMaxAbsElement(int** matrix, int n, int& row, int& col) {
    int maxAbs = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (std::abs(matrix[i][j]) > std::abs(maxAbs)) {
                maxAbs = matrix[i][j];
                row = i;
                col = j;
            }
        }
    }
    return maxAbs;
}

void createReducedMatrix(int**& matrix, int &rang_matrix, int& rowToRemove, int& colToRemove) {
    int old_rang_matrix = rang_matrix;
    rang_matrix--;
    int** reducedMatrix = new int*[rang_matrix];
    for (int i = 0; i < rang_matrix; ++i) {
        reducedMatrix[i] = new int[rang_matrix];
    }
    int reducedRow = 0, reducedCol = 0;
    for (int i = 0; i < old_rang_matrix; ++i) {
        if (i != rowToRemove) {
            for (int j = 0; j < old_rang_matrix; ++j) {
                if (j != colToRemove) {
                    reducedMatrix[reducedRow][reducedCol] = matrix[i][j];
                    reducedCol++;
                }
            }
            reducedRow++;
            reducedCol = 0;
        }
    }
    deleteMatrix(matrix, old_rang_matrix);
    matrix = reducedMatrix;
}


int main() {
	int n = correct("Введите порядок квадратной матрицы: ");
    while (n <= 0) {
		std::cout << "Некорректный порядок матрицы\n";
        n = correct("Введите порядок квадратной матрицы: ");
    }

    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = correct("Элемент [" + std::to_string(i) + "][" + std::to_string(j) + "]: ");
        }
    }

    std::cout << "Исходная матрица:\n";
    printMatrix(matrix, n);

    int row = -1, col = -1;
    int maxAbsElement = findMaxAbsElement(matrix, n, row, col);

    std::cout << "Наибольший элемент по модулю: " << maxAbsElement << " в позиции [" << row << "][" << col << "]" << std::endl;

    createReducedMatrix(matrix, n, row, col);

    std::cout << "Матрица после удаления строки и столбца:\n";
    printMatrix(matrix, n);

    deleteMatrix(matrix, n);
    printMatrix(matrix, n);

    return 0;
}

