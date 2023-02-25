#include <lt_help/lt.h>




class Solution {
public:

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
     
        vector<vector<int>> res;        
        if( root != NULL ) 
            findPathSum(root, sum, 0, res);  
        
        return res;
    }
    
    void findPathSum(TreeNode* node, int sum, int len, vector<vector<int>>& res)
    {
        path[len] = node->val;
        sum -= node->val;
        
        if( node->left == NULL && node->right == NULL && sum == 0)
        {   res.push_back(vector<int>(path, path+len+1));
            return;
        }

        if( node->left != NULL )
            findPathSum(node->left, sum, len + 1, res);
        
        if( node->right != NULL )
            findPathSum(node->right, sum, len + 1, res);
    }
    
private:
    int path[1024];
};
    

void test(TreeNode* root, int sum)
{
    cout << "input: ";
    outputTree(root);
    vector<vector<int>> r = Solution().pathSum(root, sum);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,4,8,11,null,13,4,7,2,null,null,5,1}"), 22);
}

// Result 
//
// 2022-11-23: Runtime 13ms 60.91% Memory 20MB 60.57%, https://leetcode.com/problems/path-sum-ii/submissions/848473201/


