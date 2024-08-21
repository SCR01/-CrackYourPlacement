class Solution {
public:
 struct Compare{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first < b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        // Max heap to store the k closest points with greater distances at the top
     
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>maxHeap;
        // Calculate squared distance and maintain only k smallest distances in the heap
        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(maxHeap.size() < k) {
                maxHeap.push({dist, i});
            }else if(dist < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({dist, i});
            }
        }
        // Collect the k closest points
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        // for(auto&x : points) cout << x << " x" << nl;
        return result;
    }
};