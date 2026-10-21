class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr = "";

        generate(n, curr, ans);
        if(ans.size() < k)
            return "";
        return ans[k-1];
    }
    void generate(int n, string &curr, vector<string>& ans)
    {
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(char c = 'a'; c <= 'c'; c++)
        {
            if (!curr.empty() && curr.back() == c)
                continue;
            curr.push_back(c);
            generate(n, curr, ans);
            curr.pop_back();
        }
    }
};