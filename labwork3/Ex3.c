#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct stack{
	int data;
	struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);	// push a number into stack
struct stack *pop(struct stack *);			// pop numbers in stack, also print out the numbers
int draw_number2(int);						// generate number2 satisfied the condition num2 != num1
struct stack  *game(struct stack *);		// main "engine" of the game here
void tutorial();							// print the tutorial

struct stack *push(struct stack *top, int val){
	struct stack *ptr;
	ptr = (struct stack *)malloc(sizeof(struct stack));
	ptr -> data = val;
	if (top == NULL){
		ptr -> next = NULL;
		top = ptr;
	}
	else {
		ptr -> next = top;
		top = ptr;;
	}
	return top;
}

struct stack *pop(struct stack *top){
	struct stack *ptr;
	ptr = top;
	
	top = top -> next;
	printf(" %d ", ptr -> data);
	free(ptr);

	return top;
}

int draw_number2(int num1){
	int num2;
	do {
		srand( time(NULL));
		num2 = rand() % 9 + 1;
	} while (num1 == num2);
	
	return num2;
}

struct stack *game(struct stack *top){
	srand(time(NULL));				// create number1
	int num1 = rand() % 9 + 1;
	top = push(top, num1);

	int num2 = draw_number2(num1);  // create number2
	top = push(top, num2);

	int  x;

	printf("\nEnter your guess (0 <= x <= 9): "); scanf("%d", &x);
	if ((num1 < x && x < num2) || ((num2 < x && x < num1))){
		printf("--------------->You win.Congratulation!");
	}
	else{
		printf("--------------->Wrong. One more try!\n");
		printf("\nNew number2 has been created!");
		printf("\nThe previous number2 is: ");
		top = pop(top);
		num2 = draw_number2(num1);
		top = push(top, num2);

		printf("\n\nEnter your guess(0 <= x <= 9): "); scanf("%d", &x);
		if ((num1 < x && x < num2) || ((num2 < x && x < num1)))
			printf("--------------->You win. Congratulation!");
		else
			printf("--------------->Game over :((");	
	}
	return top;
}

void tutorial(){
	printf("\n\n*************HOW TO PLAY*************");
	printf("\n- The objective of this game is to guess the right number x");
	printf("\nsatisfied the condition: ");
	printf("\n\t    num1 < x < num2");
	printf("\n\tor  num2 < x < num1");
	printf("\n(num1 are num2 are generated randomly by the program.)");
	printf("\n\n- You have only 2 chances. So try your best!");
	printf("\n- If you lose the first chance, the num2 will be automatically");
	printf("\ngenerated. The num1 will be kept! REMEMER THIS IS YOUR LAST CHANCE");
}

int main(){
	int option;
	struct stack *top;
	printf("\n****************LUCKY NUMBER****************");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2");
	while (option != 3){
		printf("\n\n\t\tMAIN MENU");
		printf("\n\t1.New game.");
		printf("\n\t2.How to play");
		printf("\n\t3.Exit game.");
		printf("\n\t   Enter your choice: "); scanf("%d", &option);
		switch (option){
			case 1: 
				top = game(top); 
				printf("\nThe 2 unknown numbers are: "); 
				for (int i =0; i< 2; i++)
					top = pop(top);			// clear stack and print out 2 numbers.
				break;
			case 2:
				tutorial();
				break;
		}	
	}
	return 0;
}