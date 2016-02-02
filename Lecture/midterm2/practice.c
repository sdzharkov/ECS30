#include <stdio.h>
#include <stdlib.h>

/*
void perm4(int values[],int len, int perm[][4]){
	

	return;
}
*/
void readin (int len, int values[]){
	int i = 0;
	int j = 0;

	for (i = 0;i<len;++i){
		scanf("%d",&values[i]);
		}
	for (j=0;j<len;++j){
		printf("%d ",values[i]);
	}
	printf("\n");

	return;
}

int main(){
	int values [4];
	int len = 4;
	printf("Please enter four numbers:\n");
	readin(len, values);

	
	return 0;
	
}
