class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sme=INT_MAX;
        int smo=INT_MAX;
        int cne=0,cno=0;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                cne++;
                sme=min(sme,nums1[i]);
            }else{
                cno++;
                smo=min(smo,nums1[i]);
            }
        }
        if(cne==n) return true;
        if(cno==n) return true;
        if(sme>smo) return true;
        return false;

    }
};