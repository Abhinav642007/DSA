class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            // If stack is empty OR current character is different
            // from the top character, push it
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            }
            else {
                // Same character found -> remove the top
                st.pop();
            }
        }

        // Stack contains the answer in reverse order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // Reverse to get the correct order
        reverse(result.begin(), result.end());

        return result;
    }
};