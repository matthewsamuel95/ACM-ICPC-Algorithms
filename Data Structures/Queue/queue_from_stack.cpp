// CPP program to implement Queue using 
// one stack and recursive call stack. 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Queue { 
    stack<int> s; 
  
    // Enqueue an item to the queue 
    void enQueue(int x) 
    { 
        s.push(x); 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        if (s.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        // pop an item from the stack 
        int x = s.top(); 
        s.pop(); 
  
        // if stack becomes empty, return 
        // the popped item 
        if (s.empty()) 
            return x; 
  
        // recursive call 
        int item = deQueue(); 
  
        // push popped item back to the stack 
        s.push(x); 
  
        // return the result of deQueue() call 
        return item; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
  
    return 0; 
} 