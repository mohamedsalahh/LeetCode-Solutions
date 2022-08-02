class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum = vector<int>(nums.size()+1, 0);
        for(int i = 1; i <= nums.size(); ++i)
            prefixSum[i] = prefixSum[i-1] + nums[i-1]; 
    }
    
    int sumRange(int left, int right) {
        left++; right++;
        return prefixSum[right] - prefixSum[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */