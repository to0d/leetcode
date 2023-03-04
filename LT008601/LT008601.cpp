#include <lt_help/lt.h>

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if( head == NULL )
            return NULL;
        
        // find x node
        ListNode *xparent = NULL, *xnode = NULL;
        for(ListNode *pnode = head, *parent = NULL; pnode != NULL; parent = pnode, pnode = pnode->next)
        {   if( pnode->val >= x )
            {   xparent = parent;
                xnode   = pnode;
                break;
            }
        }
        
        if( xnode == NULL )
            return head;
        
        // find node which's value is smaller than x
        ListNode *smallHead = NULL, *smallTail = NULL, *pnode = xnode;
        while( pnode != NULL )
        {   if( pnode->next != NULL && pnode->next->val < x )
            {   if( smallTail == NULL )
                {   smallTail = pnode->next;                    
                    pnode->next = smallTail->next;
                    smallTail->next = NULL;
                    smallHead = smallTail;
                }
                else
                {   smallTail->next = pnode->next;
                    smallTail = smallTail->next;
                    pnode->next = smallTail->next;
                    smallTail->next = NULL;
                }
            }
            else
                pnode = pnode->next;
        }
        
        if( smallTail == NULL )
            return head;

        if( xparent == NULL )
        {   smallTail->next = head;
            return smallHead;
        }
        else
        {   xparent->next = smallHead;
            smallTail->next = xnode;
            return head;
        }
    }
};



void test(ListNode* head, int x)
{
    cout << "input: x=" << x << ", list="; 
    outputList(head); 
    ListNode* r = Solution().partition(head, x);
    cout << "; output: ";  
    outputList(r); 
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(6,1,4,3,2,5,2), 3);
}

// Result 
//
// 2023-02-01: Runtime 11ms 24.60% Memory 10.3MB 77.20%, https://leetcode.com/problems/partition-list/submissions/889442610/
// 2023-03-05: Runtime 4ms 77.18% Memory 10.2MB 94.85%, https://leetcode.com/problems/partition-list/submissions/909000764/


