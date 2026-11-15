class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;

        long long even = 1, odd = 0;
        long long ans = 0, sum = 0;

        int n = arr.size();
        for( int i = 0; i < n; i++)
        {
            sum += arr[i];

            if(sum % 2 == 0){
                ans += odd;
                even++;
            }else{
                ans += even;
                odd++;
            }
            ans = ans % mod;
        }
        return ans;
    }
};