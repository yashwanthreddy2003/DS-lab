/* This code implements a queue data structure using a linked list*/

#include<stdio.h> // Including standard input/output header file.
#include<stdlib.h> // Including standard library header file.
struct node // Defining the structure of the node data type using struct.
{
int data;
struct node *next;
};
struct node *front; //Declaring front pointer of format node
struct node *rear; //Declaring rear pointer of format node
void insert(); //function prototype
void delete();
void display();
void main () //main function will consist of menu options and will call function based on user choice
{
int choice;
while(choice != 4) // A loop to keep the menu running until the user chooses to exit.
{
printf("\nMain Menu***\n");
printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
printf("\nEnter your choice ?");
scanf("%d",& choice); // Taking user's choice as input.
switch(choice) // A switch statement to call the appropriate function based on user's choice.
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(0); // Exiting the program if user chooses to exit.
break;
default:
printf("\nEnter valid choice??\n"); // Printing a message if user enters an invalid choice.
}
}
}
void insert() // Function to insert an element into the queue.
{
struct node*ptr;
int item;
ptr = (struct node *) malloc (sizeof(struct node));  // Dynamically allocating memory for the new node.
if(ptr == NULL)  // Checking if memory allocation was successful.
{  
    printf("\nOVERFLOW\n");  
    return;  
}  
else  
{   
    printf("\nEnter value?\n");  
    scanf("%d",&item);  // Taking the value of the new element as input.
    ptr -> data = item;  // Assigning the value to the data element of the new node.
    if(front == NULL)  // If the queue is empty, the new node becomes both the front and the rear.
    {  
        front = ptr;  
        rear = ptr;   
        front->next = NULL;  
        rear->next = NULL;  
    }  
    else   
    {  
        rear -> next = ptr;  // If the queue is not empty, the new node is added to the rear.
        rear = ptr;  
        rear->next = NULL;  
    }  
}
}
void delete ()  //Function to delete element from queue
{  
    struct node *ptr;  //Declaring a pointer variable to struct node
    if(front == NULL)  //Checking if queue is empty by checking if front pointer is NULL
    {  
        printf("\nUNDERFLOW\n");  //Printing underflow message if queue is empty
        return;  //Returning from function
    }  
    else   //If queue is not empty
    {  
        ptr = front;  //Assigning front pointer to ptr temporary pointer variable
        front = front -> next;  //Setting front pointer to point to the next node in the queue
        free(ptr);  //Freeing the memory allocated to the first node of the queue
    }  
}  

void display()  //Function to display the elements of the queue
{  
    struct node *ptr;  //Declaring a pointer variable to struct node
    ptr = front;  //Assigning front pointer to ptr temporary pointer variable
    if(front == NULL)  //Checking if queue is empty by checking if front pointer is NULL
    {  
        printf("\nEmpty queue\n");  //Printing empty queue message if queue is empty
    }  
    else  //If queue is not empty
    {   
        printf("\nprinting values .....\n");  //Printing message to indicate that values are being printed
        while(ptr != NULL)   //Looping through the queue until the end is reached
        {  
            printf("\n%d\n",ptr -> data);  //Printing the data of the current node
            ptr = ptr -> next;  //Setting ptr to point to the next node in the queue
        }  
    }  
}