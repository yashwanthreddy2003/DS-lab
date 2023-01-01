#include <stdio.h>//header file
#include <string.h>
#define MAX 25//defining size of MAX is 25
char infix[MAX], prefix[MAX], stack[MAX];//initializing infix,prefix and stack arrays
int top = -1;//setting the value of top =-1
void reverse(char arr[])//funtion to reverse the string
{
    int i, j = 0;//declaring variables
    for (i = 0; i < strlen(arr); i++)//for loop to revrse the string
    {
        top++;//increment of top value
        stack[top] = arr[i];//placing the values of arr aray into stack array
    }
    while (top != -1)//if top not equals to -1
    {
        arr[j] = stack[top];//then place the values of stack[top] int arr array
        j++;//increment j value
        top--;//decrememnt the top value
    }
    arr[j] = '\0';
}

void push(char x)//function to push
{
    top++;//increment the top value
    stack[top] = x;//and the store the x value in stack array
}
char pop()//function to perform pop
{
    char value = stack[top];// value of stack[top] into value
    top--;//decrememt value of top
    return value;//return value
}
int isempty()//function to check whether stack is empty
{
    if (top == -1)//if top==-1 then stack is empty
        return 1;//then return 1
    else
        return 0;//else 0
}
int precedence(char symbol)//funtion to check precedence of symbol
{
    switch (symbol)//switch case of symbol
    {
    case '+':
    case '-':
        return 1;//if symbol is + or - then return 1
    case '*':
    case '/':
        return 2;//if symbol is * or / then return 2
    default:
        return 0;
    }
}
void infix_to_prefix()// Function for conversion of infix to prefix
{
    int i, j = 0;
    char symbol, value;
    for (i = 0; i < strlen(infix); i++)//for loop for conversion
    {
        symbol = infix[i];//value of infix[i] expresion into symbol
        switch (symbol)//switch case of symbol
        {
        case ')'://if symbol is ) then push
            push(symbol);
            break;
        case '+':
        case '-':
        case '*':
        case '/'://if symbol is +,-,*,/ then run while loop
            while (!isempty() && precedence(symbol) <= precedence(stack[top]))//if staack is not empty and precedence of incoming symbol is less than or equal to precedence of value on top of sstack then pop
                prefix[j++] = pop();//call pop function to pop the top value
            push(symbol);//push the incoming symbol int stack
            break;
        case '('://if incoming symbol is ( ghen run while loop
            while ((value = pop()) != ')')//if not equal to ) then
                prefix[j++] = value;//value into prefix 
            break;
        default:
            prefix[j++] = symbol;//symbol into prefix array
            break;
        }
    }
    while (!isempty())//if it is not empty
        prefix[j++] = pop();//then pop out remaining elements
    prefix[j] = '\0';
    reverse(prefix);//reverse function
}
void main()//main function
{
    printf("Enter the infix expression:");
    gets(infix);//to take input of infix expression
    reverse(infix);//reverse the infix expression
    infix_to_prefix();//function to convert infix to prefix
    printf("Prefix Expression is: ");
    for (int i = 0; i < MAX + 1; i++)//for loop to print the prefix expression
        printf("%c", prefix[i]);
}

