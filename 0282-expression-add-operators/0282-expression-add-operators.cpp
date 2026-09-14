class Solution {
public:
    void solve(int ind,string& num, int target, string curr, vector<string>& ans, long prev, long res){
        if(ind==num.length()){
            if(res==target){
                ans.push_back(curr);
            }
            return;
        }
        string st="";
        long currres=0;
        for(int i=ind;i<num.size();i++){
            if(i>ind && num[ind]=='0') break;
            st+=num[i];
            currres=currres*10+(num[i]-'0');
            if(ind==0){
                solve(i+1,num,target,st,ans,currres,currres);
            }else{
                solve(i+1,num,target,curr+"+"+st,ans,+currres,res+currres);
                solve(i+1,num,target,curr+"-"+st,ans,-currres,res-currres);
                solve(i+1,num,target,curr+"*"+st,ans,prev*currres,res-prev+(prev*currres));
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0,num,target,"",ans,0,0);
        return ans;
    }
};