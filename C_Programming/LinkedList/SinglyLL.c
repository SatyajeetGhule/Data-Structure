// Singly Linear Linked List

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int Count(PNODE first);
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = no;
    newn->Next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->Next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = no;
    newn->Next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;        
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCount = Count(*first);
    if(pos < 1 || pos > iCount +1)
    {
        printf("Invalid Position...\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iCount +1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->Data = no;
        newn->Next = NULL;

        temp = *first;
        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Node is Empty.\n");
        return;
    }
    else
    {
        temp = *first;
        *first = (*first)->Next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        printf("Node is Empty.\n");
        return;
    }
    else
    {
        temp = *first;
        while(temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        free(temp->Next);
        temp->Next = NULL;
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0;
    iCount = Count(*first);
    if (pos < 1 || pos > iCount)
    {
        printf("Invalid Position...\n");
        return;
    }
    else
    {
        temp = *first;
        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->Next;
        }
        target = temp->Next;
        temp->Next = target->Next;
        free(target);
    }    
}

void Display(PNODE first)
{
    if(first == NULL)
    {
        printf("Node is Empty..\n");
        return;
    }
    
    while (first != NULL)
    {
        printf("| %d | -> ",first->Data);
        first = first->Next;
    }
    printf("NULL\n");    
}

int Count(PNODE first)
{
    if(first == NULL)
    {
        printf("Node is Empty..\n");
        return 0;
    }
    int iCount = 0;
    while (first != NULL)
    {
        iCount++;
        first = first->Next;
    }
    return iCount;    
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    printf("-------------------------------------------------\n");
    InsertFirst(&head,90);
    InsertFirst(&head,60);
    InsertFirst(&head,30);
    Display(head);
    iRet = Count(head);
    printf("Number of After Insert First Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    InsertLast(&head,33);
    InsertLast(&head,66);
    InsertLast(&head,99);
    Display(head);
    iRet = Count(head);
    printf("Number of After Insert Last Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    InsertAtPos(&head,180, 4);
    Display(head);
    iRet = Count(head);
    printf("Number of After Insert At Position Node are : %d\n",iRet);
 
    printf("-------------------------------------------------\n");
    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of After Delete First Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of After Delete Last Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    DeleteAtPos(&head, 3);
    Display(head);
    iRet = Count(head);
    printf("Number of After Delete At Position Node are : %d\n",iRet);
    return 0;
}
