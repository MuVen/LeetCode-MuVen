/*
Merge k sorted linked lists and return it as one sorted list. Analyze and 
describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

//solution
class Solution {
	ListNode* head;
	ListNode* prev;
	vector<ListNode*> heap;
	
public:
	Solution(){
		head = prev = nullptr;
	}
	void minHeapify(int index, int size){
		int smallest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left < size && heap[left] && heap[smallest] && heap[left]->val < heap[smallest]->val)
			smallest = left;
		if (right < size && heap[right] && heap[smallest] && heap[right]->val < heap[smallest]->val)
			smallest = right;
		if (smallest != index){
			ListNode* temp = heap[index];
			heap[index] = heap[smallest];
			heap[smallest] = temp;
			minHeapify(smallest, size);
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;

		for (int i = 0; i < lists.size(); i++){
			if (lists[i] != nullptr)
				heap.push_back(lists[i]);
		}

        if(heap.size() == 0)
            return nullptr;

		for (int i = heap.size() / 2 - 1; i >= 0; i--){
			minHeapify(i, heap.size());
		}

		while (1){
			ListNode* t = heap[0];
			if (head == nullptr){
				head = t;
				prev = t;
			}
			else{
				prev->next = t;
				prev = t;
			}

			heap[0] = heap[0]->next;
			if (heap[0] == nullptr){
				heap[0] = heap[heap.size() - 1];
				heap.pop_back();
			}
			
			if (heap.size() == 0)
				break;
			minHeapify(0, heap.size());
		}

		return head;
	}
};