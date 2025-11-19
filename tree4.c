#include<stdio.h>

struct Tree
{
    int data;
    struct Tree *left, *right;
}*root;

struct Tree *search(struct Tree* r , int d)
{
    struct Tree *parent;
    while(r!=NULL)
    {
        if(r->data==d)
            return NULL;
        else if(r->data<d)//  A<H
  {
            parent = r;
            r = r->right;
        }else{
        parent =r;
        r = r->left;
        }
    }
    return parent;
};

void add()
{
    struct Tree *t ,*prev ;
    t=(struct Tree*)malloc(sizeof(struct Tree));//Ji kariye okk Busy? i was calling u .Ok
    printf("Enter Data  : ");
    scanf("%d" , &t->data);

    if(root==NULL)
    {
        root=t;
        root->left=root->right=NULL;
    }
    else
    {
       prev = search(root , t->data);
       if(prev==NULL)
       {
           printf("\nDuplicate not allowed.");
       }
       else
       {
           if(prev->data>t->data)
           {
               prev->left=t;
           }
           else{
            prev->right=t;
           }
           t->left=t->right=NULL;
       }
    }
}


void traverse(struct Tree *root)
{
    if(root==NULL)
        return;
    printf("\n Data is %d" , root->data);
    traverse(root->left);
    traverse(root->right);
}

void main()
{
    int ch;


    do{
    printf("\n1.Add a node");
    printf("\n2.Traverse");
    printf("\n4.exit");
    printf("\n Enter a value ");
    scanf("%d" , &ch);

        if(ch==1)
            add();
        else if(ch==2)
            traverse(root);
    }while(ch!=4);

}

