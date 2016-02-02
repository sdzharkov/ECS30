
//this program has the user repeatedly guess a number until they guess the secret number
//possible improvements: telling the user if they are getting closer or not.
//challenge try converting while loop to for loop. What if we wanted more than 1 secret number?

#include <stdio.h>

int get_guess(){

  int guess;
  printf("Enter a number to try and guess my secret number: ");
  scanf("%d", &guess);

  return guess;
}

int main(){

  const int secret_num = 69;
  int user_guess = 0;
  
  //get the first guess
  user_guess = get_guess();
  
  if(user_guess != secret_num){ //check to see if the user got it right on the first guess
  
    while(user_guess != secret_num){
      printf("Nope, that wasn't my secret number.\n");
    
      //get the next guess
      user_guess = get_guess();
    }
  }//user did not guess the secret number

  printf("Great job! You guessed my secret number.\n");

  return 0;
}
