class Solution {
public:
    void solve(string s, int close, int open, int n, vector<string>& ans)
    {
        if(s.size() == 2 * n){
            ans.push_back(s);
            return;
        }
        if(open < n)
            solve(s + "(" , close, open+1, n, ans);
        if(close < open)
            solve(s + ")", close+1, open, n, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", 0, 0, n, ans);
        return ans;
    }
};