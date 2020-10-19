//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  cin >> n;
  int a[n];
  for(int &i : a) cin >> i;
  vector<int> p; 
  for(int i = 0; i < n; i++) {
    int count = 0;
    while(a[i] == 0 and i < n) {
      count++;
      i++;
    }
    if(count > 0) 
      p.push_back(count);
  }
  sort(p.begin(), p.end());
  int x = 0, y = 0;
  if(p.size() > 0)
    x = p[p.size()-1];
  if(p.size() > 1)
    y = p[p.size()-2];
  if(!y) 
    cout << (x&1 ? "Yes" : "No") << endl;
  else if(~x&1)
    cout << "No" << endl;
  else if(x/2 >= y)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  