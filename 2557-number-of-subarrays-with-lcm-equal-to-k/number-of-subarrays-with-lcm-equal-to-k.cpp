class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            int currlm = 1;

            for(int j = i; j < n; j++)
            {
                if(k % nums[j] != 0){
                    break;
                }
                currlm = lcm(currlm, nums[j]);
                if(currlm == k){
                    count++;
                }
            }
        }
        return count;
    }
};