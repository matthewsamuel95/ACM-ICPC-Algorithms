public class SLLSample{
	public static void main(String[] args){
		SLList<String> hello=new SLList<String>();
		SNode<String> p1=new SNode<String>("One");
		SNode<String> p2=new SNode<String>("Two");
		SNode<String> p3=new SNode<String>("Three");
		SNode<String> p4=new SNode<String>("Four");
		hello.head=p1;
		p1.next=p2;
		p2.next=p3;
		p3.next=p4;
		hello.tail=p4;
		hello.print();
		p1.next=p3.next;
		p1=p3;
		//p1.info;
		System.out.println(p1.toString());
		//hello.print();
	
	}
}