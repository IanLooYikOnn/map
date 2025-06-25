#include <stdio.h>

int i, j;
int x, y;
int grid[6][6];
int steps;
int newX, newY;

void printGrid() {
    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 6; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void updateGrid() {
    grid[y][x] = '.';
    x = newX;
    y = newY;
    grid[y][x] = 'X';
}

void startPosition() {
    while (1) {
        printf("Enter starting position (x,y): ");
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= 6 || y < 0 || y >= 6) {
            printf("Invalid input. Please enter valid coordinates (0-5).\n");
            continue;
        }
        else {
            grid[y][x] = 'X';
        }
        
        printGrid();
        printf("Position: (%d,%d)\n", x, y);
        printf("\n");

        break;
    }
}

void changePosition() {
    while (1) {
        printf("Position: (%d,%d)\n", x, y);
        printf("Enter new position (x,y): ");
        scanf("%d %d", &newX, &newY);
        if (newX < 0 || newX >= 6 || newY < 0 || newY >= 6) {
            printf("Invalid input. Please enter valid coordinates (0-5).\n");
            continue;
        }
        else {
            updateGrid();
        }
        
        // Print updated grid with row labels (bottom-left is (0,0))
        printGrid();
        printf("Position: (%d,%d)\n", x, y);
        printf("\n");

        break;
    }
}

int moveX(int optionX, int x, int y, int grid[6][6]) {
    if (optionX == 5) {
        return 0;
    }

    printf("Enter number of steps: ");
    scanf("%d", &steps);

    if (steps <= 0) {
        printf("Invalid steps. Please enter a positive number.\n");
        return 0;
    }

    switch (optionX) {
        case 1:
            newX = x - steps;
            newY = y + steps;
            break;
        case 2:
            newX = x + steps;
            newY = y + steps;
            break;
        case 3:
            newX = x - steps;
            newY = y - steps;
            break;
        case 4:
            newX = x + steps;
            newY = y - steps;
            break;
        default:
            printf("Invalid option.\n");
            return 0;
    }

    if (newX < 0 || newX >= 6 || newY < 0 || newY >= 6) {
        printf("Invalid move. Position out of bounds.\n");
        return 0;
    }

    updateGrid();

    printGrid();
    printf("Position: (%d,%d)\n", x, y);
    printf("\n");
    return 1;
}

int moveY(int optionY, int x, int y, int grid[6][6]) {
    if (optionY == 5) {
        return 0;
    }

    printf("Enter number of steps: ");
    scanf("%d", &steps);

    if (steps <= 0) {
        printf("Invalid steps. Please enter a positive number.\n");
        return 0;
    }

    switch (optionY) {
        case 1:
            newX = x;
            newY = y + steps;
            break;
        case 2:
            newX = x;
            newY = y + steps;
            break;
        case 3:
            newX = x - steps;
            newY = y;
            break;
        case 4:
            newX = x + steps;
            newY = y;
            break;
        default:
            printf("Invalid option.\n");
            return 0;
    }

    if (newX < 0 || newX >= 6 || newY < 0 || newY >= 6) {
        printf("Invalid move. Position out of bounds.\n");
        return 0;
    }

    updateGrid();

    printGrid();
    printf("Position: (%d,%d)\n", x, y);
    printf("\n");
    return 1;
}

void optionX() {
    int optionX;

    printf("========== Move X ==========\n");
    printf("1. Move up-left diagonally\n");
    printf("2. Move up-right diagonally\n");
    printf("3. Move down-left diagonally\n");
    printf("4. Move down-right diagonally\n");
    printf("5. Cancel\n");
    printf("Select option (1/2/3/4/5): ");
    scanf("%d", &optionX);

    moveX(optionX, x, y, grid);
}

void optionY() {
    int optionY;

    printf("========== Move Y ==========\n");
    printf("1. Move up\n");
    printf("2. Move down\n");
    printf("3. Move left\n");
    printf("4. Move right\n");
    printf("5. Cancel\n");
    printf("Select option (1/2/3/4/5): ");
    scanf("%d", &optionY);

    moveY(optionY, x, y, grid);
}

int main() {
    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 6; j++) {
            grid[i][j] = '.';
        }
    }
    
    printGrid();

    startPosition();

    int option;
    while (1) {

        printf("======== Options ========\n");
        printf("1. Move X\n");
        printf("2. Move Y\n");
        printf("3. Change Position\n");
        printf("4. Exit\n");
        printf("Select option (1/2/3/4): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                optionX();
                continue;
            case 2:
                optionY();
                continue;
            case 3:
                changePosition();
                continue;
            case 4:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                continue;
        }
    }
}
