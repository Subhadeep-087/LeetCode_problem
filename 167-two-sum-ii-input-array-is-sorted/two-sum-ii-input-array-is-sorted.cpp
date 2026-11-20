class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high)
        {
            if(nums[low] + nums[high] == target)
            {
                return {low + 1, high + 1};
            }else if(nums[low] + nums[high] <= target){
                low++;
            }else{
                high--;
            }
        }
        return {};
    }
};