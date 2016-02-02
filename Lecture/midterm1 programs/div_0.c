#include <stdio.h>

int main(){
  double first, second;
  printf("Enter a number: ");
  scanf("%lf", &first);
  
  printf("Enter another number: ");
  scanf("%lf", &second);
  
  printf("%lf\n", first/second);
  
  return 0;

}
