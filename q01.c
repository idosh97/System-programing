#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GRID_SIZE 3
#define TREASURE_COUNT 6
#define MIN_TREASURE_COUNT 5
#define MAX_MOVES 10
int treasuresFound = 0;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    //set a blanc grid
    int i,j;
    for (i=0; i<GRID_SIZE;i++) {
        for (j=0; j<GRID_SIZE; j++) {
            grid[i][j]='-';
        }
    }
    //set the treasures
    for (i=0; i<TREASURE_COUNT; i++) {
        int row= rand() % GRID_SIZE;
        int col=rand() % GRID_SIZE;
        while (grid[row][col]=='T'){
            row= rand() % GRID_SIZE;
            col=rand() % GRID_SIZE;
        }
        grid[row][col]= 'T';
    }
}

void display_grid(char grid[GRID_SIZE][GRID_SIZE], int player_col, int player_row) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (i == player_row && j == player_col)
                printf("P");
            else
                printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void treasure_found(char grid[GRID_SIZE][GRID_SIZE], const int *player_col, const int *player_row, int valid_move, int moves) {
    if (valid_move && grid[*player_row][*player_col] == 'T') {
        treasuresFound++;
        printf("moves = %d Treasures Found = %d \n", moves, treasuresFound);
        grid[*player_row][*player_col] = '-';
    }
    else {
        printf("moves = %d Treasures Found = %d \n", moves, treasuresFound);
    }
}

void move_player(char grid[GRID_SIZE][GRID_SIZE], int *player_col, int *player_row, char user_choice, int *valid_move){
    *valid_move = 1;
    if (user_choice == 'U' && *player_row > 0) {
        (*player_row)--;
        //printf("Moved up.\n");
    } else if (user_choice == 'D' && *player_row < GRID_SIZE - 1) {
        (*player_row)++;
        //printf("Moved down.\n");
    } else if (user_choice == 'L' && *player_col > 0) {
        (*player_col)--;
        //printf("Moved left.\n");
    } else if (user_choice == 'R' && *player_col < GRID_SIZE - 1) {
        (*player_col)++;
        //printf("Moved right.\n");
    } else {
        //printf("Invalid move. choose U (up), D(down), L(left) or R(right) to move: \n");
        *valid_move = 0;
    }
}

int main() {
    srand(2024); // Seed the random number generator

    char user_choice;
    char grid[GRID_SIZE][GRID_SIZE];
    int player_row = rand() % GRID_SIZE;
    int player_col = rand() % GRID_SIZE;
    int moves = 0;
    int valid_move = 1;
    initialize_grid(grid);
    display_grid(grid, player_col, player_row);
    treasure_found(grid, &player_col, &player_row, valid_move, moves);
    while (moves < MAX_MOVES && treasuresFound < MIN_TREASURE_COUNT) {
        //Input validation
        char inpValidation[2];
        while(1) {
            printf("Enter move (D/L/U/R):");
            scanf("%2[^\n]", inpValidation);
            //discard any remaining characters in the buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            };
            // Check if the input has exactly 1 character
            if (inpValidation[0] != '\0' && inpValidation[1] == '\0') {
                user_choice = inpValidation[0];
                break;
            }
            else {
                //printf("Invalid move. choose U (up), D(down), L(left) or R(right) to move: \n");
                if (moves >= MAX_MOVES) {
                    break;
                } else {
                    moves++;
                    display_grid(grid, player_col, player_row);
                    treasure_found(grid, &player_col, &player_row, valid_move, moves);
                }
            }
        }
        move_player(grid, &player_col, &player_row, user_choice,&valid_move);
        if (moves < MAX_MOVES) {
            moves++;
        }
        display_grid(grid, player_col, player_row);
        treasure_found(grid, &player_col, &player_row, valid_move, moves);
    }
    if (treasuresFound >= MIN_TREASURE_COUNT)
        printf("\nCongratulations! You found all the treasures.\n");
    else
        printf("\nSorry, you ran out of moves.\n");
    return 0;
}
