#include <lt_help/lt.h>

class Solution {
public:
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {

         airports.clear();
         airportNextPorts.clear();
         airportTicketIndexs.clear();
         airportIndexMap.clear();

         {
             unordered_set<string> airportNames;
             for(auto pt : tickets )
             {   airportNames.insert(pt[0]);
                 airportNames.insert(pt[1]);
             }
             
             for(auto n : airportNames)
                airports.push_back(n);   

             std::sort(airports.begin(), airports.end());
            
             int index = 0;
             for( auto& n : airports)
                airportIndexMap[n] = index++;
         }
         
         airportNextPorts.resize(airports.size());  
         airportTicketIndexs.resize(airports.size());
         
         for(auto& pt : tickets)
             airportNextPorts[airportIndexMap[pt[0]]].push_back(airportIndexMap[pt[1]]);

         ticketCount = 0;
         int portIndex = 0;
         for(auto& nextPorts : airportNextPorts)
         {
             auto& ticketIndexs = airportTicketIndexs[portIndex++];
             sort(nextPorts.begin(), nextPorts.end());
             for( int i = nextPorts.size(); i > 0; --i)
                  ticketIndexs.push_back( ticketCount++ );
         }
         
         unordered_set<int> usedTickets;
         vector<int> visitedAirport;

         findItinerary(airportIndexMap["JFK"], visitedAirport, usedTickets);

         vector<string> res;
         for( int index : visitedAirport)
            res.push_back( airports[index] );

        return res;
    }
    
    bool findItinerary(int fromAirport, vector<int>& visitedAirport, unordered_set<int>& usedTickets){
        visitedAirport.push_back(fromAirport);

        if( usedTickets.size() == ticketCount )
            return true;
        
        auto& nextPorts = airportNextPorts[fromAirport];
        auto& ticketIndexs = airportTicketIndexs[fromAirport];
        int nextCount = nextPorts.size();
        
        for( int i = 0; i < nextCount ; ++i )
        {   int nextTicketIndex = ticketIndexs[i], nextPort = nextPorts[i];
            if( usedTickets.count(nextTicketIndex) == 0 )
            {   usedTickets.insert(nextTicketIndex);
                if( findItinerary (nextPort, visitedAirport, usedTickets))
                    return true;
                usedTickets.erase(nextTicketIndex);
            }
        }

        visitedAirport.pop_back();
        return false;
    }
    
    vector<string> airports;
    vector<vector<int>> airportNextPorts;
    vector<vector<int>> airportTicketIndexs;
    unordered_map<string,int> airportIndexMap;
    int ticketCount;
};


void test(vector<vector<string>> tickets)
{
    cout << "input: ";
    outputVector(tickets);
    vector<string> r = Solution().findItinerary(tickets);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}});
}


// Result 
//
// 2022-12-05: Runtime 65ms 13.57% Memory 16MB 19.49%, https://leetcode.com/problems/reconstruct-itinerary/submissions/855079403/
// 2023-02-17: Runtime 39ms 26.96% Memory 16MB 17.59%, https://leetcode.com/problems/reconstruct-itinerary/submissions/899794302/



