/* Programmer: Muhammad Abser mansoor
 * Date: 10/10/2023
 * Task: Initialization of the starting sudoku board for each difficulty.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Arguements include the initial array, the randomly chosen coordinates, the random number and dimension of the square matrix
// Checking columns and rows to see if any column or row collinear to the coordinates has a number equal to the inputted number
int Checkrowscolumns(int ar[length][length],int randposr,int randposc,int num,int length) {
    for (int k = 0;k<length;k++) { 
        if (num == ar[randposr][k] || num == ar[k][randposc]) {
           return 0; 
        }
    }
    return 1;
}

int Checksubblock(int ar[length][length],int randposr,int randposc,int num,int sr,int sc) {
    int srow = sr * (randposr / sr); // sr and sc are the dimensions of the subblocks
    int scolumn = sc * (randposc / sc);
    for (int k = srow;k<srow + sr;k++) { // Now check the subblock that the address belongs to and find if any equal value exists
        for (int j = scolumn;j<scolumn + sc;j++) {
            if (num == ar[k][j]) {
                return 0;
            }
        }
    }
    return 1;
}


void CreatematrixMD() {
    int ar[9][9] = {0}; // Creating a Sudoku Matrix (Medium Difficullty)
    int clue = 0;
    int subblockrows = 3;
    int subblockcolumns = 3;
    int num = 0;
    for (int i = 0;clue < 22;i++) { // Loop for inserting 22 clues within the empty matrix
        
        int randposr = (rand() % (9));

        int randposc = (rand() % (9)); // random numbers chosen to randomly select any block and insert a clue
        
        if (ar[randposr][randposc] == 0) { // Checks if there is no clue present

            num = (rand() % (9)) + 1; // Inputs a random number between 1 and 9 into num variable
            
            // If statement checks the functions return values to see if num passes the sudoku rules
            
            if (Checkrowscolumns(ar,randposr,randposc,num,9) == 1 && Checksubblock(ar,randposr,randposc,num,subblockrows,subblockcolumns) == 1) {
                
                ar[randposr][randposc] = num;
                
                clue++;
            }
        }
    }
    for (int i = 0;i<9;i++) { // Printing the initial matrix
        for (int j = 0;j<9;j++) {
            printf("%d  ",ar[i][j]);
        }
        printf("\n");
    }
}

void CreatematrixED() {
    int ar[6][6] = {0}; // Creating a Sudoku Matrix (Easy Difficullty)
    int clue = 0;
    int subblockrows = 2;
    int subblockcolumns = 3;
    int num = 0;
    for (int i = 0;clue < 14;i++) { // Loop for inserting 14 clues within the empty matrix
        
        int randposr = (rand() % (6));

        int randposc = (rand() % (6)); // random numbers chosen to randomly select any block and insert a clue
        
        if (ar[randposr][randposc] == 0) { // Checks if there is no clue present

            num = (rand() % (6)) + 1; // Inputs a random number between 1 and 6 into num variable
           // If statement checks the functions return values to see if num passes the sudoku rules
            if (Checkrowscolumns(ar,randposr,randposc,num,6) == 1 && Checksubblock(ar,randposr,randposc,num,subblockrows,subblockcolumns) == 1) {
                
                ar[randposr][randposc] = num;
                
                clue++;
            }
        }
    }
    for (int i = 0;i<6;i++) { // Printing the initial matrix
        for (int j = 0;j<6;j++) {
            printf("%d  ",ar[i][j]);
        }
        printf("\n");
    }
}

void CreatematrixHD() {
    int ar[12][12] = {0}; // Creating a Sudoku Matrix (Hard Difficullty)
    int clue = 0;
    int subblockrows = 3;
    int subblockcolumns = 4;
    int num = 0;
    for (int i = 0;clue < 37;i++) { // Loop for inserting 37 clues within the empty matrix
        
        int randposr = (rand() % (12));

        int randposc = (rand() % (12)); // random numbers chosen to randomly select any block and insert a clue
        
        if (ar[randposr][randposc] == 0) { // Checks if there is no clue present

            num = (rand() % (12)) + 1; // Inputs a random number between 1 and 12 into num variable
           // If statement checks the functions return values to see if num passes the sudoku rules
            if (Checkrowscolumns(ar,randposr,randposc,num,12) == 1 && Checksubblock(ar,randposr,randposc,num,subblockrows,subblockcolumns) == 1) {
                
                ar[randposr][randposc] = num;
                
                clue++;
            }
        }
    }
    for (int i = 0;i<12;i++) { // Printing the initial matrix
        for (int j = 0;j<12;j++) {
            if (ar[i][j] >= 10) {
                printf("%c  ",ar[i][j] + 55); // If a number is greater than 9 then capitalized characters are used to represent them
            }
            else {
                printf("%d  ",ar[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    CreatematrixED();
    printf("\n");
    CreatematrixMD();
    printf("\n");
    CreatematrixHD();
    return 0;
}
