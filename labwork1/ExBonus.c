#include <stdio.h>

int main(){
	// Exericse bonus:
	printf("\nExericse bonus:\n");
	int a[20], j = 0, total = 0, c;
	printf("ISNB (digit only): "); scanf("%d", &c);
	
	// exchange input into an array of numbers
	// (the general way to do that is to use getchar() and isdigit() function,
	// then users can type in not only digit characters but also special characters )
	for ( j = 8; j>=0 ; j--){
		a[j] = c % 10;
		c /= 10;
	}

	// calculate the control number
	for (j = 0; j < 9; j++){
		total += a[j] * (j+1);
	}

	printf("%d", total % 11);
	return 0;
}