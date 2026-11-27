class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] % k != 0)
                continue;
            
            int gd = 0;
            for(int j = i; j < n; j++)
            {
                gd = gcd(gd, nums[j]);

                if(gd == k)
                    count++;
                if(gd % k != 0)
                    break;
            }
        }
        return count;
    }
};