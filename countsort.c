// coutingsort algo
/*
countsort(array,size)
max=find largest element in the array
initialize count array with all zeros
for j= 0 to size
    find the total count of each unique element and store the count at the jth index in count array
for i= 1 to max 
    fint the cumulative sum and store it in count array itself
for j=size down to 1
    restore the elements to the array
    decrease count of each element restored by 1*/

#include<stdio.h>
void countingsort(int a[],int size)
{
    int op[50];
    int i;

    //Find the largest element in the array
    int max =a[0];
    for(i=0;i<size;i++)
    {
        if(a[i]>max)
            max =a[i];
    } 

    //size of the count must be atleast (max+1)
    int count[10];
    //initialize count array with all zeros
    for(i=0;i<size;i++){
        count[a[i]]++;
    }
    //store the cummulative count of each array
    for(i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }
    //find the index of each element of the original array in count array,
    //and place the element in the output array
    for(int i=size-1;i>=0;i--)
    {
        op[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    //copy the sorted elements into original array
    for(int i=0;i<size;i++)
    {
        a[i]=op[i];
    }

}
//Function to display the array
void display(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
//Driver Code
int main()
{
    int a[]={4,2,2,8,3,3,1};
    int n=sizeof(a[0]);
    countingsort(a,n);
    display(a,n);
}