#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void display(int arr[], int); 			// display all elements in the array.
int is_sorted(int arr[], int);			// check whether the array is sorted or not by using recursive method.
void sort_top(int arr[], int, int);		// sort from an initial index to a final index by a "increasing" for loop.
void sort_bottom(int arr[], int, int);	// nearly similar with the "sort_top" function. Now use a "decreasing" for loop.
void bubble_variation();				// main program here, includes: generating an array by users; sorting; displaying.
void complexity();						// print the complexity and my short explaination.

int main(){
	printf("\n*******A variation of the bubble sorting algorithm*******");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2\n");
	bubble_variation();
	complexity();
	return 0;
}

void bubble_variation(){
	int arr[100], n, num;
	int index = 0;
	// start generating an array by input from users
	printf("\n***Add some numbers to the array.");
	printf("\nEnter number of elements: "); scanf("%d", &n);

	for ( int i = 0; i < n; i++){
		printf("Enter a number: "); scanf("%d", &num);
		arr[i] = num;
	} 

	printf("\nYour original array is:\n"); display(arr, n);

	// start sorting here
	int length = n - 1; // the biggest index
	int i = 0; 			// the smallest index, and also be the number of steps
	bool check = false; 

	while (check == false){
		sort_top(arr, index, length); 		// sort from top
		length -= 1;	// decrease the biggest index, because the greatest element is in the right place.

		printf("\nPass %d, from top: \n", ++i); display(arr,n);

		sort_bottom(arr, length, index); 	// sort from bottom
		index += 1;		// increase the smallest index, because the smallest element is in the right place.

		printf("\nPass %d, from bottom: \n", ++i); display(arr,n);

		check = is_sorted(arr,n); // maintain the loop
	}

	printf("\n\nThe sorted array is: "); display(arr, n);
	printf("\nThe algorithm take %d pass(es).", i);

}

void display(int arr[], int n){
	int i;
	printf("\t");
	for (i = 0; i < n; i++){
		printf("   %d   ", arr[i]);
	}
}

int is_sorted(int arr[], int n){
	if ( n == 1 || n == 0) // Base case: when there is 0 or 1 items in the array, it means the array is sorted.
		return 1;
	if ( arr[n-1] < arr[n-2]) // check all pairs here
		return 0;
	return is_sorted(arr, n-1);
}

void sort_top(int arr[], int from, int to){
	int i, temp;
	for ( i = from; i < to ; i++){ // "forward" loop
		if (arr[i] > arr[i+1]){
			temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp; //swap 2 values
		}
	}
}


void sort_bottom(int arr[], int from, int to){
	int i, temp;
	for (i = from; i > to; i--){ // "downward" loop
		if (arr[i] < arr[i-1]){
			temp = arr[i]; arr[i] = arr[i-1]; arr[i-1] = temp; //swap 2 values
		}
	}
}

void complexity(){
	printf("\n\n\t*****Complexity*****");
	printf("\n***Best case: O(n)");
	printf("\n- In the best case (the input is a sorted array), my algorithm need");
	printf("to pass through 3 \"for\" loops with complexity O(n) only *1 time.");
	printf("\n- We have: O(3n) = O(n)");
	printf("\n***Worst case: O(n^2)");
	printf("\n- Similarly my algorithm need to pass through 3 loops for *n times.");
	printf("\n***Average case: O(n^2)");
}