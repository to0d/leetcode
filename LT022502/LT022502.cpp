#include <lt_help/lt.h>



class MyStack {
public:
    MyStack() : mi(0){}; 

    void push(int x) {
        
        queue<int>& a = mQueue[mi];
        queue<int>& b = mQueue[ (mi+1)%2 ];
        
        b.push(x);
        while( !a.empty() )
        { 
            b.push(a.front());
            a.pop();
        }
        
        mi = (mi+1)%2;
    }

    int pop() {
        int val = mQueue[mi].front();
        mQueue[mi].pop();
        return val;
    }

    int top() {
        return mQueue[mi].front();
    }

    bool empty() {
        return mQueue[mi].empty();
    }

    queue<int> mQueue[2];
    int mi;
};


int main(void)
{   cout << "output: done!" << endl;
}


// Result 
//
// 2022-12-26: Runtime 0ms 100% Memory 6.9MB 38.56%, https://leetcode.com/problems/implement-stack-using-queues/submissions/865522779/


