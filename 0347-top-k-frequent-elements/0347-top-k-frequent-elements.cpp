class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using a hash map
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        // Step 2: Maintain a min-heap of size k
        // Pair structure: {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        for (auto& pair : counts) {
            min_heap.push({pair.second, pair.first});
            
            // If the heap exceeds size k, pop the element with the lowest frequency
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        // Step 3: Extract the top k frequent elements from the heap
        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};