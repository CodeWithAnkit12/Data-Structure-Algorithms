class Solution {
public:
    void func(int i, int k, int sum, int n, vector<int>& vec, vector<vector<int>>& ans){
        if(k<0) return;
        if(k==0){
            if(sum==n){
                ans.push_back(vec);
            }
            return;
        }
        if(i==10) return;
        vec.push_back(i);
        func(i+1,k-1,sum+i,n,vec,ans);
        vec.pop_back();
        func(i+1,k,sum,n,vec,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        vector<vector<int>> ans;
        func(1,k,0,n,vec,ans);
        return ans;
    }
};