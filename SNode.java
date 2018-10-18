public class SNode <T>
{
    public T info;
    public SNode<T> next;
    
    public SNode(){
        next = null;
    }
    
    public SNode(T el)
    {
        info = el;
        next = null;
    }
    
    public SNode(T el, SNode<T> ptr)
    {
        info = el;
        next = ptr;
    }

    public String toString()
    {
        return info.toString();
    }
}
