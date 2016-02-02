#include <stdio.h>

int is_sick(int vomitting, int fever, int runny_nose){
  //you are consdered sick if you are vommiting OR have a fever AND a runny_nose
  if(vomitting){
    return 1; //All numbers that aren't 0 are considered true
  }
  else if(fever && runny_nose){ //&& stands for logical and
    //here you would be sick if you had a fever and a runny nose
    return 1;
  }
  
  else{
    return 0; //0 is considered false in C
  }

  //we could rewrite the above as
  return vomitting || (fever && runny_nose);
  //the || stand for logical or
}




int main(){

  int vommitting, fever, runny_nose;
  
  printf("If you are vommiting enter 1 otherwise enter 0: ");
  scanf("%d", &vommitting);
  
  printf("If you have a fever enter 1 otherwise enter 0: ");
  scanf("%d", &fever);
  
  printf("If you have a runny nose enter 1 otherwise enter 0: ");
  scanf("%d", &runny_nose);
  
  if(is_sick(vommitting, fever, runny_nose)){
    printf("You shouldn't go to school today\n");
  }
  else{
    printf("You can go to school\n");
  }

}
