class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        long long total = 0;
        for (int x : diff) total += x;

        if (k >= total) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int x : diff) {
                if (x > mid)
                    operations += x - mid;
            }

            if (operations <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int x : diff) {
            int remaining = min(x, low);
            ans += 1LL * remaining * remaining;

            if (x > low)
                used += x - low;
        }

        long long extra = k - used;

        for (int x : diff) {
            if (extra == 0) break;

            if (x >= low && low > 0) {
                ans -= 1LL * low * low;
                ans += 1LL * (low - 1) * (low - 1);
                extra--;
            }
        }

        return ans;
    }
};