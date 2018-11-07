#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

// node of stack (character of the string)
struct character{
	char data;
	struct character *next;
};
// stack consists of its size data and nodes
struct stack{
	int size;
	struct character *next;
};

struct stack *create_stack();	// create an empty stack
void push(struct stack *);		// push new character to the stack
int pop(struct stack *);		// PRINT OUT characters while delete them. So we can get the reverse order.
void print_reverse(struct stack *); // use function "pop" to print out the whole reversed name.

int main(){
	struct stack *string;
	string  = create_stack();
	printf("\n*************REVERSE YOUR NAME*************");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2");
	while (true){	// makes the program runs forever. Exit by use "Ctrl + C" in the console
		push(string);
		print_reverse(string);
		printf("\n");	// just for formating
	}
	return 0;
}

struct stack *create_stack(){
	struct stack *string = (struct stack*)malloc(sizeof(struct stack));
	string -> size = 0;
	string -> next = NULL;
	return string;
}

void push(struct stack *top){
	char c;

	printf("\n\nEnter your name       : ");
	while ((c = getchar()) != '\n'){	//get each character by using "getchar" in "while" loop
		struct character *character;
		character  = (struct character*)malloc(sizeof(struct character));
		character -> data = c;
		character -> next = top -> next;
		top -> next = character;
		top -> size ++;
	}
}

int pop(struct stack *top){
	struct character *push;
	push = top ->next;
	top -> size --;
	top -> next = top -> next -> next;
	int data = push -> data;
	free (push);
	return data;
}

void print_reverse(struct stack *top){
	printf("Your reverse name is  : ");
	while (top -> size > 0){
		printf("%c", pop(top));
	}
}

