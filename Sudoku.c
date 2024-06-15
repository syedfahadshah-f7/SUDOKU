#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <fcntl.h>

void createMatrixED(char** ar);

void createMatrixMD(char** ar);

void createMatrixHD(char** ar);

int storing_in_file(char** arr, int size, int total_clues, int all_rows[total_clues], int all_cols[total_clues]);

int fetching_from_file();

void inputOutput(int all_rows[], int all_cols[], int totalRows, int totalClues, char** arr, int sr, int sc);

int checkRowsColumns(int randposr,int randposc,int num, int length, char** ar);

int checkSubblock(int randposr,int randposc,int num, int length, int sr, int sc, char** ar);

void printMatrix(int totalRows, int sr, int sc, char** arr, int totalClues, int all_rows[totalClues], int all_cols[totalClues]);

int checkingForEasy(char** arr, int row, int col);

int checkingForMedium(char** arr, int row, int col);

int checkingForHard(char** arr, int row, int col);

int main() {

    srand(time(NULL)); // Seed the random number generator with the current time

    start : ; // Label to allow restarting the game

    char difficultyLevel;

    do { // Prompt the user to choose difficulty or resume a saved game
        printf("Enter 'E' for easy, 'M' for medium, 'H' for hard, or 'R' to resume the saved game : ");
        scanf(" %c", &difficultyLevel);
        getchar(); // Consume the newline character left in the input buffer

        if(difficultyLevel != 'E' && difficultyLevel != 'M' && difficultyLevel != 'H' && difficultyLevel != 'R'){
            printf("Please choose from 'E', 'M', 'H' or 'R'.\n");
        }
    } while(difficultyLevel != 'E' && difficultyLevel != 'M' && difficultyLevel != 'H' && difficultyLevel != 'R');

    int size = difficultyLevel == 'E' ? 6 : difficultyLevel == 'M' ? 9 : 12; // Determine the size of the matrix based on the chosen difficulty

    // Allocate memory for the matrix
    char** arr = calloc(size, sizeof(char*));
    char* brr = calloc(size * size, sizeof(char));

    for(int i = 0; i < size; i++) {
        arr[i] = brr + (i * size);
    }

    // Choose matrix creation based on difficulty level
    switch(difficultyLevel){
        case 'E' : 
            createMatrixED(arr);
            break;
        case 'M' : 
            createMatrixMD(arr);
            break;
        case 'H' :
            createMatrixHD(arr);
            break;
        case 'R' : ;
            int fetch = fetching_from_file();
            if(fetch == 2) { // Check if a saved game is available
                printf("You have not saved any game.\n");
                goto start; // Restart the game if no saved game is found
            }
            break;
    }

    // Free the allocated memory for the matrix
    for(int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// Creating a Sudoku Matrix (Easy Difficullty)
void createMatrixED(char** ar) {
    int all_rows[14], all_cols[14];
    int clue = 0;
    int num = 0;
    for (int i = 0, k = 0;clue < 14;i++) { // Loop for inserting 14 clues within the empty matrix
        
        int randposr = (rand() % (6));

        int randposc = (rand() % (6)); // random numbers chosen to randomly select any block and insert a clue
        
        if (!ar[randposr][randposc]) { // Checks if there is no clue present

            num = (rand() % (6)) + 1; // Inputs a random number between 1 and 6 into num variable
           // If statement checks the functions return values to see if num passes the sudoku rules
            if (checkRowsColumns(randposr, randposc, num, 6, ar) && checkSubblock(randposr,randposc,num,6,2,3, ar)) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }

    printMatrix(6, 2, 3, ar, 14, all_rows, all_cols);
    inputOutput(all_rows, all_cols, 6, 14, ar, 2, 3);
}

// Creating a Sudoku Matrix (Medium Difficullty)
void createMatrixMD(char** ar) {
    int all_rows[22], all_cols[22];
    int clue = 0;
    int num = 0;
    for (int i = 0, k = 0;clue < 22;i++) { // Loop for inserting 22 clues within the empty matrix
        
        int randposr = (rand() % (9));

        int randposc = (rand() % (9)); // random numbers chosen to randomly select any block and insert a clue
        
        if (!ar[randposr][randposc]) { // Checks if there is no clue present

            num = (rand() % (9)) + 1; // Inputs a random number between 1 and 9 into num variable
           
            if (checkRowsColumns(randposr,randposc,num, 9, ar) && checkSubblock(randposr,randposc,num, 9, 3, 3, ar)) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }

    printMatrix(9, 3, 3, ar, 22, all_rows, all_cols);
    inputOutput(all_rows, all_cols, 9, 22, ar, 3, 3);
}

// Creating a Sudoku Matrix (Hard Difficullty)
void createMatrixHD(char** ar) {
    int all_rows[37], all_cols[37];
    int clue = 0;
    int num = 0;
    for (int i = 0, k = 0; clue < 37; i++) { // Loop for inserting 37 clues within the empty matrix
        
        int randposr = (rand() % (12));

        int randposc = (rand() % (12)); // random numbers chosen to randomly select any block and insert a clue
        
        if (!ar[randposr][randposc]) { // Checks if there is no clue present

            num = (rand() % (12)) + 1; // Inputs a random number between 1 and 12 into num variable
            // If statement checks the functions return values to see if num passes the sudoku rules
            if (checkRowsColumns(randposr, randposc, num, 12, ar) && checkSubblock(randposr,randposc,num,12,3,4,ar)) {
                
                ar[randposr][randposc] = num;
                all_rows[k] = randposr, all_cols[k++] = randposc;
                
                clue++;
            }
        }
    }
    
    printMatrix(12, 3, 4, ar, 37, all_rows, all_cols);
    inputOutput(all_rows, all_cols, 12, 37, ar, 3, 4);
}

// storing  matrix in file
int storing_in_file(char** arr, int size, int total_clues, int all_rows[total_clues], int all_cols[total_clues]) {
	FILE *f=fopen("sudokufile.txt","w");
	if(f == NULL){
		printf("Error in opening file");
		return 1;
	}

    fprintf(f,"%d",size);

	// storing main matrix in file 
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			fprintf(f, "%c" , arr[i][j]);
		}
	}
    // storing all rows matrix in file 
	for(int i=0;i<total_clues;i++){		
			fprintf(f, "%d " , all_rows[i]);
	}
    // storing all cols matrix in file 
		for(int j=0;j<total_clues;j++){
			fprintf(f, "%d " , all_cols[j]);
		}
	fclose(f);
}

// fetching stored matrix From file
int fetching_from_file() {

    int size;

    FILE *f = fopen("sudokufile.txt", "r");
    if (f == NULL) {
        printf("Error in opening file");
        return 1;
    }

    int buffer_size=1024;
	char buffer[buffer_size];
	fgets(buffer,buffer_size,f);
	if(buffer == NULL) return 2;
	fseek(f,0,SEEK_SET);

    fscanf(f,"%d",&size);

    // Allocate memory for the matrix
    char** arr = calloc(size, sizeof(char*));
    char* brr = calloc(size * size, sizeof(char));

    for(int i = 0; i < size; i++) {
        arr[i] = brr + (i * size);
    }

    int total_clues = size == 6 ? 14 : size == 9 ? 22 : 37;
    int all_rows[total_clues], all_cols[total_clues];

    // Fetching from main matrix in file
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fscanf(f, "%c", &arr[i][j]);
        }
    }

    // Fetching all_rows matrix in file
    for (int i = 0; i < total_clues; i++) {
        fscanf(f, "%d", &all_rows[i]);
    }

    // Fetching all_cols matrix in file
    for (int i = 0; i < total_clues; i++) {
        fscanf(f, "%d", &all_cols[i]);
    }

    fclose(f);

    printMatrix(size, size == 6 ? 2 : 3, size == 12 ? 4 : 3, arr, total_clues, all_rows, all_cols);
    inputOutput(all_rows, all_cols, size, total_clues, arr, size == 6 ? 2 : 3, size == 12 ? 4 : 3);

    // Free the allocated memory for the matrix
    for(int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// Function to handle input and output for the game
void inputOutput(int all_rows[], int all_cols[], int totalRows, int totalClues, char** arr, int sr, int sc) {
    bool isSuccessful = false;  // Flag to indicate if the game is successfully completed
    int i = 0;  // Counter for the number of iterations

    while (!isSuccessful) { // Main loop that executes until the game is finished

        start: ;  // Label to allow jumping back to the beginning of the loop

        char choice;

        if (i > 0) { // Ask the user whether to replace or add a value
            do {
                printf("Enter 'r' to replace, 'a' to add any value, or 'S' to save your game for later use : ");
                scanf(" %c", &choice);

                if (choice != 'a' && choice != 'r'  && choice != 'S') {
                    printf("Please choose from 'r', 'a' or 'S'.\n");
                }
            } while (choice != 'a' && choice != 'r' && choice != 'S');
        } else {
            choice = 'a';  // Default choice for the first iteration
        }

        switch (choice) {
            int rn, cn;  // Variables for row and column numbers
            char rn1, cn1;

            case 'a':  // Add a value
            label_a: ;  // Label to allow jumping back to this point

                do { // Ask the user for the row and column numbers to add a value
                    printf("Enter coordinates (in row-col) : ");
                    scanf(" %c-%c", &rn1, &cn1);

                    if(rn1 >= '0' && rn1 <= '9') rn = rn1 - '0';
                    else rn = rn1 - 55;

                    if(cn1 >= '0' && cn1 <= '9') cn = cn1 - '0';
                    else cn = cn1 - 55;

                    if (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows) {
                        printf("Invalid row or col. Try again.\n");
                    }
                } while (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows);

                if (!arr[rn - 1][cn - 1]) { // Check if the chosen cell is empty
                    char value;

                    // Ask the user for the value to add based on the game's dimensions
                    if (totalRows == 12) { // For a 12x12 game
                        do {
                            printf("Enter the value to add : ");
                            scanf(" %c", &value);
                            if (value < '1' || value > '9' && value != 'A' && value != 'B' && value != 'C') {
                                printf("Invalid value. Please choose from (1-12, A, B, C).\n");
                            } else {
                                break;
                            }
                        } while (1);
                    } else { // For 6x6 and 9x9
                        do {
                            printf("Enter the value to add : ");
                            scanf(" %c", &value);

                            if (value < '1' || value > (totalRows + '0')) {
                                printf("Invalid value. Please choose from (1-%d)\n", totalRows);
                            }
                        } while (value < '1' || value > (totalRows + '0'));
                    }

                    // Convert character to integer
                    if (value >= '1' && value <= '9') {
                        value -= 48;
                    } else {
                        value -= 55;
                    }

                    // Check if the value is valid in the row, column, and subblock
                    if (checkRowsColumns(rn - 1, cn - 1, value, totalRows, arr) && checkSubblock(rn - 1, cn - 1, value, totalRows, sr, sc, arr)) {
                        arr[rn - 1][cn - 1] = value;
                        i++;  // Increment the iteration counter
                    } else {
                        printf("This value exists in that row, column, or subblock. Try again.\n");
                        goto start;  // Jump back to the beginning of the loop
                    }
                } else {
                    char pref;

                    if (i > 0) { // Ask the user whether to replace or choose another row and column
                        do {
                            printf("There is value at row %c, col %c. Press 'r' to replace, 'a' to choose another row-col, or 'S' to save the game : ", rn1, cn1);
                            scanf(" %c", &pref);

                            if (pref != 'a' && pref != 'r' && pref != 'S') {
                                printf("Please choose 'r', 'a' or 'S'.\n");
                            }
                        } while (pref != 'a' && pref != 'r' && pref != 'S');
                    } else {
                        printf("There is already a value. Try again.\n");
                        goto label_a;  // Jump back to choosing another row and column
                    }

                    // Jump to the label according to user's choice
                    if (pref == 'r') goto label_r;
                    else if (pref == 'a') goto label_a;
                    else goto label_S;
                }
                break;

            case 'r':  // Replace a value
            label_r: ;  // Label to allow jumping back to this point

                bool isCoordinateSame = false;

                do { // Ask the user for the row and column numbers to replace a value
                    printf("Enter coordinates (in row-col) : ");
                    scanf(" %c-%c", &rn1, &cn1);

                    if(rn1 >= '0' && rn1 <= '9') rn = rn1 - '0';
                    else rn = rn1 - 55;

                    if(cn1 >= '0' && cn1 <= '9') cn = cn1 - '0';
                    else cn = cn1 - 55;

                    if (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows) {
                        printf("Invalid row or col. Try again.\n");
                    } else {
                        // Check if the chosen cell is computer-generated (a clue)
                        for (int i = 0; i < totalClues; i++) {
                            if (rn - 1 == all_rows[i] && cn - 1 == all_cols[i]) {
                                printf("You can't replace it as it is computer-generated. Try again.\n");
                                isCoordinateSame = true;
                                goto start;  // Jump back to the beginning of the loop
                            }
                        }
                    }
                } while (rn < 1 || rn > totalRows || cn < 1 || cn > totalRows || isCoordinateSame);

                if (arr[rn - 1][cn - 1]) { // Check if the chosen cell already has a value
                    char value;

                    // Ask the user for the new value based on the game's dimensions
                    if (totalRows == 12) { // For a 12x12 game
                        do {
                            printf("Enter the new value to replace : ");
                            scanf(" %c", &value);

                            if (value < '1' || value > '9' && value != 'A' && value != 'B' && value != 'C') {
                                printf("Invalid value. Please choose from (1-12, A, B, C).\n");
                            } else {
                                break;
                            }
                        } while (1);
                    } else { // For 6x6 and 9x9
                        do {
                            printf("Enter the new value to replace : ");
                            scanf(" %c", &value);

                            if (value < '1' || value > totalRows + '0') {
                                printf("Invalid value. Please choose from (1-%d)\n", totalRows);
                            }
                        } while (value < '1' || value > totalRows + '0');
                    }

                    // Convert character to integer
                    if (value >= '1' && value <= '9') {
                        value -= 48;
                    } else {
                        value -= 55;
                    }

                    // Check if the new value is valid in the row, column, and subblock
                    if (checkRowsColumns(rn - 1, cn - 1, value, totalRows, arr) && checkSubblock(rn - 1, cn - 1, value, totalRows, sr, sc, arr)) {
                        arr[rn - 1][cn - 1] = value;
                    } else {
                        printf("This value exists in that row, column, or subblock. Try again.\n");
                        goto start;  // Jump back to the beginning of the loop
                    }
                } else {
                    char pref;

                    do { // Ask the user whether to add a value or choose another row and column to replace
                        printf("There is not any value at row %d, col %c. Press 'a' to add, 'r' to replace any other value, or 'S' to save the game : ", rn, cn);
                        scanf(" %c", &pref);

                        if (pref != 'a' && pref != 'r' && pref != 'S') {
                            printf("Please choose from 'r', 'a' or 'S'.\n");
                        }
                    } while (pref != 'a' && pref != 'r' && pref != 'S');

                    // Jump to the label according to the user's choice
                    if (pref == 'r') goto label_r;
                    else if (pref == 'a') goto label_a;
                    else goto label_S;
                }
                break;

            case 'S' : 
            label_S : ;

                int store = storing_in_file(arr, totalRows, totalClues, all_rows, all_cols);
                
                if(store) {
                    printf("Sorry, there is an issue in saving the game.");
                    goto start;
                } else {
                    printf("Game is saved successfully.");
                    return;
                }
                break;

        }

        printMatrix(totalRows, sr, sc, arr, totalClues, all_rows, all_cols); // Print the updated matrix

        // Check if all cells are filled (no zeros)
        bool noZero = true;
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalRows; j++) {
                if (arr[i][j] == 0) {
                    noZero = false;
                    break;
                }
            }
            if (!noZero) {
                break;
            }
        }

        // Check if the game is successfully completed based on the dimensions
        if (noZero) {
            switch (totalRows) {
                case 6:
                    if (checkingForEasy(arr, 6, 6)) {
                        printf("Congratulations. You win the game.\n");
                        isSuccessful = true;
                    }
                    break;
                case 9:
                    if (checkingForMedium(arr, 9, 9)) {
                        printf("Congratulations. You win the game.\n");
                        isSuccessful = true;
                    }
                    break;
                case 12 :
                    if(checkingForHard(arr, 12, 12)){
                        printf("Congratulations. You win the game.");
                        isSuccessful = true;
                    }
                    break;
            }
        }
    }
}

