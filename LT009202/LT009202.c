#include <lt_help/lt.h>

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    
    struct ListNode tmp, *last, *cur, *mstart, *mlast, *next;
    int i;
    
    if( m == n )
        return head;
    
    for(tmp.next = head, i = 0, cur=&tmp; i < m; ++i)
    {   last = cur;
        cur  = cur->next;
    }

    for(mstart = cur, mlast = last, last = NULL ; i <= n; ++i )
    {   next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }

    mlast->next = last;
    mstart->next = cur;
    return tmp.next;
}

void test(struct ListNode* list, int m, int n)
{
    printf("input: list=");
    outputList(list);
    printf(", m=%d, n=%d", m, n);
    struct ListNode* out = reverseBetween(list, m, n);
    printf("; output: ");
    outputList(out);
    printf("\n");
}

int main(void)
{
    test(makeList(5,1,2,3,4,5), 2, 4);
}

// Result 
//
// 2022-11-08: Runtime 3ms 47.79% Memory 6MB 41.91%, https://leetcode.com/problems/reverse-linked-list-ii/submissions/839085565/


