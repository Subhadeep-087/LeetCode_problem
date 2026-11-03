class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        for(int x : nums){
            if(x > max){
                max = x;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < max){
            ans += max - nums[i];
            }
        }
        return ans;
    }
};