// Arguements include the initial array, the randomly chosen coordinates, the random number and dimension of the square matrix
// Checking columns and rows to see if any column or row collinear to the coordinates has a number equal to the inputted number
int checkRowsColumns(int randposr,int randposc,int num, int length, char** ar) {
    for (int k = 0; k < length; k++) { 
        if (num == ar[randposr][k] || num == ar[k][randposc]) {
          return 0; 
        }
    }
    return 1;
}

int checkSubblock(int randposr,int randposc,int num, int length, int sr, int sc, char** ar) {
    int srow = sr * (randposr / sr);  // sr and sc are the dimensions of the subblocks
    int scolumn = sc * (randposc / sc);
    for (int k = srow; k < srow + sr; k++) { // Now check the subblock that the address belongs to and find if any equal value exists
        for (int j = scolumn; j < scolumn + sc; j++) {
            if (num == ar[k][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the generated and updated both type of matrices
void printMatrix(int totalRows, int sr, int sc, char** arr, int totalClues, int all_rows[totalClues], int all_cols[totalClues]){

    system("cls"); // To clear the screen before printing matrix

    // To handle the colors of the matrix
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printf("\n    ");
    for(int i = 0; i < sr; i++){
        printf(" ");
        for(int j = 0; j < sc; j++){
            printf(" %c", sc*i+j > 8 ? sc*i+j+56 : sc*i+j+49);
        }
        printf(" ");
    }
    printf("\n");
    for (int i = 0; i < totalRows; i++) { // Iterate through rows
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        if(!(i % sr)){ // Print horizontal separator for subgrid
            printf("    ");
            for(int j = 0; j < sr; j++){
                printf(" ");
                for(int k = 0; k < sc; k++){
                    printf(" -");
                }
                printf(" ");
            }
            printf("\n");
        }
        printf(" %c  ", i > 8 ? i+56 : i+49);
        for (int j = 0; j < totalRows; j++) { // Iterate through columns
            if(!(j % sc)){ // Print vertical separator for subgrid
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                printf("| ");
            }
            bool isGeneratedCoordinate = false;
            for(int k = 0; k < totalClues; k++){
                if(i == all_rows[k] && j == all_cols[k]){
                    isGeneratedCoordinate = true;
                    break; 
                }
            }
            // Print the cell value or a space if the cell is empty
            if(arr[i][j]){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), isGeneratedCoordinate ? 4 : 1);
                printf("%c ", (arr[i][j] >= 10 ? arr[i][j] + 55 : arr[i][j] + '0'));
            } else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                _setmode(_fileno(stdout), 0x00020000);
                wprintf(L"□ ");
                _setmode(_fileno(stdout), _O_TEXT);
            }
            if(j + 1 == totalRows){ // Print the closing vertical separator for the last cell in the row
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                printf("| ");
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        printf("\n");
        if(i + 1 == totalRows){ // Print the horizontal separator for the last subgrid
            printf("    ");
            for(int j = 0; j < sr; j++){
                printf(" ");
                for(int k = 0; k < sc; k++){
                    printf(" -");
                }
                printf(" ");
            }
            printf("\n");
        }
    }
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), saved_attributes);
}

int checkingForEasy(char** arr, int row, int col) {
    int check;
    arr[row][col];
    bool flag = true;

    // checking Row and Column
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            check = arr[i][j];

            // Check Row
            for (int k = j + 1; k < col; k++) {
                if (check != 0 && check == arr[i][k]) {
                    flag = false;
                }
            }

            // Check Column
            for (int k = i + 1; k < row; k++) {
                if (check != 0 && check == arr[k][j]) {
                    flag = false;
                }
            }
        }
    }  
    // checking sub blocks for easy level
    if (row == 6 && col == 6) {
        for (int startRow = 0; startRow < row; startRow += 2) {
            for (int startCol = 0; startCol < col; startCol += 3) {
                int subBlock[10] = {0};  

                for (int i = startRow; i < startRow + 2; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        check = arr[i][j];

                        if (check != 0) {
                            if (subBlock[check] == 1) {
                                flag = false;  
                                return flag;
                            } else {
                                subBlock[check] = 1;  
                            }
                        }
                    }
                }
            }
        }
    } 
	return flag;  
}

