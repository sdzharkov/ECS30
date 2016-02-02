#include <stdio.h>

int main(void) {
   const int NUM_VALS = 4;     
   int userValues[NUM_VALS];        
   int i = 0;        
   int matchValue = 4;
   int numMatches = -99; // Set numMatches to 0 before your for loop
                
   userValues[0] = 4;
   userValues[1] = 4;
   userValues[2] = 1;
   userValues[3] = 4;
   
   for(i = 0, numMatches = 0; i <= NUM_VALS; i++){
    printf("i = %d, numMatches = %d, NUM_VALS = %d userValues[i] = %d\n",i, numMatches, NUM_VALS, userValues[i]);
    if(userValues[i] == matchValue){
      numMatches++;
    }
   }
   printf("matchValue: %d, numMatches: %d\n", matchValue, numMatches);

   return 0;
}
