#include <lt_help/lt.h>

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
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


   
void test(ListNode *head)
{
    cout << "input: ";
    outputList(head);
    ListNode* r = Solution().insertionSortList(head);
    cout << "; output: ";
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
     test(makeList(5,-1,5,3,4,0));
}

// Result 
//
// 2022-11-21: Runtime 26ms 68.81% Memory 9.6MB 80.90%, https://leetcode.com/problems/insertion-sort-list/submissions/847477935/
// 2023-03-07: Runtime 20ms 69.63% Memory 9.6MB 46.1%, https://leetcode.com/problems/insertion-sort-list/submissions/910865865/


