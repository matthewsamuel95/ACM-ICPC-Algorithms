public class SLList<T> 
{
    public SNode<T> head,tail;
    public SLList()
    {
        this.head = this.tail = null;
    }
    
    public boolean isEmpty()
    {
        return (this.head == null);
    }
    
    // Addition operators
    public void addtoHead(T el)	
    {
        this.head = new SNode<T>(el,head);
        if (this.tail == null)
        {
            this.tail = this.head; 
        }	
    }
    public void addtoTail(T el)
    {
        if (this.isEmpty())
        {
		  this.head = this.tail = new SNode<T>(el); 
        }
        else
        {
		  this.tail.next = new SNode<T>(el); 
		  this.tail = this.tail.next; 
	   }
    }

    // Deletion Operators
    public T deletefromHead()
    {
        if (this.isEmpty()) 
        {
            return null;
        }      
        T el = this.head.info;
        
        if (this.head == this.tail)
        {                              
            this.head = this.tail = null;
        }
        else
        {
            this.head = this.head.next;
        }                                           
        return el; 
    }
    public T deletefromTail()
    {
        if (this.isEmpty())  return null;
	   T el = this.tail.info;
	   if (this.head == this.tail)
       {              
            this.head = this.tail = null;
        }
        else
        {
            SNode<T> p=this.head;                             
            while(p.next!=this.tail){
				this.tail = p;                              
				this.tail.next = null;
			}
        }
	   return el;
    }
	
	public SNode<T> find(T el){
		SNode<T> p=this.head;
		while(p!=null&&p.info!=el){
			p=p.next;
		}
		
		return p;
	}
	
	public T delete(T el){
		if(this.isEmpty()){
			System.out.println("List Empty");
			return el;
		}
		else if(el==this.tail.info){
			return this.deletefromTail();
		}
		else if(el==this.head.info){
			return this.deletefromHead();
		}
		SNode<T> pred=this.head;
		SNode<T> t=this.head.next;
		while(t!=null&&t.info!=el){
			pred=pred.next;
			t=t.next;
		}
		if(t==null){
			System.out.println("List Empty");
			return el;
		}
		else{
			pred.next=t.next;
			//this.delete(t);
		}
		
		return el;
	}
	
	
    
    // Print Method
    public void print()
    {
        System.out.println("List");
        System.out.print(head.info + " -> ");
        SNode node = head;
        while(head.next!=null){
            SNode temp = head;
            head = head.next;
            System.out.print(head.toString());
            if(head != null)
            {
                System.out.print(" -> ");
            }
        }
        head = node;
        System.out.println();
    }
    
    // Count Nodes
    public int countNodes()
    {
		int count=1;
        if(head==null)
        {
            return 0;
        }
        else
        {
			SNode<T> t=this.head;
          	while(t!=null){
				count++;
				t=t.next;
			}
            return count;
        }
    }
    
    // Replace Method
    public int replaceInfo(T el, T newEl)
    {
		SNode<T> temp = head;
        while(head.info != el)
        {
            this.head = this.head.next;
        }
        if(this.head.info==el)
        {
            this.head.info=newEl;
            this.head=temp;
        }
        return 1;
    }
	
	public int maxInfo(){
		SNode<T> max=this.head;
		SNode<T> temp=this.head;
		while(temp!=null){
			if(Integer.parseInt(max.toString())>Integer.parseInt(temp.toString())){
				temp=temp.next;
			}
			else{
				max=temp;
				temp=temp.next;
			}
		}

		return Integer.parseInt(max.toString());
	}
	
	public int countOccurence(T el){
		int ctr=0;
		SNode<T> occur=this.head;
		while(occur!=null){
			if(el==occur.info){
				ctr++;
				occur=occur.next;
			}
			else{
				occur=occur.next;
			}
		}
		return ctr;
	}
	
	public T findNode(T el){
		int ctr=0;
		SNode<T> find=this.head;
		while(ctr!=Integer.parseInt(el.toString())){
			ctr++;
			find=find.next;
		}
		
		return find.info;
	}
	
	public SLList<T> linkSelected(SLList<T> L, SLList<T> P){
		SLList<T> output=new SLList<T>();
		SNode<T> LHead=L.head;
		SNode<T> PHead=P.head;
		while(!P.isEmpty()){
			int ctr=1;
			T el=LHead.info;
			while(ctr!=Integer.parseInt(P.head.toString())){
				ctr++;
				el=LHead.info;
				LHead=LHead.next;
			}
			output.addtoTail(el);
			P.deletefromHead();
		}
		
		return output;
	}
}

