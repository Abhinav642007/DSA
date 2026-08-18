class Solution {
public:
    int calculate(string s) {
        int n = s.length();

        long long number = 0;   // int → long long
        long long result = 0;   // int → long long

        stack<int> st;
        int sign = 1;

        for (int i = 0; i < n; i++) {

            if (isdigit(s[i])) {

                // Number ko digit by digit build kar rahe hain
                number = number * 10 + (s[i] - '0');

            } 
            else if (s[i] == '+') {

                // Current number ko result mein add karo
                result += number * sign;

                number = 0;
                sign = 1;

            } 
            else if (s[i] == '-') {

                // Current number ko result mein add karo
                result += number * sign;

                number = 0;
                sign = -1;

            } 
            else if (s[i] == '(') {

                // Bracket ke bahar ka result aur sign save karo
                st.push(result);
                st.push(sign);

                // Bracket ke andar fresh calculation
                result = 0;
                number = 0;
                sign = 1;

            } 
            else if (s[i] == ')') {

                // Bracket ke andar ka last number add karo
                result += number * sign;

                number = 0;

                // Previous sign nikalo
                int stack_sign = st.top();
                st.pop();

                // Previous result nikalo
                long long last_result = st.top();
                st.pop();

                // Bracket ke result par previous sign apply karo
                result *= stack_sign;

                // Previous result mein bracket ka result add karo
                result += last_result;
            }
        }

        // Last number ko result mein add karo
        result += number * sign;

        return (int)result;
    }
};