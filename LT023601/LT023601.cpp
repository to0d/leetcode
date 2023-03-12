#include <lt_help/lt.h>

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode*> path1, path2;
        TreeNode* ancestor;
        visit(root, p, q, path1, path2, &ancestor);
        return ancestor;
    }

    bool visit(TreeNode* node, TreeNode* t1, TreeNode* t2, vector<TreeNode*>& path1, vector<TreeNode*>& path2, TreeNode** ancestor) {  
        if( node == NULL )
            return false;
        path1.push_back(node);
        if( node == t1 || node == t2)
        {   if( path2.size() == 0 )
                std::copy(begin(path1), end(path1), back_inserter(path2));
            else
            {   int size = std::min(path1.size(), path2.size());
                for(int i = 0; i < size && path1[i] == path2[i]; ++i)   // find common ancestor from root node
                    *ancestor = path1[i];
                return true;
            }
        }
        if( visit(node->left, t1, t2, path1, path2, ancestor) || visit(node->right, t1, t2, path1, path2, ancestor) )
            return true;
        path1.pop_back();
        return false;
    }
};



void test(TreeNode* root, TreeNode* p, TreeNode* q)
{
    cout << "input: root=";
    outputTree(root);
    cout << ", p=" << p->val << ", q=" << q->val;
    TreeNode* r = Solution().lowestCommonAncestor(root, p, q);
    cout << "; output: " ;
    if( r == NULL )
        cout << "null" ;
    else
        cout << r->val ;
    cout << ";" << endl;
}


int main(void)
{
    TreeNode* tree = makeTree("{3,5,1,6,2,0,8,null,null,7,4}");
    test(tree, findNode(tree, 5), findNode(tree, 1));
}

// Result 
//
// 2022-11-23: Runtime 34ms 14.43% Memory 16.8MB 13.45%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/848485979/
// 2023-02-22: Runtime 29ms 14.15% Memory 16.6MB 13.89%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/902723471/
// 2023-03-12: Runtime 12ms 94.34% Memory 18.5MB 6.10%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/913837864/


