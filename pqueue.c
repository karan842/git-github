#include<stdio.h>
#include<stdlib.h>
#include"pqueue.h"
int main()
{
    int n,ch;
    printf("\n1.Insert an element to the Queue:");
    printf("\n2.Delete an element from the Queue");
    printf("\n3.Diplay the elements of the Queue:");
    printf("\n4.Exit");

    create();

    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\n1.Insertion of Element:");
                    scanf("%d",&n);
                    insertpriority(n);
                    break;
            case 2: printf("\n2.Deletion of an element:");
                    scanf("%d",&n);
                    deletepriority(n);
                    break;
            case 3: printf("\n3.Display the elements:");
                    scanf("%d",&n);
                    displaypqueue();
                    break;
            case 4: 
                    exit(0);

            default:
                    printf("\nWrong Choice!!");

        }
    }
    return 0;

}