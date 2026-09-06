class Solution {
public:
    void func(int i, string& temp, string& digits, vector<string>& ans, unordered_map<char,string>& mp){
        if(i==digits.length()){
            ans.push_back(temp);
        }
        string s1=mp[digits[i]];
        for(int j=0;j<s1.length();j++){
            temp+=s1[j];
            func(i+1,temp,digits,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string s;
        vector<string> ans;
        func(0,s,digits,ans,mp);
        return ans;
    }
};