#include <stack>
#include <string>
using namespace std;

class Solution {
public:
        // stack<char> st;
        // for (char ch : s) {
        //     if (ch == '(' || ch == '[' || ch == '{') {
        //         st.push(ch);
        //     } else {
        //         if (st.empty()) {
        //             return false;
        //         }
        //         char top = st.top();
        //         st.pop();
        //         if (ch == ')' && top != '(') return false;
        //         if (ch == ']' && top != '[') return false;
        //         if (ch == '}' && top != '{') return false;
        //     }
        // }
        // return st.empty();

    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {

            // If opening bracket, push it into the stack
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            }
            else {
                // If closing bracket comes but stack is empty
                if (st.empty()) {
                    return false;
                }

                // Check whether the top opening bracket matches
                // the current closing bracket
                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {

                    st.pop();  // Matching pair found
                }
                else {
                    return false; // Mismatched brackets
                }
            }
        }

        // Valid only if no opening brackets are left
        return st.empty();
    }
};