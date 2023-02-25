#include <lt_help/lt.h>



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> rst;
        for(ListNode* node = head; node != NULL; node = node->next )
            rst.push_back(node);
        int size  = rst.size();
        int size2 = size/k;
        int add   = size - size2*k;
        int pos   = 0;
        for(int i = 0; i < k && i < size && pos < size; ++i)
        {   //cout << "i=" << i << ", pos=" << pos << endl;
            if( pos > 0 )
                rst[pos-1]->next = NULL;
            rst[i] = rst[pos];
            pos += size2;
            if( i < add )
                pos++;
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


