class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digisum=0;
        int digiproduct=1;
        while(n>0){
            int digit=n%10;
            digisum=digisum+digit;
            digiproduct=digiproduct*digit;

            n=n/10;
        }
        int result = digisum + digiproduct;

        // Original number ko result se divide karke check
        return original % result == 0;
    }
};