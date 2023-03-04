#include <lt_help/lt.h>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if( head== NULL || head->next == NULL || m == n)
            return head;

        ListNode *pmp = NULL, *p = head;
        int pos = 1;
        for(; pos < m; ++pos)
        {   pmp = p;
            p = p->next;
        }
        
        ListNode* pm = p, *pn = p;
        p = p->next;
        for(; pos < n; ++pos)
        {   ListNode* p2 = p;
            p  = p->next;
            p2->next = pn;
            pn = p2;
        }

        pm->next = p;  

        if( pmp != NULL )
            pmp->next = pn;
        else
            head = pn;
           
        return head;
    }
};



void test(ListNode* list, int m, int n)
{
    cout << "input: list=";
    outputList(list);
    cout << ", m=" << m << ", n=" << n;
    ListNode* r = Solution().reverseBetween(list, m, n);
    cout << "; output: ";
    outputList(r);
    cout << endl;
}

int main(void)
{
    test(makeList(5,1,2,3,4,5), 2, 4);
}

// Result 
//
// 2022-11-08: Runtime 4ms 38.51% Memory 7.5MB 22.61%, https://leetcode.com/problems/reverse-linked-list-ii/submissions/839084341/
// 2023-02-18: Runtime 0ms 100% Memory 7.5MB 67.98%, https://leetcode.com/problems/reverse-linked-list-ii/submissions/900109551/
// 2023-03-05: Runtime 0ms 100% Memory 7.4MB 68.41%, https://leetcode.com/problems/reverse-linked-list-ii/submissions/909003328/


