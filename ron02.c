#include <stdio.h>
#include <string.h>
#define MAX_FLOORS 10

void floor_move(int *current_floor, int floor, char floors[MAX_FLOORS][15]) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        printf("You requested to go to the %s\n", floors[floor]);
        if (*current_floor < floor) {
            while (*current_floor < floor) {
                (*current_floor)++;
                printf("Passing floor %d\n", *current_floor);
            }
            printf("Arrived at Floor %d\n", *current_floor);
        } else {
            while (*current_floor > floor) {
                (*current_floor)--;
                printf("Passing floor %d\n", *current_floor);
            }
            printf("Arrived at Floor %d\n", *current_floor);
        }
    }
    else
        printf("Invalid floor number. Please enter a floor between 0 and %d.\n", MAX_FLOORS - 1);
    }


int main() {
    char floors[MAX_FLOORS][15]= {"Ground floor", "First floor", "Second floor", "Third floor",
                "Fourth floor", "Fifth floor", "Sixth floor", "Seventh floor",
                "Eighth floor", "Ninth floor"};
    int current_floor =0;
    int floor;
    printf("Elevator is currently at floor: %d\n", current_floor);
    while (1) {
        printf("Enter the floor number you wish to go to (-1 to exit):");
        scanf(" %d", &floor);
        if (floor==-1)
            printf("Elevator simulation ended.");
            break;
        floor_move(&current_floor, floor, floors);

    }

    return 0;
}

