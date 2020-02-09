/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. 
Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

//solution
class Solution {
    vector<int> original;
    vector<int> shufflevec;
    int sizevec;
public:
    Solution(vector<int>& nums) {
        original = nums;
        shufflevec = move(nums);
        sizevec = shufflevec.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shufflevec = original;
        return shufflevec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int sizec = sizevec;
        for(int i = 0; i < sizevec; i++){
            int rval = rand() % sizec;
            swap(shufflevec[rval], shufflevec[sizec-1]);
            sizec--;
        }
        return shufflevec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */