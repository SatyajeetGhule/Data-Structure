// Singly Circular Linked List

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

int Count(PNODE first, PNODE last);
void InsertFirst(PPNODE first, PPNODE last, int no) 
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn-> Data = no;
    newn-> Next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        (*last)->Next = *first;
    }
    else
    {
        newn->Next = *first;
        *first = newn;
        (*last)->Next = *first;
    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->Next =NULL;
    newn->Data = no;
    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        newn->Next = *first;
    }
    else
    {
        temp = *first;
        while (temp->Next != *first)
        {
            temp= temp->Next;
        }
        temp->Next = newn;
        newn->Next = *first;
        *last = newn;        
    }
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    iCount = Count(*first, *last);
    if(pos < 1 || pos > iCount +1)
    {
        printf("Invalid Position.\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(pos == iCount +1)
    {
        InsertLast(first,last,no);
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

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    
    if(*first == NULL && *last == NULL)    
    {
        printf("Node is Empty.\n");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->Next;
        free(temp);
        (*last)->Next = *first;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;
    
    if(*first == NULL && *last == NULL)    
    {
        printf("Node is Empty.\n");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while (temp->Next != *last)
        {
            temp = temp->Next;
        }
        free(temp->Next);
        *last = temp;
        temp->Next = *first;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCount = 0;
    iCount = Count(*first, *last);

    if(pos < 1 || pos > iCount)
    {
        printf("Inavlid Position.\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first, last);
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

void Display(PNODE first, PNODE last)
{
    do
    {
        printf("| %d | -> ",first->Data);
        first = first->Next;
    } while (first != last->Next);
    printf("NULL\n");
}

int Count(PNODE first, PNODE last)
{
    PNODE temp = NULL;
    temp = first;
    int iCount = 0;
    do
    {
        iCount++;
        temp = temp->Next;
    } while (temp != first);
    return iCount;
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;

    printf("-------------------------------------------------\n");
    InsertFirst(&head,&tail,90);
    InsertFirst(&head,&tail,60);
    InsertFirst(&head,&tail,30);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Insert First Node are : %d\n",iRet);
 
    printf("-------------------------------------------------\n");
    InsertLast(&head,&tail,33);
    InsertLast(&head,&tail,66);
    InsertLast(&head,&tail,99);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Insert Last Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    InsertAtPos(&head,&tail,180, 4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Insert At Position Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Delete First Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Delete Last Node are : %d\n",iRet);

    printf("-------------------------------------------------\n");
    DeleteAtPos(&head,&tail,3);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Delete At Position Node are : %d\n",iRet);

    return 0;
}