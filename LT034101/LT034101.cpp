#include <lt_help/lt.h>


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        pNestedInteger = NULL;
        indexStack.push(-1);
        listStack.push(&nestedList);
    }

    int next() {       
        int val = pNestedInteger->getInteger();
        pNestedInteger = NULL;
        return val;
    }

    bool hasNext() {
        while(pNestedInteger == NULL && !indexStack.empty())
        {   vector<NestedInteger>* pList = listStack.top();
            int index = indexStack.top();
            indexStack.pop();
            ++index;

            if( index<(*pList).size())
            {   indexStack.push( index );
                NestedInteger* pNextedList = &(*pList)[index];
                if( (*pNextedList).isInteger() )
                   pNestedInteger = pNextedList;
                else
                {
                    indexStack.push( -1 );
                    listStack.push(&(pNextedList->getList()));
                }
            }
            else
               listStack.pop();
        }
        return pNestedInteger != NULL;
    }

    stack<vector<NestedInteger>*> listStack;
    stack<int> indexStack;
    NestedInteger* pNestedInteger;
};



int main(void)
{   cout << "output: done" << endl;
}


// Result 
//
// 2022-12-05: Runtime 37ms 11.57% Memory 12.8MB 97.96%, https://leetcode.com/problems/flatten-nested-list-iterator/submissions/855081948/
// 2023-02-27: Runtime 11ms 97.4% Memory 13MB 73.79%, https://leetcode.com/problems/flatten-nested-list-iterator/submissions/905735917/




