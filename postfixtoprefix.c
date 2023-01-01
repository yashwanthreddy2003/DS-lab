#include<stdio.h>//standard input output
#include<string.h>
#include<stdlib.h>//standard library function
#define MAX 25 //definig size of MAX as 20
char str[MAX], stack[MAX];
int top = -1;//initializing the value of top as -1
void push(char c)//funtion to perform push
{
  stack[++top] = c;//incrememnt the value of top and store value of x in stack[++top]
}
char pop()//function to perform pop
{
  return stack[top--];//return the value of stack[top--]
} 
int checkIfOperand(char ch)// function to check if the given character is operand 
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');//return the ch char ch is between a and z or A and Z
}
int isOperator(char symbol) //funtion to check whather it is a operator or not
{
  switch (symbol) {//sswitch case of symbol
  case '+':
  case '-':
  case '/':
  case '*':
    return 1;//if symbol is +,-,*,/ return 1
  }
  return 0;
}
void postfixToprfix() //function to convert postfix to prefix
{
  int n, i, j = 0;
  char c[20];
  char a, b, op;

  printf("Enter the postfix expression\n");
  scanf("%s", str);//taing input of string of postfix expression
  n = strlen(str);//n is string length of postfix expresion
  for (i = 0; i < MAX; i++)//for loop to convert to prefix
    stack[i] = '\0';
  printf("Prefix expression is:");
  for (i = n - 1; i >= 0; i--)//for loop to print prefix expression
  {
    if (isOperator(str[i]))//if incoming element is operator
    {
      push(str[i]);//push the element
    } else
    {
      c[j++] = str[i];
      while ((top != -1) && (stack[top] == '#')) //if top!=-1 and stack[top]==# then 
      {
        a = pop();//operand
        c[j++] = pop();//pop funtion
      }
      push('#');
    }
  }
  c[j] = '\0';

  i = 0;//initializinig i =0
  j = strlen(c) - 1;//assigning the value of j as lenght of c-1
  char P[20];

  while (c[i] != '\0') {
    P[j--] = c[i++];//elements of array c into d
  }

  printf("%s\n", P);//printing prefix expression

}

int main()//main function 
{

  postfixToprfix();//calling function to convert postfix to prefix

  return 0;
  }
