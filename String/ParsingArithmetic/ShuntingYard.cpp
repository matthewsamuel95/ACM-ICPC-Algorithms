#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>

using namespace std;

// precedences
map<char, int> prec{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

// handles +, -, *, / and parentheses
// only handles single digit, positive numbers for simplicity
int shuntyard(stringstream& ss) {
    char c;
    queue<char> output;
    stack<char> ops;
    while (ss >> c) {
        if (isdigit(c)) {
            output.push(c);
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.top() != '(') {
                output.push(ops.top());
                ops.pop();
            }
            ops.pop();
        } else {
            assert(c == '+' || c == '-' || c == '*' || c == '/');
            while (!ops.empty() && (ops.top() != '(' && prec[ops.top()] >= prec[c])) {
                output.push(ops.top());
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) {
        assert(ops.top() != '(' && ops.top() != ')');
        output.push(ops.top());
        ops.pop();
    }
    
    stack<int> st;
    while (!output.empty()) {
        c = output.front();
        output.pop();
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int x, y;
            y = st.top(); st.pop();
            x = st.top(); st.pop();
            if (c == '+') {
                st.push(x + y);
            } else if (c == '-') {
                st.push(x - y);
            } else if (c == '/') {
                st.push(x / y);
            } else {
                st.push(x * y);
            }
        }
    }
    return st.top();
}

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    int val = shuntyard(ss);
    cout << input << " = " << val << endl;
    return 0;
}
