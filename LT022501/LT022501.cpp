#include <lt_help/lt.h>

class MyStack {
public:
    MyStack() {}

    void push(int x) {
        int size = mqueue.size();
        mqueue.push(x);
        while( size-- > 0 )
        {   mqueue.push(mqueue.front());
            mqueue.pop();
        }
    }

    int pop() {
        int val = mqueue.front();
        mqueue.pop();
        return val;
    }

    int top() {
        return mqueue.front();
    }

    bool empty() {
        return mqueue.empty();
    }
    
    queue<int> mqueue;
};


int main(void)
{   cout << "output: done!" << endl;
}


// Result 
//
// 2022-12-26: Runtime 4ms 34.30% Memory 7MB 38.56%, https://leetcode.com/problems/implement-stack-using-queues/submissions/865520987/



