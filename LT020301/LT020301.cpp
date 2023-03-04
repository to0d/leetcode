#include <lt_help/lt.h>

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode tmp(0);
        ListNode* tail = &tmp;
        for(; head != NULL; head = head->next)
            if( head->val != val )
            {   tail->next = head;
                tail = head;
            }

        tail->next = NULL;
        return tmp.next;
    }
};



void test(ListNode* head, int val)
{
    cout << "input: val=" << val << ", head=";
    outputList(head);
    ListNode* r = Solution().removeElements(head, val);
    cout << "; output: ";
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(7, 1,2,6,3,4,5,6), 6);
}

// Result 
//
// 2022-11-21: Runtime 29ms 40.55% Memory 15MB 52.89%, https://leetcode.com/problems/remove-linked-list-elements/submissions/847505150/
// 2023-02-22: Runtime 23ms 77.76% Memory 15.1MB 53.46%, https://leetcode.com/problems/remove-linked-list-elements/submissions/902717957/
// 2023-03-04: Runtime 24ms 72.76% Memory 14.9MB 85.1%, https://leetcode.com/problems/remove-linked-list-elements/submissions/908952336/



