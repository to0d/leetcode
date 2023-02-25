#include <lt_help/lt.h>

int diff_vec(const vector<int>& a, int a_size, const vector<int>& b, int b_size){  
    int size = std::min(a_size, b_size), d = 0;
    for(int i = 0; d == 0 && i < size; ++i)
        d = b[i] - a[i];
    if( d == 0 )
        d = b_size - a_size;
    return d;
}

bool less_vec(const vector<int>& a, const vector<int>& b){   
    return diff_vec(b, b.size(), a, a.size()) < 0;
}

bool compare_vec(const vector<int>& a, const vector<int>& b){
    int size = std::min(a.size(), b.size());
    return diff_vec(b, size, a, size) < 0;
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end(), std::less<int>());
        vector<int> path;
        vector<vector<int>> result;
        find(candidates, 0, target, path, result);        
        return result;
    }
  
    void find(vector<int>& candidates, int index, int target, vector<int>& path, vector<vector<int>>& result){
        if( target == 0 )
        {   result.push_back(path);    
            std::sort(result.begin(), result.end(), less_vec);
            return;
        }

        int size = candidates.size();
        if( index == size || target < 0)
            return;

        int value = candidates[index];
        if( target >= value )
        {   path.push_back(value);            
            if( !std::binary_search(result.begin(), result.end(), path, compare_vec) )
            {
                // find(candidates, index, target-value, path, result);  // LT0039, element can be used multi-times
                find(candidates, index+1, target-value, path, result);   // LT0040, element can only be used once
            }
            path.pop_back();
        }

        find(candidates, index+1, target, path, result);
    }
};

void test(vector<int> candidates, int target)
{
    cout << "input: candidates=";
    outputVector(candidates);
    cout << ", target=" << target << "; output: ";
    vector<vector<int>> r = Solution().combinationSum2(candidates, target);
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({10,1,2,7,6,1,5}, 8);
}


// Result 
//
// 2022-11-16: Runtime 11ms 36.72% Memory 13.5MB 20.10%, https://leetcode.com/problems/combination-sum-ii/submissions/844563344/
//class Solution {
//public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
//     {
//        std::sort(candidates.begin(), candidates.end());
//        values.clear();
//        nums.clear();
//        result.clear();
//        path.clear();
//
//        int lastVal = -1;
//        int num = 0;
//        for( int v : candidates )
//        {  if( v != lastVal )
//            {   if( num > 0 )
//                {   values.push_back(lastVal);
//                    nums.push_back(num);
//                }
//                num = 1;
//                lastVal = v;
//            }
//            else
//            {   ++num;
//            }            
//        }
//         
//        if( num > 0 )
//        {   values.push_back(lastVal);
//            nums.push_back(num);
//        }
//
//        // std::copy( values.begin(), values.end(), ostream_iterator<int>(cout, ","));
//        // std::cout << endl;
//        // std::copy( nums.begin(), nums.end(), ostream_iterator<int>(cout, ","));
//        // std::cout << endl;
//
//        find(target, values.size()-1);
//        return result;
//    }
//     
//     void find( int target, int k) 
//     {
//         // cout << "target" << target << ", k" << k << endl;
//         if( target == 0 )
//         {   result.push_back(path);
//             return;
//         }
//
//         if( k < 0 || target < 0 ) 
//         {   return;
//         }
//
//         int v = values[k];
//         int d = std::min(target/v, nums[k]);
//
//         while( d > 0 )
//         {   
//             for( int i = 0; i < d; ++i)
//             {   path.push_back(v);
//             }
//
//             find(target-d*v, k-1);
//
//             for( int i = 0; i < d; ++i)
//             {   path.pop_back();
//             }
//
//             d--;
//         }
//         
//         find(target, k-1);
//     }
//
//     vector<int> values;
//     vector<int> nums;
//     vector<int> path;
//     vector<vector<int>> result;
//};
//
// 2023-02-17: Runtime 1437ms 5.4% Memory 14.3MB 16.23%, https://leetcode.com/problems/combination-sum-ii/submissions/899591522/


