class Solution {
public:
    string truncateSentence(string s, int k) {
        
    }
};class Solution {
public:
    string truncateSentence(string s, int k) 
    {
        int space=0;
        string ans= "";
        for (int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')  
            {
                space++;
            }
            if(space==k)
            {
                return ans;
            }
            ans+=s[i];
        }  
        return s;
    }
};