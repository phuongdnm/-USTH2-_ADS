#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>

struct node {
	int A;
	int DEG;
	struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *); 		// create linked list here
struct node *add_term(struct node *); 		// goes with the function "check_exist"
struct node *delete(struct node *); 		// delete a node
struct node *delete_term(struct node *); 	// delete a node with information from user
struct node *calculate(struct node *); 		// enter x and calculate the value of fucntion
struct node *display(struct node *);		// print out the function in DECREASING order
struct node *sort_list(struct node *);		// I create this function because I have free time :))

int main(){
	int x, add_option;

	while (x!= 6){
		printf("\n1. Create a linked list of terms");
		printf("\n2. Add new term");
		printf("\n3. Remove a term");
		printf("\n4. Enter a value x then calculate the function");
		printf("\n5. Display the whole function");
		printf("\n6. Exit");
		printf("\n\tEnter your option: "); scanf("%d", &x);

		switch (x){
			case 1: start = create_ll(start); break;
			case 2: start = add_term(start); break;
			case 3: start = delete_term(start); break;
			case 4: start = calculate(start); break;
			case 5: start = display(start); break;
		}
	}
	return 0;
}

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int a, deg;

	printf("\nEnter a = -1 to finish.");
	printf("\nEnter constant a: "); scanf("%d", &a);
	printf("Enter degree: "); scanf("%d", &deg);

	// ask user to enter a link list until const a = -1
	while (a != -1){
		// take input to a new node
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> A = a;
		new_node -> DEG = deg;
		// add new node to the list
		if (start == NULL){
			new_node -> next = NULL;
			start = new_node;
		}
		else {
			ptr = start;
			while(ptr -> next != NULL)
				ptr = ptr -> next;
				ptr -> next = new_node;
				new_node -> next = NULL;
		}
		printf("\nEnter constant a: "); scanf("%d", &a);
		printf("Enter degree: "); scanf("%d", &deg);
	}
	return start;
}

bool check_exist(struct node *start, int deg){
	// check whether the degree of new node exists or not
	struct node *ptr;
	ptr = start;
	while (ptr != NULL){
		if (ptr -> DEG == deg)
			return true;
		ptr = ptr -> next;
	}
	return false ;
}

struct node *add_term(struct node *start){
	struct node *ptr, *new_node;
	int a, a_total, deg;
	bool check;
	// take input to a node
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter constant a: "); scanf("%d", &a);
	printf("Enter degree: "); scanf("%d", &deg);

	ptr = start;
	check = check_exist(ptr, deg);

	if (check){ // the degree already exist, so we add the const a together
		while (ptr != NULL){
			if ( ptr -> DEG == deg){
				ptr -> A = ptr -> A + a;
				break;
			}
			ptr = ptr -> next;
		}
	}
	else { // new degree has been found, take it to new node and put in the end of function
		new_node -> A = a;
		new_node -> DEG = deg;
		new_node -> next = NULL;
		ptr = start;
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new_node;
	}
	return start;
}

struct node *delete (struct node *start){ // free memory of a node
	struct node *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	return start;
}

struct node *delete_term(struct node *start){
	struct node *ptr, *preptr; // we need a "pre pointer" here to connect 2 parts after deleting a node between them
	int a, deg;
	printf("\nEnter a and deg of the term in function you want to delete .\n");
	printf("Enter a of this term: "); scanf("%d", &a);
	printf("Enter deg of this term: "); scanf("%d", &deg);

	ptr = start;
	if( (ptr -> A == a) && (ptr -> DEG == deg)){ // find the position of the node that should be deleted
		start = delete(start);
		return start;
	}
	else {
		while( (ptr -> A != a) && (ptr -> DEG != deg)){ //now, connect 2 parts after removing a node
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}

struct node *calculate(struct node *start){ 
	int x, sum = 0;
	struct node *ptr;
	ptr = start;

	printf("Enter x: "); scanf("%d", &x);
	while (ptr != NULL){
		sum += (ptr -> A)*pow(x, ptr -> DEG);
		ptr = ptr -> next;
	}
	printf("Sum = %d", sum);
	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	start = sort_list(start);
	ptr = start;
	printf("\nFunction in decreasing order: ");
	while (ptr != NULL){
		printf(" %dx^%d +", ptr -> A, ptr -> DEG);
		ptr = ptr -> next;
	}
	return start;
}

struct node *sort_list(struct node *start){ //for this sorting, I use bubble sort algorithm
	struct node *ptr1, *ptr2;
	int u,v;
	ptr1 = start;
	while (ptr1 -> next != NULL){
		ptr2 = ptr1 -> next;
		while (ptr2 != NULL){
			if (ptr1 -> DEG < ptr2 -> DEG){
				u = ptr1 -> A; ptr1 -> A = ptr2 -> A; ptr2 -> A = u;
				v = ptr1 -> DEG; ptr1 -> DEG = ptr2 -> DEG; ptr2 -> DEG = v;
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return start;
}




