class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max Heap: farthest point at top
        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &p : points) {

            int x = p[0];
            int y = p[1];

            // Calculate squared distance
            int dist = x*x + y*y;

            // Store distance and coordinates
            pq.push({dist, {x, y}});

            // Maintain only K closest points
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        // Extract K closest points
        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            ans.push_back({
                top.second.first,
                top.second.second
            });
        }

        return ans;
    }
};