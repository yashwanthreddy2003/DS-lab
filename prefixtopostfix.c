#include<stdio.h>//Standard input otput
#include<string.h>
#include<stdlib.h>//stadard library function
# define MAX 20 //declaring size
char str[MAX],stack[MAX];//intializing string and stack array
int top=-1;//giving top value as -1
void push(char symbol)//function to push
{
   stack[++top]=symbol;//pushing symbol into stack
}
char pop()//pop function
{
   return stack[top--];//decreasing top value by 1 and return stackvalue
}
void post_fix()//function to convert into postfix expression
{
   int n,i,j=0; char postfix[20];
   char a,b,op;
   printf("Enter the prefix expression\n");//print 
   gets(str);//get the string of prefix expression input from user
   n=strlen(str);//nequal to length of string
   for(i=0;i<MAX;i++)//for loop
   stack[i]='\0';
   printf("Postfix expression is:\t");
   for(i=0;i<n;i++)//loop to convert into postfix
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')//if incoming symbol is+,-,*,/ then push 
      {
         push(str[i]);//calling push function
      }
      else
      { postfix[j++]=str[i];//else store in postfix array
        while((top!=-1)&&(stack[top]=='#'))//while loop if it is not empty 
        {
            a=pop(); postfix[j++]=pop();// store the poped elemt in the postfix
        }
        push('#');
      }
   }
   postfix[j]='\0';
   printf("%s",postfix);//print the postfix expression
}
void main()//main function
{
    post_fix();//calling postfix function
}