[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/j0WbCUcA)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=13059247&assignment_repo_type=AssignmentRepo)
# Project

## Members:

### Muhammad Abser Mansoor (23K-0030): Initialization of sudoku boards
### Syed Fahad Faheem Shah (23k-0062): Validation of sudoku boards and Save state feature
### Muhammad Umar (23K-0023): Input and Output

## Main Idea: Create a Sudoku game with multiple difficulties using C.

## Input:
The very first input will be the selection of difficulty using a char input of E, M or H pertaining to Easy, Medium, and Hard difficulties respectively.
After selection of difficulty, the user will be prompted to enter coordinates for the desired position they want to modify and will then be able to modify the value at those coordinates, although the clues generated at the start of the matrix creation cannot be modified.

## Working:

After selection of difficulty, one of 3 starting matrices will be chosen pertaining to each difficulty, starting from a 6x6 with 14 clues then a 9x9 with 22 clues and then a 12x12 with 37 clues. These clues will be filled in by the computer which will randomly choose a number between 1 and 9, inclusive, whilst also obeying the rules of sudoku. After clue insertion, those values cannot be changed by the user. The checking for conformity to the rules of sudoku will be done by separate functions after each clue is inserted and each input is given.
## UI: 
User will be asked for difficulty selection and the starting matrix with the clues filled in will be shown after which they will be asked to input coordinates and then input a value at those coordinates. After each input the modified matrix will be displayed and the user will have the ability to replace previously inputted values.

## Future plan:
As planned, a save state feature has been added along with 2 new difficulties.# SUDOKU
