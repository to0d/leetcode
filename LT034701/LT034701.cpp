#include <lt_help/lt.h>



class KHeap
{
public:
    vector<int> numValue;
    vector<int> numCount;
    vector<int> indexHeap;
    int maxCap;
    int maxIndex;
    
    KHeap(int k) : maxCap(k), maxIndex(0) {};
    
    void pushHeap(int value, int count)
    {
        // cout << "Push: " << v << endl; 
        if( indexHeap.size() == maxCap )
        {
            if(count <= getCount(0) ) 
                return;

            //Adjust Heap
            indexHeap[0] = addValue(value, count);
            adjustHeap(0);
        }
        else
        {
            indexHeap.push_back(addValue(value, count));
            
            // Build Heap
            if( indexHeap.size() == maxCap )
            {
                for(int pos = maxCap/2-1; pos >= 0; --pos)
                {
                    int posL = 2*pos+1;
                    int posR = posL+1;
                    
                    if( getCount(posL) < getCount(pos) )
                    {
                        swap( posL, pos);
                        adjustHeap( posL );
                    }
                    
                    if(posR < maxCap && getCount(posR) < getCount(pos) )
                    {
                        swap( posR, pos);
                        adjustHeap( posR );
                    }
                }
            }
        }
    }
    
    void adjustHeap(int pos)
    {
        while (pos <= (maxCap/2-1))
        {
            int child = 2*pos+1; 

            if( (child + 1) < maxCap && getCount(child) > getCount(child+1) )
                ++child;

            if( getCount(pos) <= getCount(child) )
                break;

            swap( pos, child);
            pos = child;
        }
    }
    
    int getCount(int pos)
    {   return numCount[indexHeap[pos]];
    }
    
    int addValue(int value, int count)
    {   numValue.push_back(value);
        numCount.push_back(count);
        return maxIndex++;
    } 

    void swap(int a, int b)
    {   int index = indexHeap[a];
        indexHeap[a] = indexHeap[b];
        indexHeap[b] = index;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;

        unordered_map<int,int> nmap;
        for(int v : nums)
            nmap[v]++;
        
        if( k == 1 )
        {
            int topCount = -1;
            int topValue = 0;
            for( auto& pm : nmap)
            {   if( pm.second > topCount )
                {   topCount = pm.second;
                    topValue = pm.first;
                }
            }
            
            res.push_back(topValue);
        }
        else
        {
            KHeap kHeap(k);

            for( auto& pm : nmap)
                kHeap.pushHeap(pm.first, pm.second);

            for( int index: kHeap.indexHeap )
                res.push_back(kHeap.numValue[index]);
        }
        
        return res;
    }
};


void test(vector<int> nums, int k)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", k=" << k << "; output: "; 
    vector<int> r = Solution().topKFrequent(nums, k);
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({1,1,1,2,2,3}, 2);
}

// Result 
//
// 2022-11-18: Runtime 39ms 10.21% Memory 13.8MB 52.7%, https://leetcode.com/problems/top-k-frequent-elements/submissions/845866987/


