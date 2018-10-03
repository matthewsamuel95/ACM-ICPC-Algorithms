//
// Created by Azi Crawford on 03/10/2018.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>

class Stack
{
    std::queue<int> q1, q2;

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

        // Push all the remaining elements
        // in q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the name of the two queues
        std::queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
            return;
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

    bool empty()
    {
        return curr_size == 0;
    }
};

std::string boolToString(bool expression){
    std::string yes = "Yes";
    std::string no = "No";
    return expression ? yes : no;
}

int main(){
    std::cout << "I'm preparing a stack for you...\n";
    Stack s;
    std::cout << "I have a stack for you with " << s.size() << " integers in it.\n";
    std::cout << "How many integers are we pushing?\n";
    int numberToPush;
    std::cin >> numberToPush;
    if(numberToPush > 0){
        std::cout << "Cool.  You said we are going to push " << numberToPush << " integers onto your stack.\nLet's start.\n";
    } else {
        std::cout << "okay... if you want to be boring...  go ahead.\n";
    }
    std::vector<int> items;
    for( int count = 0; count < numberToPush; count++){
        std::cout << "Item number " << count + 1 << "? ";
        int item;
        std::cin >> item;
        items.push_back(item);
        s.push(item);
    }
    std::cout << "The stack now has size " << s.size() << "\n";
    std::cout << "Your items:\n";
    for ( auto i : items){
        std::cout << i << " ";
    }
    std::cout << "\nLet's start popping and comparing it to the reverse order of your numbers\n";

    int reverseCount = items.size();
    while (!s.empty()){
        int reverseEntry = items[reverseCount - 1];
        int topOfStack = s.top();
        std::cout << "Top of stack: " << topOfStack << " vs. reverse order of vector: " << reverseEntry << ". Same? ";
        std::cout << boolToString(topOfStack == reverseEntry) << "\n";
        s.pop();
        reverseCount--;
    }
    return 0;
}
