#include <stdio.h>

//an inefficient sorting algorithm

void swap(int ar[], int i, int j);
void sort(int ar[], int size);

void sort(int ar[], int size){
  int i, j;
  
  for(i = 0; i < size; i++){
    for(j = i + 1 ; j < size; j++){
      if(ar[j] < ar[i]){
        swap(ar, i, j);
      }
    }
  }
}

void swap(int ar[], int i, int j){
  int temp = ar[i];
  ar[i] = ar[j];
  ar[j] = temp;
}

int main(){
  int ar[100];
  int size;
  int i;
  
  printf("How many numbers are you going to enter? ");
  scanf("%d", &size);
  
  for(i = 0; i < size; i++){
    printf("Please enter the next number: ");
    scanf("%d", &ar[i]);
  }
  sort(ar, size);
  
  for(i = 0; i < size; i++){
    printf("%d\n", ar[i]);
  }

  return 0;
}
