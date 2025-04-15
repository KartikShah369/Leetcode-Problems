class NumArray {
private:
    int n;
    vector<int> segTree;
    vector<int> arr;
    void buildTree(int i, int l, int r) {
        if(l == r) {
            segTree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(2*i + 1, l, mid);
        buildTree(2*i + 2, mid+1, r);
        segTree[i] = segTree[2*i + 1] + segTree[2*i+2];
    }
    void updateTree(int ind, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(ind <= mid) updateTree(ind, val, 2*i+1, l, mid);
        else updateTree(ind, val, 2*i+2, mid+1, r);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int query(int start, int end, int i, int l, int r) {
        if(l > end || r < start) return 0;
        if(l >= start && r <= end) return segTree[i];
        int mid = (l + r) / 2;
        return query(start, end, 2*i+1, l, mid) + query(start, end, 2*i+2, mid+1, r);
    }

public:
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        segTree = vector<int>(4*n);
        buildTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */