/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. 
If the index is invalid, return -1.

addAtHead(val) : Add a node of value val before the first element of the linked list.
 After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list.
If index equals to the length of linked list, the node will be appended to the end of linked list. 
If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 
Example:

Input: 
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:  
[null,null,null,null,2,null,3]

Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
 
Constraints:

0 <= index,val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
*/

//solution
class MyLinkedList {
    struct node{
        int val;
        node* next;
        node* prev;
    };
    int nindex = 0;
    node nodes[1005];
    node* getNode(int val){
        node* temp = &nodes[nindex++];
        temp->val = val;
        temp->next = temp->prev = nullptr;
        return temp;
    }
    node* first;
    node* last;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        nindex = len = 0;
        first = last = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node* ftemp  = first;
        int count = 0;
        while(ftemp){
            if(count == index)
                break;
            count++;
            ftemp = ftemp->next;
        }
        return ftemp ? ftemp->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* temp = getNode(val);
        len++;
        if(first == nullptr && last == nullptr){
            first = last = temp;
            return;
        }
        
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* temp = getNode(val);
        len++;
        if(first == nullptr && last == nullptr){
            first = last = temp;
            return;
        }
        
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    
    node* getNodeAtIndex(int index){
        node* ftemp  = first;
        int count = 0;
        while(ftemp){
            if(count == index)
                break;
            count++;
            ftemp = ftemp->next;
        }
        return ftemp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0)
            addAtHead(val);
        
        if(index > len)
            return;
        
        node* temp = getNode(val);
        if (index == len){
			if (first == nullptr && last == nullptr){
				first = last = temp;
				len++;
			}
			else{
				temp->prev = last;
				last->next = temp;
				last = temp;
                len++;
			}
			return;
		}

        node* nindex = getNodeAtIndex(index);
        if(nindex == nullptr)
            return;
        
        if(nindex == first){
            temp->next = first;
            first->prev = temp;
            first = temp;
            len++;
        }
        
        nindex->prev->next = temp;
        temp->prev = nindex->prev;
        temp->next = nindex;
        nindex->prev = temp;
        len++;
    }
    

    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node* nindex = getNodeAtIndex(index);
        if(nindex == nullptr)
            return;

        if(first == nindex && last == nindex){
            first = last = nullptr;
            len--;
        }
        else if(first == nindex && last != nindex){
            first = first->next;
            first->prev = nullptr;
            len--;
        }
        else if(first != nindex && last == nindex){
            last = last->prev;
            last->next = nullptr;
            len--;
        }
        else{
            nindex->prev->next = nindex->next;
            nindex->next->prev = nindex->prev;
            len--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */