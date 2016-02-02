//program to add together matrices A and B, and display their sum in C

#include <stdio.h>

//declare all functions at the beginning of the program
void add_matrices(int num_rows, int num_cols, int matrix_A[num_rows][num_cols], int matrix_B[num_rows][num_cols]);
void get_matrix(int num_rows, int num_cols, int matrix[num_rows][num_cols]);

//function of type void that adds together matrix A and matrix B
//prints the result and stores it in matrix C
void add_matrices(int num_rows, int num_cols, int matrix_A[num_rows][num_cols], int matrix_B[num_rows][num_cols]) {
	int i, j;
	int matrix_C[num_rows][num_cols]; //initialize the resulting matrix
	for (i = 0; i < num_rows; i++) { //nested for loop to access a specific element in the 2 dimensional array
		for (j = 0; j < num_cols; j++) {
			matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j]; //add the elements at location[i][j] in A and B to matrix C
		}
	}
	for (i = 0; i < num_rows; i++) {
		for (j = 0; j < num_cols; j++) { 
			printf("%d ", matrix_C[i][j]); //print each resulting number
		}
		printf("\n");
	}

	return;

}

//function to read in the matrices from the user 
//changes made inside the function will be reflected outside the function as well
void get_matrix(int num_rows, int num_cols, int matrix[num_rows][num_cols]) {

	int i = 0; 
	int j= 0;
	//use a nested for loop to access every row and each column in that specific row
	for (i = 0; i < num_rows; i++) {// for each row
		for (j = 0; j < num_cols; j++) { //for each column in each row
			scanf("%d", &matrix[i][j]); //read in a number from the user for that corresponding location
		}
	}

	return;
}


int main() {

	int num_rows = 0; //initialize number of rows
	int num_cols = 0; //initialize number of columns
	int max_size = 100; //maximum dimension the array can have
	int matrix_A[max_size][max_size]; //first matrix whose dimensions are initialized by the max size
	int matrix_B[max_size][max_size]; //second matrix
	

	printf("Please enter the number of rows: "); //ask the user how many rows are in the matrix
	scanf("%d", &num_rows);

	printf("Please enter the number of columns: "); //ask the user how many columns are in the matrix
	scanf("%d", &num_cols);

	printf("Enter Matrix A\n");
	get_matrix(num_rows, num_cols, matrix_A); //call the function that stores the values in matrix A, passed as an argument

	printf("Enter Matrix B\n");
	get_matrix(num_rows, num_cols, matrix_B); //call the function that stores the values in matrix B, passed in the argument

	printf("A + B =\n"); //resulting matrix
	add_matrices(num_rows, num_cols, matrix_A, matrix_B); //call the function that adds them together




	return 0;
}
