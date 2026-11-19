class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        while(true)
        {
            unordered_set<int> st;
            bool freq = false;

            for(int i = 0; i < n; i++)
            {
                if(st.find(nums[i]) != st.end()){
                    freq = true;
                    break;
                }
                st.insert(nums[i]);
            }

            if(!freq){
                return ans;
            }
            nums.erase(nums.begin(), nums.begin() + min(n, 3));
            n = nums.size();
            ans++;
        }
        return ans;
    }
};