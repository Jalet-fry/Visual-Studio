#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include <stdio.h>
#include <math.h>

// Функция для вычисления расстояния от точки до начала координат
double distance(double x, double y) {
  return sqrt(x * x + y * y);
}
void find_pi(){
    int member=500;
    double pi = 0;
   // printf("Введите число членов ряда: ");
   // scanf("%d", member);
    for(int a = 0; a < member;a++){
        pi += 4*(pow(-1.0,(double)a)/(2*a + 1));
    }
    printf("При %d членов pi = %lf \n",member,pi);

}
void smallest_n(){
    double a;
    int n = 0;
    printf("Введите действительное число а: ");
    scanf("%lf", &a);
    double sum = 1;
    if(sum <= a){
        n = 1;
        while (sum <= a){
            sum += 1.0 / n;
            n++;
        }
    }
    printf("Для числа %f наименьшее n=%d \n",a,n);
}
void  main() {
    char welcome[600] = "Привествуем вас,выберите функции:\n"
    "-1)sos or help or h = инструкция для вас\n"
    "0)exit или 0 = выход\n"
    "1)smallest_n = Сравнение 3-х чисел\n"
    "2)find_pi=Найдем число pi по формуле Грегора\n"
    "3)coordinate=вычислим кратчайшее расстояние до начала координат\n"
    "4)report= Форма сдачи предмета\n";
    printf("%s",welcome);
    // Бесконечный цикл
    while (1) {
        printf("Вызов функции:");
        char choice[20];// Строка для хранения выбора пользователя
        scanf("%s", choice); 
        if (strcmp(choice, "exit") == 0 || !strcmp(choice, "0")) {
            printf("С вами была компания NOmicrosoft, До Новых Встреч!\n");
            printf("%s",choice);
            break; // Выход из цикла
        }
        else if (strcmp(choice, "smallest_n") == 0 ||strcmp(choice,"1")==0) {
            smallest_n(); 
        }
        else if (strcmp(choice, "sos") == 0 || strcmp(choice, "help") == 0 || strcmp(choice, "h") == 0 || strcmp(choice,"-1")== 0) {
            printf("\n**************\n%s",welcome); 
        }  
        else if (strcmp(choice, "find_pi") == 0 || !strcmp(choice, "2")) {
            find_pi();
        }
//        else if (strcmp(choice, "coordinate") == 0 || !strcmp(choice, "3")) {
  //          coordinate();
//        }
    //    else if (strcmp(choice, "report") == 0 || !strcmp(choice, "4")) {
      //      report();
  //      }
        else{printf("%s",choice);}
    }
}
