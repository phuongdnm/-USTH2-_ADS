#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiply(int num1, int num2){
	if (num1 < num2 && num2 <= 0){ 		// if 2 numbers are negative, so it works for " -3 * -1"
		multiply(abs(num1), abs(num2));
	}
	else if (num2 < 0 && num1 >= 0){	// if 1 of 2 numbers are negative , so it works for "3 * -1"
		multiply(num2, num1);
	}
	else {		// main recursive method is here, num2 must be positive in order to be decreased 
				// in each recursion!
		if (num2 != 0)
			return num1 + multiply(num1, num2 -1);
		else
			return 0;
	}
}


int main(){
	int num1, num2;

	while (1){
		printf("\nEnter number 1: "); scanf("%d", &num1);
		printf("Enter number 2: "); scanf("%d", &num2);
	
		printf(" %d * %d = %d", num1, num2, multiply(num1, num2));
	}
	return 0;
}