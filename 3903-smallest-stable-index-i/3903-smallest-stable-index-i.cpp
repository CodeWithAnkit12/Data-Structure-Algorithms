class Solution {
public:
    bool isStable(int m, vector<int>& nums, int k){
        int a=INT_MIN;
        for(int i=0;i<=m;i++){
            a=max(a,nums[i]);
        }
        int b=INT_MAX;
        for(int i=m;i<nums.size();i++){
            b=min(b,nums[i]);
        }
        int instability_score=a-b;
        if(instability_score<=k) return true;
        return false;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(isStable(i,nums,k)){
                ans=min(i,ans);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};