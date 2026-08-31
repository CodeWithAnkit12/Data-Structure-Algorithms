class Solution {
public:
    void func(int ind, vector<int>& candidates, int target, vector<int>& vec, vector<vector<int>>& ans){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(vec);
            }
            return ;
        }
        if(candidates[ind]<=target){
        vec.push_back(candidates[ind]);
        func(ind,candidates,target-candidates[ind],vec,ans);
        vec.pop_back();
        }
        func(ind+1,candidates,target,vec,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        func(0,candidates,target,vec,ans);
        return ans;
    }
};