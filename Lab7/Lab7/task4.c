#include "task4.h" 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6 
void task4(int argc, char** args) {
	for (int x = argc - 1; x >= 0; x--) { printf("|%s|\n", args[x]); }
	double *arr = malloc(argc * sizeof(double));
	for (int i = argc - 1; i >= 0; i--) {
		printf("arr[%d] = %s\n", argc - 1 - i, args[i]);
		arr[argc - 1 - i] = strtod(args[i], NULL);
	}
	for (double x = -1000.0; x < 102.0; x += 0.1) { 
		double  result = arr[0];
		double step_x = 1.0;
		for (int i = 1; i < argc; i++) {
			if (fabs(x - 101.1) < EPS) {
				printf("|%s|\n", args[i]);
			}
			
			step_x *= x;
			result = result + step_x * arr[i];
		}
		if (fabs(result) < EPS) { 
			printf("Корень есть для x = %f \n", x);
		}
	}
	free(arr);
}


