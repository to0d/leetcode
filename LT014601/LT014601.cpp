#include <lt_help/lt.h>

struct LRUEntry
{   int key;
    int value;
    int life;
};

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity), m_life(0), m_update(false){}
    
    int get(int key) {
        auto it = m_map.find(key);
        if( it == m_map.end() )
            return -1;

        LRUEntry* entry = it->second;
        if( entry->life != m_life )
        {   entry->life = m_life++;
            m_update = true;
        }

        return entry->value;
    }
    
    void put(int key, int value) {
        auto it = m_map.find(key);
        if( it != m_map.end() )
        {   LRUEntry* entry = it->second;
            entry->value = value;
            if( entry->life != m_life )
            {   entry->life = m_life++;
                m_update = true;
            }
        }
        else if( m_list.size() < m_capacity )
        {   LRUEntry* entry = new LRUEntry();
            entry->key = key;
            entry->value = value;
            entry->life = m_life++;
            m_list.push_back(entry);
            m_map[key] = entry;
            m_update = true;
        }
        else
        {
            _update();

            LRUEntry* entry = m_list[0];
            m_map.erase(entry->key);
            
            entry->key = key;
            entry->value = value;
            entry->life = m_life++;
            m_map[key] = entry;
            m_update = true;
        }
    }

private: 
    void _update(){  
        if( !m_update )
            return; 
        
        int minLife = m_list[0]->life, minIdx = 0;
        for(int i = 1;i < m_capacity; ++i)
        {   LRUEntry* entry = m_list[i];
            if( entry->life < minLife )
            {   minLife = entry->life;
                minIdx  = i;
            }
        }

        if( minIdx != 0 )
        {   LRUEntry* tmp  = m_list[minIdx];
            m_list[minIdx] = m_list[0];
            m_list[0]      = tmp;
        }
        
        m_update = false;
    }        
   
    unordered_map<int, LRUEntry*> m_map;
    vector<LRUEntry*> m_list;
    bool m_update;
    int m_life;
    int m_capacity;
};


int main(void)
{
    cout << "output: done!;" << endl;
}

// Result 
//
// 2023-02-01: Runtime 806ms 5.4% Memory 163.3MB 98.46%, https://leetcode.com/problems/lru-cache/submissions/889501213/


