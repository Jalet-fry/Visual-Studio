// Lab3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>

//int main()
//{
//    std::cout << "Привет мир!\n";
//    printf("Привет андрей");
//}

//#include <iostream>
//#include <cmath>
//#include <cstdlib>
//
//int correct(char* c) {
//    char input[100];
//    int valid = 0;
//    int num;
//    char* endptr; 
//    valid = 0;
//    while (!valid) {
//        std::cout << c;
//        std::fgets(input, sizeof(input) / sizeof(char), stdin);
//        if (input[0] == '\n') {
//            return -1;
//        }
//        num = static_cast<int>(std::strtol(input, &endptr, 10)); 
//        if (*endptr != '\n' && *endptr != '\0') { 
//            std::cout << "Это не число. Попробуйте еще раз.\n";
//        }
//        else {
//            valid = 1;
//            std::cout << "Вы ввели число: " << num << std::endl;
//        }
//    }
//    return num;
//}
//
//int findMaxAbsElement(int** matrix, int n) {
//    int maxAbsElement = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (std::abs(matrix[i][j]) > std::abs(maxAbsElement)) {
//                maxAbsElement = matrix[i][j];
//            }
//        }
//    }
//    return maxAbsElement;
//}
//
//int** createReducedMatrix(int** matrix, int n, int maxAbsElementRow, int maxAbsElementCol) {
//    int** reducedMatrix = new int*[n-1];
//    for (int i = 0; i < n-1; i++) {
//        reducedMatrix[i] = new int[n-1];
//    }
//
//    int reducedRow = 0, reducedCol = 0;
//    for (int i = 0; i < n; i++) {
//        if (i != maxAbsElementRow) {
//            for (int j = 0; j < n; j++) {
//                if (j != maxAbsElementCol) {
//                    reducedMatrix[reducedRow][reducedCol] = matrix[i][j];
//                    reducedCol++;
//                }
//            }
//            reducedRow++;
//            reducedCol = 0;
//        }
//    }
//
//    return reducedMatrix;
//}
//
//int main() {
//    int n = correct("Введите размерность матрицы: ");
//    if (n == -1) {
//        return 0;
//    }
//
//    int** matrix = new int*[n];
//    for (int i = 0; i < n; i++) {
//        matrix[i] = new int[n];
//    }
//
//    std::cout << "Введите элементы матрицы:\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            matrix[i][j] = correct("Введите элемент [" + std::to_string(i) + "][" + std::to_string(j) + "]: ");
//        }
//    }
//
//    int maxAbsElement = findMaxAbsElement(matrix, n);
//    int maxAbsElementRow = -1, maxAbsElementCol = -1;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (matrix[i][j] == maxAbsElement) {
//                maxAbsElementRow = i;
//                maxAbsElementCol = j;
//                break;
//            }
//        }
//    }
//
//    int** reducedMatrix = createReducedMatrix(matrix, n, maxAbsElementRow, maxAbsElementCol);
//    std::cout << "Новая матрица размерности " << n-1 << ":\n";
//    for (int i = 0; i < n-1; i++) {
//        for (int j = 0; j < n-1; j++) {
//            std::cout << reducedMatrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    for (int i = 0; i < n; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//
//    for (int i = 0; i < n-1; i++) {
//        delete[] reducedMatrix[i];
//    }
//    delete[] reducedMatrix;
//
//    return 0;
//}
//
////#include <iostream>
////#include <string>
////#include <limits>
////
////int correct(const std::string& prompt) {
////    std::string input;
////    int num;
////    bool valid = false;
////
////    while (!valid) {
////        std::cout << prompt;
////        std::getline(std::cin, input);
////
////        if (input.empty()) {
////            return -1;
////        }
////
////        try {
////            size_t pos;
////            num = std::stoi(input, &pos);
////            if (pos == input.length()) {
////                valid = true;
////                std::cout << "Вы ввели число: " << num << std::endl;
////            } else {
////                std::cout << "Это не число. Попробуйте еще раз.\n";
////            }
////        } catch (std::invalid_argument&) {
////            std::cout << "Это не число. Попробуйте еще раз.\n";
////        } catch (std::out_of_range&) {
////            std::cout << "Число вне допустимого диапазона. Попробуйте еще раз.\n";
////        }
////    }
////
////    return num;
////}
////#include <iostream>
////#include <vector>
////#include <cmath>
////#include <limits>
////
////std::vector<std::vector<int>> createMatrix(int n) {
////    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
////    for (int i = 0; i < n; ++i) {
////        for (int j = 0; j < n; ++j) {
////            matrix[i][j] = correct("Введите элемент [" + std::to_string(i) + "][" + std::to_string(j) + "]: ");
////        }
////    }
////    return matrix;
////}
////
////std::pair<int, int> findMaxElement(const std::vector<std::vector<int>>& matrix) {
////    int maxElement = std::numeric_limits<int>::min();
////    std::pair<int, int> maxPos = {0, 0};
////
////    for (int i = 0; i < matrix.size(); ++i) {
////        for (int j = 0; j < matrix[i].size(); ++j) {
////            if (std::abs(matrix[i][j]) > std::abs(maxElement)) {
////                maxElement = matrix[i][j];
////                maxPos = {i, j};
////            }
////        }
////    }
////
////    return maxPos;
////}
////
////std::vector<std::vector<int>> createReducedMatrix(const std::vector<std::vector<int>>& matrix, int row, int col) {
////    int n = matrix.size();
////    std::vector<std::vector<int>> reducedMatrix(n - 1, std::vector<int>(n - 1));
////
////    for (int i = 0, new_i = 0; i < n; ++i) {
////        if (i == row) continue;
////        for (int j = 0, new_j = 0; j < n; ++j) {
////            if (j == col) continue;
////            reducedMatrix[new_i][new_j] = matrix[i][j];
////            ++new_j;
////        }
////        ++new_i;
////    }
////
////    return reducedMatrix;
////}
////
////int main() {
////    int n = correct("Введите размер матрицы n: ");
////    if (n <= 0) {
////        std::cout << "Некорректный размер матрицы.\n";
////        return 1;
////    }
////
////    std::vector<std::vector<int>> matrix = createMatrix(n);
////    auto [maxRow, maxCol] = findMaxElement(matrix);
////    std::vector<std::vector<int>> reducedMatrix = createReducedMatrix(matrix, maxRow, maxCol);
////
////    std::cout << "Исходная матрица:\n";
////    for (const auto& row : matrix) {
////        for (int elem : row) {
////            std::cout << elem << " ";
////        }
////        std::cout << "\n";
////    }
////
////    std::cout << "Матрица после удаления строки и столбца с наибольшим элементом:\n";
////    for (const auto& row : reducedMatrix) {
////        for (int elem : row) {
////            std::cout << elem << " ";
////        }
////        std::cout << "\n";
////    }
////
////    return 0;
////}
////
////// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
////// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
////
////// Советы по началу работы 
//////   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//////   2. В окне Team Explorer можно подключиться к системе управления версиями.
//////   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//////   4. В окне "Список ошибок" можно просматривать ошибки.
//////   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//////   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.



#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

int getUserInput(const std::string &prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Проверяем, пуст ли ввод
        if (input.empty()) {
            return -1; // Возвращаем -1, если ввод пустой
        }

        char *endptr;
        int num = std::strtol(input.c_str(), &endptr, 10);
        if (*endptr != '\n' && *endptr != '\0') {
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

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (std::abs(matrix[i][j]) > std::abs(maxAbs)) {
                maxAbs = matrix[i][j];
                row = i;
                col = j;
            }
        }
    }
    return maxAbs;
}

std::vector<std::vector<int>> createReducedMatrix(const std::vector<std::vector<int>> &matrix, int rowToRemove, int colToRemove) {
    std::vector<std::vector<int>> reducedMatrix;
    for (int i = 0; i < matrix.size(); ++i) {
        if (i == rowToRemove) continue;
        std::vector<int> newRow;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (j == colToRemove) continue;
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

    std::cout << "Наибольший элемент по модулю: " << maxAbsElement << " в позиции [" << row + 1 << "][" << col + 1 << "]" << std::endl;

    auto reducedMatrix = createReducedMatrix(matrix, row, col);

    std::cout << "Матрица после удаления строки и столбца:\n";
    printMatrix(reducedMatrix);

    return 0;
}

