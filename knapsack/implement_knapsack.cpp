

#include <bits/stdc++.h>
using namespace std;
int val[1005];
int weigth[1005];

int knapsack(int i, int mx_weigth){
    // base case
    if(i<0 || mx_weigth <= 0)
        return 0;
    // add korbo and add korbo na
    if(weigth[i] <= mx_weigth){
        int op1 = knapsack(i-1,mx_weigth - weigth[i]) + val[i];
        int op2 = knapsack(i-1,mx_weigth);
        return max(op1,op2);
    }
    else{
        // add korbo na
        int op2 = knapsack(i-1,mx_weigth);
        return op2;
    }
}

int main(){
    int n,mx_weigth;

    cin >> n ;

    for(int i=0; i<n; i++)
        cin >> val[i];
    for(int i=0; i<n; i++)
        cin >> weigth[i];

    cin >> mx_weigth;

    cout << knapsack(n-1,mx_weigth);

    return 0;
}