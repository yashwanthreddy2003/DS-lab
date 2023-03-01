#include <stdio.h>
#include <stdlib.h>

// function prototypes
void push();        // function to push a value onto the top of the stack
void pop();         // function to pop the top value from the stack
void display();     // function to display the current state of the stack

// node struct definition
struct Node {
    int value;              // value held by node
    struct Node* next;      // pointer to next node in the stack
};

// global variable head to keep track of the top of the stack
struct Node* head;

// main function
int main() {
    int choice = 0;
    printf("\n** Stack operations using linked list **\n");
    printf("\n--------------------------------------------\n");

    // display menu and perform chosen operation until user exits
    while (choice != 4) {
        printf("\n\nChoose one of the following options...\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                push();
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice! Please enter a valid choice.\n");
            }
        }
    }
    return 0;
}

// function to push a value onto the top of the stack
void push() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // allocate memory for new node

    if (newNode == NULL) {      // check if memory allocation was successful
        printf("Error: Unable to push value onto stack. Memory allocation failed.\n");
    } else {
        printf("Enter the value to be pushed onto the stack: ");
        scanf("%d", &value);
        newNode->value = value;     // set value of new node to user input

        if (head == NULL) {     // if stack is empty, set head to new node
            newNode->next = NULL;
            head = newNode;
        } else {        // else, add new node to top of stack and update head
            newNode->next = head;
            head = newNode;
        }

        printf("Value %d has been pushed onto the stack.\n", value);
    }
}

// function to pop the top value from the stack
void pop() {
    int value;
    struct Node* temp;

    if (head == NULL) {     // check if stack is empty
        printf("Error: Unable to pop value from stack. Stack is empty.\n");
    } else {
        value = head->value;        // get value of top node
        temp = head;        // set temporary pointer to top node
        head = head->next;      // update head to next node in stack
        free(temp);     // free memory occupied by top node

        printf("Value %d has been popped from the stack.\n", value);
    }
}

// function to display the current state of the stack
void display() {
    int i;
    struct Node* temp;
    temp = head;

    if (temp == NULL) {     // check if stack is empty
        printf("Stack is empty.\n");
    } else {
        printf("Current stack: \n");
        while (temp != NULL) { 
            
        // loop through stack
printf("%d\n", temp->value);
temp = temp->next;
}
}
}