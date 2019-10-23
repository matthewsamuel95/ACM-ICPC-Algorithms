class Fenwick
{
    private final long a[];
    
    public Fenwick(int n)
    {
        this.a=new long[n+1];
    }
    
    public void update(final int index,final int value)
    {
        int effectiveIndex=index+1;
        
        while(effectiveIndex>0 && effectiveIndex<a.length)
        {
            a[effectiveIndex]+= value;
            effectiveIndex = getNext(effectiveIndex);
        }
    }
    
    public long query(final int left,final int right)
    {
        if(left>right) return 0;
        
        return query(right+1)-query(left);
    }
    
    private long query(int i)
    {
        if(i<=0) return 0;
        if(i>=a.length) i=a.length-1;
        
        long sum=0;
        
        while(i>0)
        {
            sum+=a[i];
            i=getParent(i);
        }
        return sum;
    }
    
    private int getNext(final int effectiveIndex)
    {
        return effectiveIndex+((~effectiveIndex+1) & effectiveIndex));
    }
    
    private int getParent(final int effectiveIndex)
    {
         return effectiveIndex-((~effectiveIndex+1) & effectiveIndex));
    }
}
