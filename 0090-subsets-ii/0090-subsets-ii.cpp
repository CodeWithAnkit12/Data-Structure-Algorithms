class Solution {
public:
    void func(int ind,vector<int>& nums,vector<int>& vec, vector<vector<int>>& ans){
            ans.push_back(vec);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            vec.push_back(nums[i]);
            func(i+1,nums,vec,ans);
            vec.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> vec;
        func(0,nums,vec,ans);
        return ans;
    }
};