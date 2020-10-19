#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
  if(a.first == b.first) return (a.second < b.second);
  return a.first < b.first;
}

void solve(){
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>>a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), sortbysec);
  int b = 1, count = 0;
  for(int i = 0; i < n; i++) {
   // cout << b << endl;
    //cout << a[i].first << ' ' << a[i].second << '\n';
    if(a[i].first > b) count++, b = a[i].first+k;
    if(a[i].second > b) {
      a[i].second -= b;
      int x = a[i].second / k + (a[i].second %k ? 1 : 0);
      count += x;
      b += (k*x);
    }
  }
  cout << count << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  cout << "Case #" << ++tt  << ": ";
    solve();
  }
  return 0;
}
