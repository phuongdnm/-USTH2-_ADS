#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *front = NULL; // head of each node in queue.
struct node *rear = NULL;  // tail of each node in queue.
void insert(int num);	   // push new node to the queue. Take the information from user by "num".
int delete();			   // pop the first node in the queue.
void display();			   // display a map with passengers and their positions.
int peek();				   // show who is the first passenger.

int main(){
	int option, num, del, first;
	printf("\n****MANAGE A QUEUE OF PASSENGER WAITING TO ENTER A TRAIN CAR****");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group 2");

	while(option != 5){
		printf("\n\n1. Insert new passenger. ");
		printf("\n2. Remove first passenger (Let he/she moves into the train).");
		printf("\n3. Display the queue.");
		printf("\n4. Print out the first passenger.");
		printf("\n5. Exit.");
		printf("\n \tEnter your choice: "); scanf("%d", &option);

		switch(option){
			case 1: 
				printf("\n\tAdd new passenger to the rear.");
				printf("\n\tEnter his/her ticket number: ");
				scanf("%d", &num);
				insert(num); 
				break;
			case 2: 
				del = delete();
				if (del != 0)
					printf("\n\tThe passenger with ticket %d has moved to train.", del);
				break;
			case 3: display(); break;
			case 4: first = peek(); 
				if (first != 0)
					printf("\n\tThe first passenger now is: %d", first);
				break;
		}
	}
	return 0;
}

void insert(int num){
	struct node *q;
	q = (struct node *)malloc(sizeof(struct node));
	q -> data = num;
	q-> next = NULL;

	if (front == NULL)
		front = q; // if the queue is empty, make a totally new node the set it as the queue
	else 
		rear -> next = q;
	rear = q;
}

int delete(){
	int num;
	struct node *q;
	if (front == NULL){
		printf("\n\tZero passenger!");
		return 0;
	}
	else{
		q = front;
		num = q -> data;
		front = front -> next;
		free(q);
	}
	return num;
}

void display(){
	struct node *ptr;;
	int i = 0; // I create this variable in order to count the total number of passengers

	if (front == NULL)
		printf("\n\tZero passenger\n");

	ptr = front;
	printf("\n\t\tQueue of all passenger ticket numbers: "); // just for formatting
	printf("\n\tTHE GATE------->|    |");
	printf("\n\t----------------      ----------------------");
	while (ptr != NULL){
		printf("\n\t\t\t |%d| ", ptr -> data);
		ptr = ptr -> next;
		i++;
	}
	printf("\n\t\tTotal: %d passenger(s)" , i);
}

int peek(){
	struct node *q;
	int num;
	if (front == NULL){
		printf("\n\t\t Zero passenger!");
		return 0;
	}
	else
		q= front;
	num = q -> data;
	return num;
}