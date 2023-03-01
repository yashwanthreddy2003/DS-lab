#include <stdio.h>
#define MAX 5  // Maximum size of the circular queue

int cqueue_arr[MAX];  // Circular queue array
int front = -1;  // Index of the front element
int rear = -1;  // Index of the rear element

/* Function to insert an element into the circular queue */
void insert(int item)
{
    // Check if the queue is full
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow\n");
        return;
    }

    // If queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // Update the rear index to the next element
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }

    // Insert the element into the circular queue
    cqueue_arr[rear] = item;
}

/* Function to delete an element from the circular queue */
void del()
{
    // Check if the queue is empty
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    // Print the element being deleted and update the front index
    printf("Element deleted from queue is: %d\n", cqueue_arr[front]);

    // If queue has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        // Update the front index to the next element
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

/* Function to display the elements of the circular queue */
void display()
{
    int front_pos = front;
    int rear_pos = rear;

    // Check if the queue is empty
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    // Print the elements of the circular queue
    printf("Queue elements:\n");

    if (front_pos <= rear_pos)
    {
        // Print elements starting from the front index
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    else
    {
        // Print elements starting from the front index and wrap around
        while (front_pos <= MAX - 1)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

/* Main function to test the circular queue implementation */
int main()
{
    int choice;
    int item;

    // Loop until the user chooses to quit
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice)
        {
            case 1:
                printf("Input the element for insertion in queue: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                del();
                break;

            case 3:
            display();
            break;
            
            case 4:
            break;
            default:
            printf("Wrongchoice\n");
        }
    }while(choice!=4);//if choice not equal to 4 the run the loop
    return 0;
}
