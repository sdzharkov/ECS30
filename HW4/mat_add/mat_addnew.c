#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int** makematrix(int row, int col);
void readinMatrix(int row,int col,int** matrix);
void addMatrix(int row, int col, int** matrixA,int** matrixB);
//void freeMatrix(int row, int** matrix);

int** makeMatrix(int row, int col){
	int i = 0;
	int** matrix = (int**)malloc(sizeof(row*sizeof(int*)));
	for (i=0;i<row;++i){
		matrix[i]= (int*)malloc(sizeof(col*sizeof(int)));
		
	return matrix;
}

void readinMatrix(int row,int col,int** matrix){
	int i = 0;
	int j = 0;
	

	for (i=0;i<row;++i){
		for(j=0;j<col;++j){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	return;
}	


void addMatrix(int row, int col, int** matrixA,int** matrixB,int** matrixC){
	int i = 0;
	int j = 0;
	for (i= 0;i<row; ++i){
		for (j=0;j<col; ++j){
			matrixC = matrixA[i][j] + matrixB[i][j]);
		}
	}
	
	for (i = 0; i<row;++i){
		for(j=0;j<col;++j){
			printf("%d",matrixC[i][j]);
			}
			printf("\n");
		}
		
		i = 0;
	for (i = 0; i < num_rows; i++) {
		free(matrix_A[i]);
		free(matrix_B[i]);
		free(matrix_C[i]);
	}
	free(matrix_A);
	free(matrix_B);
	free(matrix_C);

	return;
}
/*
void freeMatrix(int row, int** matrix){
	int i =0;
	for (i=0;i<row;++i){
		free(matrix[i]);
		}
	free(matrix);
	return;
}
*/
int main(){

	int row = 0;
	int col = 0;

	int** matrixA= NULL;
	int** matrixB= NULL;
	int** matrixC = NULL;


	printf("Please enter the number of rows: ");
	scanf("%d",&row);
	printf("Please enter the number of columns: ");
	scanf("%d",&col);
	
	matrixA = makematrix(row,col);
	matrixB = makematrix(row,col);
	matrixC = makematrix(row,col);
	
	printf("Enter Matrix A \n");
	readinMatrix(row,col,matrixA);
	printf("Enter Matrix B \n");
	readinMatrix(row,col,matrixB);
	
	printf("A + B = \n");
	addMatrix(row,col,matrixA,matrixB,matrixC);
	/*
	freeMatrix(row,matrixA);
	freeMatrix(row,matrixB);
*/
	return 0;
	
}

