//this program finds the minimum of all values entered by a user
//the user is done entering numbers if they enter a non number

int for_min(){
int cur_min, user_num, count;
  
  printf("Please enter a number or something else to finish: ");
  
  count = scanf("%d", &cur_min);
  
  for(;count == 1;){
    printf("Please enter a number or something else to finish: ");
    count = scanf("%d", &user_num);
    
    if(count != 1){ //the user didn't enter a number
     break; //leave the loop
    }
    
    if(user_num < cur_min){ //new number is smaller than smallest number seen so far
      cur_min = user_num; //update our smallest number
    }
  
  }//while numbers are still being entered
 
  
  
  printf("The smallest number you entered was %d.\n", cur_min);




}


#include <stdio.h>

int main(){

  int cur_min, user_num, count;
  
  printf("Please enter a number or something else to finish: ");
  
  count = scanf("%d", &cur_min);
  
  while(count == 1){
    printf("Please enter a number or something else to finish: ");
    count = scanf("%d", &user_num);
    
    if(count != 1){ //the user didn't enter a number
     break; //leave the loop
    }
    
    if(user_num < cur_min){ //new number is smaller than smallest number seen so far
      cur_min = user_num; //update our smallest number
    }
  
  }//while numbers are still being entered
 
  
  
  printf("The smallest number you entered was %d.\n", cur_min);


  return 0;
}
