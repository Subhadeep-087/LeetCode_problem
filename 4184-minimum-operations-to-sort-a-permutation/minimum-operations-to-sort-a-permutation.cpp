class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(),nums.end(), 0) - nums.begin();

        bool inc = true, dec = true;

        for(int i = 0; i < n; i++)
        {
            if(nums[(i+1) % n] != (nums[i] + 1) % n)
                inc = false;

            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n)
                dec = false;
        }
        if(!inc && !dec) 
            return -1;
        if(inc)
            return min(zero, n - zero + 2);
        
        return min(zero + 2, n - zero);
    }
};