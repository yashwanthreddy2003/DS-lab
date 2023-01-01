#include<stdio.h>//standard input output
#include<string.h>
#define MAX 30//declaring size

int stack_int[MAX]; //stack with size MAX
     int top_int = -1;  
   void push_int(int item) {//funtion to push item into stack
        stack_int[++top_int] = item; //incrementing the top to place item
     } 
     
     char pop_int() {//function to pop
        return stack_int[top_int--]; // decrement the top and return the value of stack after decrementing top
     } 
    
     
     int evaluate(char *postfix){//funtion to evaluate postfix
     
        char x;
       int i = 0,operand1,operand2;//initializing operands 
     
       while( (x = postfix[i++]) != '\0') {//while loop for evaluating
           if(isdigit(x)) {//if x is a digit the push
     	     push_int(x-'0'); //calling push function
          } else {
              
              operand2 = pop_int();
              operand1 = pop_int();
     			
              switch(x) {
                case '+':
                    push_int(operand1+operand2);//if x is '+' then push as operand1+operand2 
                  break;
                 case '-':
                   push_int(operand1-operand2);//if x is '-' then push as operand1-operand2 
                   break;
                case '*':
                    push_int(operand1*operand2);//if x is '*' then push as operand1*operand2 
                    break;
                 case '/':
                    push_int(operand1/operand2);//if x is '/' then push as operand1/operand2 
                    break;
              }
           }
        }
    	
        return stack_int[top_int];//returning the value of stack at top
     }
     
     void main() { //main funtion
        char postfix[MAX];//postfix array with size MAX
        printf("Enter the postfix Expression:\t");
        scanf("%s",postfix);//taking postfix expression inputfrom user
        printf("Postfix expression : %s\n" , postfix);//printing postifix expression
        printf("Evaluated expression: %d\n" , evaluate(postfix));//evaluated postfix expression
     } 
