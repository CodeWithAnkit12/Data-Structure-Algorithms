class Solution {
public:
    bool checkDivisibility(int n) {
        int q=n;
        int sum=0;
        int prod=1;
        while(n>0){
            int x=n%10;
            sum+=x;
            prod*=x;
            n/=10;
        }
        int y=sum+prod;
        if(q%y==0) return true;
        return false;
    }
};