// Singly Linear Linked List

#include<iostream>
using namespace std;

struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;


class SinglyLL
{
    private :
        PNODE first;
        int iCount;

    public :
        SinglyLL()
        {
            cout<<"Object of SinglyLL is Created..\n";
            this->first = NULL;
            this->iCount = 0;
        }
        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->Data = no;
            newn->Next = NULL;

            newn->Next = this->first;
            this->first = newn;
            this->iCount++; 
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->Data = no;
            newn->Next = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                temp = this -> first;
                while(temp -> Next != NULL)
                {
                    temp = temp -> Next;
                }
                temp->Next = newn;
            }
            this->iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            
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

                temp = first;
                for(int iCnt = 1; iCnt < pos -1; iCnt++)
                {
                    temp = temp -> Next;
                }
                newn->Next = temp ->Next;
                temp->Next = newn;
                this->iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->Next == NULL)
            {
                delete this -> first;
                this->first = NULL;
            }
            else
            {
                temp = this -> first;                

                this->first = this->first->Next;
                delete temp;
            }
            this -> iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->Next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;
                while (temp->Next->Next != NULL)
                {
                    temp = temp->Next;
                }
                delete temp->Next;
                temp->Next = NULL;
                this->iCount--;
            }
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
                temp->Next = target;
                delete target;
                this->iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;
            temp = this->first;
            while(temp != NULL)
            {
                cout<<"| "<<temp->Data<<" | -> ";
                temp = temp -> Next;
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
    SinglyLL obj;

    obj.InsertFirst(27);
    obj.InsertFirst(24);
    obj.InsertFirst(21);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert First Node are : "<<iRet<<"\n";
    cout<<"-----------------------------------------------------------\n";

    obj.InsertLast(30);
    obj.InsertLast(33);
    obj.InsertLast(39);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Insert Last Node are : "<<iRet<<"\n";
    cout<<"-----------------------------------------------------------\n";
    
    obj.InsertAtPos(36,6);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After InsertAt Position Node are : "<<iRet<<"\n";
    cout<<"-----------------------------------------------------------\n";
    
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete First Node are : "<<iRet<<"\n";
    cout<<"-----------------------------------------------------------\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete Last Node are : "<<iRet<<"\n";
    cout<<"-----------------------------------------------------------\n";
    
    obj.DeleteAtPos(6);
    obj.Display();
    iRet = obj.Count();
    cout<<"Numbers of After Delete At Position Node are : "<<iRet<<"\n";
    cout<<"-----------------------------------------------------------\n";
    
    return 0;
}
