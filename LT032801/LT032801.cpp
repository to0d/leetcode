#include <lt_help/lt.h>

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL || head->next == NULL)
            return head;
        
        ListNode *pNew  = head, *pEven = head, *pOdd  = head->next;
        head = head->next->next;
        int i = 3;
        while( head != NULL )
        {   ListNode* pNode = head;
            head = head->next;
            if( i++ % 2 !=0 )   //even nodes
            {   pNode->next = pEven->next;
                pEven->next = pNode;
                pEven = pNode;
            }
            else    // odd notes
            {   pOdd->next = pNode;
                pOdd = pNode;
            }
        }
        
        pOdd->next = NULL;
        return pNew;
    }
};



void test(ListNode* head)
{
    cout << "input: ";
    outputList(head);
    ListNode* r = Solution().oddEvenList(head);
    cout << "; output: "; 
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(7,2,1,3,5,6,4,7));
}


// Result 
//
// 2022-11-16: Runtime 30ms 6.84% Memory 10.5MB 37.68%, https://leetcode.com/problems/odd-even-linked-list/submissions/844628950/
// 2023-02-22: Runtime 12ms 65.61% Memory 10.6MB 39.10%, https://leetcode.com/problems/odd-even-linked-list/submissions/902747991/



