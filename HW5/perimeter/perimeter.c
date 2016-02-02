#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cord_struct{ //define struct with x and y values
	int xval;
	int yval;
} cord;

void scanFile (FILE* inFile); //declaration of scanFile
double findperimeter(int numpoints,cord* cordptr); //declaration of find perimeter

void scanFile (FILE* inFile){ //this function scans the file and the values in
	int i= 0;
	int numPoints;
	fread(&numPoints,sizeof(int),1, inFile);//this reads the number  of points in
	cord* cordptr = NULL; //declaration of my cord pointer
	cordptr = (cord*)malloc(numPoints*sizeof(cord)); //allocating space for the cord

	for (i=0;i<numPoints; i++){ //until i is less than the number of points
		fread(&(cordptr[i].xval),sizeof(int),1,inFile);// scan the x in 
		fread(&(cordptr[i].yval),sizeof(int),1,inFile);// scan the y in
	} 
	printf("The perimeter is %.2lf\n",findperimeter(numPoints,cordptr));//call findperimeter and print
}

double findperimeter(int numPoints,cord* cordptr){//this function finds the perimter with the distance formula 
	double perimeter = 0.0;
	int i = 0;
	double totalLen = 0.0;
	double lastLen = 0.0;
	
	for (i=0;i<numPoints - 1;i++){ // when i is less than the number of points minus one 
		totalLen = (pow((cordptr[i+1].xval - cordptr[i].xval),2) + pow((cordptr[i+1].yval - cordptr[i].yval),2)); //calculate length of side
		perimeter += sqrt(totalLen); // adds the square root of the side to the perimter variable
	}
	lastLen = sqrt(pow((cordptr[(numPoints-1)].xval - cordptr[0].xval),2)
					 + pow((cordptr[(numPoints-1)].yval-cordptr[0].yval),2));//finds the distance between the first and last point
	perimeter += lastLen;//adds the final length of the perimeter
	return perimeter;
}

int main(int argc, const char* argv[]){
	FILE* inFile = fopen(argv[1],"rb"); //opens the file for reading
	scanFile(inFile); //calling scanfile with the file
	fclose(inFile); // closes the file
	return 0;
}

