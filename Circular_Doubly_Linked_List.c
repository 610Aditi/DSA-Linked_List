#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *previous,*next;
};
struct node *tail;

struct node*ADD_AT_EMPTY(tail)
{
    struct node *temp=malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("\n%d",&temp->data);
    temp->previous=temp;
    temp->next=temp;
    tail=temp;
    return tail;
}
struct node*ADD_AT_BEG(struct node*tail)
{
    struct node *newnode=malloc(sizeof(struct node));
    struct node *temp=malloc(sizeof(struct node)); 
    temp=tail->next;
    printf("\nenter the data : ");
    scanf("\n%d",&newnode->data);
    newnode->previous=tail;  // time complexity is o(1)
    newnode->next=temp;
    temp->previous=newnode;
    tail->next=newnode;
    return tail;
}
struct node*ADD_AT_END(struct node*tail)
{    
    struct node *temp=tail->next;
    struct node *newnode=malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("\n%d",&newnode->data);
    tail->next=newnode;
    newnode->previous=tail;
    temp->previous=newnode;
    newnode->next=temp;
    tail=newnode;
    return tail;
}
struct node *ADD_AT_POSITION(struct node*tail,int pos)
{
    struct node *temp2=tail->next;
    struct node *temp=tail->next;
    struct node *newnode=malloc(sizeof(struct node));
    if(pos==1)
    {
    tail=ADD_AT_BEG(tail);
    return tail;
    }
    
    while(pos>1)
    {
    temp2=temp;
    temp=temp->next;
    pos--;
    }
    if(temp==tail)
    {
    tail=ADD_AT_END(tail);
    return tail;       
    }
    else
    {
    printf("enter data : ");
    scanf("%d",&newnode->data);
    temp2->next=newnode;
    newnode->previous=temp2;
    newnode->next=temp;
    temp->previous=newnode;
    return tail;
    }
}
struct node*DEL_AT_BEG(struct node*tail)
{
    struct node *temp=tail->next;
    if(temp==tail)
    {
    free(tail);
    return NULL;
    } 
    tail->next=temp->next;
    temp->next->previous=tail;
    free(temp);
    temp=NULL;
    return tail;
}
struct node*DEL_AT_END(struct node*tail)
{   
    struct node *temp=tail->next;
    struct node *temp2=tail->previous;
    if(temp==tail)
    {
    free(tail);
    return NULL;
    } 
    temp2->next=temp;
    temp->previous=temp2;
    free(tail);
    tail=temp2;
    return tail;
}
struct node *DEL_AT_POSITION(struct node*tail,int pos)
{  
    struct node *temp=tail->next;
    struct node *temp2;       //next node,node to be deleted
    if(pos==1)
    {
    tail=DEL_AT_BEG(tail);
    return tail;
    }
    else
    while(pos>2)       
    {
    temp=temp->next;
    pos--;
    }
    temp2=temp->next;
    if(temp->next==tail)
    {
    tail=DEL_AT_END(tail);
    return tail;
    }
    else
    {
    temp->next=temp2->next;
    temp2->next->previous=temp;
    free(temp2);
    temp2=NULL;
    return tail;
    }
}

struct node*display(struct node*tail)
{
    printf("\nTHE CIRCULAR DOUBLY LINKED LIST IS  : ");
    struct node *temp=tail->next;
    do
    {
    printf(" %d ",temp->data);
    temp=temp->next;
    }
    while(temp!=tail->next);
    return 0;
}
int main()
{
if(tail==NULL)
{
printf("No Elements in Linked list  :\n ");
}
printf("\nCREATING THE LINKED LIST ......................\n");
tail=ADD_AT_EMPTY(tail);
display(tail);

int choice;
int YES=1;
while(YES==1)
{
printf("\nIf you want to Insert At Beginning PRESS 1");
printf("\nIf you want to Insert At Middle PRESS 2");
printf("\nIf you want to Insert At End PRESS 3");
printf("\nIf you want to Delete At Beginning PRESS 4");
printf("\nIf you want to Delete At Middle PRESS 5");
printf("\nIf you want to Delete At End PRESS 6");

printf("\n\nEnter Choice : ");
scanf("%d",&choice);
switch(choice) {
   case 1:
   printf("\nINSERTING AT BEGGINING IN LINKED LIST IS.......................\n");
   tail=ADD_AT_BEG(tail);
   display(tail); 
   break;

   case 2:
   printf("\nINSERTION AT MID IN LINKED LIST IS.......................\n");
   int pos;
   printf("\nENTER THE POSITION TO INSERT VALUE : ");
   scanf("%d",&pos);
   tail=ADD_AT_POSITION(tail,pos);
   display(tail);
   break;

   case 3:
   printf("\nINSERTING AT END IN LINKED LIST IS.......................\n");
   tail=ADD_AT_END(tail);
   display(tail);
   break;

   case 4:
   printf("\nDELETION AT BEGGINING IN LINKED LIST IS.......................\n");
   tail=DEL_AT_BEG(tail);
   display(tail);  
   break;

   case 5:
   printf("\nDELETION AT MID IN LINKED LIST IS.......................\n");
   printf("\nENTER THE POSITION TO INSERT VALUE : ");
   scanf("%d",&pos);
   tail=DEL_AT_POSITION(tail,pos);
   display(tail);
   break;

   case 6:
   printf("\nDELETION AT END IN LINKED LIST IS.......................\n");
   tail=DEL_AT_END(tail);
   display(tail);
   break;
   
   default:
   printf("\nEnter Valid Number ......");
}
printf("\nDO YOU WANT TO CONTINUE : ");
printf("\nIF YES PRESS 1 ,IF NO PRESS 0 : " );
scanf("%d",&YES);
}
return 0;
}