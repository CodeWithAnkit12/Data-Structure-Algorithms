class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans+=nums[i]-l;
        }
        return ans;
    }
};