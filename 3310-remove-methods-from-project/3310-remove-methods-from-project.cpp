class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& suspicious) {
        suspicious[node] = true;

        for (int nei : graph[node]) {
            if (!suspicious[nei])
                dfs(nei, graph, suspicious);
        }
    }

    void dfs2(int node, vector<vector<int>>& graph,
              vector<bool>& vis, vector<bool>& suspicious) {
        vis[node] = true;

        for (int nei : graph[node]) {
            if (!vis[nei]) {
                suspicious[nei] = false;
                dfs2(nei, graph, vis, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> undirected(n), directed(n);

        // Build graphs
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            directed[u].push_back(v);

            undirected[u].push_back(v);
            undirected[v].push_back(u);
        }

        vector<bool> suspicious(n, false);
        vector<bool> vis(n, false);

        // Mark all suspicious methods
        dfs(k, directed, suspicious);

        // Traverse from all non-suspicious methods
        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !vis[i])
                dfs2(i, undirected, vis, suspicious);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};