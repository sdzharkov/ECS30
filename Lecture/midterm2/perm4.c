#include <stdio.h>
#define MAX_LEN 4
void perm4(int values[], int len, int perms[][MAX_LEN]){
  int i,j,k,l;
  int perm_count = 0;
  
  for(i = 0; i < len; i++){
    for(j = 0; j < len; j++){
      if(j ==i){
        continue;
      }
      for(k = 0; k < len; k++){
        if(k == i || k == j){
          continue;
        }
        for(l = 0; l < len; l++){
          if(l == i || l == j || l == k){
            continue;
          }
          perms[perm_count][0] = values[i];
          perms[perm_count][1] = values[j];
          perms[perm_count][2] = values[k];
          perms[perm_count][3] = values[l];
          perm_count++;
        }
      }
    }
  }

}

int factorial(int n){
  int prod = 1;
  int i;
  
  for(i = 2; i <= n; i++){
    prod *= i;
  }
  return prod;
}

int main(){
  int values[] = {1,2,3,4};
  int num_perms = factorial(MAX_LEN);
  int perms[num_perms][MAX_LEN];
  int i,j;
  
  perm4(values, MAX_LEN, perms);
  
  printf("There are %d permutations\n", num_perms);
  for(i =0; i < num_perms; i++){
    for(j = 0; j < MAX_LEN; j++){
      printf("%d ", perms[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
  
  
