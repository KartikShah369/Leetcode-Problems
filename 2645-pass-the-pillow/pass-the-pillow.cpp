class Solution {
public:
    int passThePillow(int n, int time) {
        if(!(time/(n-1) & 1))
        return time%(n-1) + 1;
        else {
            return n - (time%(n-1));
        }
    }
};