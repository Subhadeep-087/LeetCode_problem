class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char c : s)
        {
            int value = c - 'a' + 1;

            while(value > 0)
            {
                sum += value % 10;
                value /= 10;
            }
        }
        k--;

        while(k > 0)
        {
            int newSum = 0;
            while(sum > 0)
            {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
            k--;
        }
        return sum;
    }
};