class GfG{
    public Queue<Integer> rev(Queue<Integer> q){
        //add code here.
        //revHelperRecursive(q);
        revHelperIterative(q);
        return q;
    }
    private void revHelperIterative(Queue<Integer> q){
        Stack<Integer> s=new Stack<Integer>();
        while(!q.isEmpty()){
            s.push(q.poll());
        }
        while(!s.empty()){
            q.offer(s.pop());
        }
    }
    private void revHelperRecursive(Queue<Integer> q){
        if(q.isEmpty())return;
        int temp=q.poll();
        revHelperRecursive(q);
        q.offer(temp);
    }
}