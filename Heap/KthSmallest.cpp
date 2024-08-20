class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        struct Compare{
        bool operator()(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            return a.first > b.first;
        }
    };
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,Compare>minHeap;
    int n = matrix.size();
    //  the heap with the first element of each row
    for(int i = 0; i < n;i++){
        minHeap.push({matrix[i][0], {i, 0}});
    }
    int result = 0;
    // Extract-min k times
    for (int i = 0; i < k; i++){
        auto elem = minHeap.top();
        minHeap.pop();
        result = elem.first;
        int row = elem.second.first;
        int col = elem.second.second;
        // If there is a next element in the row, add it to the heap
        if (col + 1 < n) {
            minHeap.push({matrix[row][col + 1], {row, col + 1}});
        }
    }

    return result;
    }
};