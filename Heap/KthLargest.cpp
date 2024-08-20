class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Initialize an empty list
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Add first k elements to the list
        for (int i = 0; i < k; i++)
            minHeap.push(nums[i]);

        // Loop through the remaining elements in the 'nums' array
        for (int i = k; i < nums.size(); i++) {
            // Compare the current element with the minimum
            // element (root) of the min-heap
            if (nums[i] > minHeap.top()) {
                // Remove the smallest element
                minHeap.pop();
                // Add the current element
                minHeap.push(nums[i]);
            }
        }

        // The root of the heap has the Kth largest element
        return minHeap.top();
    }
};