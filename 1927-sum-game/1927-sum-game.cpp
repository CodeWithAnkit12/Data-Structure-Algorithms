class Solution {
public:
    bool sumGame(string num) {
        int n= num.size();
        int ql=0,qr=0,suml=0,sumr=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') ql++;
            else suml+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') qr++;
            else sumr+=num[i]-'0';
        }
        int qd=abs(ql-qr);
        int sumd=abs(suml-sumr);
        if(ql==qr && ql==0){
            if(sumd==0) return false;
            else return true;
        }
        else if ((ql+qr)%2==1){
            return true;
        }
        else if ((ql+qr)%2==0){
            if(ql==qr){
                if(suml==sumr) return false;
                else{
                    return true;
                }
            }
            else{
                if(2*(suml-sumr)==9*(qr-ql)) return false;
                else{
                    return true;
                }
            }
        }
        return true;        
    }
};