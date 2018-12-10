#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define SPACE 10 // define a number using in formatting the image of the tree

// THERE IS A NOTE AT THE END OF THE PROGRAM, PLESE CHECK IT CAREFULLY

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree = NULL; 						// initialize the tree
void program();									// main program is here
void sort(int arr[], int);						// sort the input array using bubble sort
struct node *create_tree(int arr[], int, int);	// build the interal nodes and leaf nodes using recursive method
void display(struct node *, int);				// print out the picture of the tree 
void preorderTraversal(struct node*);			// print out the inorder traversal of the tree;

int main(){
	printf("\n\t*********BINARY SEARCH TREE PROGRAM*********");
	printf("\nCreated: Dinh Nhu Minh Phuong - BI8_141 - Group2");
	printf("\n//Special thanks to my friend Le Nhu Chu Hiep for helping me understanding the idea.");
	program();
	return 0;
}

void program(){
	/*INITIALIZE THE INPUT */
	// 1. ask user to enter the input
	int i = 0, n, num;
	int arr[100];
	printf("\n\n***Enter number of elements: "); scanf("%d", &n);
	for ( i = 0; i < n; i++){
		printf("Enter a[%d]: ", i); scanf("%d", &arr[i]);
	}
	sort(arr, n);
	printf("---->Your input: ");
	for (int j = 0; j< n; j++){
		printf(" %d ", arr[j]);
	}

	// 2. calculate the number of leaf nodes then add more leaf nodes
	//that have value equal to the maximum of the array
	printf("\n\n***Calculate the number of leaf nodes:");
	int h = round(log(n) / log(2)); //mathematically, log2(n) = log(n) / log(2)
	int numLeaf = pow(2,h);
	int max = arr[i-1];
	printf("\n\t\th = round_up(log2(%d)) = %d",n, h);
	printf("\n\t\tNumber of leaf nodes = 2^h = %d", numLeaf);

	int count; // final number of elements of the final array
	if (numLeaf >= n ) {
		count = numLeaf;
		for( i = n - 1; i< numLeaf; i++){ // add more number
			arr[i] = max;
		}
	}
	else
		count = n;
	printf("\n---->So we need to add %d node(s) more.", count - n);

	// 3. print out the final array to confirm
	printf("\n---->The final array is: [");
	for (int j = 0; j< count; j++){
		printf(" %d ", arr[j]);
	}
	printf("]");


	/* CREATE THE BINARY SEARCH TREE BASED ON THE FINAL INPUT*/
	tree = create_tree(arr, 0, count/2);
	

	/* PRINT OUT THE DIAGRAM OF THE TREE*/
	printf("\n\n***START PRINTING OUT THE TREE");
	printf("\n(The picture of the tree is rotated 90 degrees counter-clockwise)\n");
	display(tree, 0);


	/* PRINT OUT THE INORDER TRAVERSAL */
	printf("\n***Preorder Traversal: ");
	preorderTraversal(tree);
}

void sort(int arr[], int n){ // buble sort algorithm
	int i, j;
	int temp;
	for( i = 0; i < n; i++){
		for (j = 0; j < n - i - 1; j++){
			if ( arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

struct node *create_tree(int arr[], int index, int length){
	// create the root
	struct node *tree = (struct node *)malloc(sizeof(struct node));
	tree -> data = arr[index + length - 1];

	// base case
	if (length == 1){
		// add left node to an internal node
		tree -> left = (struct node *)malloc(sizeof(struct node));
		tree -> left -> data = arr[index];
		tree -> left -> left = tree -> left -> right = NULL;
		// add right node to an internal node
		tree -> right = (struct node *)malloc(sizeof(struct node));
		tree -> right -> data = arr[index + 1];
		tree -> right -> left = tree -> right -> right = NULL;
		return tree;
	}
	// recursively create both left and right subtree from root.
	struct node *leftSubtree = create_tree(arr, index, length/2);
	struct node *rightSubtree = create_tree(arr, index + length, length/2);
	tree -> left = leftSubtree;
	tree -> right = rightSubtree;

	return tree;

}

void display(struct node *ptr, int space){
	// Base case
	if ( ptr == NULL)
		return;
	// Increase distance between levels
	space += SPACE;

	// Process right child first
	display(ptr -> right, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = SPACE; i < space; i++)
		printf(" ");
	printf("%d\n", ptr -> data);

	// Process left child
	display(ptr -> left, space);
}

void preorderTraversal(struct node *ptr){
	if ( ptr != NULL){
		printf("%d ", ptr -> data);
		preorderTraversal(ptr -> left);
		preorderTraversal(ptr -> right);
	}
}

/* IMPORTANT NOTE: THE ALGORTITHM IN THE EXERCISE IS NOT ALWAYS CORRECT:
I and my friend, Praise Oketola, have found some special cases.

If the user enters 5 (or 9, 17, ...) numbers to the input array, then we have 
	h = round(log2(5)) = 2
----> number of leaf nodes = 2^h = 2^2 = 4 < 5
----> num_leafnodes < num_input.
The exercise hasn't mentioned any information about this case!!!
For me, I decided to make the final array which has num_leafnodes items.
*/