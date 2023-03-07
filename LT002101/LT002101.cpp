#include <lt_help/lt.h>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tmp(0);
        ListNode* l3 = &tmp;
        while( l1 != NULL && l2 != NULL )
        {   ListNode** pmin = (l1->val < l2->val) ? &l1 : &l2;
            l3->next = *pmin;
            l3       = l3->next;
            *pmin    =(*pmin)->next;
        }
        l3->next= (l1==NULL)? l2 : l1;
        return tmp.next;
    }
};



void test(ListNode* l1, ListNode* l2)
{
    cout << "input: l1=";
    outputList(l1);
    cout << ", l2=";
    outputList(l2);
    ListNode* r = Solution().mergeTwoLists(l1, l2);
    cout << "; output: ";
    outputList(r);
    cout << endl;
}

int main(void)
{
    test(makeList(3,1,2,4), makeList(3,1,3,4));
}

// Result 
//
// 2022-11-05: Runtime 16ms 15.3% Memory 14.7MB 85.44%, https://leetcode.com/problems/merge-two-sorted-lists/submissions/837402697/
// 2023-02-15: Runtime 5ms 81.79% Memory 14.8MB 48.84%, https://leetcode.com/problems/merge-two-sorted-lists/submissions/898563575/
// 2023-03-04: Runtime 4ms 92.58% Memory 14.8MB 49.9%, https://leetcode.com/problems/merge-two-sorted-lists/submissions/908898927/


