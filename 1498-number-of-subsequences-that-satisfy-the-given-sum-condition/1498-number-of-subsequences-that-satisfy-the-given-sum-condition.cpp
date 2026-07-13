class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int l=0,r=n-1;
    int mod=1e9+7;
    int result=0;
    vector<int> pow(n,1);
    for(int i=1;i<n;i++){
        pow[i]=(pow[i-1]*2)%mod;
    }
    while(l<=r){
        if(nums[l]+nums[r]<=target){
            result=(result+pow[r-l])%mod;
            l++;
        }
        else{
            r--;
        }
    }
    return result;
}
    
};