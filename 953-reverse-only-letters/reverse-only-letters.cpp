class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int st = 0;
        int end = n-1;

        while(st < end)
        {
            if(!isalpha(s[st])){
                st++;
                continue;
            }
            if(!isalpha(s[end])){
                end--;
                continue;
            }
            swap(s[st],s[end]);
            st++;
            end--;
        }
        return s;
    }
};