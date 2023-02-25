#include <lt_help/lt.h>

class Solution {
public:
    bool hasCycle(ListNode *head){
        if( head == NULL || head->next == NULL) return false;
        if( head == head->next ) return true;

        ListNode* slow = head, *fast = head->next;
        while( fast != NULL && slow != NULL && fast->next != NULL )
        {   if( fast == slow )
            {   return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};



void test(ListNode *head)
{
    cout << "input: ";
    outputList(head);
    bool r = Solution().hasCycle(head);
    cout << "; output: " << r << endl;
}

int main(void)
{
     test(makeList(4,3,2,0,-4));
}

// Result 
//
// 2022-11-21: Runtime 16ms 28.9% Memory 8.1MB 48.12%, https://leetcode.com/problems/linked-list-cycle/submissions/847472985/
// 2023-02-20: Runtime 11ms 70.86% Memory 8.1MB 77.85%, https://leetcode.com/problems/linked-list-cycle/submissions/901626379/
