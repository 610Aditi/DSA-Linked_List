#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head,*temp=NULL;
/*************************************************************************************************/
void create()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............\n");
}
 int data;
 printf("Enter Data :");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 if(head==NULL)
 {
   head=newnode;
   temp=newnode;
 }
 else
 {
   temp=head;
   while(temp->next!=NULL)
   {
   temp=temp->next;
   }
   temp->next=newnode;
 }
}
/*************************************************************************************************/
void print()
{
struct node *temp=head;
if(temp==NULL)
{
printf("\nNo Elements in Linked list ");
return;
}
printf("\nSINGLY LINKED LIST IS.......................\n");
printf("\nElements are :\n");
while(temp!=NULL)
{
printf("%d    ",temp->data);
temp=temp->next;
}
}
/*************************************************************************************************/
struct node in_beg()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............\n");
}
int data;
printf("Enter Data :");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
}
/************************************************************************************************/
struct node in_mid()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............");
}
int data,p;
printf("\nEnter position : ");
scanf("%d",&p);
if(p!=1)
{
printf("Enter Data :");
scanf("%d",&newnode->data);
}
if(p<1)
{
printf("Invalid position "); 
free(newnode); 
}
if(p==1)
{
in_beg();
free(newnode);
}
else
{
temp=head;
for(int i=1;i<p-1&&temp!=NULL;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("Position out of Bound...");
free(newnode);
}
newnode->next=temp->next;
temp->next=newnode;
}
}
/*********************************************************************************************/
struct node in_end()
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\n Memory Allocation is Failed............\n");
}
int data;
printf("Enter Data :");
scanf("%d",&newnode->data);
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
//*********************************************************************************************//
struct node del_beg()
{
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
else
{
temp=head;
head=head->next;
free(temp);
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
struct node del_mid()
{
struct node *prenode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
int p;
if(p!=1)
{
printf("\nEnter position : ");
scanf("%d",&p);
}
if(p<1)
{
printf("Invalid position "); 
}
if(p==1)
{
del_beg();
}
else
{
temp=head;
for(int i=0;i<p-1&&temp!=NULL;i++)
{
prenode=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("Position Out Of Bound");
}
prenode->next=temp->next;
free(temp);
}
}
////////////////////////////////////////////////////////////////////////////////////////////////
struct node del_end( )
{
struct node *prenode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
else
{
temp=head;
while(temp->next!=NULL)
{
prenode=temp;
temp=temp->next;
}
prenode->next=temp->next;    // or prenode->next=NULL
free(temp);
}
}
/*************************************************************************************************/
int main()
{
if(head==NULL)
{
printf("No Elements in Linked list\n ");
}
printf("\nCREATING THE LINKED LIST ......................\n");
create();
print();

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
   in_beg();
   print();
   break;

   case 2:
   printf("\nINSERTION AT MID IN LINKED LIST IS.......................\n");
   in_mid();
   print();
   break;

   case 3:
   printf("\nINSERTING AT END IN LINKED LIST IS.......................\n");
   in_end();
   print();
   break;

   case 4:
   printf("\nDELETION AT BEGGINING IN LINKED LIST IS.......................\n");
   del_beg();
   print();  
   break;

   case 5:
   printf("\nDELETION AT MID IN LINKED LIST IS.......................\n");
   del_mid();
   print();
   break;

   case 6:
   printf("\nDELETION AT END IN LINKED LIST IS.......................\n");
   del_end();
   print();
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