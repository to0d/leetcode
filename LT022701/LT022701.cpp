#include <lt_help/lt.h>

class Solution {

public:

    int calculate(string s) {
        m_s = s;
        m_nPos = 0;
        m_nSize = s.size();
        nums = stack<int>();
        ops  = stack<char>();

        int nt = 0;
        while((nt = next()) != 0 || !ops.empty())
        {   if( nt == 1 )
            {   push_val( getNumber() );
                continue;
            }

            char op = (nt == 2 ? getOperator() : 0);           
            if( op == '(' || ops.empty() || getOpLevel( ops.top() ) < getOpLevel(op) )
            {   push_op(op);
                continue;
            }
            
            if( op == ')' )
            {   while( ops.top() != '(' )
                   compute();
                pop_op();
                continue;
            }
            
            while( !ops.empty() && getOpLevel(ops.top()) >= getOpLevel(op) )
                compute();
            
            if( op != 0)
               ops.push(op);
        }

        return nums.top();  
    }
    
    void compute(){
        int n1 = pop_val(), n2 = pop_val(), n3 = 0;
        switch (pop_op())
        {   case '+': n3 = n2 + n1; break;
            case '-': n3 = n2 - n1; break;
            case '*': n3 = n2 * n1; break;
            case '/': n3 = n2 / n1; break;
        }
        push_val(n3);;   
    }
    
    int pop_val(){
        int val = nums.top(); 
        nums.pop();
        return val;
    }
    
    char pop_op(){
        char op = ops.top(); 
        ops.pop();
        return op;
    }
    
    void push_val(int v){ nums.push( v );  }

    void push_op(char op){ ops.push( op ); }
    
    //  0: no token found
    //  1: number
    //  2: operator
    int next(){
        if( m_nPos >= m_nSize)
            return 0;

        char c = m_s[m_nPos];
        if( c == '+' ||  c == '-' ||  c == '*' ||  c == '/' ||  c == '(' ||  c == ')')
            return 2;

        if( c >= '0' && c <= '9')
            return 1;

        ++m_nPos; //ignore other characters
        return next();
    }
    
    char getOperator(){ return m_s[m_nPos++]; }
    
    int getOpLevel(char op) {   switch(op)
        {   case '+':
            case '-': return 10;
            case '*':
            case '/': return 20;
            case '(':
            case ')': return 0;
            default : return 0;
        }
    }
    
    int getNumber() {
        static char buffer[64] = {0};
        int len = 0, val = 0;
        for(char c = 0 ; m_nPos < m_nSize && (c = m_s[m_nPos]) >= '0' && c <= '9'; ++m_nPos)
            buffer[len++] = c;
        buffer[len] = 0;
        sscanf(buffer, "%d", &val);
        return val;
    }

private:

    stack<int> nums;
    stack<char> ops;
    string m_s;
    int m_nPos;
    int m_nSize;
};



void test(string s)
{
    cout << "input: " << s;
    int r = Solution().calculate(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("3+2*2");
    test(" 3/2 ");
    test(" 3+5 / 2 ");
}

// Result 
//
// 2022-11-19: Runtime 32ms 41.15% Memory 8.4MB 100%, https://leetcode.com/problems/basic-calculator-ii/submissions/846323854/
// 2023-02-20: Runtime 86ms 12.28% Memory 10.6MB 71.43%, https://leetcode.com/problems/basic-calculator-ii/submissions/901594075/



