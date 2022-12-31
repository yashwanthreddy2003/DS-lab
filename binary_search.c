//binary search//
#include <stdio.h>//standard input otput
int binarySearch(int array[], int x, int low, int high) {//function for binary search and intializing 2 pointers low and high
if (high >= low) {//ifhigh>=low
int mid = low + (high - low) / 2;//then mid=low+(high-low)/2
if (array[mid] == x)//is x==mid
return mid;//then return the mid value of array
if (array[mid] > x)//if x<mid value of array
return binarySearch(array, x, low, mid - 1);//then return binarysearch function with high=mid-1
return binarySearch(array, x, mid + 1, high);//return binarysearch function with low=mid+1
}
return -1;//else return -1
}
int main(void) {//main function
int array[8] = {0,3,4,5,6,7,8,9};//intializing array of size 8
for(int i=0;i<8;i++)//for loop to print the value in array
{
printf("%d\n",array[i]);//print the values
}
int n = sizeof(array) / sizeof(array[0]);//initializing n
int x ;//intiailizing x
printf("Enter the number to search:");
scanf("%d",&x);//taking input of x
int result = binarySearch(array, x, 0, n - 1);//initializing result with low=0 and high with n-1
if (result == -1)//if result==-1 then it is not found
printf("Not found");//print statement
else
printf("Element is found at index %d", result);//else print the position of element
}
