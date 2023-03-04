#include <lt_help/lt.h>

ListNode* travelList(ListNode *head, int& len) {
    len = 0;
    ListNode *tail = head;
    if( tail == NULL )
        return NULL;
    for(++len; tail->next != NULL; tail = tail->next)
        ++len;
    return tail;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0 || head == NULL)
            return head;
        
        int count = 0;
        ListNode* tail = travelList(head, count);
        if(k % count == 0 || count == 1)
            return head;

        tail->next = head;
        k = count - k % count ;
        for (int i = 0; i < k; ++i)
            tail = tail->next;

        head = tail->next;
        tail->next = NULL;
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
// 2023-03-05: Runtime 3ms 97.47% Memory 11.7MB 61.29%, https://leetcode.com/problems/rotate-list/submissions/908995795/

