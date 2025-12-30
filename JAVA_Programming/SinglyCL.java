// Singly Circular Linked List

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

class SinglyCircular
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCircular()
    {
        System.out.println("Object of SingliCircular is Created.");
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
            this.last.Next = this.first;
        }
        else
        {
            newn.Next = this.first;
            this.first = newn;
            this.last.Next = this.first;
        }    
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node temp = null;
        node newn = null;
        newn = new node(no);
        if(this.first ==  null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
            newn.Next = this.first;
        }
        else
        {
            temp = this.first;
            while(temp.Next != first)
            {
                temp = temp.Next;
            }
            temp.Next = newn;
            newn.Next = this.first;
            this.last = newn;
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
        }
        this.iCount++;
    }

    public void DeleteFirst()
    {        
        if(this.first == null && this.last == null)
        {
            System.out.println("Node is Empty.");
            return;
        }
        else
        {
            this.first = this.first.Next;
            this.last.Next = this.first;
            System.gc();
            this.iCount--;
        }
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null && this.last == null)
        {
            System.out.println("Node is Empty.");
            return;
        }
        else
        {
            temp = this.first;
            while(temp.Next.Next != this.first)
            {
                temp = temp.Next;
            }
            temp.Next = this.first;
            this.last = temp;
            System.gc();
        }
        this.iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        node target = null;
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position.");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        if(pos == iCount)
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
        do
        {
            System.out.print("| "+temp.Data+" | -> ");
            temp = temp.Next;
        }while(temp != first);
        System.out.println("Back to first Node");
    }

    public int Count()
    {
        return iCount;
    }
}

class SinglyCL 
{
    public static void main(String[] args)    
    {
        int iRet = 0;
        SinglyCircular sobj = new SinglyCircular();

        System.out.println("-------------------------------------------------------------\n");
        sobj.InsertFirst(90);
        sobj.InsertFirst(60);
        sobj.InsertFirst(30);
        sobj.Display();
        sobj.Count();
        iRet = sobj.Count();
        System.out.println("Numbers of After Insert First Node are : "+iRet);

        System.out.println("-------------------------------------------------------------\n");
        sobj.InsertLast(33);
        sobj.InsertLast(66);
        sobj.InsertLast(99);
        sobj.Display();
        sobj.Count();
        iRet = sobj.Count();
        System.out.println("Numbers of After Insert Last Node are : "+iRet);

        System.out.println("-------------------------------------------------------------\n");
        sobj.InsertAtPos(180, 4);
        sobj.Display();
        sobj.Count();
        iRet = sobj.Count();
        System.out.println("Numbers of After Insert At Position Node are : "+iRet);
 
        System.out.println("-------------------------------------------------------------\n");
        sobj.DeleteFirst();
        sobj.Display();
        sobj.Count();
        iRet = sobj.Count();
        System.out.println("Numbers of After Delete First Node are : "+iRet);
 
        System.out.println("-------------------------------------------------------------\n");
        sobj.DeleteLast();
        sobj.Display();
        sobj.Count();
        iRet = sobj.Count();
        System.out.println("Numbers of After delete Last Node are : "+iRet);
 
        System.out.println("-------------------------------------------------------------\n");
        sobj.DeleteAtPos(3);
        sobj.Display();
        sobj.Count();
        iRet = sobj.Count();
        System.out.println("Numbers of After Delete At Position Node are : "+iRet);
    }
}