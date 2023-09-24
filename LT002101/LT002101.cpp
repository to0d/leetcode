#include <lt_help/lt.h>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode tmp, *l3 = &tmp;
        while(list1 != NULL || list2 != NULL) {
            if( list1!= NULL && (list2 == NULL || list1->val < list2->val) ){
                l3->next = list1;
                list1 = list1->next;
            } else {
                l3->next = list2;
                list2 = list2->next;
            }                
            l3 = l3->next;
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
// 2023-09-23: Runtime 4ms 92.10% Memory 14.57MB 5.03%, https://leetcode.cn/problems/merge-two-sorted-lists/submissions/468972132/


