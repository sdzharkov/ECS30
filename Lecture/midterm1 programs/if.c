//this program demonstrates the use if statements
//if statements allow you to take actions when certain conditions are met

#include <stdio.h>

void can_drink(int age){
  //syntax is
  //if(expression){
  //code to be run if expression is true
  //}
  //else{
  // code to run if expression is false
  //}
  //the else is optional 
  if(age >= 21){
    printf("Yes you can drink alcohol\n");
  }
  else{
    printf("You are not old enough to drink alcohol\n");
  }

}

void stop_light(int color){
  const int red = 0;
  const int green = 1;
  const int yellow = 2;
  
  //the full syntax is 
  /*
  if(expression){
    code to run if expression is true
  }
  else if(expression 2){
    code to run if expression 2 is true
  }
  else if(expression 3){
    code to run if expresion 3 is true
  }
  ...
  else{
    code to run if no expression holds true
  }
  
  exactly only branch of an if/else if/else statement will be run
  the expressions are evaluated from top to bottom and the first one 
  that is true will be run
  */
  
  if(color == red){
    printf("Stop your car\n");
  } 
  else if(color == green){
    printf("Continue moving\n");
  }
  else if(color == yellow){
    printf("Floor it!\n");
  }
  else{
    printf("Unrecognized color\n");
  }


}

void height_if(double height){
  //this function demonstrates that
  //if statements are not mutually exclusive

  if(height > 7){
    printf("You are very tall\n");
  }
  
  if(height > 6){
    printf("You are tall\n");
  }
  
  if(height <= 6 && height > 5){
    printf("You are average height\n");
  }

  if( height <= 5 && height > 4){
    printf("You are short\n");
  }
  else{
    printf("You are very short\n");
  }
}


void height_else_if(double height){
  //we really only want one arm of our if statement to be run
  //so we switch to else if

  if(height > 7){
    printf("You are very tall\n");
  }
  
  else if(height > 6){
    printf("You are tall\n");
  }
  
  else if(height <= 6 && height > 5){
    printf("You are average height\n");
  }

  else if( height <= 5 && height > 4){
    printf("You are short\n");
  }
  else{
    printf("You are very short\n");
    hi
  }
}


int main(){
  double height;
  printf("Enter your height in feet: ");
  scanf("%lf", &height);
  height_if(height);
  height_else_if(height);
  return 0;
}

