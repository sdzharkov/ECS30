#include <stdio.h>

int main(){
  int num1, num2;
  
  printf("Please enter a number: ");
  scanf("%d", &num1);
  
  printf("Please enter another number: ");
  scanf("%d", &num2);
  
  
  if((num1 == num2)){
    printf("%d equals %d\n", num1, num2);
  }
  
  if(num1 != num2){
    printf("%d does not equal %d\n", num1, num2);
  }
  
  if(num1 > num2){
    printf("%d is greater than %d\n", num1, num2);
  }
  
  if(num1 >= num2){
    printf("%d is greater than or equal to %d\n", num1, num2);
  }
  
  if(num1 < num2){
    printf("%d is less than %d\n", num1, num2);
  }
  
  if(num1 <= num2){
    printf("%d is less than or equal %d\n", num1, num2);
  }

  return 0;
}
