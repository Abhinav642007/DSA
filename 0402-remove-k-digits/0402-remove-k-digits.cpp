class Solution {
public:

    string removeKdigits(string num, int k) {

        // Stack mein digits store karenge.
        // Hum ise left-to-right number maintain karne ke liye use karenge.
        stack<char> st;


        // Number ke har digit ko left se right process karo.
        // Example: "1432219"
        // digit = 1 → 4 → 3 → 2 → 2 → 1 → 9
        for (char digit : num) {


            // Main logic:
            //
            // st.empty()       → remove karne ke liye koi digit hai?
            // k > 0            → abhi removal allowed hai?
            // st.top() > digit → previous digit current se bada hai?
            //
            // Agar previous digit bada hai,
            // toh usko remove karna number ko chhota banayega.
            //
            // Example:
            // Stack = 14
            // Current digit = 3
            //
            // 4 > 3 → 4 ko remove karo
            //
            // 14 → 1
            while (!st.empty() &&
                   k > 0 &&
                   st.top() > digit) {


                // Stack ke top wala bada digit remove karo.
                //
                // Example:
                // Stack = 14
                // top = 4
                //
                // pop() ke baad:
                // Stack = 1
                st.pop();


                // Ek digit remove ho gaya,
                // isliye k ko 1 kam karo.
                //
                // k = 3
                // becomes
                // k = 2
                k--;
            }


            // Ab current digit ko stack mein daal do.
            //
            // Example:
            // Stack = 1
            // digit = 3
            //
            // Stack = 13
            st.push(digit);
        }


        // ------------------------------------------------
        // Agar number process hone ke baad bhi k bacha hai
        // ------------------------------------------------
        //
        // Example:
        // num = "12345"
        // k = 2
        //
        // Koi previous digit bada nahi milega,
        // isliye upar wali while se removal nahi hoga.
        //
        // Ab smallest number banane ke liye
        // end/right se digits remove karenge.
        while (k > 0) {

            // Last digit remove karo.
            st.pop();

            // Ek removal use ho gaya.
            k--;
        }


        // ------------------------------------------------
        // Stack ko answer string mein convert karna
        // ------------------------------------------------

        string ans;


        // Stack LIFO hota hai:
        //
        // Stack:
        // 1
        // 2
        // 1
        // 9
        //
        // Top se niklega:
        // 9 → 1 → 2 → 1
        //
        // Isliye answer reverse order mein milega.
        while (!st.empty()) {

            // Stack ka top digit answer mein add karo.
            ans += st.top();

            // Jo digit le liya usko stack se hata do.
            st.pop();
        }


        // Abhi answer reverse hai,
        // isliye original order mein laane ke liye reverse karo.
        //
        // Example:
        // ans = "9121"
        //
        // reverse:
        // ans = "1219"
        reverse(ans.begin(), ans.end());


        // ------------------------------------------------
        // Leading zeros remove karna
        // ------------------------------------------------

        // Starting position se check karenge.
        int i = 0;


        // Jab tak starting mein '0' mil raha hai,
        // index ko aage badhao.
        //
        // Example:
        // ans = "00123"
        //
        // i = 0 → 0 → skip
        // i = 1 → 0 → skip
        // i = 2 → 1 → stop
        while (i < ans.size() &&
               ans[i] == '0') {

            i++;
        }


        // Agar poori string zeros thi,
        // toh valid answer "0" hoga.
        //
        // Example:
        // ans = "000"
        if (i == ans.size()) {
            return "0";
        }


        // Leading zeros ke baad ka actual number return karo.
        //
        // Example:
        // ans = "00123"
        // i = 2
        //
        // ans.substr(2) = "123"
        return ans.substr(i);
    }
};