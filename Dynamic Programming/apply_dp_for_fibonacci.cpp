

#include <bits/stdc++.h>
using namespace std;

vector<long long>dp(1005,-1);

long long fibo(long long n){
    if(n < 3) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}

int main(){
    long long n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}