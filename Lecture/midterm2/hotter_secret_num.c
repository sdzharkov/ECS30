
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

int abs(int a){
  
  if(a >=0){
    return a;
  }
  else{
    return -1 * a;
  }

}

int main(){

  const int secret_num = 69;
  int current_guess, old_guess;
  
  
  //get the first guess
  current_guess = get_guess();
  
  if(current_guess != secret_num){ //check to see if the user got it right on the first guess
    printf("Nope, that wasn't my secret number.\n");
    old_guess = current_guess;
    current_guess = get_guess();
  
    while(current_guess != secret_num){
      printf("Nope, that wasn't my secret number.\n");
      if(abs(current_guess - secret_num) > 
          abs(old_guess - secret_num)){
        printf("You are getting colder\n");    
      }
      else if(abs(current_guess - secret_num) <
          abs(old_guess - secret_num) ){
        printf("You are getting warmer\n");
      }
      else{
        printf("You just guessed that number\n");
      }
      old_guess = current_guess;
      current_guess = get_guess();
    }
  }//user did not guess the secret number

  printf("Great job! You guessed my secret number.\n");

  return 0;
}
