class Solution {
public:
    void func(int ind,vector<int>& nums,vector<int>& vec, vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[ind]);
        func(ind+1,nums,vec,ans);
        vec.pop_back();
        func(ind+1,nums,vec,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        func(0,nums,vec,ans);
        return ans;
    }
};