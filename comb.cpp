//AtCoderのパクリ
//https://github.com/atcoder-live/library/blob/master/comb.cpp
//これが元
//mintが必要

struct combinatoin{
    vector<mint> fact, ifact;
    combinatoin(int n):fact(n+1), ifact(n+1){
        assert(n < mod);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for(int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k){
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};
