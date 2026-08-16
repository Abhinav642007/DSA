class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        for(steps = 0; num > 0; steps++) {
            if(num % 2 == 0) num /= 2;
            else num--;
        }
        return steps;
    }
};