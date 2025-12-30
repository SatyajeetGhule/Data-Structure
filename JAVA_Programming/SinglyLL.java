// Singly Linear Linked List

class node
{
    public int Data;
    public node Next;

    public node(int no)
    {
        this.Data = no;
        this.Next = null;
    }
}

class SinglyLinear
{
    public node first;
    public int iCount;

    public SinglyLinear()
    {
        System.out.println("Object of SinglyLinear Created.");
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);

        newn.Next = this.first;
        this.first = newn;
        
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node temp = null;
        node newn = null;
        newn = new node(no);
 
        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;
            while(temp.Next != null)
            {
                temp = temp.Next;
            }
            temp.Next = newn;
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
            for(int iCnt = 1; iCnt < pos -1; iCnt++)
            {
                temp = temp.Next;
            }
            newn.Next = temp.Next;
            temp.Next = newn;
            this.iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(this.first == null)
        {
            System.out.println("Node is Empty.");
            return;
        }
        else
        {
            this.first = this.first.Next;
        }
        System.gc();
        this.iCount--;       
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null)
        {
            System.out.println("Node is Empty.");
            return;
        }
        else if(this.first.Next == null)
        {
            this.first = null;
            System.gc();
        }
        else
        {
            temp = this.first;
            while(temp.Next.Next != null)
            {
                temp = temp.Next;
            }
            temp.Next = null;
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
            System.gc();            
            this.iCount--;
        }
    }

    public void Display()
    {
        node temp = null;
        temp = this.first;
        while(temp != null)
        {
            System.out.print("| "+temp.Data+" | -> ");
            temp = temp.Next;
        }
        System.out.println("null");        
    }

    public int Count()
    {
        return iCount;
    }
}

class SinglyLL
{
    public static void main(String[] args)
    {
        int iRet = 0;
        SinglyLinear sobj = new SinglyLinear();
    
        System.out.println("----------------------------------------------------------------------------");
        sobj.InsertFirst(90);
        sobj.InsertFirst(60);
        sobj.InsertFirst(30);
        sobj.Display();
        iRet = sobj.Count();
        System.err.println("Number of After Insert First Node are : "+iRet);

        System.out.println("----------------------------------------------------------------------------");
        sobj.InsertLast(33);
        sobj.InsertLast(66);
        sobj.InsertLast(99);
        sobj.Display();
        iRet = sobj.Count();
        System.err.println("Number of After Insert Last Node are : "+iRet);

        System.out.println("----------------------------------------------------------------------------");
        sobj.InsertAtPos(180,4);
        sobj.Display();
        iRet = sobj.Count();
        System.err.println("Number of After Insert At Position Node are : "+iRet);

        System.out.println("----------------------------------------------------------------------------");
        sobj.DeleteFirst();
        sobj.Display();
        iRet = sobj.Count();
        System.err.println("Number of After Delete First Node are : "+iRet);

        System.out.println("----------------------------------------------------------------------------");
        sobj.DeleteLast();
        sobj.Display();
        iRet = sobj.Count();
        System.err.println("Number of After Delete Last Node are : "+iRet);

        System.out.println("----------------------------------------------------------------------------");
        sobj.DeleteAtPos(3);
        sobj.Display();
        iRet = sobj.Count();
        System.err.println("Number of After Delete At Position Node are : "+iRet);
    }
}
