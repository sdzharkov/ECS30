#include <stdio.h>
 
void print_alpha(){
  char cur_char = 'a';
  
  while(cur_char <= 'z'){
    printf("%c\n", cur_char);
    cur_char +=1;
  }
}

void print_alpha_for(){



/*
  for(intialization; condition; update){
    code to be run on each iteration
  }
  
  */
  
  char cur_char;
  char letter;
  
  letter = ++cur_char + 1;// letter = (cur_char += 1) + 1
  letter = cur_char++ + 1;//letter = cur_char + 1; cur_char +=1;
  
  for(cur_char = 'a'; cur_char <= 'z'; cur_char++){
  ++curchar
  cur_char++
    printf("%c\n", cur_char);
  }
  
}

int main(){

  int count_max = 0;
  int current_count = 1;
   
  print_alpha(); 
  printf("Enter a number to count to: ");
  scanf("%d", &count_max);

  while(current_count <= count_max){
    printf("%d\n", current_count); 
    current_count += 1;
  }
  return 0;
}
