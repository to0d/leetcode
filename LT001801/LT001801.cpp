#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        int size = nums.size(); 

        if( size < 4)
            return res;

        if( size == 4 )
        {
            long long sum = 0;
            for( auto num : nums) 
                sum += num;

            if( sum == target )
                res.push_back(nums);             

            return res;
        }

        unordered_map<int, list<pair<int,int>>> d2map;
        vector<int> d2vec;
        vector<pair<int,int>> d4vec;

        for( int i = 0; i < size; ++i )
            for( int j = i+1; j < size; ++j ) {
                int sum = nums[i]+nums[j];
                d2map[sum].push_back(make_pair(i,j));
            }
            
        for( auto& e : d2map )
            d2vec.push_back( e.first );

        for( int d2 : d2vec ) {
            int t2 = target - d2;
            if( d2 < t2 && d2map.count(t2) > 0 )
                d4vec.push_back(make_pair(d2,t2));
        }

        if( target %2 == 0 ) {
            int d2 = target /2;
            if( d2map.count(d2) > 0 )
                d4vec.push_back(make_pair(d2,d2));
        }

        unordered_set<int> xorSet;
        vector<int> xorVec;
        for( auto& d4 : d4vec ) {
            auto& la = d2map[d4.first];
            auto& lb = d2map[d4.second];
            for( auto& pa : la) {
                 for( auto& pb : lb) 
                 {
                    if( pa.first == pb.first || pa.first == pb.second || pa.second== pb.first || pa.second== pb.second )
                        continue;

                   vector<int> r = {nums[pa.first], nums[pa.second], nums[pb.first], nums[pb.second]};
                   sort( r.begin(),r.end());
                   
                   int xv = 0;
                   for( int v : r )
                       xv ^= v;
                   
                   bool findEqual = false;
                   
                   if( xorSet.count( xv ) > 0 ) {
                       int nc = res.size();
                       for( int i = 0; i < nc && !findEqual; ++i) {
                           if( xorVec[i] == xv ) {
                               vector<int>& rr = res[i];
                               int j = 0;
                               for(; j < 4; ++j){
                                    if( r[j] != rr[j] )
                                        break;
                               }
                               if ( j == 4 )
                                   findEqual = true;
                           }   
                       }
                   }
                   else
                       xorSet.insert(xv);

                   if( !findEqual ) {
                        res.push_back(r);
                        xorVec.push_back(xv);
                   }
                }
            }
        }
        
        return res;
    }
};


void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);
    vector<vector<int>> r = Solution().fourSum(nums, target);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test({1,0,-1,0,-2,2}, 0);
}

