#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node{
	int NUM;
	char NAME[100];
	struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *); 	// We create the linked list here
struct node *add_before(struct node *);	// I decide to make 3 different addition functions
struct node *add_beg(struct node *);	// so the code will be much easier to read
struct node *add_end(struct node *);
struct node *delete_zero(struct node *);// delete the car with 0 passenger
struct node *display(struct node *);	// show all the cars and their names

int main(){
	int x, addtype;

	while( x!= 5){
		printf("\n1. Create a linked list of cars. ");
		printf("\n2. Add a new car into the train. ");
		printf("\n3. Display all cars's information.");
		printf("\n4. Delete cars that have 0 passenger.");
		printf("\n5. Exit.");
		printf("\n\n \tEnter your option: ");
		scanf("%d", &x);
	
		switch(x){
			case 1: start = create_ll(start); break;
			case 2: 
				printf("\n1. Insert at the begining.");
				printf("\n2. Insert before a position.");
				printf("\n3. Insert at the end.");
				printf("\nYour choice: "); scanf("%d", &addtype);
				switch (addtype){
					case 1: start = add_beg(start); break;
					case 2: start = add_before(start); break;
					case 3: start = add_end(start); break;
				} break;
			case 3: start = display(start); break;
			case 4: start = delete_zero(start); break;
		}
	}
	return 0;
}

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int num;
	char name[100];
	printf("\nEnter num = -1 to end");
	printf("\nEnter num: "); scanf("%d", &num);
	printf("Enter name: "); scanf("%s", &name);

	while(num != -1){
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> NUM= num;
		strcpy(new_node ->NAME, name);
		if (start == NULL){
			new_node -> next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while (ptr -> next != NULL)
				ptr = ptr -> next;
			ptr -> next = new_node;
			new_node -> next = NULL;
		}
		printf("\nEnter num: "); scanf("%d", &num);
		printf("Enter name: "); scanf("%s", &name);
	}
	return start;
}

struct node *add_before(struct node *start){
	struct node *new_node, *ptr, *preptr;
	int num, pos;
	char name[100];
	

	printf("\nEnter num: ");
	scanf("%d", &num);
	printf("Enter name: ");
	scanf("%s", name);
	printf("Enter the position before which you want to insert: ");
	scanf("%d", &pos);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> NUM = num;
	strcpy(new_node -> NAME, name);

	ptr = start;
	while (ptr -> NUM != pos){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;
	return start;
}

struct node *add_beg(struct node *start){
	struct node *new_node;
	int num;
	char name[100];

	printf("\nEnter num: "); scanf("%d", &num);
	printf("\nEnter name: "); scanf("%s", name);

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> NUM = num;
	strcpy(new_node -> NAME, name);
	new_node -> next = start;
	start = new_node;
	return start;
}

struct node *add_end(struct node *start){
	struct node *ptr, *new_node;
	int num;
	char name[100];
	printf("\nEnter num: "); scanf("%d", &num);
	printf("\nEnter name: "); scanf("%s", name);

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> NUM = num;
	strcpy(new_node -> NAME, name);

	new_node -> next = NULL;
	ptr = start;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node;
	return start;
}

struct node *delete(struct node *start){
	struct node *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	return start;
}

struct node *delete_zero(struct node *start){
	struct node *ptr, *preptr;
	ptr = start;
	
	if (ptr -> NUM == 0){
		start = delete(start);
		return start;
	}
	else {
		while (ptr -> NUM != 0){
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	printf("\t\tList of all cars:\n");
	while (ptr != NULL){
		printf("\t \t%d %s\n", ptr -> NUM, ptr -> NAME);
		ptr = ptr -> next;
	}
	return start;
}






