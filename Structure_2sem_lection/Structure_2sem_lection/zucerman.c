#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <time.h>
double power(double a, double b) {
  double c = 1.0; // инициализируем c единицей
  for (int i = 0; i < b; i++) { // повторяем b раз
    c = c * a; // умножаем c на a
  }
  return c; // возвращаем c
}

int check(int massive[], int chsl) {
    int x;
    for (x = 0; x < 10; x++) {
        if (chsl == massive[x]) {
            printf("Число %d есть в массиве!\n", chsl);
            return 1;
        }
    }
    return 0;
}
// Функция для проверки, является ли число числом Армстронга
int isZucerman(int number) {
    int originalNumber = number;
    int sum = 1;
    while (number >= 1) {
        int digit = number % 10;
        sum *= digit;
        number /= 10;
    }
    if (sum !=0 && originalNumber % sum==0) {
        return 1; 
    }
    return 0; 
}

int main(void) {
    struct timeval start_time, end_time;
    int answer;
    printf("Zucerman numbers:\n");
    double time,pow;
    printf("Введите степень для 10:");
    scanf("%lf",&pow);
    printf("Нужен ли вывод(1=yes,0=no):");
    scanf("%d",&answer);
    int engage=1,closing=(int)floor(power(10.0,pow));
    int percents[10];
    for (int i = 10; i <= 100; i += 10) {
        int a = closing * i / 100;
        percents[i / 10 - 1] = a;
    }
    int count=0;
    gettimeofday(&start_time, NULL); 
    for (int number = engage; number <= closing; number++) {
        if (isZucerman(number)) {
            count++;
            if(answer==1){
                printf("%d,", number);
            }
            else if (count % 100 == 0) {
                printf("Проверено %.2f %%\n", ((float)number /(float) closing) * 100);
//                printf("Проверено %d%%\n", (number / closing) * 100); // выводим процент выполнени
            }
        }
    }
    gettimeofday(&end_time, NULL); 
    time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000; 
    printf("Всего найдено %d чисел из %d за %f секунд",count,closing,time);
    return 0;
}
