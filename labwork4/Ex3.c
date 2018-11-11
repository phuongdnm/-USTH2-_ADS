#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <time.h>


struct stack {
	int data;  //store the disk number
	char name; //store the name of column, used in the displaying the move
	struct stack *next;
};

struct stack *column1 = NULL;  			// create 3 empty stacks
struct stack *column2 = NULL;
struct stack *column3 = NULL;
struct stack *create_stack(char name);	// initialize 3 stacks above
void push(struct stack *, int);			// push a number into a stack. I use the same function in previous labworks
int pop(struct stack *);				// return the "top" value of a stack then delete it from the stack
void display(struct stack *);			// display all elements in a stack
void display_all();						// use the "display" function 3 times to display 3 stacks in the same time
void recursion(int, struct stack *, struct stack *, struct stack *); // main recursive method is here
void towerOfHanoi(); // Dr.Quang asked all of us to move all the code line into a function,
					 // so that the "main" will be much easier to follow. That's the reason
					 // why I create this function.

int main(){
	printf("\n\t*******\"Tower of Hanoi\" PROGRAM*******");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2");
	printf("\n//Special thanks to Praise Oketola and Vu Tuan Phong for helping me understand the idea.");
	towerOfHanoi();
	return 0;
}

void towerOfHanoi(){
	int n, i;
	printf("\n\nEnter number of disks: "); scanf("%d", &n);

	column1 = create_stack('S');
	column2 = create_stack('T');
	column3 = create_stack('D');

	for ( i = 0; i < n; i++){
		push(column1, n - i);
	} // push some number (you can call them diskes) into stack 1 (column 1)

	printf("\n%d diskes have been added into the column Source", n);
	display_all();
	printf("\n\t***PLEASE FOLLOW THE INSTRUCTION TO SOLVE THE PROBLEM*** ");
	recursion(n, column1, column3, column2);
	int step = pow(2,n) - 1;
	printf("*****IT TAKES TOTAL %d STEPS.", step);
}

struct stack *create_stack(char name_input){
	struct stack *top;
	top = (struct stack *)malloc(sizeof(struct stack));
	top -> data = 0;
	top -> name = name_input;
	top -> next = NULL;
	return top;
}

void push(struct stack *top, int data){
	struct stack *ptr;
	ptr = (struct stack *)malloc(sizeof(struct stack));
	ptr -> data = data;
	ptr -> next = top -> next;
	top -> next = ptr;
}

int pop(struct stack *top){
	struct stack *ptr;
	if (top == NULL)
		printf("\n EMPTY");
	else {
		ptr = top -> next;
		top -> next = top -> next -> next;
		int value;
		value = ptr -> data;
		free(ptr);
		return value;
	}
}

void display(struct stack *top){
	struct stack *ptr;
	ptr = top -> next;
	if (ptr == NULL)
		printf("(Empty)");
	else {

		while (ptr != NULL){
			printf("[%d]", ptr -> data);
			ptr = ptr -> next;
		}
	}
}

void display_all(){
	printf("\nSource(S)"); 
	printf("\tTemp(T)");
	printf("\t\tDest(D)");
	printf("\n"); display(column1);
	printf("\t\t"); display(column2);
	printf("\t\t"); display(column3);
	printf("\nEnd step!");
	printf("\n--------------------------------\n");
}

void recursion(int n, struct stack *source, struct stack *dest, struct stack *temp){
	if (n == 1){
		int number = pop(source);
		push(dest, number);
		printf("\nMove #%d from %c to %c", number, source -> name, dest -> name);
		display_all();
	}
	else {
		recursion(n-1, source, temp, dest);
		recursion(1, source, dest, temp);
		recursion(n-1, temp, dest, source);
	}
} 
// the hardest part is the base case: we have to "move" one dish from the soucre column
// to the dest column.
// I use 2 functions to do that: push(dest, number) and pop(source).
// It's much faster than making a "temporary node"



