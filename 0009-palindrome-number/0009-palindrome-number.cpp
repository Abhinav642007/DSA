class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int original = x;
        long int rev=0,rem;
        while(x!=0){
            rev = rev * 10 + x % 10;
            x = x/10;
        }
        return ( rev==original );
    }
};