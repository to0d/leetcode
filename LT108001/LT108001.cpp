#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        vector<TreeNode*> path;
        unordered_set<TreeNode*> hits;
        _sufficientSubset1(root, path, hits, 0, limit, 0);
        return _sufficientSubset2(root, hits);
    }
   
    void _sufficientSubset1(TreeNode* node, vector<TreeNode*>& path, unordered_set<TreeNode*>& hits, int len, int limit, int sum) {
        if( path.size() == len )
            path.push_back(node);
        else
            path[len] = node;
        
        len++;
        sum += node->val;

        if( node->left == NULL && node->right == NULL )
        {   if( sum < limit )
            {   for(int i = 0;i < len; ++i)
                    hits.insert(path[i]);
            }
            return;
        }
        
        if ( node->left != NULL )
            _sufficientSubset1(node->left, path, hits, len, limit, sum);

        if ( node->right != NULL )
            _sufficientSubset1(node->right, path, hits, len, limit, sum);
    }
    
    TreeNode* _sufficientSubset2(TreeNode* node, unordered_set<TreeNode*>& hits) {
        if ( node->left != NULL )
             node->left = _sufficientSubset2(node->left, hits);
        
        if ( node->right != NULL )
             node->right = _sufficientSubset2(node->right, hits);

        int childCount = 0, childHit = 0;
        if( node->left != NULL )
        {   childCount++;
            if( hits.count(node->left) != 0 )
                childHit++;
        }

        if( node->right != NULL )
        {   childCount++;
            if( hits.count(node->right) != 0 )
                childHit++;
        }
        
        if( (childCount > 0 && childCount == childHit) || (childCount == 0 && hits.count(node) != 0))
            return NULL;
        
        if( childCount > 0 )
            hits.erase(node);

        return node;
    }
};



void test(TreeNode* root, int limit)
{
    cout << "input: limit=" << limit << ", tree=";
    outputTree(root);   
    TreeNode* r = Solution().sufficientSubset(root, limit);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14}"), 1);
}

// Result 
//
// 2023-01-31: Runtime 59ms 24.71% Memory 35.6MB 5.2%, https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/submissions/888831303/
// 2023-02-18: Runtime 61ms 21.32% Memory 35.5MB 5.4%, https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/submissions/900116010/


