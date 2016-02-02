//this program generate the multiplication table from 1 - 12

#include <stdio.h>

void for_mult_table(){

  int i, j;
  const int max_mult = 12;
  
  for(i = 1; i <= max_mult; ++i){ //for each row
    for(j = 1; j <= max_mult; ++j){ //for each column
      //printf("%4d ", i*j);
      printf("i = %d and j = %d\n", i, j);
    }
    //finished a row display a new line
    printf("\n");
  
  }//for each row

}//for mult_table


void while_mult_table(){

  int i, j;
  const int max_mult = 12;
  
  i = 1;
  while( i <= max_mult){ //for each row
    j = 1;
    while(j <= max_mult){ //for each column
      printf("%4d ", i*j);
      ++j;
    }
    
    //finished a row display a new line
    printf("\n");
    ++i;
  }//for each row

}//while_mult_table


int main(){

 for_mult_table();

  return 0;
}
