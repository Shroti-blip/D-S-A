#include<stdio.h>

struct Employee
{
    int empno;
    char name[20];
    struct Employee *link;
} *head;

void addNode()
{
    struct Employee *e , *ptr , *prev;
    e = (struct Employee *)malloc(sizeof(struct Employee));
    if(e==NULL){
        printf("\nCan not allocate memory");
    }
    else{
        printf("\nEmp no.");
        scanf("%d" , &e->empno);
        printf("\nEmp Name");
        scanf("%s" , &e->name);
        if(head==NULL){
            head=e;
            e->link=NULL;
        }
        else{
            for(ptr=head; ptr!=NULL; ptr = ptr->link)
                prev = ptr;
            prev->link=e;
            e->link=NULL;
        }
    }
}


void displayNodes()
{
    struct Employee *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("\nEmp no\t\t%d" , ptr->empno);
        printf("\nEmp name \t%s" , ptr->name);
        ptr=ptr->link;
        printf("\n========================================");
    }
}

 void main()
 {
     head=NULL;
     int c;
     while(1)
     {
         printf("\n1.Add an Emplyee");
         printf("\n2.Display all Employee");
       //  printf("\n3. Delete an emplyee");
         printf("\n3.Exit");
         scanf("%d" , &c);
         if(c==1)
            addNode();
         else if(c==2)
            displayNodes();
       else if(c==3)
       break;

     }
 }
