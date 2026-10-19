class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, last = -1;
        int low = 0, high = n - 1;

        //First target value find
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] < target)
            {
                low = mid + 1;
            }else if(nums[mid] > target)
            {
                high = mid - 1;
            }else{
                first = mid;
                high = mid - 1;
            }
        }

        //Last target value find

        low = 0, high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] < target)
            {
                low = mid + 1;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                last = mid;
                low = mid + 1;
            }
        }
        return {first, last};
    }
};