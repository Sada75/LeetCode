class Solution {
public:
    bool canAliceWin(int n) {
        bool ans;
        int turn = 0;
        int temp = n;
        int k = 10;
        while(true){
            if(temp < k){
                if(turn == 0){
                    ans = false;
                    break;
                }else{
                    ans = true;
                    break;
                }
            }else{
                temp = temp - k;
                k = k-1;
            }
            if(turn == 0){
                turn = 1;
            }else{
                turn = 0;
            }
        }
        return ans;
    }
};
