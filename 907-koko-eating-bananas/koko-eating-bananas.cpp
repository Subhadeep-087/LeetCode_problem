class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            long long hrs = 0;

            for(int i = 0; i < piles.size(); i++){
                hrs += (piles[i] + mid - 1) / mid;
            }
            if(hrs <= h){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};