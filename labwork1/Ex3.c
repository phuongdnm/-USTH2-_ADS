#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x;
	double y;	
} Point;

int main(){
	// Exercise 3: Define a structure Point to describe a coordinate point (x,y). Write a program to
	// compute the Euclidean distance between two Points.
	printf("\nExercise 3: \n");
	Point point1; Point point2;
	printf("Enter point1 (x,y): "); scanf("%lf,%lf", &point1.x, &point1.y);
	printf("Enter point2 (x,y): "); scanf("%lf,%lf", &point2.x, &point2.y);
	
	double distance = sqrt((point1.x - point2.x)*(point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y));
	printf("Distance = %.3f", distance);
}