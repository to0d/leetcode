#include <lt_help/lt.h>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if( head== NULL || head->next == NULL || m == n)
            return head;

        ListNode* pm(NULL), *pmp(NULL), *pn(NULL), *p(head), *p2(NULL);
        int i = 1;
        for(; i < m; ++i)
        {   pmp = p;
            p = p->next;
        }
        
        pm = p;
        pn = pm;
        p  = p->next;

        for(; i < n; ++i)
        {   p2 = p;
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


