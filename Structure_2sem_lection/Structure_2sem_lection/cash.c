#include <stdio.h>
#include <stdlib.h>

// Переменные bancnots и size_money передаются в качестве параметров функции
void find_combinations(int sum, int sum_copy, int index, int count[], FILE *file, const int bancnots[], int size_money) {
  if (sum == 0) {
    fprintf(file, "%d = ", sum_copy); // Используем sum_copy вместо sum
    int flag = 0;
    for (int i = 0; i < size_money; i++) {
      if (count[i] > 0) {
        if (flag) {
          fprintf(file, " + ");
        }
        fprintf(file, "%d*%d", bancnots[i], count[i]);
        flag = 1;
      }
    }
    fprintf(file, "\n");
    return;
  }
  // Если сумма меньше нуля или мы перебрали все номиналы, значит мы не нашли способа разложения
  if (sum < 0 || index >= size_money) {
    return;
  }
  for (int i = 0; i <= sum / bancnots[index]; i++) {
    // Увеличиваем количество купюр текущего номинала на i
    count[index] += i;
    find_combinations(sum - i * bancnots[index], sum_copy, index + 1, count, file, bancnots, size_money);
    count[index] -= i;
  }
}
int main() {
    const int bancnots[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
    const int size_money = sizeof(bancnots) / sizeof(int);
    int sum;
    printf("Введите число sum: ");
    scanf("%d", &sum);
    int count[size_money];
    for (int i = 0; i < size_money; i++) {
      count[i] = 0;
    }
    int choice;
    printf("Если вы хотите сохранить результаты в файл dengi.txt, введите 1. Если вы хотите вывести результаты на экран, введите 0: ");
    scanf("%d", &choice);
    FILE *file = NULL;
    if (choice == 1) {
      file = fopen("dengi.txt", "w");
      if (file == NULL) {
        printf("Не удалось открыть файл dengi.txt\n");
        return 1;
      }
    }
    // Переменные bancnots и size_money передаются в качестве аргументов функции
    find_combinations(sum, sum, 0, count, choice == 1 ? file : stdout, bancnots, size_money); 
    if (file != NULL) {
      fclose(file);
    }
    return 0;
}

