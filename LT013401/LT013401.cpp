#include <lt_help/lt.h>



class Solution {

    class GasPosition
    {
    public:
        int gas;
        int position;
        GasPosition(int g, int p) : gas(g), position(p) {};
    }; 

public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {       

        int count = gas.size();
        if( count == 0 || ( accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)))
            return -1;

        vector<GasPosition> gs;
        for(int i = 0 ; i < count; ++i )
        {   gs.push_back(GasPosition(gas[i], i));
            gs.push_back(GasPosition(-cost[i], i));
        }
        
        while( gs.size() > 1 )
        {
            GasPosition reverseGas(0, -1);
            int ncout = gs.size() / 2;
            int index = 0;
            
            if( !canComplete(gs[0].gas + gs[1].gas) )
            {
                reverseGas.position = gs[0].position;
                for( ;index < ncout; ++index)
                {
                    int ncost = gs[2*index].gas + gs[2*index + 1].gas;
                    if( !canComplete(ncost))
                        reverseGas.gas += ncost;
                    else
                        break;
                }
            }
            
            bool lastCanComplete = false;
            int lastIndex = -1;
            
            for( ;index < ncout; ++index)
            {
                int ncost = gs[2*index].gas + gs[2*index + 1].gas;
                if( lastCanComplete != canComplete(ncost) )
                {
                    ++lastIndex;
                    gs[lastIndex].position = gs[2*index].position;
                    gs[lastIndex].gas = ncost;
                    lastCanComplete = !lastCanComplete;
                }
                else
                    gs[lastIndex].gas += ncost;
            }
            
            if( (int)gs.size() > (lastIndex+1) )
                gs.erase( gs.begin() + lastIndex + 1, gs.end());
            
            if( reverseGas.position >= 0 )
            {
                if( lastIndex < 0 || canComplete(gs[lastIndex].gas) )
                {
                    gs.push_back(reverseGas);
                    ++lastIndex;
                }
                else
                    gs[lastIndex].gas +=  reverseGas.gas;
            }
            else
            {
                if( lastIndex > 0 && canComplete( gs[lastIndex].gas ) )
                {
                    gs[0].gas +=  gs[lastIndex].gas;
                    gs[0].position +=  gs[lastIndex].position;
                    gs.erase( gs.begin() + lastIndex, gs.end());
                }               
            }
        }
        
        return gs[0].position;
    }
    
    bool canComplete(int gas) { return gas >= 0; }
};



void test(vector<int> gas, vector<int> cost)
{
    cout << "input: gas=";
    outputVector(gas);
    cout << ", cost=";
    outputVector(cost);
    int r = Solution().canCompleteCircuit(gas, cost);
    cout << "; output: "; 
    cout << r << ";" << endl;
}

int main(void)
{
    test({1,2,3,4,5}, {3,4,5,1,2});
}

// Result 
//
// 2022-11-18: Runtime 91ms 51.14% Memory 78.5MB 8.84%, https://leetcode.com/problems/gas-station/submissions/845833435/
