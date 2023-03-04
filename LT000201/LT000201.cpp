#include <lt_help/lt.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL, *cur = NULL;
        for(int v = 0; l1 != NULL || l2 != NULL  || v > 0; v /= 10)
        {   if( l1 != NULL )
            {   v += l1->val;
                l1 = l1->next;
            }
            if( l2 != NULL )
            {   v += l2->val;
                l2 = l2->next;
            }
            ListNode* pnew = new ListNode( v%10 );
            if( cur == NULL )
                l3 = pnew;
            else
                cur->next = pnew;
            cur = pnew;
        }
        return l3;
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



