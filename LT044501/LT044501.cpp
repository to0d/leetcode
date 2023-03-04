#include <lt_help/lt.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // refer LT000201.cpp
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *l3 = NULL, *cur = NULL;
        for(int v = 0; l1 != NULL || l2 != NULL  || v > 0; v /= 10)
        {   if( l1 != NULL )
            {   v += l1->val;
                l1 = l1->next;
            }
            if( l2 != NULL )
            {   v += l2->val;
                l2 = l2->next;
            }
            ListNode* pnew = new ListNode( v%10 );
            if( cur == NULL )
                l3 = pnew;
            else
                cur->next = pnew;
            cur = pnew;
        }
        return reverseList(l3);
    }

    ListNode* reverseList(ListNode* head) { // refer LT020601.cpp
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



void test(ListNode* l1, ListNode* l2)
{
    cout << "input: l1="; 
    outputList(l1); 
    cout << ", l2="; 
    outputList(l2);  
    ListNode* r = Solution().addTwoNumbers(l1, l2);
    cout << "; output: "; 
    outputList(r); 
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(4,7,2,4,3), makeList(3,5,6,4));
}

// Result 
//
// 2023-01-29: Runtime 43ms 54.3% Memory 71.1MB 87.55%, https://leetcode.com/problems/add-two-numbers-ii/submissions/887378957/
// 2023-03-04: Runtime 31ms 88.86% Memory 71.1MB 93.14%, https://leetcode.com/problems/add-two-numbers-ii/submissions/908970919/


