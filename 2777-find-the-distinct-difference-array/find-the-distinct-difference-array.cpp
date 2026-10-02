class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        unordered_set<int> left;
        unordered_map<int, int> freq;

        for(int x : nums)
            freq[x]++;

        int rightDistinct = freq.size();

        for(int i = 0; i < n; i++) {
            freq[nums[i]]--;

            if(freq[nums[i]] == 0)
                rightDistinct--;

            left.insert(nums[i]);

            ans[i] = (int)left.size() - rightDistinct;
        }

        return ans;
    }
};