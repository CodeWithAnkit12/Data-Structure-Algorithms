class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int f[26]={0};
        int res=0;
        for(int l=0,r=0; r<n;r++){
            f[s[r]-'a']++;
            while(f[s[r]-'a']>2){
                f[s[l]-'a']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};