// Singly Circular Linked List

#include<iostream>
using namespace std;

struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private :
        PNODE first;
        PNODE last;
        int iCount;
    
    public :
        SinglyCL()
        {
            cout<<"Object of SinglyCL is Created.\n";
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
            if(this->first == NULL)
            {
                this->first = newn;
                this->last = newn;
                newn->Next = this->first;
            }
            else
            {
                newn->Next = this->first;
                this->first = newn;
                this->last->Next = first;
            }
            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            newn = new NODE;
            newn->Data = no;
            newn->Next = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
                newn->Next = this->first;
            }
            else
            {
                temp = this->first;
                while(temp->Next != this->first)
                {
                    temp = temp->Next;
                }
                temp->Next = newn;
                newn->Next = this->first;
                this->last = newn;
            }
            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

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
                newn->Data = no;
                newn->Next = NULL;

                temp = this->first;
                for(int iCnt = 1; iCnt < pos -1; iCnt++)
                {
                    temp = temp->Next;
                }
                newn->Next = temp->Next;
                temp->Next = newn;
                iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                this->first = first->Next;
                delete temp;
                this->last->Next = first;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if (this->first == NULL && this->last == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                while(temp->Next != this->last)
                {
                    temp = temp->Next;
                }
                delete temp->Next;
                temp->Next = first;
                this->last->Next = this->first;
            }
            iCount--;            
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;

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
                delete target;
                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;
            temp = this->first;
            do
            {
                cout<<"| "<<temp->Data<<" | -> ";
                temp = temp->Next;
            }while(temp != this->first);
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
    SinglyCL obj;

    cout<<"-----------------------------------------------------------------\n";
    obj.InsertFirst(90);
    obj.InsertFirst(60);
    obj.InsertFirst(30);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert First Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------\n";
    obj.InsertLast(33);
    obj.InsertLast(66);
    obj.InsertLast(99);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert Last Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------\n";
    obj.InsertAtPos(120,4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert At Position Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------\n";
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete First Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------\n";
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete Last Node are : "<<iRet<<"\n";

    cout<<"-----------------------------------------------------------------\n";
    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete At Position Node are : "<<iRet<<"\n";

    return 0;
}