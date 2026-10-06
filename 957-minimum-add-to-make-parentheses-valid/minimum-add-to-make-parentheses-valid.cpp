class Solution {
public:
    int minAddToMakeValid(string s) { 
        int count = 0;
        int open = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                open++;
            }else{
                if(open > 0)
                {
                    open--;
                }else{
                    count++;
                }
            }
        }
        return count + open;
    }
};