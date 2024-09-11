#include<stdio.h>
#include<stdlib.h>

struct node 
{
int data;
struct node *prev, *next;
};
struct node *head = NULL, *temp;

/*************************************************************************************/
void create() 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
    printf("\nMemory Allocation Failed\n");
    return;
    }
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL) 
    {
    head = newnode;  // Initialize head for the first node
    } 
    else 
    {
    temp = head;
    while (temp->next != NULL) 
    {
    temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    }
}

/********************************************************************************************************/
void print(struct node *head) 
{
    if (head == NULL) 
    {
    printf("\nNo Element in the List\n");
    return;
    }
    temp = head;
    printf("\nDoubly Linked List: ");
    while (temp != NULL) 
    {
    printf("%d ", temp->data);
    temp = temp->next;
    }
    printf("\n");
}

/********************************************************************************************************/
struct node *In_beg() 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
    printf("\nMemory Allocation Failed\n");
    return;
    }
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL)
    {
    head->prev = newnode;
    }
    head = newnode;  // Update head to the new node
}

/********************************************************************************************************/
struct node *In_end() 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
    printf("\nMemory Allocation Failed\n");
    return;
    }
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) 
    {
    newnode->prev = NULL;
    head = newnode;
    } 
    else
    {
    temp = head;
    while (temp->next != NULL)
    {
    temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    }
}

/****************************************************************************************/
struct node *In_mid() 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
    printf("\nMemory Allocation Failed\n");
    return;
    }

    int p;
    printf("\nEnter Position: ");
    scanf("%d", &p);
    
    if (p <= 1) 
    {
    In_beg();  // Insert at the beginning if position is 1
    return;
    }
    
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    temp = head;
    for (int i = 1; i < p - 1 && temp != NULL; i++) 
    {
    temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) 
    {
    In_end();  // Insert at end if position is out of bounds
    return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) 
    {
    temp->next->prev = newnode;
    }
    temp->next = newnode;
}

/********************************************************************************************************/
struct node *Del_beg() 
{
    if (head == NULL) 
    {
    printf("\nNo Element in the List\n");
    return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) 
    {
    head->prev = NULL;
    }
    free(temp);
}

/********************************************************************************************************/
struct node *Del_end() 
{
    if (head == NULL) 
    {
    printf("\nNo Element in the List\n");
    return;
    }

    temp = head;
    while (temp->next != NULL) 
    {
    temp = temp->next;
    }

    if (temp->prev != NULL) 
    {
    temp->prev->next = NULL;
    } 
    else 
    {
    head = NULL;
    }
    free(temp);
}

/********************************************************************************************************/
struct node *Del_mid() 
{
    int p;
    printf("\nEnter Position: ");
    scanf("%d", &p);

    if (p <= 1) 
    {
    Del_beg();
    return;
    }
    temp = head;
    for (int i = 1; i < p && temp != NULL; i++) 
    {
    temp = temp->next;
    }

    if (temp == NULL) 
    {
    printf("\nInvalid Position\n");
    return;
    }

    if (temp->prev != NULL) 
    {
    temp->prev->next = temp->next;
    }
    if (temp->next != NULL) 
    {
    temp->next->prev = temp->prev;
    }
    free(temp);
}

/********************************************************************************************************/
int main() 
{
    if (head == NULL)
    {
    printf("No Elements in Doubly Linked List\n");
    }

    create();
    print(head);

    int choice;
    int YES = 1;
    while (YES == 1) 
    {
        printf("\nIf you want to Insert At Beginning PRESS 1");
        printf("\nIf you want to Insert At Middle PRESS 2");
        printf("\nIf you want to Insert At End PRESS 3");
        printf("\nIf you want to Delete At Beginning PRESS 4");
        printf("\nIf you want to Delete At Middle PRESS 5");
        printf("\nIf you want to Delete At End PRESS 6");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                In_beg();
                print(head);
                break;

            case 2:
                In_mid();
                print(head);
                break;

            case 3:
                In_end();
                print(head);
                break;

            case 4:
                Del_beg();
                print(head);
                break;

            case 5:
                Del_mid();
                print(head);
                break;

            case 6:
                Del_end();
                print(head);
                break;

            default:
                printf("\nEnter Valid Number\n");
        }
        printf("\nDo you want to continue? Press 1 for YES, 0 for NO: ");
        scanf("%d", &YES);
    }
    return 0;
}
