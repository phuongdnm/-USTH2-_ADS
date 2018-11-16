#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};

struct node *start; 										// the global list to save data
void display(struct node *);								// display all the item
void push(struct node **, int);								// push new node ino the list
void Split(struct node *, struct node **, struct node **);	// split all the linked list
struct node *mergeLists(struct node *, struct node *);		// merge 2 small lists into 1 using recrusive method, then return list
void mergeSort(struct node **);								// main sorting algorithm is here
void program();												// initialize new linked list, sort it then display the sorted list

int main(){
	printf("\n*******Merge sort implemented by Linked list*******");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2\n");
	program();

	return 0;
}

void program(){
	struct node *head = NULL;
	int i;
	printf("\n***Add some number to the list: ");
	printf("\n***Enter -1 to exit.\n");
	while (i != -1){
		printf("Enter a number: ");
		scanf("%d", &i);
		if(i != -1)
			push(&head, i);
	}
	printf("\nYour original list is: ");
	display(start);

	printf("\n\n***Start spliting the list: ");
	mergeSort(&start);

	printf("The sorted list is: ");
	display(start);
}

void display(struct node *top){ 
	struct node *ptr = top;
	while (ptr != NULL){
		printf(" %d ", ptr -> data);
		ptr = ptr -> next;
	}
	printf("\t");	// just for formatting
}

void push(struct node **head, int data){ // same as other functions in previous labwork
	struct node *new_node = (struct node *)malloc(sizeof(struct node));	
	new_node -> data = data;
	new_node -> next = NULL;
	
	if ((*head) == NULL){
		*head = new_node;
		start = *head;
	}
	else{
		(*head) -> next = new_node;
		*head = new_node;
	}
}

void Split(struct node *top, struct node **front, struct node **back){
	struct node *fast; 
	struct node *slow;

	if (top == NULL || top -> next == NULL){
		*front = top;
		*back = NULL;
	}
	else { 
		printf("\n");
		slow = top;
		fast = top -> next;

		while (fast != NULL){ 	// this loop finds the middle of the list
			fast = fast -> next;
			if (fast != NULL){
				slow = slow -> next;
				fast = fast -> next;
			}
		}
		*front = top; 		  // set the first half of the list to "front"
		*back = slow -> next; // set the second half of the list to "back"
		slow -> next = NULL;  // cut the list

		printf("\nFront: "); display(*front);
		printf("Back: "); display(*back);	
	}
}

struct node *mergeLists(struct node *a, struct node *b){
	struct node *finalList = NULL;
	if ( a == NULL) 		// If one of 2 lists is empty -> copy the rest
		return b;		    //of the other to the list
	else if ( b == NULL)
		return a;

	if (a -> data <= b -> data){ 			// Compare the value of 2 first nodes in each list
		finalList = a;           			//then place them in the right place.
		finalList -> next = mergeLists(a -> next, b);
	}
	else{
		finalList = b;
		finalList -> next = mergeLists(a, b -> next);
	}
	return finalList;
}

void mergeSort(struct node **source){
	struct node *head;  // save the whole list here
	struct node *a, *b; // "storage" lists to save halves after spliting.

	head = *source;
	if (head == NULL || head -> next == NULL) // base case
		return;

	Split(head, &a, &b);	// Spliting the whole list
	printf("\n");

	mergeSort(&a);
	mergeSort(&b);

	display(a); printf("\t"); display(b); // dispaly the process

	printf("\n");

	*source = mergeLists(a,b); // add the "small" sorted list to the "source" after each sorting and merging.
	printf("--->Final: "); display(*source); printf("\n\n");
}





