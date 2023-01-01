#include <stdio.h>//standard input output
int main()//main function
{    int oprnd1, oprnd2;//initializing operands
     char oprtr; //+,-,*, /-operators
     int result , invalid = 0; // invalid is a flag, assume valid
     printf("Enter operand 1\n");
     scanf("%d", &oprnd1);//fetching input of operand1 from user
     printf("Enter operand 2\n");
     scanf("%d", &oprnd2);//fetching input of operand2 from user
     printf("Enter operator 1\n");
     scanf("%c", &oprtr); // dummy for \n after oprnd2
     scanf("%c", &oprtr);//fetching input of operator from user
     switch (oprtr)//switch case of operator
     {
        case '+': result = oprnd1 + oprnd2;
                  break;
        case '-': result = oprnd1 - oprnd2;
                  break;
        case '*': result = oprnd1 * oprnd2;
                  break; 
        case '/': result = oprnd1 / oprnd2;
                  break;
        default: invalid = 1;//if not above cases then invalid=1and print invalid operator
                 printf("invalid operator\n");
                 break;
     }
     if (!invalid)//if not invalid then prin result
         printf("%d %c %d= %d\n",oprnd1,oprtr,oprnd2,result);
     return 0;
}
