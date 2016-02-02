#include <stdio.h>

int at_least_half(double first, double second){
  //returns true if first is at least half of second
 
  //logical and and logical or have a short circuit behavior
  //since false and anything is always false if C finds part of an and to be false
  //it will stop evaluating the rest
  //C evalutates the expressions from left to right
  if(second != 0 && (first / second) >= 0.5){ //beacuse of the short circuiting this is ok
    //but this wouldn't be: if(first/second >= 0.5 && second != 0)
    return 1; 
  } 
  else{
    return 0;
  }

}


int main(){
  double first, second;
  
  printf("Enter a number: ");
  scanf("%lf", &first);
  
  printf("Enter another number: ");
  scanf("%lf", &second);
  
  if(at_least_half(first, second)){
    printf("%lf is at least half of %lf\n", first, second);
  }
  else{
    printf("%lf is not at least half of %lf\n", first, second);
  }
  return 0;
}
