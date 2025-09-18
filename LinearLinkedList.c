#include<stdio.h>

struct Student
{
    int rollno;
    struct Student *next;
}*start;

struct Student *createNode()
{
    struct Student *s;
    s = (struct Student *)malloc(sizeof(struct Student));
    if(s==NULL)
        printf("\nNot enough memory");
    else
    {
        printf("\nRoll no ");
        scanf("%d" , &s->rollno);
    }
    return s;
};

void addEnd()
{
    printf("\nEnter a node at the end");
    struct Student *ptr , *p , *last;
    ptr = createNode();
    if(start == NULL){
        start=ptr;
        ptr->next=NULL;
    }
    else
    {
        for(p=start; (p);p=p->next)
            last=p;
        last->next=ptr;
        ptr->next=NULL;
    }
}

void addBeg()
{
    printf("\nAdd a node at the beginning");
    struct Student *s;
    s = createNode();
    s->next=start;
    start=s;
}

void addMiddle()
{
    if(start==NULL)
    {
        printf("\nNo node found");
        return;
    }
    printf("\nAdd a node at the middle");
    struct Student *ptr,*p ;
    ptr = createNode();
    int no;
    printf("\nEnter a roll no after which you want to insert a node");
    scanf("%d" , &no);
    for(p=start;(p);p=p->next)
    {
        if(p->rollno == no)
        {
            ptr->next=p->next;
            p->next=ptr;
        }
    }
}

void showAll(){
if(start==NULL)
{
    printf("\nNo nodes found");
    return;
}
struct Student *p;
for(p=start;(p); p=p->next)
{
    printf("\nRoll no %d" , p->rollno);
    printf("\n=====================================");
}
}

void main()
{
    start = NULL;
    int c;
    do
    {
        printf("\n1. Add at the beg");
        printf("n2. Add at the middle");
        printf("n3. Add at the end");
        printf("\n4. Show all nodes");
        printf("\n5. Exit");
        printf("\nEnter your choice");
        scanf("%d" , &c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMiddle();
        else if(c==3)
            addEnd();
        else if(c==4)
            showAll();
    }while(c!=5);
}
