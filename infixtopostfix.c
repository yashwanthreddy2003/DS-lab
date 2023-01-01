//infix to postfix
#include<stdio.h> //header file
#include<string.h> 
#include<ctype.h>
char stack[25]; //initiallizing array and size
int top = -1;     //assigning value of top=-1
void push(char item) //funtion to push item
{
stack[++top] = item; //assigning value of item to stack
}    
char pop()//funtion to pop item
{
return stack[top--]; //after pop return the value of next top element
}
int precedence(char symbol) //function to check precedence
 {  
        switch(symbol) //switch condition of symbol
         {
           case '+': 
           case '-':
           return 2; //if operator is +/- return 2
           break; 
           case '*': 
           case '/':
           return 3; //if operator is * or / return 3
           break; 
           case '^': 
           return 4; //if operator is ^ then return 4
           break; 
           case '(': 
           case ')': 
           case '#':
           return 1; //if operators are (,),# then return 1
           break; 
        } 
 } 
int isOperator(char symbol)//funtion to check whether the entered symbol is operator or not
 {
        switch(symbol)//switch case to check whether entered symbol is opeator or not
         {
           case '+': 
           case '-': 
           case '*': 
           case '/': 
           case '^': 
           case '(': 
           case ')':
              return 1; //if operator is in above case then return 1 
           break; 
              default:
             return 0; //else return 0
        } 
 } 
void convert(char infix[],char postfix[]) {//funtion to convert infix to postfix
        int i,symbol,j = 0; //intializing values
        stack[++top] = '#'; 
     	
        for(i = 0;i<strlen(infix);i++) {//for loop to check every symbol in stack is operator or not
           symbol = infix[i]; //symbol to array infix
     		
           if(isOperator(symbol) == 0) {//if it is 0 then give that value to postfix array
              postfix[j] = symbol; //plaacing symbol inthe postfix array
              j++; //incrementing j 
           } else {
              if(symbol == '(') {//if the symbol is ( then push the symbol int stack
                 push(symbol);//push the symbol 
              } else {
                 if(symbol == ')') {//if symbol is ) then 
     				
                   while(stack[top] != '(') {//ru a while loop to pop until ( is encountered
                      postfix[j] = pop(); // pop the symbol from top of stack
                       j++; //increment j to run loop
                    } 
     					
                    pop();  //calling pop function
                 } else {
                    if(precedence(symbol)>precedence(stack[top])) {//if precedence of incoming symbol is  greater than the symbol on top of stack then
                       push(symbol); //push the symbol into the stack
                   } else {
     					
                       while(precedence(symbol)<=precedence(stack[top])) {//if incoming symbol is less than or equal to precedence of symbol on top of staack then 
                         postfix[j] = pop(); //pop the top element until condition is satisfied
                          j++; 
                      } 
    						
                      push(symbol); //calling push function
                    }
                 }
              }
           }
       }
     	
       while(stack[top] != '#') {//if symbol on top of stack is not equal to # then pop
           postfix[j] = pop(); //calling pop function
           j++; 
       } 
     	
        postfix[j]='\0'; 
     } 
     
     //evaluation of postfix expression
    int stack_int[25]; 
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
        char infix[50] = "5*(8+3)-(9*9)",postfix[50];//initialiaing infix expresion 
        convert(infix,postfix); //callinf funtion to convert infix to postfix
     	
        printf("Infix expression : %s\n" , infix);// printing infix expression
        printf("Postfix expression : %s\n" , postfix);//printing postifix expression
        printf("Evaluated expression: %d\n" , evaluate(postfix));//evaluated postfix expression
     } 
