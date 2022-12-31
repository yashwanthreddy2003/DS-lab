#include<stdio.h>
#define SIZE 10 //size of stack
void push(int);//fuction to push
void pop(); //function to pop
void display();//function to display
int stack[SIZE],top=-1;//assigning top=-1 to ensure stack is empty
void main()
{
int value,choice;
while(choice!=4)//to run loop and exit when we select 4
{
printf("menu\n");
printf("1.push\n 2.pop\n 3.display\n 4.Exit\n");//assigning numbers to choices
printf("Enter your choice: ");
scanf("%d",&choice);//to input the choice
switch(choice){//to execute the case according to choice
case 1:printf("Enter the value to be inserted: ");
scanf("%d",&value);//to input the value that is to be pushed into the stack
push(value);//calling push function
break;
case 2:pop();//calling pop funtion to pop the values from stack
break;
case 3:display();//callling display funtion to display the values in stack
break;
case 4:printf("\nExit");
break;
default: printf("wrong selection!!!\n\n");//other than 3 cases it is wrong selection
}
}
}
void push(int value)//defining the push function
{
if(top==SIZE-1)//intial value when stack is empty is -1 if it is full then top value will be SIZE-1
printf("Stack full\n");//if it is full printf stack full 
else{
top++;//increasing top value by 1 every time
stack[top]=value;//giving the value 
printf("Insertion success\n");
}
}
void pop()//defining the pop function
{
if(top==-1)//if top is -1(intial value) then stock is empty 
printf("stack empty\n");
else{
printf("Deleted :%d \n",stack[top]);//if top!=-1 then the last inserted value will be deleted
 top--;//and decrease the top value 
}}
void display()//defining the display funtion
{
if(top==-1)//if top value is -1 then stack is empty
printf("Empty stack");
else{//else to display the values in stack we use loop 
int i;
printf("Elemets are : \n");
for(i=top;i>=0;i--)//loop to display the values in stack from i=top to i=0(i==-1 empty stack)
printf("%d\n",stack[i]);//printing the values in stack
}
}
