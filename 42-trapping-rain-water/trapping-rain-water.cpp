class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n,0),rmax(n,0);
        lmax[0] = max(0,height[0]);
        rmax[n-1] = max(0,height[n-1]);
        for(int i = 1; i<n; i++) {
            lmax[i] = max(height[i], lmax[i-1]);
        }
        for(int i = n-2; i>=0; i--) rmax[i] = max(height[i] , rmax[i+1]);
        int total = 0;
        for(int i =0; i<n; i++) {
            int l = lmax[i] , r = rmax[i];
            if(height[i] < l && height[i] < r) {
                total += min(l,r) - height[i];
            }
        }
        return total;
    }
};