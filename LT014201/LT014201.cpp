#include <lt_help/lt.h>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* join = hasCycle (head);
        if( join == NULL ) return NULL;
        if( join == head ) return head;

        int m = reverseList(head);
        int n = 1;
        for(ListNode* cur = join; cur->next != join; cur = cur->next)
            ++n;

        int x = (m-n)/2;
        for( join = head; x > 0 ; --x)
             join = join->next;

        reverseList(head);
        return join;
    }
    
    ListNode* hasCycle(ListNode *head){
        if( head == NULL || head->next == NULL) return NULL;
        if( head == head->next ) return head;

        ListNode* slow = head, *fast = head->next;
        while( fast != NULL && slow != NULL && fast->next != NULL )
        {   if( fast == slow )
            {   return fast;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return NULL;
    }
    
    int reverseList(ListNode* head) {
        int count = 0;
        ListNode* last = NULL;
        while( head != NULL )
        {   ListNode* next = head->next;
            head->next = last;
            last = head;
            head = next;
            ++count;
        }
        return count;
    }
};



void test(ListNode *head)
{
    printf("input: ");
    outputList(head);
    ListNode* r = Solution().detectCycle(head);
    printf("; output: ");
    outputList(r);
    printf(";\n");
}

int main(void)
{
     test(makeList(4,3,2,0,-4));
}

// Result 
//
// 2022-11-21: Runtime 5ms 80.7% Memory 7.3MB 24.2%, https://leetcode.com/problems/linked-list-cycle-ii/submissions/847476063/
// 2023-02-20: Runtime 8ms 77.35% Memory 7.7MB 29.6%, https://leetcode.com/problems/linked-list-cycle-ii/submissions/901627288/


