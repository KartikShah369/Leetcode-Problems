class ProductOfNumbers {
public:
    vector<int> arr;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        arr.insert(arr.begin(),num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for(int i =0;i<k;i++){
            ans *= arr[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */