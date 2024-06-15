#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// fetching stored matrix From file
char fetching_from_file(char* arr[][12],int size){
  // initializing matrix with size 
	arr[size][size];
  // opening a file and assigning a file pointer in its begining
	FILE *f=fopen("sudokufiling.txt","r");
  // checking file pointer is not null 
	if(f == NULL){
		printf("Error in opening file");
		return 1;
	}
	int i,j;
  // fetching and storing file data in matrix charachter by character 
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fscanf(f, "%c" , &arr[i][j]);
		}
	}
  // closing file pointer
	fclose(f);
}


// storing  matrix in file
char storing_in_file(char* arr[][12],int size){
    // initializing matrix with size 
	arr[size][size];
   // opening a file and assigning a file pointer in its begining
	FILE *f=fopen("sudokufiling.txt","w");
	if(f == NULL){
		printf("Error in opening file");
		return 1;
	}
	int i,j;
  //  storing matrix data in file charachter by character 
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(f, "%s" , arr[i][j]);
		}
	}
  // closing file pointer
	fclose(f);
}
