class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0, ans = 0;

        for(char ch : s)
        {
            if(ch == 'b'){
                b++;
            }else{
                ans = min(ans + 1, b);
            }
        }
        return ans;
    }
};