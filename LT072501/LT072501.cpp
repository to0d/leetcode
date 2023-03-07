#include <lt_help/lt.h>

ListNode* travelList(ListNode *head, int& len) { // refer LT006101.cpp
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> rst;
        int size = 0;
        travelList(head, size);

        int size2 = size/k;
        int add   = size - size2*k;
        for(int i = 0; i < k ; ++i )
        {   int size3 = size2;
            if( i < add )
                size3++;
            rst.push_back(head);
            ListNode* last = NULL;
            for(int j = 0; head!= NULL && j < size3 ; ++j)
            {   last = head;
                head = head->next;
            }
            if( last != NULL )
                last->next = NULL;
        }

        rst.resize(k);
        return rst;
    }
};



void test(ListNode* head, int k)
{
    cout << "input: k=" << k << ", list="; 
    outputList(head); 
    vector<ListNode*> r = Solution().splitListToParts(head, k);
    cout << "; output: ";  
    outputList(r); 
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(10, 1,2,3,4,5,6,7,8,9,10), 3);
}

// Result 
//
// 2023-01-18: Runtime 8ms 74.51% Memory 9.1MB 8.36%, https://leetcode.com/problems/split-linked-list-in-parts/submissions/880422266/
// 2023-03-07: Runtime 4ms 94.23% Memory 8.9MB 65.27%, https://leetcode.com/problems/split-linked-list-in-parts/submissions/910919290/


