#include <stdio.h>

int main(){
	// Exercise 1: Write a program to add two variables of any data type using references and/or
	// pointers.
	printf("Excercise 1:\n");
	double a, b, *p, *q;

	printf("Enter 2 numbers (a,b): "); scanf("%lf,%lf", &a, &b);
	p = &a;
	q = &b;

	double sum = *p + *q;
	printf("sum = %.3f", sum);
	return 0;

}