// Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Dota;
    struct node *Next;
    struct node *Prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int Count(PNODE first, PNODE last);
void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->Dota = no;
    newn->Next = NULL;
    newn->Prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        newn->Next = *first;
        newn->Prev = *last;
    }
    else
    {
        newn->Next = *first;
        (*first)->Prev = newn;
        newn->Prev = *last;
        *first = newn;
        (*last)->Next = *first;
    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->Dota = no;
    newn->Next = NULL;
    newn->Prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
        newn->Prev = *last;
        newn->Next = *first;
    }
    else
    {
        (*last)->Next = newn;
        newn->Prev = *last;
        *last = newn;
        (*first)->Prev = *last;
        (*last)->Next = *first;        
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
        InsertFirst(first,last,no);
    }
    else if(pos == iCount)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->Dota = no;
        newn->Next = NULL;
        newn->Prev = NULL;

        temp = *first;
        for(int iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        newn->Next->Prev = newn;
        newn->Prev = temp;
        temp->Next = newn;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        printf("Node is Empty.\n");
        return;
    }
    else
    {
        temp = *first;
        *first = (*first)->Next;
        free(temp);
        (*first)->Prev = *last;
        (*last)->Next = *first;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        printf("Node is Empty.\n");
        return;
    }
    else
    {
        (*first)->Prev = (*last)->Prev;
        free(*last);
        *last = (*first)->Prev;
        (*last)->Next = *first;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    PNODE temp = NULL;

    int iCount = 0;
    iCount = Count(*first, *last);
    if(pos < 1 || pos > iCount)
    {
        printf("Invalid Position.\n");
        return ;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;
        for(int iCnt = 1; iCnt < pos; iCnt++)
        {
            temp = temp->Next;
        }
        temp->Next->Prev = temp->Prev;
        temp->Prev->Next = temp->Next;
        free(temp); 
    }
}

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        printf("Node is Empty.\n");
        return;
    }
    
    printf("<=>");
    do
    {
        printf(" | %d | <=> ",first->Dota);
        first = first->Next;
    } while (first != last->Next);
    printf("\n");
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    if(first == NULL && last == NULL)
    {
        printf("Node is Empty.\n");
        return 0;
    }
    do
    {
        iCount++;
        first = first->Next;
    } while (first != last->Next);
    return iCount;
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;

    printf("---------------------------------------------------------\n");
    InsertFirst(&head,&tail,90);
    InsertFirst(&head,&tail,60);
    InsertFirst(&head,&tail,30);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Insert First Node are : %d\n",iRet);

    printf("---------------------------------------------------------\n");
    InsertLast(&head,&tail,33);
    InsertLast(&head,&tail,66);
    InsertLast(&head,&tail,99);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Insert Last Node are : %d\n",iRet);

    printf("---------------------------------------------------------\n");
    InsertAtPos(&head,&tail,180,4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Insert At Position Node are : %d\n",iRet);

    printf("---------------------------------------------------------\n");
    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Delete First Node are : %d\n",iRet);

    printf("---------------------------------------------------------\n");
    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Delete Last Node are : %d\n",iRet);

    printf("---------------------------------------------------------\n");
    DeleteAtPos(&head,&tail,3);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of After Delete At Position Node are : %d\n",iRet);

    return 0;
}