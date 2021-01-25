#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
};

void insert(struct node*tree,int n)
{
    struct node *temp=NULL;
    if(!(tree))
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->right=temp->left=NULL;
        temp->data=n;
        return;
    }

    if(n<tree->data)
    {
        insert(&*tree->left,n);
    }
    else if(n>tree->data)
    {
        insert(&tree->right,n);
    }
}

void inorder(struct node *tree)
{
    if(tree)
    {
        inorder(tree->left);
        printf("%d",tree->data);
        inorder(tree->right);
    }

}
void postorder(struct node *tree)
{
    if(tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d",tree->data);
    }
}
void preorder(struct node *tree)
{
    if(tree)
    {
        printf("%d",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void deltree(struct node *tree)
{
    if(tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}
void search(struct node *tree,int n)
{
    if(!(tree))
    {
        return NULL;
    }

    if(n<tree->data)
    {
        search(&tree->left,n);
    }
    else if(n>tree->data)
    {
        search(&tree->right,n);
    }
    else if(n==tree->data)
    {
        return tree;
    }
}
void main()
{
    struct node *q;
    struct node *root;
    int i;

    root=NULL;
    insert(&root,9);
    insert(&root,4);
    insert(&root,15);
    insert(&root,6);
    insert(&root,12);
    insert(&root,17);
    insert(&root,2);

    printf("In Order Display:\n");
    inorder(root);

    printf("Pre Order Display:\n");
    preorder(root);

    printf("Post Order Display:\n");
    postorder(root);

    q=search(&root,4);


    if(q)
    {
        printf("Searched Data=%d\n",q->data);
    }
    else if
    {
        printf("Data not found in tree.\n")
    }
    deltree(root);

    
}