/* Program to implement a stack using
two queue */
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;

    int curr_size;

    public:
    Stack()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;

        // Push x first in empty q2
        q2.push(x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop(){

        // if no elements are there in q1
        if (q1.empty())
            return ;
        q1.pop();
        curr_size--;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return curr_size;
    }
};

//main function
int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);

    cout << "current size: " << stk.size()
         << endl;
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;

    cout << "current size: " << stk.size()
         << endl;
    return 0;
}
