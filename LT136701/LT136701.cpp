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
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> depths;
        _findTarget(root, nodes, depths, head->val);
        int size = nodes.size(), listSize = 0;
        travelList(head, listSize);
        for(int i = 0;i < size; ++i)
            if( depths[i] >= listSize && _isSubPath(head, nodes[i]) )
                return true;
        return false;
    }

    bool _isSubPath(ListNode* head, TreeNode* node) {
        if( head == NULL )
            return true;
        if( node == NULL || node->val != head->val)
            return false;
        return _isSubPath(head->next, node->left) || _isSubPath(head->next, node->right);
    }

    int _findTarget(TreeNode* node, vector<TreeNode*>& nodes, vector<int>& deeps, int target) {   
        if( node == NULL )
            return 0;

        int deepIdx = -1;
        if( node->val == target )
        {   deepIdx = deeps.size();
            nodes.push_back(node);
            deeps.push_back(0);
        }
                
        int ld = _findTarget(node->left, nodes, deeps, target);
        int rd = _findTarget(node->right, nodes, deeps, target);
        int deep = std::max(ld, rd) + 1;
        if( deepIdx != -1 )
            deeps[deepIdx] = deep;
        return deep;
    }
};



void test(ListNode* head, TreeNode* root)
{
    cout << "input: list=";
    outputList(head);
    cout << ", tree=";
    outputTree(root);
    bool r = Solution().isSubPath(head, root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeList(3,4,2,8), makeTree("{1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3}"));
}

// Result 
//
// 2023-01-14: Runtime 31ms 88.87% Memory 33MB 6.10%, https://leetcode.com/problems/linked-list-in-binary-tree/submissions/877779071/
// 2023-03-08: Runtime 32ms 85.47% Memory 33MB 7.38%, https://leetcode.com/problems/linked-list-in-binary-tree/submissions/910931133/



