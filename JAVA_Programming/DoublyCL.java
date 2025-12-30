//Doubly Circular Linked List

class node
{
    public int Data;
    public node Next;
    public node Prev;

    public node(int no)
    {
        this.Next = null;
        this.Prev = null;
        this.Data = no;
    }
}

class DoublyCircular
{
    public node first;
    public node last;
    public int iCount;

    public DoublyCircular()
    {
        System.out.println("Object of DoublyCircular is Created.");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            newn.Next = this.first;
            newn.Prev = this.last;
        }
        else
        {
            newn.Next = this.first;
            this.first.Prev = newn;
            this.first = newn;
            newn.Prev = this.last;
            this.last.Next = this.first;
        }
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node temp = null;
        node newn = null;
        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            newn.Next = this.first;
            newn.Prev = this.last;
        }
        else
        {
            temp = this.first;
            while (temp.Next != this.first)
            {
                temp = temp.Next;   
            }
            temp.Next = newn;
            newn.Prev = temp;
            newn.Next = this.first;
            this.last = newn;
            this.first.Prev = this.last;
        }
        this.iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {
        node temp = null;
        node newn = null;
        newn = new node(no);

        if(pos < 1 || pos > iCount +1)
        {
            System.out.println("Invalid Position.");
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
            temp = this.first;
            for(int iCnt = 0; iCnt < pos -1; iCnt++)
            {
                temp = temp.Next;
            }
            newn.Next = temp.Next;
            newn.Prev = temp;
            newn.Next.Prev = newn;
            temp.Next = newn;
            this.iCount++;
        }
    }

    public void DeleteFirst()
    {
        node temp = null;

        if(this.first == null && this.last == null)
        {
            System.out.println("Node is Empty");
            return;
        }
        else 
        {
            temp = this.first;
            this.first = this.first.Next;
            this.first.Prev = this.last;
            temp = null;
            System.gc();
        }
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null && this.last == null)
        {
            System.out.println("Node is Empty");
            return;
        }
        else 
        {
            temp = this.first;
            while(temp.Next.Next != this.first)
            {
                temp = temp.Next;
            }
            temp.Next = null;
            temp.Next = this.first;
            this.last = temp;
            this.first.Prev = this.last;
            System.gc(); 
        }
        this.iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        node target = null;
        node temp = null;
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position.");
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
            temp = this.first;
            for(int iCnt = 1; iCnt < pos -1; iCnt++)
            {
                temp = temp.Next;
            }
            target = temp.Next;
            temp.Next = target.Next;
            target.Next.Prev = temp;
            target = null;
            System.gc();
            this.iCount--;
        }
    }

    public void Display()
    {
        node temp = null;
        temp = this.first;
        System.out.print("<=> ");
        do
        {
            System.out.print("| "+temp.Data+" | <=> ");
            temp = temp.Next;
        }while(temp != first);
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class DoublyCL
{
    public static void main(String[] args)
    {
        int iRet = 0;
        DoublyCircular dobj = new DoublyCircular();

        System.out.println("------------------------------------------------------------");
        dobj.InsertFirst(90);
        dobj.InsertFirst(60);
        dobj.InsertFirst(30);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Numbers of After Insert First Node are : "+iRet);

        System.out.println("------------------------------------------------------------");
        dobj.InsertLast(33);
        dobj.InsertLast(66);
        dobj.InsertLast(99);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Numbers of After Insert First Node are : "+iRet);

        System.out.println("------------------------------------------------------------");
        dobj.InsertAtPos(180,3);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Numbers of After Insert At Position Node are : "+iRet);
 
        System.out.println("------------------------------------------------------------");
        dobj.DeleteFirst();
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Numbers of After Delete First Node are : "+iRet);

        System.out.println("------------------------------------------------------------");
        dobj.DeleteLast();
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Numbers of After Delete Last Node are : "+iRet); 

        System.out.println("------------------------------------------------------------");
        dobj.DeleteAtPos(3);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Numbers of After Delete At Position Node are : "+iRet);
    }
}