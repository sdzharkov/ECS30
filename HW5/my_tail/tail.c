#include <stdio.h>
#include <stdlib.h>


void tail(FILE* inFile,int numLine){
	int linecount;
	//char fileName[100];
	char c;
	//int i;
	int count;
	int ncount;
	
	
	while (!feof(inFile)){
		ncount = fgetc(inFile);
		if (ncount == '\n'){
			linecount ++;
		}
	}
		fseek(inFile,0,SEEK_SET);
		
	while (!feof(inFile)){
		fscanf(inFile,"%c",c);
		if (numLine >= linecount){
			//if (c = "\x00"){
			printf("%c",c);
	}
		else { 
			if ((c == '\n')&&(count < linecount-numLine-1)){
				count ++;
			if (count == linecount-numLine-1){
				printf("%c",c);
			}
		}
	}
		/*
		if (numLine >= linecount){
			while (!feof(inFile)){
				fgets(fileName,100,inFile);
				printf("%s\n",fileName);
			}
		}
		else {
			while (!feof(inFile)){
				
			}
	}
} */
}
}
int main(int argc, char* argv[]) {
	
	FILE* inFile = fopen(argv[1],"r"); 
	int numLine = atoi(argv[2]);
	tail(inFile,numLine);
	fclose(inFile);
	return 0;
	
}
