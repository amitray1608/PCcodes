//Ryuzaki
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sine() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  sort(a.begin(), a.end()); 
  ll sum = 0;
  for(int i =  n - k - 1; i < n; i++)
    sum += a[i], a[i] = 0;
  cout << sum << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
