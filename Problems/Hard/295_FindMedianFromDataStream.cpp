/*
Median is the middle value in an ordered integer list. If the size of the 
list is even, there is no middle value. 
So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the 
data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, 
how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, 
how would you optimize it?
*/

//solution
class MedianFinder {
    vector<int> maxHeap;
    vector<int> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void maxHeapify(int index, int size){
        int largest = index;
        int left = 2 * largest + 1;
        int right = 2 * largest + 2;
        if(left < size && maxHeap[left] > maxHeap[largest])
            largest = left;
        if(right < size && maxHeap[right] > maxHeap[largest])
            largest = right;
        if(largest != index){
            swap(maxHeap[largest], maxHeap[index]);
            maxHeapify(largest, size);
        }
    }
    
    void minHeapify(int index, int size){
        int smallest = index;
        int left = 2 * smallest + 1;
        int right = 2 * smallest + 2;
        if(left < size && minHeap[left] < minHeap[smallest])
            smallest = left;
        if(right < size && minHeap[right] < minHeap[smallest])
            smallest = right;
        if(smallest != index){
            swap(minHeap[smallest], minHeap[index]);
            minHeapify(smallest, size);
        }        
    }
    
    void buildMaxHeapify(int index, int size){
        while(index){
            int parent = (index % 2 == 0) ? (index-2)/2 : (index-1)/2;
            maxHeapify(parent, size);
            if(parent == 0)
                break;
            index = parent;
        }
    }
    
    void buildMinHeapify(int index, int size){
        while(index){
            int parent = (index % 2 == 0) ? (index-2)/2 : (index-1)/2;
            minHeapify(parent, size);
            if(parent == 0)
                break;
            index = parent;
        }        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 ||  num < maxHeap[0]){
            maxHeap.push_back(num);            
            buildMaxHeapify(maxHeap.size()-1, maxHeap.size());
        }else{
            minHeap.push_back(num);
            buildMinHeapify(minHeap.size()-1, minHeap.size());
        }
        
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        if(lsize == rsize)
            return;
        
        int balance = lsize - rsize;
        if(balance >= 2){
            int val = maxHeap[0];
            //remove the element from maxheap and put it in to minheap
            swap(maxHeap[0], maxHeap[maxHeap.size()-1]);
            maxHeap.pop_back();
            maxHeapify(0, maxHeap.size());

            minHeap.push_back(val);
            buildMinHeapify(minHeap.size()-1, minHeap.size());
        }else if(balance <= -2){
            int val = minHeap[0];
            //remove the element from minheap and put it in to maxheap
            swap(minHeap[0], minHeap[minHeap.size()-1]);
            minHeap.pop_back();
            minHeapify(0, minHeap.size());
            
            maxHeap.push_back(val);
            buildMaxHeapify(maxHeap.size()-1, maxHeap.size());            
        }
    }
    
    double findMedian() {
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        if(lsize == rsize){
            return (maxHeap[0]+minHeap[0])/2.0;
        }
        
        if(lsize > rsize)
            return maxHeap[0];
        
        return minHeap[0];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */