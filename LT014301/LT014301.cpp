#include <lt_help/lt.h>

class Solution {
public:
    void reorderList(ListNode* head) {
        if( head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        ListNode *mid = head, *node = head, *head2 = NULL;
        for(int i = 0; node->next != NULL ; node = node->next )
            if( ++i % 2 == 0 )
                mid = mid->next;

        node = mid->next;
        mid->next = NULL;
        while( node != NULL)
        {   ListNode *temp = node;
            node = node->next;
            temp->next = head2;
            head2 = temp;
        }

        node = head;
        while( head2 != NULL)
        {   ListNode *temp = head2;
            head2 = head2->next;
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        }
    }
};



void test(ListNode* head)
{
    cout << "input: ";
    outputList(head); 
    Solution().reorderList(head);
    cout << "; output: ";
    outputList(head);
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(5, 1,2,3,4,5));
}

// Result 
//
// 2022-11-16: Runtime 92ms 17% Memory 17.7MB 78.13%, https://leetcode.com/problems/reorder-list/submissions/844613856/
// 2023-02-19: Runtime 38ms 92.12% Memory 17.8MB 51.50%, https://leetcode.com/problems/reorder-list/submissions/900659693/



