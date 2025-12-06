#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum plates in stack

int stack[MAX];
int top = -1;

// Push a plate onto the stack
void push(int plateNumber) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot add plate %d\n", plateNumber);
        return;
    }
    stack[++top] = plateNumber;
    printf("\nPlate %d placed on top of the stack.\n", plateNumber);
}

// Pop a plate from the stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No plates to take.\n");
        return;
    }
    printf("\nPlate %d taken from the top.\n", stack[top--]);
}

// Peek at the top plate
void peek() {
    if (top == -1) {
        printf("\nNo plates in the stack!\n");
        return;
    }
    printf("\nTop plate is %d\n", stack[top]);
}

// Display all plates
void display() {
    if (top == -1) {
        printf("\nNo plates in the stack!\n");
        return;
    }
    printf("\nPlates in stack (Top -> Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, plateNumber;

    while (1) {
        printf("\n--- CAFETERIA STACK SIMULATION ---\n");
        printf("1. Place a plate (Push)\n");
        printf("2. Take a plate (Pop)\n");
        printf("3. Peek top plate\n");
        printf("4. Display all plates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Try again.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter plate number to place: ");
                if (scanf("%d", &plateNumber) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); // clear input buffer
                    break;
                }
                push(plateNumber);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting simulation...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}