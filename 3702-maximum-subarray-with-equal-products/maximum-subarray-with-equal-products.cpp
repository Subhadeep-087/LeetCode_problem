class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            long long prod = 1;
            int gd = 0;
            long long lm = 1;
            for(int j = i; j < n; j++)
            {
                gd = gcd(gd, nums[j]);
                lm = lcm(lm, (long long)nums[j]);

                long long target = gd * lm;
                if(prod > target/nums[j])
                    break;
                prod = prod * nums[j];

                if(prod == target){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};