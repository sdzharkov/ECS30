#include <stdio.h>
#include <string.h>
#include <ctype.h>

void comparestrings(char word1[], char word2[]);
int findanagram(char word1[], char word2[]);
	

void comparestrings(char word1[],char word2[]){
	int i =0;
	int j = 0;
	char rep1[20];
	char rep2[20];
	
	strcpy(rep1,word1);
	strcpy(rep2,word2);
	
	if (strlen(word1) !=  strlen(word2)){
		printf("%s is NOT an anagram of %s\n",word1,word2);
	}
	for (i=0;i<=strlen(word1);++i){
		word1[i] = tolower(word1[i]);
	}
	for (j=0;j<=strlen(word2);++j){
		word2[j] = tolower(word2[j]);
	}
	
	findanagram(rep1,rep2);
	if (findanagram(word1,word2) == 0){
		printf("%s is an anagram of %s",rep1,rep2);
	}
	else {
		printf("%s is NOT an anagram of %s",rep1,rep2);
	}
	return;
}

int findanagram(char word1[],char word2[]){//finding the length and comparing
	int i,j;
	int count1= 0;
	int count2 = 0;
	
	for (i=0;i<=strlen(word1);++i){
		count1 += (int)word1[i];
	}
	for (j=0;j<=strlen(word2);++j){
		count2 += (int)word2[j];
	}
	if (count1 != count2)
		return 1;
	
	
	return 0;
}

int main(){

	char word1[20];
	char word2[20];

	printf("Please enter the first word: ");
	scanf("%s",word1);
	printf("Please  enter the second word: ");
	scanf("%s",word2);
	
	comparestrings(word1,word2);
	
	return 0;
}
