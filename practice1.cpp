
#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int rod_rec(int n,vector<int> &price){
if(n==0) return 0;
int max1=INT_MIN;
for(int i=1;i<=n;i++){
max1=max(max1,price[i]+rod_rec(n-i,price));
}
return max1;

}
int memoized_help(int n,vector<int> &price,vector<int> &dp){
if(n==0) return 0;
if(dp[n]!=-1) return dp[n];
int max1=INT_MIN;
for(int i=1;i<=n;i++){
max1=max(max1,price[i]+memoized_help(n-i,price,dp));
}
return dp[n]=max1;

}
int mem(int n,vector<int> &price){
vector<int> dp(n+1,-1);
memoized_help(n,price,dp);

}

int main(){
int n;
cin>> n;
vector<int> p(n+1);
for(int i=1;i<n+1;i++){
cin>> p[i];
}
cout<<"The maximum profit can be drawn by cutting into"<<rod_rec(7,p)<<endl;
cout<<"The maximum profit can be drawn by cutting into"<<mem(7,p)<<endl;
}