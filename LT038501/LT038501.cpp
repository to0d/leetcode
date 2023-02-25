#include <lt_help/lt.h>




// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class Solution {
public:
    NestedInteger deserialize(string s) {
        m_p = s.c_str();
        return _nextNested();
    }
    
    NestedInteger _nextNested() 
    {   
        char c = *m_p;
        bool isNested = false, hasVal = false;
        int val;
        // cout << "_nextNested=" << string(m_p, strlen(m_p)) << ", c=" << c << endl;
        
        if( c == '[' )
        {   ++m_p; 
            isNested = true;
        }        
        
        if( _isNum(*m_p) )
        {   val = _nextVal();
            hasVal = true;
        }
        
        NestedInteger nested;

        if( !isNested )
        {   if( hasVal )
                nested.setInteger(val);
        }
        else
        {
            if( hasVal )
                nested.add(NestedInteger(val));

            while( (c = *(m_p++)) != 0)
            {   if( c == ',' )
                    nested.add(_nextNested());
                else if( c == '[' )
                {   --m_p;
                    nested.add(_nextNested());
                }
                else
                    break;
            }
        }

        return nested;
    }
    
    int _nextVal()
    {   const char* p2 = m_p;
        char c;
        while( (c = *p2) != 0 && _isNum(c) )
            ++p2;
        if( m_p == p2 )
            return 0;
        int val = std::stoi(string(m_p, p2-m_p));
        m_p = p2;
        //cout << "p2=" << string(p2, strlen(p2)) << ", val=" << val << endl;
        return val;
    }
    
    bool _isNum(char c)
    {   return (c >= '0' && c <= '9') || c == '-';
    }
    
    const char* m_p;
};



int main(void)
{
    cout << "output: done!" << endl;
}

// Result 
//
// 2023-01-05: Runtime 19ms 38% Memory 12.4MB 48%, https://leetcode.com/problems/mini-parser/submissions/872004020/


