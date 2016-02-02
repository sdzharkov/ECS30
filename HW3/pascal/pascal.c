#include <stdio.h>

void pascalfunc(int pascalNum);


int main(){
	int pascalNum = 0;
	
	printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
	scanf("%d", &pascalNum);
	
	pascalfunc(pascalNum);
	
	return 0;
	}
	
void pascalfunc(int pascalNum){

	int row = 0;
	int num = 0;
	int col = 0;
	
	
	for (row=0; row < pascalNum; ++row){
		num = 1;
		for (col = 0; col <= row; ++col){
			printf("%d ",num);
			num = num * (row-col) / (col + 1);
		}
		printf("\n");
	}
			
	return;
	
	}
			
