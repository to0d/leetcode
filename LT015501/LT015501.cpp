#include <lt_help/lt.h>

class MinStack {
public:
    void push(int x) {
        valueStack.push(x);
        if( minStack.empty() || minStack.top() > x )
            minStack.push(x);
        else
            minStack.push(minStack.top());
    }

    void pop() {
        if( !valueStack.empty() )
        {   valueStack.pop();
            minStack.pop();
        }
    }

    int top() {      
        return valueStack.top();
    }

    int getMin() {
        return minStack.top();
    }

    stack<int> valueStack;
    stack<int> minStack;
};


int main(void)
{   cout << "output: done" << endl;
}


// Result 
//
// 2022-12-06: Runtime 68ms 8.68% Memory 16.2MB 99.3%, https://leetcode.com/problems/min-stack/submissions/855117327/
// 2023-03-12: Runtime 21ms 79.34% Memory 16.2MB 99.13%, https://leetcode.com/problems/min-stack/submissions/913865044/



