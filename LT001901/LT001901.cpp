#include <lt_help/lt.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head, *p2 = head;
        for(int i = 1;i < n; ++i)
            p1 = p1->next;
        if( p1->next == NULL ) // remove head
            return head->next;
        p1 = p1->next;
        while( p1->next != NULL ){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};



void test(ListNode* list, int n)
{
    cout << "input: n=" << n << ", list=";
    outputList(list);
    ListNode* r = Solution().removeNthFromEnd(list, n);
    cout << "; output: ";
    outputList(r);
    cout << endl;
}

int main(void)
{
    test(makeList(7,1,2,3,4,5,6,7), 2);
}

// Result 
//
// 2022-11-03: Runtime 12ms 5.47% Memory 10.6MB 97.77%, https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/836100712/
// 2023-02-15: Runtime 3ms 85.55% Memory 10.8MB 38.75%, https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/898556763/
// 2023-03-05: Runtime 5ms 56.23% Memory 10.8MB 39.32%, https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/908988351/
// 2023-09-23: Runtime 0ms 100% Memory 10.62MB 5.31%%, https://leetcode.cn/problems/remove-nth-node-from-end-of-list/submissions/468968836/



