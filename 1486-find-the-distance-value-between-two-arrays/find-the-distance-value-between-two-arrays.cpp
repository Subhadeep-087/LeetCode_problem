class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;

        for(int x : arr1){
            int low = 0, high = arr2.size() - 1;
            bool valid = true;

            while(low <= high){
                int mid = low + (high - low)/2;

                if(abs(arr2[mid] - x) <= d){
                    valid = false;
                    break;
                }
                else if(arr2[mid] < x){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(valid){
                ans++;
            }
        }
        return ans;
    }
};