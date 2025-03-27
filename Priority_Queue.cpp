//Priority Queue ADT
//1. Using an Unsorted Array
class PriorityQueueArray {
private:
    vector<int> arr;

public:
    void enqueue(int x) {
        arr.push_back(x); // O(1)
    }

    int first() {
        if (arr.empty()) throw underflow_error("Queue is empty");
        return *max_element(arr.begin(), arr.end()); // O(n)
    }

    int dequeue() {
        if (arr.empty()) throw underflow_error("Queue is empty");
        
        auto maxIt = max_element(arr.begin(), arr.end()); // O(n)
        int maxVal = *maxIt;
        arr.erase(maxIt); // O(n)
        return maxVal;
    }

    int size() { return arr.size(); }
    bool is_empty() { return arr.empty(); }
};


//2. Using a Sorted Array

class PriorityQueueSortedArray {
private:
    vector<int> arr;

public:
    void enqueue(int x) {
        arr.insert(upper_bound(arr.begin(), arr.end(), x), x); // O(n)
    }

    int first() {
        if (arr.empty()) throw underflow_error("Queue is empty");
        return arr.back(); // O(1)
    }

    int dequeue() {
        if (arr.empty()) throw underflow_error("Queue is empty");
        int maxVal = arr.back();
        arr.pop_back(); // O(1)
        return maxVal;
    }

    int size() { return arr.size(); }
    bool is_empty() { return arr.empty(); }
};


//3. Using a Min/Max Heap (Binary Heap)

#include <queue>

class PriorityQueueHeap {
private:
    priority_queue<int> pq; // Max heap

public:
    void enqueue(int x) {
        pq.push(x); // O(log n)
    }

    int first() {
        if (pq.empty()) throw underflow_error("Queue is empty");
        return pq.top(); // O(1)
    }

    int dequeue() {
        if (pq.empty()) throw underflow_error("Queue is empty");
        int maxVal = pq.top();
        pq.pop(); // O(log n)
        return maxVal;
    }

    int size() { return pq.size(); }
    bool is_empty() { return pq.empty(); }
};


//
