class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            for (int i = 0; i < n && valid; i += k) {
                vector<int> lps(k, 0);

                for (int j = 1, len = 0; j < k;) {
                    if (sorted[i + j] == sorted[i + len]) {
                        lps[j++] = ++len;
                    } else if (len > 0) {
                        len = lps[len - 1];
                    } else {
                        lps[j++] = 0;
                    }
                }

                bool found = false;
                int len = 0;

                for (int j = 0; j < 2 * k - 1; j++) {
                    int x = nums[i + j % k];

                    while (len > 0 && x != sorted[i + len])
                        len = lps[len - 1];

                    if (x == sorted[i + len])
                        len++;

                    if (len == k) {
                        found = true;
                        break;
                    }
                }

                if (!found)
                    valid = false;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};