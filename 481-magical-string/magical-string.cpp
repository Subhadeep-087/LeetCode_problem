class Solution {
public:
    int magicalString(int n) {
        if(n <= 3)
        {
            return 1;
        }
        vector<int>s(n);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int i = 2;
        int j = 3;
        int count = 1;

        while(j < n)
        {
            int next = 3 - s[j-1];
            for(int k = 0; k < s[i] && j < n; k++) {
                s[j] = next;

                if(next == 1)
                    count++;

                j++;
            }
            i++;
        }
        return count;
    }
};