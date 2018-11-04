#include <stdio.h>

int main(){
	// Exercise 2: Write a program to calculate the sum of an array of n elements declared with any
	// data type using references and/or pointers.
	printf("Excercise 2: \n");
	
	int array2[100], n, i, sum = 0, x;
	printf("Enter number of elements: "); scanf("%d", &n);
	
	// declare an array
	printf("Enter n integers: \n");
	for (i = 0; i < n; i++){
		printf("a[%d] = ", i); scanf("%d", &x); 
		array2[i] =  x;
	}

	// calculate the sum of all elements
	for (i = 0; i < n; i++){
		sum += array2[i];
	}
	printf("Sum = %d", sum);

	return 0;
}