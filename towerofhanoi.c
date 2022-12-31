//Tower of Hanoi using recursions
#include <stdio.h>//standard input output
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)//function to solve tower of hanoi
{
if(n==1)//checking if only 1 disk is present at from_rod
{
printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);//printing the statement
return;
}
towerOfHanoi(n-1,from_rod,aux_rod,to_rod);//recursive function
printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
towerOfHanoi(n-1,aux_rod,to_rod,from_rod);
}
int main() //main function
{
int n;
printf("\n Enter number of Disks:");
scanf("%d",&n);// taking no. of disk input from user
towerOfHanoi(n,'A','C','B');// A, B and C are names of rods
return 0;
}
