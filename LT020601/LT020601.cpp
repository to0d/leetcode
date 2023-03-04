#include <lt_help/lt.h>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while( head != NULL )
        {   ListNode* next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }
};



void test(ListNode* list)
{
    cout << "input: ";
    outputList(list);
    ListNode* r = Solution().reverseList(list);
    cout << "; output: ";
    outputList(r);
    cout << endl;
}

int main(void)
{
    test(makeList(5,1,2,3,4,5));
}

// Result 
//
// 2022-11-08: Runtime 16ms 7.21% Memory 8.3MB 85.70%, https://leetcode.com/problems/reverse-linked-list/submissions/839076376/
// 2023-02-16: Runtime 7ms 70.32% Memory 8.3MB 52.10%, https://leetcode.com/problems/reverse-linked-list/submissions/899179360/
// 2023-03-04: Runtime 7ms 68.67% Memory 8.4MB 51.79%, https://leetcode.com/problems/reverse-linked-list/submissions/908913536/


