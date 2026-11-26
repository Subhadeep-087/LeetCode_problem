class Solution {
public:
    bool canAliceWin(int n) {
        int fstRemove = 10;
        int turn = 0;

        while(n >= fstRemove){
            n = n - fstRemove;
            fstRemove--;
            turn++;
        }
        return turn % 2 == 1;
    }
};