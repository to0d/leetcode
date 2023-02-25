#include <lt_help/lt.h>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {        
        if( head == NULL || head->next == NULL )
            return head;
        
        ListNode *node = head, *last = NULL, *next, *tail;
        head = head->next;

        while( node != NULL && node->next != NULL )
        {   next = node->next;
            tail = next->next;
            next->next = node;
            node->next = tail;
            if( last != NULL )
                last->next = next;
            last = node;
            node = tail;
        }            

        return head;
    }
};


void test(ListNode* list)
{
    cout << "input: ";
    outputList(list);
    ListNode* out = Solution().swapPairs(list);
    cout << "; output: ";
    outputList(out);
    cout << endl;
}

int main(void)
{
    test(makeList(4,1,2,3,4));
}

// Result 
//
// 2022-11-07: Runtime 6ms 32.2% Memory 7.6MB 12.23%, https://leetcode.com/problems/swap-nodes-in-pairs/submissions/838727024/
// 2023-02-16: Runtime 3ms 65.17% Memory 7.5MB 61.26%, https://leetcode.com/problems/swap-nodes-in-pairs/submissions/899174288/

