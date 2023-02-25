#include <lt_help/lt.h>

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0 || head == NULL)
            return head;

        int count = 1;
        ListNode* ptail = head;
        while( ptail->next != NULL )
        {   count++;
            ptail = ptail->next;
        }

        if(k % count == 0 || count == 1)
            return head;

        ptail->next = head;
        k = count - k % count;

        for (int i = 0; i < k; ++i)
            ptail = ptail->next;

        head = ptail->next;
        ptail->next = NULL;
        return head;
    }
};



void test(ListNode* head, int k)
{
    cout << "input: head=";  
    outputList(head);
    cout << ", k=" << k;
    ListNode* r = Solution().rotateRight(head, k);
    cout << "; output: ";
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(5,1,2,3,4,5), 2);
}

// Result 
//
// 2022-11-18: Runtime 29ms 5.66% Memory 11.7MB 91.3%, https://leetcode.com/problems/rotate-list/submissions/845889318/
// 2023-02-18: Runtime 14ms 21.57% Memory 11.7MB 61.20%, https://leetcode.com/problems/rotate-list/submissions/900067880/

