#include <stdio.h>  //standard input output
#include <string.h> 
#define MAX 30    // declaring the size
int top = -1;
char stack_int[MAX];//intializing the stack of size MAX

void push_int(int item) // push function 
{
    stack_int[++top] = item;
}
int pop_int() // pop function 
{
    return stack_int[top--];
}
int eval_prefix(char prefix[]) // evaluation of prefix expression
{
    int i = 0;
    int a,b;
    char ch;
    while (prefix[i] != '\0')//while loop for prefix array
    {
        ch = prefix[i];
        if (ch >= '0' && ch <= '9')//checking for operand
        {
            push_int(ch - '0');//pushing operand
        }
        else
        {
            int a = pop_int();//poping operand

            int b = pop_int();//poping operand

            switch (ch)//switch case to preform opearions and push into stack
            {
            case '+':
                push_int(a + b);//if operator is + then push a+b
                break;
            case '-':
                push_int(a - b); //if operator is - then push a-b
                break;
            case '*':
                push_int(a * b); //if operator is * then push a*b
                break;
            case '/':
                push_int(a / b); //if operator is / then push a/b
                break;
            }
        }
        i++;//incrementin the i of value 1 to run loop
    }
    return pop_int();
}
int reverse(char prefix[]) // reverse function to reverse the string
{
    int i = 0;
    int j = strlen(prefix) - 1;
    while (i <= j)//while loop to reversee the prefix expression
    {
        char temp = prefix[i];//temp variable to reverse
        prefix[i] = prefix[j];
        prefix[j] = temp;
        i++;
        j--;
    }
}
void main() // main function
{
    char prefix[MAX];// infix expression
    printf("Enter the prefix expression:\t");
    scanf("%s",prefix);//taking prefix expression input from user
    printf("the prefix expression is :%s\n", prefix);//printing prefix expression
    reverse(prefix);

    printf("the evaluated prefix value is :%d\n", eval_prefix(prefix)); // print
}
