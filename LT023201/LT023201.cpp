#include <lt_help/lt.h>



class MyQueue {
public:
    void push(int x) {
        m_tailStack.push(x);
    }

    int pop(void) {
        if(m_frontStack.empty())
            move();
        int val = m_frontStack.top();
        m_frontStack.pop();
        return val;
    }

    int peek(void) {
        if(m_frontStack.empty())
            move();
        return m_frontStack.top();
    }

    bool empty(void) {     
        return m_tailStack.empty() && m_frontStack.empty();
    }
    
private:
    void move()
    {   while(!m_tailStack.empty())
        {   m_frontStack.push( m_tailStack.top());
            m_tailStack.pop();
        }
    }
    stack<int> m_tailStack;
    stack<int> m_frontStack;
};


int main(void)
{   cout << "output: done!" << endl;
}


// Result 
//
// 2022-12-26: Runtime 0ms 100% Memory 7.1MB 43.29%, https://leetcode.com/problems/implement-queue-using-stacks/submissions/865524170/



