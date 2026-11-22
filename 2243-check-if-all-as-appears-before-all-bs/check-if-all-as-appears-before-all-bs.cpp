class Solution {
public:
    bool checkString(string s) {
        bool found = false;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'b'){
                found = true;
            }
            if(s[i] == 'a' && found == true){
                return false;
            }
        }
        return true;
    }
};