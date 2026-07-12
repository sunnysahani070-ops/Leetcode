#include <queue>
#include <vector>

class MedianFinder {
private:
    // Max-heap to store the smaller half of the numbers
    std::priority_queue<int> max_heap; 
    
    // Min-heap to store the larger half of the numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap; 

public:
    MedianFinder() {
        // Constructor remains empty
    }
    
    void addNum(int num) {
        // Step 1: Add to max_heap first
        max_heap.push(num);
        
        // Step 2: Balancing step - ensure every element in max_heap <= every element in min_heap
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        // Step 3: Maintain size property (max_heap can have 1 more element than min_heap)
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        // If odd number of elements, the middle one is at the top of max_heap
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        // If even number of elements, take the average of both tops
        // Divide by 2.0 to ensure a double precision result
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */