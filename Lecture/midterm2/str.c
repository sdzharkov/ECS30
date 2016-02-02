#include <stdio.h>

#include <string.h>

int strlen(char str[]){
  //returns the length of str
  int i;
  
  for(i =0; str[i] != '\0'; i++){
  
  }
  return i;
}

void strcpy(char dest[], char src[]){
  int i;
  
  for(i = 0; src[i] != '\0'; i++){
    dest[i] = src[i];
  }
  dest[i] = '\0';
}

void strncpy(char dest[], char src[], int n){
  int i;
  
  for(i = 0; i < n; i++){
    dest[i] = src[i];
    
    if(src[i] == '\0')
      break;
  }
}

void strcat(char dest[], src[]){
  int i = strlen(dest);
  int j = 0;
  
  for(; src[j] != '\0'; ++j, i++){
    dest[i] = src[j];
  }
  dest[i] = '\0';
  
}

int strcmp(char str1[], char str2[]){
  int i;
  
  for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
    if(str1[i] > str2[i]){
      return 1;
    }
    else if(str1[i] < str2[i]){
      return -1;
    }
  }
  
  if(str1[i] > str2[i]){
      return 1;
    }
    else if(str1[i] < str2[i]){
      return -1;
  } 
  else{
    return 0;
  }
  
}

int strcmp2(char str1[], char str2[]){
  int i;
  
  for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
    if(str1[i] != str2[i]){
      return str1[i] - str2[i];
    }
  }
  return str1[i] - str2[i];
  
} 

void lower_str(char str[]){
  int i;
  
  for(i = 0; str[i] != '\0'; i++){
    str[i] = to_lower(str[i]);
  }
}

int case_insensitive_strcmp(char str1[], char str2[]){
  lower_str(str1); lower_str(str2);
  return strcmp(str1, str2);
}


int main(){
  char word[20];
  int nums[100];
  int first3[] = {1,2,3};
  int more_nums[50] = {1,2,3};
  int i;
  
  char greeting[] = "Hello";
  char greeting2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  
  nums[0] = 2;
  nums[1] = 7;
  nums[99] = 64;
  
  printf("%s\n", (char*)nums);
  printf("%s", greeting);
  printf("%c", greeting[0]);
  scanf("%s", word);
  
  for(i = 0; i < 100; i++){
    printf("%s\n", nums[i]);
  }

  return 0;
}
