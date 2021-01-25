#include<stdio.h>
#include <stdlib.h>
#define MAX 5
void insertpriority(int);
void deletepriority(int);
void create();
void check(int);
void displaypqueue();
int pque[MAX];
int front, rear;
//create
void create()
{
    front = rear = -1;
}
//insertion
void insertpriority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pque[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}
//check priority and place
void check(int data)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (data >= pque[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pque[j] = pque[j - 1];
            }
            pque[i] = data;
            return;
        }
    }
    pque[i] = data;
}
//delete
void deletepriority(int data)
{
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        if (data == pque[i])
        {
            for (; i < rear; i++)
            {
                pque[i] = pque[i + 1];
            }
            pque[i] = -99;
            rear--;
            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
//display
void displaypqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (; front <= rear; front++)
    {
        printf(" %d ", pque[front]);
    }
    front = 0;
}