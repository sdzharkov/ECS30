//program to calculate the surface area and volume of a rectangular prism
//use doubles for the program
#include <stdio.h>
#include <math.h>

//declare all functions at the top
double get_dist(double x1, double x2, double x3, double y1, double y2, double y3);
double get_rect_area(double length1, double width1);
double get_surface_area(double length, double width, double height);
double get_volume(double length, double width, double height);

//function to get the distance between two points 
//when points are three dimensional
double get_dist(double x1, double x2, double x3, double y1, double y2, double y3) {
	double expression, total_distance; //initialize expression inside the square root and the final distance
	expression = pow(y1-x1, 2) + pow(y2-x2, 2) + pow(y3-x3, 2); //distance formula
	total_distance = sqrt(expression); //final part of the distance formula is to take the square root of the sum of the differences of squares
	return total_distance;
}

//function to get the volume of the rectangular prism using length, width, and height
double get_volume(double length, double width, double height) {
	return (length * width * height); //volume of a rectangular prism
	}

//function to get the area of a specific rectangle
double get_rect_area(double length1, double width1) { //pass parameters that calculates the area of the rectangle
	return length1 * width1; 
}

//function to get the surface area of the rectangular prism
double get_surface_area(double length, double width, double height ) {
	
	double surface_area; //variable to be returned 
	double area1, area2, area3; //variables to store the areas of the 3 different rectangles in the prism
	//call the function to get the areas of the different rectangles present
	area1 = (get_rect_area(length, width)) * 2; //each rectangles has two faces in the prism
	area2 = (get_rect_area(length, height)) * 2; //calculate each individual rectangle's area * 2
	area3 = (get_rect_area(width, height)) * 2;

	surface_area = (area1 + area2 + area3); //add up the areas of the 6 rectangles

	return surface_area;
}

int main() {

	double coor1_1, coor1_2, coor1_3; //storing coordinates entered by user into variables
	double coor2_1, coor2_2, coor2_3;
	double coor3_1, coor3_2, coor3_3;
	double coor4_1, coor4_2, coor4_3;
	double coor5_1, coor5_2, coor5_3;
	double coor6_1, coor6_2, coor6_3;
	double coor7_1, coor7_2, coor7_3;
	double coor8_1, coor8_2, coor8_3;
	double length, width, height; //three measurements we need to calculate volume and surface area

	printf("Enter the first coordinate in the form x y z: "); //print statements to prompt the user for all the coordinates
	scanf("%lf %lf %lf", &coor1_1, &coor1_2, &coor1_3);
	printf("Enter the second coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor2_1, &coor2_2, &coor2_3);
	printf("Enter the third coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor3_1, &coor3_2, &coor3_3);
	printf("Enter the fourth coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor4_1, &coor4_2, &coor4_3);
	printf("Enter the fifth coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor5_1, &coor5_2, &coor5_3);
	printf("Enter the sixth coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor6_1, &coor6_2, &coor6_3);
	printf("Enter the seventh coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor7_1, &coor7_2, &coor7_3);
	printf("Enter the eighth coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &coor8_1, &coor8_2, &coor8_3);

	//only really need to use 3 points from the prism to do all of the calculations
	//calculate length, width, and height of the prism through calling the function to get distance
	length = get_dist(coor1_1, coor1_2, coor1_3, coor2_1, coor2_2, coor2_3); //uses the 0 and 1 vertices
	width = get_dist(coor2_1, coor2_2, coor2_3, coor3_1, coor3_2, coor3_3); //uses the 1 and 2 vertices
	height = get_dist(coor2_1, coor2_2, coor2_3, coor7_1, coor7_2, coor7_3); //uses the 1 and 6 vertices

	printf("The surface area of the prism is %.2lf\n", get_surface_area(length, width, height)); //print statement for surface area with percision of two decimal places
	printf("The volume of the prism is %.2lf\n", get_volume(length, width, height));//print statement for volume with percision of two decimal places
	

	return 0;

}

