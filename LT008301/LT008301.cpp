#include <lt_help/lt.h>

class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while( cur!= NULL && cur->next != NULL )
        {   if( cur->next->val == cur->val )
            {   ListNode* next = cur->next;
                cur->next = next->next; 
                delete next;
            }
            else
                cur = cur->next;
        }

        return head;
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
    test(makeList(5, 1,1,2,3,3));
}

// Result 
//
// 2022-11-18: Runtime 15ms 29.55% Memory 11.7MB 9.50%, https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/845879870/
// 2023-02-18: Runtime 14ms 37.93% Memory 11.7MB 46.80%, https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/900100333/



