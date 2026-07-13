class Solution {
public:
    int m=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n= nums.size();
        //1 sort the array
        sort(begin(nums),end(nums));

        vector<int> power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1] * 2 ) % m;
        }

        //2 l=0,r=n-1
        int result=0;
        int l=0;
        int r=n-1;

        while(l<=r){
            if(nums[l]+nums[r]<=target){
                int diff=r-l;
                result=(result % m + power[diff]) % m;
                l++;
            }else{
                r--;
            }
        }
        return result;
    }
};