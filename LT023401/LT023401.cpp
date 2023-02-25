#include <lt_help/lt.h>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( head == NULL || head->next == NULL ) 
            return true;
        if( head->next->next == NULL ) 
            return head->val == head->next->val;
        
        ListNode *fast = head, *node = head, *next = node->next;
        while( fast->next != NULL && fast->next->next != NULL) 
        {   fast = fast->next->next;
            ListNode* temp = next->next;
            next->next = node;
            node = next;
            next = temp;
        }
        head->next = NULL;

        ListNode *h1 = node, *h2 = next;
        if( fast->next == NULL )  // odd list:
            h1 = h1->next;

        bool found = false;
        for(; !found && h1 != NULL; h1 = h1->next, h2 = h2->next)
        {   if( h1->val != h2->val )
                found = true;
        }

        return !found;
    }
};



void test(ListNode* head)
{
    cout << "input: ";
    outputList(head);
    cout << "; output: "; 
    bool r = Solution().isPalindrome(head);
    cout << r << ";" << endl;
}


int main(void)
{
    test(makeList(4,1,2,2,1));
}

// Result 
//
// 2022-11-19: Runtime 465ms 13.24% Memory 110.4MB 95.74%, https://leetcode.com/problems/palindrome-linked-list/submissions/846338425/
// 2023-02-19: Runtime 187ms 98.63% Memory 110.4MB 98.3%, https://leetcode.com/problems/palindrome-linked-list/submissions/900662250/


