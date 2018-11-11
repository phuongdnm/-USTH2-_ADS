#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node *start = NULL; 				// create an empty linked list 
struct node *create_ll(struct node *);	// function to add new node. I use the same funtion in previous labworks.
struct node *display(struct node*);		// display all the items in the linked list
int sum(struct node *);					// calculate sum of all elements using linked list
void program();							// the core of the program is here. And it makes "main" function look better!

int main(){
	printf("\n*******CALCULATE ALL NUMBERS IN LINKED LIST USING RECURSIVE FUNCTION*******");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2");
	program();
	return 0;
}

void program(){
	int option;

	while(option!= 4){
		printf("\n1. Create a linked list of numbers.");
		printf("\n2. Display the linked list of numbers.");
		printf("\n3. Calculate and print out the sum of all numbers.");
		printf("\n4. Exit the program.");
		printf("\n\t Enter your option: "); scanf("%d", &option);

		switch(option){
			case 1:
				start = create_ll(start);
				break;
			case 2:
				start = display(start);
				break;
			case 3: 
				sum(start);
				printf("sum = %d", sum(start));
				break;
		}
	}
}

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter num = 0 to exit!");
	printf("\nEnter num = "); scanf("%d", &num);

	while (num != 0){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = num;

		if (start == NULL){
			new_node -> next = NULL;
			start = new_node;
		}
		else {
			ptr = start;
			while (ptr -> next != NULL)
				ptr = ptr -> next;
			ptr -> next = new_node;
			new_node -> next = NULL;
		}
		printf("\nEnter num: "); scanf("%d", &num);
	}
	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	printf("\nList of all numbers: ");
	while (ptr != NULL){
		printf("\t%d", ptr -> data);
		ptr = ptr -> next;
	}
	return start;
}

int sum(struct node *start){

	if (start != NULL)
		return  start -> data + sum(start-> next); // recursive method is here
	else
		return 0;
}
