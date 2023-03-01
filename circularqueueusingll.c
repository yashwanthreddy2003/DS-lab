#include<stdio.h>
#include<stdlib.h>

// Define a struct node which contains an integer value and a pointer to the next node
struct node 
{
    int data;
    struct node *next;
};

// Define two global pointers to the front and rear of the queue
struct node *front;
struct node *rear;

// Declare the functions used in the program
void enqueue();
void dequeue();
void display();

// The main function of the program
int main()
{
    int choice;

    // A loop which will run indefinitely until the user chooses to exit the program
    while(1)
    {
        // Print the menu
        printf("MENU\n");
        printf("============\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("enter the choice to perform\n");

        // Take user input for their choice
        scanf("%d",&choice);

        // Use a switch statement to perform an action based on the user's choice
        switch(choice)
        {
            case 1:
                enqueue(); // Call the enqueue function
                break;

            case 2:
                dequeue(); // Call the dequeue function
                break;

            case 3:
                display(); // Call the display function
                break;

            case 4:
                exit(0); // Exit the program
                break;

            default:
                printf("invalid entry\n"); // Print an error message if the user enters an invalid choice
        }
    }
}

// A function to enqueue a new element into the queue
void enqueue()
{
    int item;
    struct node *ptr;

    // Allocate memory for the new node
    ptr=(struct node *)malloc(sizeof(struct node));

    // Check if the memory allocation was successful
    if(ptr==NULL)
    {
        printf("overflow\n"); // Print an error message if there is not enough memory available
    }
    else
    {
        // Ask the user for the value of the new element to be inserted
        printf("enter the element to be inserted\n");
        scanf("%d",&item);

        // If the queue is empty, set the new element as both the front and rear of the queue
        if(front==NULL&&rear==NULL)
        {
            ptr->data=item;
            front=rear=ptr;
            ptr->next=front;
        }
        else
        {
            // Otherwise, add the new element to the end of the queue and update the rear pointer to point to it
            ptr->data=item;
            rear->next=ptr;
            rear=ptr;
            rear->next=front;
        }
    }
}

// A function to dequeue an element from the queue
void dequeue()
{
    struct node *ptr;

    // Check if the queue is empty
    if(front==NULL&&rear==NULL)
    {
        printf("underflow\n"); // Print an error message if the queue is empty
    }
    else
    {
        // If the queue has only one element, set both front and rear pointers to null
        if(front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        else
        {
            // Otherwise, remove the front element and update the front pointer to point to the next element
            ptr=front;
            front=front->next;
            free(ptr);  
            rear->next=front;
        }
    }
}

// A function to display the elements in the queue
void display()
{
    struct node *ptr;
    ptr=front;

    // Check if the queue is empty
    if(front==NULL&&rear==NULL)
     {
        printf("queue is empty\n");
    }
    else
    {
        // Traverse the queue and print the elements
        printf("elements present in the queue are\n");
        do
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }while(ptr!=front);
        }
        }// Stop when we reach the front