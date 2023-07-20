#include <lt_help/lt.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode tmp, *cur = &tmp;
#define ADD_AND_MOVE(_v, _l) if( _l != NULL ) { _v += _l->val; _l = _l->next; }
        for(int val = 0; l1 != NULL || l2 != NULL || val > 0; val/= 10, cur = cur->next)
        {   ADD_AND_MOVE(val, l1);
            ADD_AND_MOVE(val, l2);
            cur->next = new ListNode(val%10);
        }
        return tmp.next;
    }
};


void test(ListNode* l1, ListNode* l2)
{
    cout << "input: l1="; 
    outputList(l1); 
    cout << ", l2="; 
    outputList(l2); 
    ListNode* r = Solution().addTwoNumbers(l1, l2);
    cout << "; output: ";  
    outputList(r); 
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(3, 2, 4, 3), makeList(3, 5, 6, 4));
}

// Result 
//
// 2023-02-06: Runtime 38ms 70.4% Memory 71.4MB 54.24%, https://leetcode.com/problems/add-two-numbers/submissions/892673320/
// 2023-03-04: Runtime 32ms 83.86% Memory 71.5MB 13.95%, https://leetcode.com/problems/add-two-numbers/submissions/908966730/
// 2023-07-20: Runtime 20 ms 91.57% Memory 69.7 MB 65.10%, https://leetcode.cn/submissions/detail/448563581/



