#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        array = new int[capacity] ;
    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {
        if (m_map.count(key) == 1) {
            m_map[key] = value;
        }
        
        if (m_index + 1 != m_capacity) {
            m_map[key] = ++m_index;
            return; 
        }


    }
    unordered_map<int, int> m_map;
    int * array;
    int m_index;
    int m_capacity;
private:
    
};