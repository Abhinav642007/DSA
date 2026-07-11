class Solution {
public:
    bool isvowel(char &ch){
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        return false;

    }
    string reverseVowels(string a) {
        int n=a.length();

        int i=0;
        int j=n-1;

        while(i<j){
            if(!isvowel(a[i])){
                i++;
            }
            else if (!isvowel(a[j])){
                j--;
            }
            else{// both are vowels
                swap(a[i],a[j]);
                i++;
                j--;
            }
        }
        return a;
        
    }
};