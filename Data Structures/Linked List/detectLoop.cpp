


struct Node
{
    int data;
    Node *next;
};



bool detectLoop(Node *head)
{
    Node *slwptr = head, *fstptr = head;
    
    while(slwptr && fstptr && fstptr->next)
    {
        slwptr = slwptr->next;
        
        fstptr = fstptr->next->next;
        
        if(slwptr == fstptr)
        {
            cout << "loop detected!";
            return 1;
        }
    }
    
    return 0;

}


// time complexity : O(n)
// space complexity : O(1)


