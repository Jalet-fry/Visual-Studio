#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include <stdio.h>
#include <math.h>
int factorial_test(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    //    printf("i=%d  f=%d\n",i,f);
    }
    return f;
}
void  test() {
    double x;
    printf("Введите в градусах x: ");
    scanf_s("%lf", &x,sizeof(x));
    int fac=6;
   // printf("factorial %d = %d \n",fac,factorial_test(fac));
    int end=10;
    x = x*3.14/180;
    double sin=0,cos=0,result=0,res = 0;
    for(int n=0;n<end;n++){
        sin += (pow(-1, n)*pow(x,2*n+1))/factorial_test(2*n+1);
        cos += (pow(-1, n)*pow(x,2*n))/factorial_test(2*n);
        res += x/(2*n+1);
        printf("sin=%lf \n",sin);
        printf("cos=%lf \n",cos);
    }
    printf("sin=%lf \n",sin);
    printf("cos=%lf \n",cos);
    result=sin/cos;
 //   printf("res=%lf \n",res);
    printf("tangens=%lf \n",result);
}
