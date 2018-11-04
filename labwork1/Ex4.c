#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	double x;
	double y;	
} Point;

int main(){
	// Exercise 4: By using mathematics (vector), we know that the 
	// condition to get the rectangle is (x1 !=  x2 or y1 != y2)
	printf("\nExercise 4: \n");
	Point P1; Point P2;
	
	int check = true ;
	// ask user to type the value until it's correct!
	while (check){
		printf("Enter point P1 (x,y): "); scanf("%lf,%lf", &P1.x, &P1.y);
		printf("Enter point P2 (x,y): "); scanf("%lf,%lf", &P2.x, &P2.y);
		
		if((P1.x == P2.x) || (P1.y == P2.y)){
			printf("Wrong \n");
		}
		else {
			printf("Right \n"); 
			check = false;
		}
	}

	// calculate the area of the rectangle
	double width = abs(P1.x - P2.x);
	double length = abs (P1.y - P2.y);
	double area =  length * width ;
	printf("Area = %.3f\n", area);

	Point C;
	printf("Enter a pointC (x,y): ");
	scanf("%lf,%lf", &C.x, &C.y);
	// To check whether the point is inside or outside of the rectangle, we compare
	// the total area of 4 small triangles with the area of the rectangle.
	double area1, area2, area3, area4;
	area1 = abs(C.x - P1.x) * length / 2; // triangle C.P1.P1'
	area2 = abs(C.y - P2.y) * width / 2;  // triangle C.P1'.P2'
	area3 = abs(C.x - P2.x) * length / 2; // triangle C.P2.P2'
	area4 = abs(C.y - P1.y) * width / 2;  // triangle C.
	if ((area1 + area2 + area3 + area4) == area) printf("1");
	else printf("0");

	return 0;
}