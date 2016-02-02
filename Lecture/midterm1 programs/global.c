//this example demonstrates global variables

#include <stdio.h> 

//variables that are declared outside of a function
//are called global variables and are accessible by all functions
//that come after them.

//there is only ever one instance of each global so if one function
//changes a global variable's value then that change is seen everywhere

//the use of global variables is highy discouraged because it
//breaks modularity of functions. This makes it harder to understand
//what is going on in a function and to modify them if needed because
//of the increased interdependence

#define VALUE 17

int num1; //this variable is global

void set_num1(int val);
void increase_num1(int amount);
void print_num1();

void set_num1(int val){
  //you reference global varibles just like any other variables
  num1 = val;
  print_num1();
}

void print_num1(){
  printf("num1 is now %d\n", num1);
}

void increase_num1(int amount){
  num1 = num1 + amount;
}


int main(){
  set_num1(VALUE);
  increase_num1(12);
  print_num1();
  increase_num1(-3);
  print_num1();
  return 0;
}

