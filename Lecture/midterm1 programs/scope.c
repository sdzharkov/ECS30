//this program demonstrates the concept of scope
//scope determines what variables are accessible by a function
//In short a function can access
//1: Global variables
//2: It's arguments
//3: variables it declares


//this program will not compile unless you comment out bad_scope
#include <stdio.h>

//global variables are visisble and accessible by all functions
//that come after their declaration. This is why when you see
//global variables they are generally at the top of a program
int global_var = 10; 


void fun1(int arg1, int arg2){
  //a function can access all of its arguments
  int result; //it can also access any variables it declares
  
  result = arg1 + arg2;
  
  //again it can also access global variables
  result = result* global_var;
  
  printf("fun1's Result = %d\n", result);

}

void fun2(){
  //multiple functions can declare variables with the same name
  //they each get their own unique variable (no sharing)
  int result; 
  
  result = global_var + 7;
  
  printf("fun2's Result = %d\n", result);
}

void hiding(){
  //if a function declares a variable that has
  //the same name as a global variable
  //that global variable becomes inacessible inside that function
  //this is called variable hiding.
  
  int global_var = 99;
  
  printf("Inside hiding global_var is %d\n", global_var);
}

/*
void bad_scope(){
  //a function cannot access another function's variables or arguments
  
  fun1(10, 12);
  
  printf("Trying to be bad. fun1's arg1 is %d and arg2 is %d\n", arg1, arg2);
  printf("Trying to be bad. fun1's result is %d\n", result);

}
*/

int main(){

  fun1(100,200);
  fun2();
  printf("global var is %d\n", global_var);
  hiding();
  printf("global var is still %d\n", global_var);
  
}
