class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=nums[n/2];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-l);
        }
        return ans;
    }
};