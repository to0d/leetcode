#include <lt_help/lt.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        while( n-- > 0 )
            node = node->next;

        if( node == NULL )
            return head->next;
        
        ListNode* previous = head;
        for( ; node->next != NULL; node = node->next)
            previous = previous->next;

        ListNode* tmp = previous->next;
        previous->next = previous->next->next;
        delete tmp;
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