int checkingForMedium(char** arr, int row, int col) {
    int check;
    arr[row][col];
    bool flag = true;
	 
     // checking Row and Column
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            check = arr[i][j];

            // Check Row
            for (int k = j + 1; k < col; k++) {
                if (check != 0 && check == arr[i][k]) {
                    flag = false;
                }
            }

            // Check Column
            for (int k = i + 1; k < row; k++) {
                if (check != 0 && check == arr[k][j]) {
                    flag = false;
                }
            }
        }
    }  
    // checking sub blocks for mid level
    if (row == 9 && col == 9) {
        for (int startRow = 0; startRow < row; startRow += 3) {
            for (int startCol = 0; startCol < col; startCol += 3) {
                int subBlock[10] = {0};  

                for (int i = startRow; i < startRow + 3; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        check = arr[i][j];

                        if (check != 0) {
                            if (subBlock[check] == 1) {
                                flag = false;  
                                return flag;
                            } else {
                                subBlock[check] = 1;  
                            }
                        }
                    }
                }
            }
        }
    }
    return flag;
}

int checkingForHard(char** arr, int row, int col) {
    int check;
    arr[row][col];
    bool flag = true;
	 
     // checking Row and Column
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            check = arr[i][j];

            // Check Row
            for (int k = j + 1; k < col; k++) {
                if (check != 0 && check == arr[i][k]) {
                    flag = false;
                }
            }

            // Check Column
            for (int k = i + 1; k < row; k++) {
                if (check != 0 && check == arr[k][j]) {
                    flag = false;
                }
            }
        }
    }  
   // Checking sub-block for hard level
if (row == 12 && col == 12) {
    for (int startRow = 0; startRow < row; startRow += 3) {
        for (int startCol = 0; startCol < col; startCol += 4) {
            int subBlock[12] = {0};

            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 4; j++) {
                    check = arr[i][j];

                    if (check != '0') {
                        int index;
                        if (check >= '0' && check <= '9') {
                            index = check - '0' - 1;  // Adjust index for 0-based array
                        } else if (check >= 'a' && check <= 'c') {
                            index = check - 'a' + 9;  // Adjust index for 0-based array
                        } else {
                            flag = false;
                            return flag;
                        }
                        if (subBlock[index] == 1) {
                            flag = false;
                            return flag;
                        } else {
                            subBlock[index] = 1;
                        }
                    }
                }
            }
        }
    }
}
    return flag;
}
