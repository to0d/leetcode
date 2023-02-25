#include <lt_help/lt.h>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pnew = NULL, *plast = NULL, *pnode = head;
        int dupCount = 0;
        while( pnode != NULL )
        {   if( pnode->next != NULL && pnode->val == pnode->next->val)
            {   dupCount++;
                ListNode* ptmp = pnode->next;
                pnode->next    = ptmp->next;
                delete ptmp;
            }
            else if( dupCount > 0 )
            {   ListNode* ptmp = pnode;
                pnode = pnode->next;
                dupCount = 0;
                delete ptmp;
            }
            else
            {   if( plast == NULL )
                {   plast = pnode;
                    pnew  = pnode;
                    pnode = pnode->next;
                }
                else
                {   plast->next = pnode;
                    plast = pnode;
                    pnode = pnode->next;
                }
                
                plast->next = NULL;
            }
        }

        return pnew;
    }
};



void test(ListNode* head)
{
    cout << "input: ";
    outputList(head); 
    ListNode* r = Solution().deleteDuplicates(head);
    cout << "; output: ";
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(5, 1,1,1,2,3));
}

// Result 
//
// 2022-11-18: Runtime 20ms 7.40% Memory 11.2MB 63.82%, https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
// 2023-02-18: Runtime 11ms 44.76% Memory 11.2MB 64.42%, https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/900101265/


