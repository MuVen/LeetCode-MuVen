/*
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, 
where h is the height of the tree.
You may assume that next() call will always be valid, that is, 
there will be at least a next smallest number in the BST when next() is called.
*/

//solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode* rootn;
    TreeNode* minnode;
    TreeNode* maxnode;
    TreeNode* nextnode;
public:
    TreeNode* getMin(TreeNode* n){
        if(n == nullptr)
            return nullptr;
        
        while(n->left){
            n = n->left;
        }
        return n;
    }
    
    void calcInorderNext(){
        if(rootn == nullptr || minnode == nullptr)
            return;
        
        if(minnode->right){
            nextnode = getMin(minnode->right);
            return;
        }
        
        if(minnode == maxnode){
            nextnode = nullptr;
            return;
        }
        
        TreeNode* successor = nullptr;
        TreeNode* rootc = rootn;
        while(rootc){
            if(minnode->val < rootc->val){
                successor = rootc;
                rootc = rootc->left;
            }else if(minnode->val > rootc->val){
                rootc = rootc->right;
            }else
                break;
        }
        nextnode = successor;
    }
    
    BSTIterator(TreeNode* root) {
        rootn = root;
        minnode = rootn;
        maxnode = rootn;
        while(minnode && minnode->left){
            minnode = minnode->left;
        }
        while(maxnode && maxnode->right){
            maxnode = maxnode->right;
        }
        calcInorderNext();
    }
    
    
    /** @return the next smallest number */
    int next() {
        if(minnode == nullptr)
            return 0;
        int val = minnode->val;
        minnode = nextnode;
        calcInorderNext();
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return minnode ? true : false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */