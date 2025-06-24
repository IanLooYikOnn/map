#include <stdio.h>

int i, j;
int x, y;
int grid[6][6];

int moveX(int optionX, int x, int y, int grid[6][6]) {}
int moveY(int optionY, int x, int y, int grid[6][6]) {}

void startPosition() {
    while (1) {
        printf("Enter starting position (x,y): ");
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= 6 || y < 0 || y >= 6) {
            printf("Invalid input. Please enter valid coordinates (0-5).\n");
            continue;
        }
        else {
            grid[x][y] = 'X';
        }
        
        // Print updated grid with row labels (bottom-left is (0,0))
        for (i = 5; i >= 0; i--) {
            for (j = 0; j < 6; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
        printf("Position: (%d,%d)\n", x, y);
        printf("\n");

        break;
    }
}

void changePosition() {
    while (1) {
        int a, b;
        printf("Position: (%d,%d)\n", x, y);
        printf("Enter new position (x,y): ");
        scanf("%d %d", &a, &b);
        if (a < 0 || a >= 6 || b < 0 || b >= 6) {
            printf("Invalid input. Please enter valid coordinates (0-5).\n");
            continue;
        }
        else {
            // Clear previous position
            grid[x][y] = '.';
            // Set new position
            x = a;
            y = b;
            grid[x][y] = 'X';
        }
        
        // Print updated grid with row labels (bottom-left is (0,0))
        for (i = 5; i >= 0; i--) {
            for (j = 0; j < 6; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
        printf("Position: (%d,%d)\n", x, y);
        printf("\n");

        break;
    }
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

    moveY(optionX, x, y, grid);
}

int main() {
    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 6; j++) {
            grid[i][j] = '.';
        }
    }
    
    // Print initial grid with row labels (bottom-left is (0,0))
    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 6; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

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
