
#include <stdio.h>

#define NAME_LENGTH (15 + 1)

void class_combs(char class1[][NAME_LENGTH], int num_people_class1, 
                 char class2[][NAME_LENGTH], int num_people_class2){
                 
  int i, j;
          
  for(i =0; i < num_people_class1; i++){
    for(j =0; j < num_people_class2; j++){
      printf("%s could be partners with %s\n", class1[i], class2[j]);  
    }
  }               
}

int main(){
  char class1[][NAME_LENGTH] = {"bob", "july", "scott"};
  char class2[][NAME_LENGTH] = {"beth", "marion", "loyd", "george"};
  
  class_combs(class1, 3, class2, 4);
  class_combs(class2, 4, class1, 3);
  
  return 0;

}
