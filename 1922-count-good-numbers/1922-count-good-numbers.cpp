class Solution {
public:
    const long long MOD = 1000000007;

long long power(long long base, long long exp) {
    if (exp == 0) return 1;
    long long result=1;
    long long half=power(base,exp/2);
    result=half*half% MOD;
    if(exp%2==1){
        result=result*base;
    }
    return result% MOD;
}

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; 
        long long oddCount = n / 2;       
        long long result = (power(5, evenCount) * power(4, oddCount)) % MOD;
        return (int)result;
    }
};