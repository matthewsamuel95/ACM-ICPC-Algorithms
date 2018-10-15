class MedianFinder {
    
    /** initialize your data structure here. */
    PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
    PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(
        new Comparator<Integer>(){
            public int compare(Integer a, Integer b){
                if(a > b)return -1;
                else if(a == b)return 0;
                return 1;
            }
        }
    );
    
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        int diff = maxHeap.size()-minHeap.size();
        if(diff == 0){
            minHeap.add(num);
            maxHeap.add(minHeap.poll());    
        }
        else{
            maxHeap.add(num);
            minHeap.add(maxHeap.poll());    
        }
    }
    
    public double findMedian() {
        double median = 0; 
        int diff = maxHeap.size()-minHeap.size();
        
        if(diff==0)median = (maxHeap.peek()+minHeap.peek())/2.0;
        else median = maxHeap.peek();
        return median;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */