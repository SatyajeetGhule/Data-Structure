//Doubly Circular Linked List

#include<iostream>
using namespace std;

struct node
{
    int Data;
    struct node *Next;
    struct node *Prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private : 
        PNODE first;
        PNODE last;
        int iCount;

    public : 
        DoublyCL()
        {
            cout<<"Object of DoublyCL is Created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn->Data = no;
            newn->Next = NULL;
            newn->Prev = NULL;
            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
                newn->Next = this->first;
                newn->Prev = this->last;
            }
            else
            {
                newn->Next = this->first;
                this->first = newn;
                newn->Prev = this->last;
                this->last->Next = this->first;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->Data = no;
            newn->Next = NULL;
            newn->Prev = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
                newn->Next = this->first;
                newn->Prev = this->last;
            }
            else
            {
                this->last->Next = newn;
                newn->Prev = this->last;
                newn->Next = this->first;
                this->last = newn;
                this->first->Prev = this->last;                
            }
            iCount++;
        }

        void InsertAtPosition(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            if(pos < 1 || pos > iCount +1)
            {
                cout<<"Invalid Position...\n";
                return;
            }
            
            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount +1)
            {
                InsertLast(no);
            }
            else
            {
                
                newn = new NODE;
                newn->Data = no;
                newn->Next = NULL;
                newn->Prev = NULL;

                temp = this->first;
                for(int iCnt = 1; iCnt < pos -1; iCnt++)
                {
                    temp = temp->Next;
                }
                newn->Next = temp->Next;
                temp->Next->Prev = newn;
                temp->Next = newn;
                newn->Prev = temp;
            }
            iCount++;

        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                cout<<"Node is Empty...\n";
                return;
            }
            else
            {   
                temp = this->first;
                this->first = this->first->Next;
                this->first->Prev = this->last;
                this->last->Next = this->first;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                cout<<"Node is Empty\n";
                return;
            }
            else
            {
                temp = this->first;
                while(temp->Next != last)
                {
                    temp = temp->Next;
                }
                delete temp->Next;
                temp->Next = this->first;
                this->last = temp;
                this->first->Prev = last;
            }
            iCount--;
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid position...\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = this->first;
                for(int iCnt= 1; iCnt < pos; iCnt++)
                {
                    temp = temp->Next;
                }
                temp->Next->Prev = temp->Prev;
                temp->Prev->Next = temp->Next;
                delete temp;
                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = this->first;
            cout<<"<=> ";
            do
            {
                cout<<"| "<<temp->Data<<" | <=> ";
                temp = temp->Next;
            }while(temp != first);
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    int iRet = 0;
    DoublyCL obj;

    cout<<"----------------------------------------------------------------------\n";
    obj.InsertFirst(90);
    obj.InsertFirst(60);
    obj.InsertFirst(30);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of After Insert First Node are : "<<iRet<<"\n";

    cout<<"----------------------------------------------------------------------\n";
    obj.InsertLast(33);
    obj.InsertLast(66);
    obj.InsertLast(99);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of After Insert Last Node are : "<<iRet<<"\n";

    cout<<"----------------------------------------------------------------------\n";
    obj.InsertAtPosition(180, 4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of After Insert At Position Node are : "<<iRet<<"\n";

    cout<<"----------------------------------------------------------------------\n";
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of After Delete First Node are : "<<iRet<<"\n";

    cout<<"----------------------------------------------------------------------\n";
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of After Delete Last Node are : "<<iRet<<"\n";

    cout<<"----------------------------------------------------------------------\n";
    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of After Delete At Position Node are : "<<iRet<<"\n";

    return 0;
}