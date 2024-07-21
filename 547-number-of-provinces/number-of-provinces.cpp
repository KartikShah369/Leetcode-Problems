class Solution {
public:
    void dfs(vector<int>& vis, vector<int>adj[], int i) {
        vis[i] = 1;
        for (auto it : adj[i]) {
            if(!vis[it]) {
                dfs(vis, adj, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(vis, adj, i);
            }
        }
        return cnt;
    }
};