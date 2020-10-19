#include<bits/stdc++.h>
using namespace std;
long long dp[100];

double ssum(function<double(int)> f, int n){
  double sum = 0;
  for(int i=0; i<=n; i++) sum = sum + f(i);
  return sum;
}
int main(){
  int n; cin >> n;
  cout << ssum([](int i){return i*i*i;}, n)<<endl;
}
