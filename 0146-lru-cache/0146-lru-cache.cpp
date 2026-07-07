#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    // List stores pairs of {key, value}
    std::list<std::pair<int, int>> cacheList;
    // Map stores key -> iterator to the position in the list
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        
        // Move accessed item to the front (Most Recently Used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update existing value and move to front
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
            return;
        }

        if (cacheList.size() == capacity) {
            // Evict the Least Recently Used item (back of the list)
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }

        // Insert new item at the front
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */