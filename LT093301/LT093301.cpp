#include <lt_help/lt.h>

struct RecentNode {
    int val;
    RecentNode *next;
    RecentNode() : val(0), next(nullptr) {}
    RecentNode(int x) : val(x), next(nullptr) {}
};

class RecentCounter {
public:
    RecentCounter() {
        ptail = &head;
        count = 0;
    }
    
    int ping(int t) { 
        ptail->next = new RecentNode(t);
        ptail=ptail->next;
        
        ++count;
        int low = t - 3000;
        while( head.next != ptail && head.next->val < low )
        {   RecentNode* tmp = head.next;
            head.next = head.next->next;
            --count;
            delete tmp;
        }

        return count;
    }
    
    RecentNode  head;
    RecentNode* ptail;
    int count;
};



int main(void)
{   cout << "output: done!" << endl;
}


// Result 
//
// 2022-12-22: Runtime 172ms 36.71% Memory 61.1MB 5.6%, https://leetcode.com/problems/number-of-recent-calls/submissions/863777439/
// 2023-02-25: Runtime 149ms 80.95% Memory 61MB 5.23%, https://leetcode.com/problems/number-of-recent-calls/submissions/904427914/



