/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n),
 where n is the array's size.
*/

//solution
class Solution {
    struct freq{
        int number;
        int freq;
    };
    vector<freq> heap;
    int hsize = 0;
    vector<int> mnums;
    unordered_map<int, int> map;
    
public:
    void maxHeapify(int index, int size){
        int largest = index;
        int left = 2 * largest + 1;
        int right = 2 * largest + 2;
        if(left < size && heap[left].freq > heap[largest].freq)
            largest = left;
        if(right < size && heap[right].freq > heap[largest].freq)
            largest = right;
        if(largest != index){
            map[heap[largest].number] = index;
            map[heap[index].number] = largest;
            swap(heap[largest], heap[index]);
            maxHeapify(largest, size);
        }
    }

    void buildHeapify(int index, int hsize){
        int parent = index;
        while(true){
            parent = (index % 2 == 0) ? (index-2)/2 : (index-1)/2;
            if(parent < 0)
                parent = 0;
            maxHeapify(parent, hsize);
            if(parent == 0)
                break;
            index = parent;
        }
    }
    
    void insertToHeap(int val){
        if(map.find(val) == map.end()){
            heap.push_back({val, 1});
            map[val] = heap.size()-1;
            buildHeapify(heap.size()-1, heap.size());
        }else{
            int index = map[val];
            heap[index].freq++;
            buildHeapify(index, heap.size());
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        mnums = move(nums);
        for(auto i : mnums)
            insertToHeap(i);
        
        vector<int> res;
        int hsize = heap.size();
        while(k--){
            res.push_back(heap[0].number);
            swap(heap[0], heap[hsize-1]);
            hsize--;
            maxHeapify(0, hsize);
        }
        return res;
    }
};