#include <lt_help/lt.h>

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = NULL, *new_tail = NULL;
        
        while ( head != NULL)
        {   
            int len = 0;
            ListNode* tail = head;
            ListNode* sub_head = reverseList(head, k, len);

            if( len < k )
            {   sub_head = reverseList(sub_head, k, len);
                tail = NULL;
            }

            if( new_head == NULL )
            {   new_head = sub_head;
                new_tail = tail;
            }
            else
            {   new_tail->next = sub_head;
                new_tail = tail;
            }            
        }
        
        return new_head;
    }
    
    ListNode* reverseList(ListNode* &head, int k, int& len) {
        len = 0;
        ListNode* last = NULL;

        while( head != NULL && len < k)
        {   ListNode* next = head->next;
            head->next = last;
            last = head;              
            head = next;
            ++len;
        }
        return last;
    }
};



void test(ListNode* list, int k)
{
    cout << "input: list=";
    outputList(list);
    cout << ", k=" << k;
    ListNode* r = Solution().reverseKGroup(list, k);
    cout << "; output: ";
    outputList(r);
    cout << endl;
}

int main(void)
{
    test(makeList(5,1,2,3,4,5), 2);
}

// Result 
//
// 2022-11-08: Runtime 22ms 31.41% Memory 11.4MB 95.88%, https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/839092819/
// 2023-02-16: Runtime 16ms 73.73% Memory 11.6MB 36.46%, https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/899183238/



