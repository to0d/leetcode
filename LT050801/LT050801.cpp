#include <lt_help/lt.h>




class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        m_map.clear();
        _findSum(root);
        vector<int> rst;
        for(auto e : m_map )
        {   if( e.second == m_maxCount)
                rst.push_back(e.first);
        }
        std::sort(rst.begin(), rst.end());
        return rst;
    }
    
    int _findSum(TreeNode* node)
    {   int sum = node->val, count = 0;
        if( node->left != NULL )
            sum += _findSum(node->left);
        if( node->right != NULL )
            sum += _findSum(node->right);        
        auto it = m_map.find(sum);
        if( it != m_map.end() )
            count = it->second;
        count++;
        m_map[sum] = count;
        m_maxCount = std::max(m_maxCount, count);
        return sum;
    }

    unordered_map<int,int> m_map;
    int m_maxCount = 0;
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<int> r = Solution().findFrequentTreeSum(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,2,-3}"));
}

// Result 
//
// 2023/01/08
//      Runtime24 ms Beats 68.17% Memory24.7 MB Beats 48.29%

