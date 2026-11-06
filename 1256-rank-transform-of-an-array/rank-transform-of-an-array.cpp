class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(ans.begin(), ans.end());
        unordered_map<int,int> rank;
        int r = 1;

        for(int i = 0; i < ans.size(); i++)
        {
            if(rank.find(ans[i]) == rank.end()){
                rank[ans[i]] = r;
                r++;
            }
        }
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};