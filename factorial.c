#include<stdio.h>//standard input output
int fact (int);//function to find factorial
int main()//main function
{
int n,f;//initializing variables
printf("Enter the number to calculate its factorial:\n");//print
scanf("%d",&n);//taking input of number n to find factorial
f=fact(n);//calling function to find factorial of n
printf("factorial=%d\n",f);//print the value of factorial of n
}
int fact(int n)//declaring factorial function
{
if(n==0)//if n==0 then return 0
{
return 0;
}
else if(n==1)//if n==1 then return 1
{
return 1;
}
else
{
return n*fact(n-1);//calling the factorial function and return the value
}
}
