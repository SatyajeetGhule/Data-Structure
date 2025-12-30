// Doubly Linear Linked List

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

class DoublyLL
{
    private :
        PNODE first;
        PNODE last;
        int iCount;

    public :
        DoublyLL()
        {
            cout<<"Object of Doubly Linear Linked List.\n";
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
                newn->Next = NULL;
                newn->Prev = NULL;
            }
            else
            {
                newn->Next = this->first;
                this->first->Prev = newn;
                this->first = newn;
                newn->Prev = NULL;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            newn = new NODE;

            newn->Data = no;
            newn->Next = NULL;
            newn->Prev = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
                newn->Next = NULL;
                newn->Prev = NULL;
            }
            else
            {
                temp = this->first;
                while(temp->Next != NULL)
                {
                    temp = temp->Next;
                }
                temp->Next = newn;
                newn->Prev = temp;
                newn->Next = NULL;
                this->last = newn;
            }
            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            if(pos < 1 || pos > this->iCount +1)
            {
                cout<<"Invalid Operation...\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == this->iCount +1)
            {
                InsertLast(no);
            }
            else
            {
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
                iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = 0;
            if(this->first == NULL && this->last == NULL)
            {
                return;
            }
            else
            {
                temp = this->first;
                this->first = this->first->Next;
                this->first->Prev = NULL;
                this->last->Next = NULL;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            if(this->first  == NULL && this->last == NULL)
            {
                cout<<"Node is Empty...\n";
                return;
            }
            else
            {
                temp = this->first;
                while(temp->Next != NULL)
                {
                    temp = temp->Next;
                }
                delete temp->Next;
                temp->Next = NULL;
                this->last = temp;
            }
            iCount--;
        }

        void DeleteAtPosition(int pos)
        {
            PNODE target = NULL;
            PNODE temp = NULL;
            
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position...\n";
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
                for(int iCnt = 1; iCnt < pos -1; iCnt++)
                {
                    temp = temp->Next;
                }
                target = temp->Next;
                temp->Next = target->Next;
                target->Next->Prev = temp;
                delete target;
                this->first->Prev = NULL;
                this->last->Next = NULL;
                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;
            temp = this-> first;
            cout<<" NULL <=> ";
            while (temp != NULL)
            {
                cout<<"| "<<temp->Data<<" | <=> ";
                temp = temp->Next;
            }
            cout<<"NULL\n";            
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    int iRet = 0;
    DoublyLL obj;

    cout<<"-----------------------------------------------------------------------\n";
    obj.InsertFirst(90);
    obj.InsertFirst(60);
    obj.InsertFirst(30);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert First Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------------\n";
    obj.InsertLast(33);
    obj.InsertLast(66);
    obj.InsertLast(99);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert Last Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------------\n";
    obj.InsertAtPos(180,4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert At Position Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------------\n";
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete First Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------------\n";
    obj.DeleteAtPosition(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete At Position Node are : "<<iRet<<"\n";

    return 0;
}