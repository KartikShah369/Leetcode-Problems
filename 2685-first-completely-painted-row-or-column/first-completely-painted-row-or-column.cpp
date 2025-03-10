class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int , pair<int,int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j =0 ;j<m;j++) {
                mp[mat[i][j]] = {i,j};
            }
        }
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int i = 0 ;i < m*n; i++) {
            int nr = mp[arr[i]].first;
            int nc = mp[arr[i]].second;
            r[nr]++;
            c[nc]++;
            if(r[nr] == m || c[nc] == n) return i; 



        }
        return 0;
    }
};