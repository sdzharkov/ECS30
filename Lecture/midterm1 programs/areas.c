//This program demonstrates the use of functions
//By allowing the user to calculate the areas of a square, rectangle, triangele, circle and trapezoid

#include <stdio.h>


//C is a one pass compiler which means it only reads the source code as it goes
//in order to allow ourselves the flexibility to place our functions in any order
//we have to give their declarations at the beginning of the program
//each declaration says what the function returns and what arguments
//it accepts but does not include the code that should be run


double rect_area(double width, double height);
double square_area(double length);
double tri_area(double base, double height);
double circle_area(double radius);
double trap_area(double top, double base, double height);

void do_rect();
void do_square();
void do_tri();
void do_circle(void);
void do_trap(void);

//function syntax
//return type function name(type arg_name1, type arg_name2, ...){
//code
//}

//every function must have a unique name

double rect_area(double width, double height){
  //calculates the area of a rectangle with the given width and height
  
  return width * height;  
  //return is how a function gives back a value
  //the syntax is
  //return expression;
  
  //return also causes a function to immeidately terminate so no code after a return is ever run
  printf("This will never be displayed because it is after a return\n");
}

double square_area(double length){
  //calculate the area of a square
  
  //to call a function write its name(first argument, second argument, ...)
  //when you call a function you immediately jump to that function and execute the code that
  //is in that function. After that function returns you come back to where you called it
  //and proceed from where you left off
  
  //a function can call other functions
  //it is perfectly ok
  return rect_area(length, length);
}

double tri_area(double base, double height){
  //calculate the area of a triangle
  return rect_area(base, height) / 2.0;
}

double circle_area(double radius){
  //calculate the area of a circle
  const double pi = 3.14159265359;
  return pi * radius * radius;
}

double trap_area(double short_side, double long_side, double height){
  //caculate the area of a trapezoid
  
  //you can store the result of a function in a variable
  //to do so just assign a variable to a function that returns something
  double r_area = rect_area(short_side, height); //the area of the center square
  double tri_base = (long_side - short_side) / 2.0;
  double tri_areas = tri_area(tri_base, height) * 2;//the area of the triable parts
  double t_area = r_area + tri_areas;
  
  return t_area;
}

//functions don't always have to return a value or accept arguments
//if a function doesn't return a value you should place void in front of it
void do_rect(){
  double height, width, area;
  
  printf("Please enter the width of the rectangle: ");
  scanf("%lf", &width);
  
  printf("Please enter the height of the rectangle: ");
  scanf("%lf", &height);
  
  area = rect_area(width, height);
  
  printf("The area of a rectangle with height %.2lf and width %.2lf is %.2lf\n", height, width, area);
  
  //if a function doesn't return anything you don't need a return staement
}//do_rect

//placing void inside the () is the same as placing nothing there
void do_square(void){
  double length, area;
  
  printf("Please enter of one side of the square: ");
  scanf("%lf", &length);
  
  area = square_area(length);
  
  printf("The area of a square with length %.2lf is %.2lf\n", length, area);
  
  //if a function doesn't return anything you can still have a return statement
  ///it just shouldn't return a value
  return; 
}//do_square


void do_tri(){
  double base, height, area;
  
  printf("Please enter the base of the triangle: ");
  scanf("%lf", &base);
  
  printf("Please enter the height of the triangle: ");
  scanf("%lf", &height);
  
  area = tri_area(base, height);
  
  printf("The area of a triangle with base %.2lf and height %.2lf is %.2lf\n", base, height, area);

}//do_tri


void do_circle(void){
  double radius, area;
  
  printf("Please enter the radius of the circle: ");
  scanf("%lf", &radius);
  
  area = circle_area(radius);
  
  printf("The area of a circle with radius %.2lf is %.2lf\n", radius, area);
}//do_circle


void do_trap(void){
  double short_side, long_side, height, area;
  
  printf("Please enter the length of the short side of the trapezoid: ");
  scanf("%lf", &short_side);
  
  printf("Please enter the length of the long side of the trapezoid: ");
  scanf("%lf", &long_side);
  
  printf("Please enter the height of the trapezoid: ");
  scanf("%lf", &height);
  
  area = trap_area(short_side, long_side, height);
  
  printf("The area of a trapezoid with a short side of %.2lf a long side of %.2lf\
 and height %.2lf is %.2lf\n", short_side, long_side, height, area);

}//do_trap


int main(){
  do_rect();
  do_square();
  do_tri();
  do_circle();
  do_trap();
  return 0;
}


