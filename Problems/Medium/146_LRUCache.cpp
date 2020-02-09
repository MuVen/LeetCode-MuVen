/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists 
in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the 
least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

//solution
struct node{
	int key;
	int val;
	node* next;
	node* prev;
};

struct nodefl{
	node* first;
	node* last;
};

node nodes[10000];
int nindex;

node* getNode(int key, int val){
	node* temp = &nodes[nindex++];
	temp->key = key;
	temp->val = val;
	temp->next = temp->prev = nullptr;
	return temp;
}

class LRUCache {
	int tcapacity;
	int mycapacity;
	nodefl nfl;
	unordered_map<int, node*> map;
public:
	LRUCache(int capacity) {
		tcapacity = capacity;
		mycapacity = nindex = 0;
		nfl.first = nfl.last = nullptr;
	}

	void touch(int key){
		node* temp = map[key];
		if (nfl.first == temp && nfl.last == temp){
			return;
		}
		else if (nfl.first == temp && nfl.last != temp){
			return;
		}
		else if (nfl.first != temp && nfl.last == temp){
			nfl.last = nfl.last->prev;
			nfl.last->next = nullptr;
			nfl.first->prev = temp;
			temp->next = nfl.first;
			nfl.first = temp;
			return;
		}
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp->next = nfl.first;
			nfl.first->prev = temp;
			nfl.first = temp;
			return;
		}
	}

	int get(int key) {
		if (map.find(key) == map.end())
			return -1;

		touch(key);
		return map[key]->val;
	}

	void put(int key, int value) {
		if (map.find(key) != map.end()){
			touch(key);
			map[key]->val = value;
			return;
		}
		
		node* temp = getNode(key, value);
		map[key] = temp;

		if (mycapacity == tcapacity){
			if (nfl.first == nfl.last){
				map.erase(nfl.last->key);
				nfl.first = nfl.last = temp;
				return;
			}
			else{
				nfl.first->prev = temp;
				temp->next = nfl.first;
				nfl.first = temp;

				map.erase(nfl.last->key);
				nfl.last = nfl.last->prev;
				nfl.last->next = nullptr;
				return;
			}
		}
		

		mycapacity++;
		if (nfl.first == nullptr && nfl.last == nullptr){
			nfl.first = nfl.last = temp;
			return;
		}
		temp->next = nfl.first;
		nfl.first->prev = temp;
		nfl.first = temp;
	}
};