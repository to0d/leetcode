#include <lt_help/lt.h>

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if( head == NULL )
            return NULL;

        ListNode* pHead(head), *pTail(head), *pNode(NULL), *pLast(NULL);         
        head = head->next; 

        while( (pNode = head) != NULL)
        {   head = head->next;
            if( pNode->val >= pTail->val ) // optimize a
            {   pTail->next = pNode;
                pTail = pNode;
            } 
            else if( pNode->val <= pHead->val )
            {   pNode->next = pHead;
                pHead = pNode;
            }
            else
            {   ListNode* pNode2 = (pLast != NULL) && ( pNode->val > pLast->val ) ? pLast : pHead; // optimize b
                while( pNode2 != pTail && pNode2->next->val < pNode->val)
                    pNode2 = pNode2->next; 
                pNode->next = pNode2->next;
                pNode2->next = pNode;
            }

            pLast= pNode;
        }
        
        pTail->next = NULL;
        return pHead;
    }
};



void test(ListNode* head)
{
    cout << "input: ";
    outputList(head);    
    ListNode* r = Solution().sortList(head);
    cout << "; output: "; 
    outputList(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeList(4,4,2,1,3));
}

// Result 
//
// 2022-11-19: Runtime 754ms 5.7% Memory 51MB 90.14%, https://leetcode.com/problems/sort-list/submissions/846346693/
// 2023-02-17: Runtime 481ms 6.59% Memory 50.8MB 98.35%, https://leetcode.com/problems/sort-list/submissions/899801185/

