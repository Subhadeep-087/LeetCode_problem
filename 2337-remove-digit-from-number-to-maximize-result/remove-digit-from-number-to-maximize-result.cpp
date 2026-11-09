class Solution {
public:
    string removeDigit(string number, char digit) {
        int pos = -1;
        int n = number.size();

        for(int i = 0; i < n; i++){
            if(number[i] == digit){
                pos = i;

                if(i+1 < number.size() && number[i+1] > digit){
                    break;
                }
            }
        }
        number.erase(pos,1);
        return number;
    }
};